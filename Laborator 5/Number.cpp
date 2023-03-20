#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstring>
#include <iostream>
using namespace std;

Number::Number(const char* value, int base)
{
	this->number = 0;
	int p = 1;
	this->digitCount = strlen(value);
	this->baseNumber = new char[GetDigitsCount()];
	strcpy(baseNumber, value);
	this->base = base;
	for (int i = 1; i <= GetDigitsCount(); i++)
	{
		if (this->baseNumber[GetDigitsCount() - i] <= '9' && this->baseNumber[GetDigitsCount() - i] >= '0')
			this->number = p * (this->baseNumber[GetDigitsCount() - i] - '0') + this->number;
		if (this->baseNumber[GetDigitsCount() - i] <= 'F' && this->baseNumber[GetDigitsCount() - i] >= 'A')
			this->number = p * (this->baseNumber[GetDigitsCount() - i] - '7') + this->number;
		p *= base;
	}
}

Number::Number(const char* value)
{
	this->number = 0;
	int p = 1;
	this->digitCount = strlen(value);
	this->baseNumber = new char[GetDigitsCount()];
	strcpy(baseNumber, value);
	this->base = 10;
	for (int i = 1; i <= GetDigitsCount(); i++)
	{
		this->number = p * (value[GetDigitsCount() - i] - '0') + this->number;
		p *= 10;
	}
}

Number::Number(int value)
{
	this->base = 10;
	this->number = value;
	int aux = value;
	int k = 0;
	while (aux)
	{
		k++;
		aux /= 10;
	}
	this->digitCount = k;
	this->baseNumber = new char[k];
	for (int i = 1; i <= k; i++)
	{
		this->baseNumber[k - i] = value % 10 + '0';
		value /= 10;
	}
}

int Number::operator[](int index)
{
	return this->baseNumber[index];
}

Number::~Number()
{
	this->baseNumber = nullptr;
	delete[] this->baseNumber;
}

Number::Number(const Number& value)
{
	this->number = value.number;
	this->digitCount = value.digitCount;
	this->base = value.base;
	this->baseNumber = new char[value.digitCount + 1];
	strcpy(this->baseNumber, value.baseNumber);
}

Number::Number(const Number&& value): base(value.base), digitCount(value.digitCount), number(value.number), baseNumber(value.baseNumber)
{
	this->baseNumber = new char[value.digitCount + 1];
	strcpy(this->baseNumber, value.baseNumber);
	delete[] value.baseNumber;
}

int Number::GetDigitsCount()
{
	return this->digitCount;
}

int Number::GetBase()
{
	return this->base;
}

void Number::Print()
{
	for (int i = 0; i < GetDigitsCount(); i++)
		cout << this->baseNumber[i];
	cout << " " << this->base <<" "<<this->number<<" "<< GetDigitsCount() << endl;
}

void Number::SwitchBase(int base)
{
	int aux = 0, p = 1;
	for (int i = 1; i <= GetDigitsCount(); i++)
	{
		if (this->baseNumber[GetDigitsCount() - i] <= '9'&& this->baseNumber[GetDigitsCount() - i]>='0')
			aux = p * (this->baseNumber[GetDigitsCount() - i] - '0') + aux;
		if(this->baseNumber[GetDigitsCount() - i]<='F'&& this->baseNumber[GetDigitsCount() - i]>='A')
			aux = p * (this->baseNumber[GetDigitsCount() - i] - '7') + aux;
		p *= this->base;
	}
	p = 1;
	int k = 0;
	while (aux > p)
	{
		p *= base;
		k++;
	}
	this->baseNumber[k] = NULL;
	this->digitCount = k;
	while (aux)
	{
		if(aux%base<=9)
			this->baseNumber[--k] = aux % base + '0';
		else
			this->baseNumber[--k] = aux % base + '7';
		aux /= base;
	}
	this->base = base;
}

Number operator+(const Number& value1, const Number& value2)
{
	int largerBase = max(value1.base, value2.base);
	Number temp1(value1), temp2(value2);
	temp1.SwitchBase(10);
	temp2.SwitchBase(10);
	int largerDigitCount = max(temp1.GetDigitsCount(), temp2.GetDigitsCount());
	char* sum = new char[largerDigitCount +1];
	sum[largerDigitCount] = '\0';
	int number = temp1.number + temp2.number;
	for (int i = 1; i <= largerDigitCount; i++)
	{
		sum[largerDigitCount - i] = number % 10 + '0';
		number /= 10;
	}
	Number result(sum, 10);
	result.SwitchBase(largerBase);
	delete[] sum;
	return result;
}

Number operator-(const Number& value1, const Number& value2)
{
	int largerBase = max(value1.base, value2.base);
	Number temp1(value1), temp2(value2);
	temp1.SwitchBase(10);
	temp2.SwitchBase(10);
	int largerDigitCount = max(temp1.GetDigitsCount(), temp2.GetDigitsCount());
	char* sum = new char[largerDigitCount + 1];
	sum[largerDigitCount] = '\0';
	int number = temp1.number - temp2.number;
	for (int i = 1; i <= largerDigitCount; i++)
	{
		sum[largerDigitCount - i] = number % 10 + '0';
		number /= 10;
	}
	Number result(sum, 10);
	result.SwitchBase(largerBase);
	delete[] sum;
	return result;
}

Number Number::operator++()
{
	return *this + 1;
}
Number Number::operator++(int numar) 
{
	return *this + 1;
}
Number Number::operator--()
{
	for (int i = 0; i < GetDigitsCount(); i++)
		this->baseNumber[i] = this->baseNumber[i + 1];
	this->baseNumber[GetDigitsCount()+1] = '\0';
	this->digitCount--;
	this->number = 0;
	int p = 1;
	for (int i = 1; i <= GetDigitsCount(); i++)
	{
		if (this->baseNumber[GetDigitsCount() - i] <= '9' && this->baseNumber[GetDigitsCount() - i] >= '0')
			this->number = p * (this->baseNumber[GetDigitsCount() - i] - '0') + this->number;
		if (this->baseNumber[GetDigitsCount() - i] <= 'F' && this->baseNumber[GetDigitsCount() - i] >= 'A')
			this->number = p * (this->baseNumber[GetDigitsCount() - i] - '7') + this->number;
		p *= base;
	}
	return *this;
}
Number Number::operator--(int numar)
{
	this->digitCount--;
	this->baseNumber[GetDigitsCount()] = '\0';
	this->number = 0;
	int p = 1;
	for (int i = 1; i <= GetDigitsCount(); i++)
	{
		if (this->baseNumber[GetDigitsCount() - i] <= '9' && this->baseNumber[GetDigitsCount() - i] >= '0')
			this->number = p * (this->baseNumber[GetDigitsCount() - i] - '0') + this->number;
		if (this->baseNumber[GetDigitsCount() - i] <= 'F' && this->baseNumber[GetDigitsCount() - i] >= 'A')
			this->number = p * (this->baseNumber[GetDigitsCount() - i] - '7') + this->number;
		p *= base;
	}
	return *this;
}

Number& Number::operator=(Number&& value)
{
	if (this != &value) 
	{
		delete[] this->baseNumber;
		this->number = value.number;
		this->digitCount = value.digitCount;
		this->base = value.base;
		this->baseNumber = new char[this->digitCount + 1];
		memcpy(baseNumber, value.baseNumber, digitCount + 1);
		value.number = 0;
		value.digitCount = 0;
		value.base = 10;
		value.baseNumber = nullptr;
	}
	return *this;
}

Number& Number::operator=(int value)
{
	this->base = 10;
	this->number = value;
	int aux = value;
	int k = 0;
	while (aux)
	{
		k++;
		aux /= 10;
	}
	this->digitCount = k;
	this->baseNumber = new char[k+1];
	for (int i = 1; i <= k; i++)
	{
		this->baseNumber[k - i] = value % 10+'0';
		value /= 10;
	}
	return *this;
}

Number& Number::operator=(char* value)
{
	this->number = 0;
	int p = 1;
	this->digitCount = strlen(value);
	this->baseNumber = new char[GetDigitsCount()+1];
	strcpy(baseNumber, value);
	this->base = 10;
	for (int i = 1; i <= GetDigitsCount(); i++)
	{
		this->number = p * (value[GetDigitsCount() - i] - '0') + this->number;
		p *= 10;
	}
	return *this;
}

bool Number::operator<(Number value)
{
	return this->number < value.number;
}

bool Number::operator>(Number value)
{
	return this->number > value.number;
}

bool Number::operator<=(Number value)
{
	return !(this->number > value.number);
}

bool Number::operator>=(Number value)
{
	return !(this->number < value.number);
}