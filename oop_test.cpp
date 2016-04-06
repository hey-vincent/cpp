#include "oop.h"

int main()
{
	Student st("Vincent", MALE);
	cout << endl;

	ColledgeStudent cs = ColledgeStudent("Shirley", FEMALE);
	cout << endl;

	Student *pStd = new ColledgeStudent("Amy", FEMALE);
	pStd->ShowInfo();
	delete pStd;
	cout << endl;

	cout << "Using operator =" << endl;
	Student st1 = st;
	cout << endl;

	cout << "Copying constructor" << endl;
	Student st2(st1);
	ColledgeStudent cs1(cs);
	cs1.ShowInfo();


	// When the constructor will  be called?
	cout << endl<< "When the constructor will  be called?" << endl;
	Student student("JIM",MALE);
	Student *pStudent;
	Student *pStud = new Student("JIM",MALE);
	Student &stu = student;

	cout<< endl <<"按值传递参数" << endl;
	st.ChangeID(st1);
	cout << "按引用传递参数" << endl;
	st.ChangeGender(st1);
	
	system("pause");
}