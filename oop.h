#include <iostream>

#include <string>
using namespace std;


typedef enum _gender
{
	MALE    =	0,
	FEMALE,
}GENDER;

class Student
{
	
public:
	 Student();								//C1; I define a non-parameter constructor which has no implementation. So 'bAlive' is safe.
	 Student(string name);						//C2;
	 Student(string name, GENDER gender = MALE);	//C3; C3 has different paramters list with C2. Which one will called if Student("Jim")?; 
	 
	 virtual ~Student();
	
	
	void ShowInfo();
	void SelfIntroduce();
private:
	string	m_name;
	GENDER	m_gender;
	short	m_age;
	int		m_ID;
	// g++ don't report error .
	// Error	1	error C2864: 'Student::bAlive' : only static const integral data members can be initialized within a class
	// const bool bAlive = true;					// this member is const. But if we don't define an non-parameter constructor. What will happen?
};

class ColledgeStudent : public Student
{
public:
	 ColledgeStudent(string name, GENDER gender);
	~ColledgeStudent();
};

