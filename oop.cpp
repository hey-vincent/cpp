#include "oop.h"

//Constructor 2;
Student::Student(string name)
{
	cout << "Constructor 2 called." << endl;
	m_name	= name;
	m_gender= MALE;
	m_age	= 0;
	m_ID	= 0;
}

//Constructor 3;
Student::Student(string name, GENDER gender)
{
	cout << "Constructor 3 called." << endl;
	m_name	= name;
	m_gender= gender;
	m_age	= 0;
	m_ID	= 0;
}

Student::~Student()
{
	cout <<__FUNCTION__<<endl;
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



/////////////////////////////////////////////////////////////////////////////////////////////////////////////
ColledgeStudent::ColledgeStudent(string name, GENDER gender)
	:Student(name,gender)
{
	cout <<__FUNCTION__<<endl;
}

// Call son's destructor and then father's
ColledgeStudent::~ColledgeStudent()
{
	cout <<__FUNCTION__<<endl;
}