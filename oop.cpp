#include "oop.h"

 int Student::student_number = 0;

//Constructor 2;
Student::Student(string name)
	:m_gender(MALE)
	,m_age(0)
	,m_ID(0)
{
	cout << "构造函数1调用" << endl;
	m_name	= name;
	student_number ++;
}

//Constructor 3;
Student::Student(string name, GENDER gender)
{
	student_number ++;
	cout << "构造函数2调用" << endl;
	m_name	= name;
	m_gender= gender;
	m_age	= 0;
	m_ID	= 0;

}

//Constructor 4
Student::Student(Student& another)
{
	student_number ++;
	cout << "拷贝构造函数调用" << endl;
	cout << "拷贝对象 " << another.m_name << endl;
	m_name = another.m_name;
	m_gender = another.m_gender;
	m_age = another.m_age;
	m_ID = another.m_ID;
}




//Destructor 
Student::~Student()
{
	cout << "析构函数调用" << endl;
}


void Student::ShowInfo()
{
	auto gend = "";
	gend = MALE == m_gender? "MALE":"FEMALE";
	cout << m_name << '\t' << gend << '\t' << m_age << '\t' << m_ID << endl<< endl;
}


void Student::SelfIntroduce()
{
	cout << "I am a student. Just student." <<  endl;
}

//Change student's ID
int Student::ChangeID(Student st)
{
	return ++st.m_ID;
}

GENDER Student::ChangeGender(Student &st)
{
	return (GENDER)(st.m_gender^1);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*					ColledgeStudent Class														  */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

ColledgeStudent::ColledgeStudent(string name)
	:Student(name)
{
	LOG;
}



ColledgeStudent::ColledgeStudent(string name, GENDER gender)
	:Student(name,gender)
{
	LOG;
}


// Call son's destructor and then father's
ColledgeStudent::~ColledgeStudent()
{
	LOG;
}


void ColledgeStudent::SelfIntroduce()
{
	cout << __FUNCTION__ << endl;
	cout << "Now I am a college student." << endl;
}


void ColledgeStudent::ShowInfo()
{
	LOG;
}