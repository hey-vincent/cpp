#include "oop.h"

//Constructor 2;
Student::Student(string name)
	:m_gender(MALE)
	,m_age(0)
	,m_ID(0)
{
	LOG;
	m_name	= name;
}

//Constructor 3;
Student::Student(string name, GENDER gender)
{
	LOG;
	m_name	= name;
	m_gender= gender;
	m_age	= 0;
	m_ID	= 0;
}

//Constructor 4
Student::Student(Student& another)
{
	LOG;
	m_name = another.m_name;
	m_gender = another.m_gender;
	m_age = another.m_age;
	m_ID = another.m_ID;
}




//Destructor 
Student::~Student()
{
	LOG;
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
