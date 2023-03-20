#pragma once
class Number
{
	int base, digitCount,number;
	char* baseNumber;
public:
	Number(const char* value, int base);
	Number(const char* value);
	Number(const Number& value);
	Number(const Number&& value);
	Number(int value);
	~Number();
	friend Number operator+(const Number& value1, const Number& value2);
	friend Number operator-(const Number& value1, const Number& value2);
	

	Number operator++();
	Number operator++(int numar);
	Number operator--();
	Number operator--(int numar);

	int operator[](int index);

	Number& operator=(Number&& value);
	Number& operator=(int value);
	Number& operator=(char* value);

	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount();
	int GetBase();

	bool operator<(Number value);
	bool operator>(Number value);
	bool operator<=(Number value);
	bool operator>=(Number value);
};