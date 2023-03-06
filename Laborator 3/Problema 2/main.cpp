#include <iostream>
#include "Canvas.h"
//#include "Math.h"
using namespace std;
Canvas x(50,50);
//Math m;
int main()
{
	////math int
	//{
	//	int a = 258, b = 337, c = 657;
	//	cout << m.Add(a, b) << endl;
	//	cout << m.Add(a, b, c) << endl;
	//	cout << m.Mul(a, b) << endl;
	//	cout << m.Mul(a, b, c) << endl;
	//}
	////math double
	//{
	//	double a = 446.16, b = 935.44, c = 208.95;
	//	cout << m.Add(a, b) << endl;
	//	cout << m.Add(a, b, c) << endl;
	//	cout << m.Mul(a, b) << endl;
	//	cout << m.Mul(a, b, c) << endl;
	//}
	////math string add
	//{
	//	cout << m.Add(6, 73, 54, 62, 13, 22, 85) << endl;
	//	char a[100] = "ABC", b[100] = "abc";
	//	strcpy_s(a, m.Add(a, b));
	//	cout << a << endl;
	//}
	//canvas
	{
		x.DrawCircle(10, 10, 7, 'c');
		x.FillCircle(10, 10, 7, '*');
		x.DrawRect(20, 30, 30, 20, 'r');
		x.FillRect(21, 29, 29, 21, '@');
		x.SetPoint(10, 40, 't');
		x.DrawLine(40, 20, 48, 48, 'l');
		x.DrawLine(48, 20, 40, 48,'l');
		//x.Clear();
		x.Print();
	}
	return 0;
}