#include "Student.h"
#include <cstring>
Student::Student() {}
float Student::getGrade_Math()
{
	return this->grade_math;
}

float Student::getGrade_English()
{
	return this->grade_english;
}

float Student::getGrade_History()
{
	return this->grade_history;
}

const char* Student::getName()
{
	return this->name;
}

void Student::setName(const char input_name[])
{
	strcpy_s(this->name, input_name);
}

void Student::setGrade_Math(float grade)
{
	if (grade < 1 || grade>10)
		return;
	grade_math = grade;
}

void Student::setGrade_English(float grade)
{
	if (grade < 1 || grade>10)
		return;
	grade_english = grade;
}

void Student::setGrade_History(float grade)
{
	if (grade < 1 || grade>10)
		return;
	grade_history = grade;
}

float Student::Grade_Average()
{
	return 1.0 * (this->grade_math + this->grade_english + this->grade_history) / 3;
}