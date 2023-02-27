#include<iostream>
#include "NumberList.h"
using namespace std;
NumberList x;

int main()
{
    x.Init();
    x.Add(2);
    x.Add(1);
    x.Sort();
    x.Print();
}