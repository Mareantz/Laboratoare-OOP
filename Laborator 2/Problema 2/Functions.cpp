#include "Student.h"
#include "Functions.h"
#include <cstring>

int CompareName(Student first, Student second)
{
	if (strcmp(first.getName(), second.getName()) > 0)
		return 1;
	if (strcmp(first.getName(), second.getName()) == 0)
		return 0;
	if (strcmp(first.getName(), second.getName()) < 0)
		return -1;
}

int CompareMathGrade(Student first, Student second)
{
	if (first.getGrade_Math() > second.getGrade_Math())
		return 1;
	if (first.getGrade_Math() == second.getGrade_Math())
		return 0;
	if (first.getGrade_Math() < second.getGrade_Math())
		return -1;
}

int CompareEnglishGrade(Student first, Student second)
{
	if (first.getGrade_English() > second.getGrade_English())
		return 1;
	if (first.getGrade_English() == second.getGrade_English())
		return 0;
	if (first.getGrade_English() < second.getGrade_English())
		return -1;
}

int CompareHistoryGrade(Student first, Student second)
{
	if (first.getGrade_History() > second.getGrade_History())
		return 1;
	if (first.getGrade_History() == second.getGrade_History())
		return 0;
	if (first.getGrade_History() < second.getGrade_History())
		return -1;
}

int CompareAverageGrade(Student first, Student second)
{
	if (first.Grade_Average() > second.Grade_Average())
		return 1;
	if (first.Grade_Average() == second.Grade_Average())
		return 0;
	if (first.Grade_Average() < second.Grade_Average())
		return -1;
}