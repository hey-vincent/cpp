#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <vector>
using namespace std;

/*******************************************************************/
// Common function

template <typename T>
void print_vector(T& c)	;		// print elements of a container

/*******************************************************************/
// Test Function
void test_struct();				// struct tester
void test_operater();			// operater tester

// :template
template <typename T>
void print_vector(T& c)
{
	typename T::iterator iter = c.begin(); // this keyword 'typename' is necessary
	while(iter != c.end())
	{
		iter->show();
		iter ++;
	}
}
// :struct
typedef struct _human
{
	char	name[16];
	int		age;
	
	 _human(char* ch_name, int n_age) // constructor with struct
	{
		memset(name, 16, 0);
		memcpy(name, ch_name, 16);
		age  = n_age;
	}
	
	
	void show()
	{
		cout<< "name: "<< name << '\t' << "age:" << age << endl;
	}
	
}Human;

void struct_tester()
{
	Human old_man("Neil Young", 50);
	old_man.show();
	
	Human young_man("Zuk Berg", 35);
	young_man.show();
	
	vector<_human> vec(10,Human("Unknown Name",0));
	print_vector< vector<_human> >(vec);
}


void test_operater()
{
	// operater:^
	cout << "0^1 " << (0^1) << endl;
	cout << "1^1 " << (1^1) << endl;
	
	int a = 0x08;
	int b = 0x04;
	int c = 0x0C;
	int d = 0x09;
	cout << "a^b " << (a^b) << endl;
	cout << "c^a " << (c^a) << endl;
	// level: ^ > |
	cout << "(c^a|a)"<< (c^a|a) << endl;
	cout << "d^b" << (d^b) << endl;
	
	
	
}

int main()
{
	//struct_tester();
	test_operater();
	return 0;
}