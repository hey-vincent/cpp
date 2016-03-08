#include <iostream>
#include <Windows.h>
using namespace std;


int nCount = 100;						// 各个现成操作的对象
HANDLE m_mutex = CreateMutex(NULL,FALSE,"MUTEX");
HANDLE m_event = CreateEvent(NULL,FALSE,FALSE,"QuitSignal");

DWORD WINAPI Thread1(LPVOID lp)			// 线程1
{
	while (true)
	{
		WaitForSingleObject(m_mutex,INFINITE);

		if (nCount <= 0)
		{
			break;
		}

		nCount --;
		cout << "Thread 1: "<< nCount<< endl;
		ReleaseMutex(m_mutex);
	}
	return 0;
}

DWORD WINAPI Thread2(LPVOID lp)			// 线程2 ：只工作到50 工作量完成后休息，剩余工作量由线程3执行
{
	while (true)
	{
		WaitForSingleObject(m_mutex,INFINITE);
		if (nCount <= 50)
		{
			cout << "线程2休息" << endl;
			break;
		}
		nCount --;
		cout << "Thread 2: "<< nCount<< endl;
		ReleaseMutex(m_mutex);
	}
	SetEvent(m_event);
	return 0;
}

DWORD WINAPI Thread3(LPVOID lp)			// 线程3，接管线程2的工作。完成后通知
{
	if( WAIT_OBJECT_0 ==  WaitForSingleObject(m_event,INFINITE))
	{
		cout << "线程3接管" << endl;
	}
	
	while (true)
	{
		WaitForSingleObject(m_mutex,INFINITE);
		if (nCount <= 0)
		{
			break;
		}

		nCount --;
		cout << "Thread 3: "<< nCount<< endl;
		ReleaseMutex(m_mutex);
	}
	ResetEvent(m_event);
	return 0;
}

int main()
{
	DWORD thread_ID_1,thread_ID_2;
	HANDLE pThreadHandle[3] = {0};
	pThreadHandle[0] = CreateThread(NULL,0,Thread1, NULL,0, &thread_ID_1);
	if (pThreadHandle == NULL)
	{
		cout << "Failed to create thread 1. With Error : " << GetLastError() << endl;
	}
	pThreadHandle[1] = CreateThread(NULL,0,Thread2, NULL,0, &thread_ID_2);
	if ( (pThreadHandle+1) == NULL)
	{
		cout << "Failed to create thread 2. With Error : " << GetLastError() << endl;
	}
	pThreadHandle[2] = CreateThread(NULL,0,Thread3,NULL,0,NULL);
	if ( (pThreadHandle+2) == NULL)
	{
		cout << "Failed to create thread 3. With Error : " << GetLastError() << endl;
	}

	WaitForMultipleObjects(3, pThreadHandle,TRUE, INFINITE);

	system("pause");
	return 0;
}