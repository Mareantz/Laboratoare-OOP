#include<iostream>
#include "Student.h"
#include "Functions.h"
using namespace std;
Student s,x;

int main()
{
    s.setName("Popescu Daniel");
    s.setGrade_Math(6.93);
    s.setGrade_English(7.44);
    s.setGrade_History(9.40);
    x.setName("Botezatu Cosmin");
    x.setGrade_Math(8.45);
    x.setGrade_English(5.46);
    x.setGrade_History(9.27);
    printf("%d\n", CompareName(s, x));
    printf("%d\n", CompareMathGrade(s, x));
    printf("%d\n", CompareEnglishGrade(s, x));
    printf("%d\n", CompareHistoryGrade(s, x));
    printf("%f %f %d\n",s.Grade_Average(),x.Grade_Average(), CompareAverageGrade(s, x));
}