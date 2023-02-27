#pragma once
class Student
{
	char name[255]= "\0";
	float grade_math=-1, grade_english, grade_history, grade_avg;
public:
	Student();
	void setName(const char input_name[]);
	void setGrade_Math(float grade_math);
	void setGrade_English(float grade_english);
	void setGrade_History(float grade_history);
	const char* getName();
	float getGrade_Math();
	float getGrade_English();
	float getGrade_History();
	float Grade_Average();
};