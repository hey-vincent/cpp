#include "oop.h"

int main()
{
	string name = "Vincent";
	Student st = Student(name, MALE);	//Compiler will report an error if I pass only one parameter.
	st.ShowInfo();

	ColledgeStudent cs = ColledgeStudent("Sherly", FEMALE);
	cs.ShowInfo();
	system("pause");
}