//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int convertire(char s[])
{
	int nr = 0;
	for (int i = 0; i < strlen(s); i++)
		if (s[i] >= '0' && s[i] <= '9')
			nr = nr * 10 + s[i] - '0';
	return nr;
}
int main()
{
	int suma = 0;
	char s[100];
	FILE* fp = fopen("in.txt", "r");
	if (fp)
	{
		while (fgets(s, 100, fp))
			suma += convertire(s);
	}
	printf("%d\n", suma);
	delete(fp);
	return 0;
}