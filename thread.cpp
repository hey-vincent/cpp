#include <iostream>
#include <Windows.h>
using namespace std;


int nCount = 100;						// �����ֳɲ����Ķ���
HANDLE m_mutex = CreateMutex(NULL,FALSE,"MUTEX");
HANDLE m_event = CreateEvent(NULL,FALSE,FALSE,"QuitSignal");

DWORD WINAPI Thread1(LPVOID lp)			// �߳�1
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

DWORD WINAPI Thread2(LPVOID lp)			// �߳�2 ��ֻ������50 ��������ɺ���Ϣ��ʣ�๤�������߳�3ִ��
{
	while (true)
	{
		WaitForSingleObject(m_mutex,INFINITE);
		if (nCount <= 50)
		{
			cout << "�߳�2��Ϣ" << endl;
			break;
		}
		nCount --;
		cout << "Thread 2: "<< nCount<< endl;
		ReleaseMutex(m_mutex);
	}
	SetEvent(m_event);
	return 0;
}

DWORD WINAPI Thread3(LPVOID lp)			// �߳�3���ӹ��߳�2�Ĺ�������ɺ�֪ͨ
{
	if( WAIT_OBJECT_0 ==  WaitForSingleObject(m_event,INFINITE))
	{
		cout << "�߳�3�ӹ�" << endl;
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