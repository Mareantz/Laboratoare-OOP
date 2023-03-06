#include "Math.h"
#include <stdarg.h>
#include <string.h>
int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	return x + y;
}

int Math::Add(double x, double y, double z)
{
	return x + y + z;
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	return x * y;
}

int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}

int Math::Add(int count, ...) 
{
	va_list list;
	va_start(list, count);
	int s = 0;
	for (int i = 0; i < count; i++)
		s = s + va_arg(list, int);
	va_end(list);
	return s;
}

char* Math::Add(const char* x, const char* y)
{
	if (x == nullptr || y == nullptr)
		return nullptr;
	char a[100], b[100];
	strcpy_s(a, x);
	strcpy_s(b, y);
	strcat_s(a, b);
	return a;
}

//tentativa adunat nr mari
//char* Math::Add(const char* x, const char* y)
//{
//	char a[100], b[100], c[101];
//	strcpy(a, x);
//	strcpy(b, y);
//	for (int i = 99; i >= 0; i--)
//	{
//		c[i] = (c[i]+a[i] + b[i] - 2 * '0') % 10;
//		if (a[i] + b[i] - 2 * '0' > 10)
//			c[i - 1] += 1;
//	}
//}