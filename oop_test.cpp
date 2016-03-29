#include "oop.h"

int main()
{
	Student st("Vincent", MALE);
	cout << endl;

	ColledgeStudent cs = ColledgeStudent("Shirley", FEMALE);
	cout << endl;

	Student *pStd = new ColledgeStudent("Amy", FEMALE);
	delete pStd;
	cout << endl;

	Student st1 = st;
	cout << endl;

	Student st2(st1);

	ColledgeStudent cs1 = cs;

	
	system("pause");
}