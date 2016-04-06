#include <iostream>

#include <string>
using namespace std;



#define LOG	cout<<__FUNCTION__<< __LINE__ <<endl


typedef enum _gender
{
	MALE    =	0,
	FEMALE,
}GENDER;

// Class Student
class Student
{
	
public:
	 Student();									//C1; I define a non-parameter constructor which has no implementation. So 'bAlive' is safe.
	 Student(string name);							//C2;
	 Student(string name, GENDER gender/*= MALE*/);	//C3; C3 has different paramters list with C2. Which one will called if Student("Jim")?; 
	 Student(Student& another);						//C4: Copying constructor

	 virtual ~Student();
	
	
	void ShowInfo();
	virtual void SelfIntroduce();
	int ChangeID(Student st);
	GENDER ChangeGender(Student &st);
private:
	string	m_name;
	GENDER	m_gender;
	short	m_age;
	int		m_ID;
	// g++ wouldn't report error .
	// error C2864: 'Student::bAlive' : only static const integral data members can be initialized within a class
	// const bool bAlive = true;					// this member is const. But if we don't define an non-parameter constructor. What will happen?

	//Only 'const int' or 'const enumeration' can be valued in class declaration
	static  const int age_least = 6;				// Define minimum age of a student.This could be fine cause it's cnst int. 
	//static char ch = 'a' ;

	static int student_number;
	
};

//Class ColledgeStudent
class ColledgeStudent : public Student
{
public:
	 ColledgeStudent(string name);
	 ColledgeStudent(string name, GENDER gender);
	~ColledgeStudent();
	void ShowInfo();
	virtual void SelfIntroduce();
};




//*******************************************************
//				Design Model:Factory
//*******************************************************
typedef enum _nokia_series
{
	JAVA		= 0	,
	SYMBIAN		,
	ANDRIOD		,
}NOKIA_SERIES;

class NokiaPhone
{
public:
	inline NokiaPhone()
	{
		nSeries = 0;
	}

	inline ~NokiaPhone()
	{

	}
private:
	int nSeries;
};

class NokiaJavaPhone : public NokiaPhone
{
public:
	inline NokiaJavaPhone()
	{

	}
	inline ~NokiaJavaPhone()
	{

	}
};

class NokiaSymbianPhone : public NokiaPhone
{
public:
	inline NokiaSymbianPhone()
	{

	}

	inline ~NokiaSymbianPhone()
	{

	}

};

// the simple factory class for Nokia phone producing.
class NokiaFactory	
{
public:
	inline NokiaFactory()
	{

	}

	inline ~NokiaFactory()
	{

	}

	inline NokiaPhone* ProduceNokiaPhone(NOKIA_SERIES series)
	{
		NokiaPhone* nokia_phone = new NokiaPhone;
		switch(series)
		{
		case JAVA:
			nokia_phone = new NokiaJavaPhone;
			break;
		case SYMBIAN:
			nokia_phone = new NokiaSymbianPhone;
			break;

		default:
			nokia_phone = NULL;
			break;
		}
	}
};