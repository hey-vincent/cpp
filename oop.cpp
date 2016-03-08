#include <iostream>
#include <string>
using namespace std;

class Father
{
	
public:
	Father();
	~Father();
	int var1;
	void Func();
	virtual void Func1();
private:
	int var2;
	void Func2();
protected:
	int var3;
	void Func3();
};

Father::Father()
:var1(0)
,var2(0)
,var3(0)
{
	
}
Father::~Father()
{
	
}

void Father::Func()
{
	cout << "Father::Func" << endl;
}

void Father::Func1()
{
	cout << "Father::Func1" << endl;
}

void Father::Func2()
{
	cout << "Father::Func2" << endl;
}

void Father::Func3()
{
	cout << "Father::Func3" << endl;
}





class Son : public Father
{
public:
	Son();
	~Son();
	void Func1();
	void Func();
};

Son::Son()
{
}
Son::~Son()
{
}

void Son::Func1()
{
	Father::Func1();
	Func3();
	
	cout << "Son::Func1 "  << var3<< endl;
}

void Son::Func()
{
	cout << "Son::Func" << endl;
}


int main()
{
	Father f;
	Son s;
	// s.Func1();
	// cout << s.var1;
	
	Father *pF = new Father();
	Father *pS = new Son();
	
	pF->Func1();
	cout << endl;
	pS->Func1();
	
	pF->Func();
	pS->Func();
	
	
	
	return 0;
}

















