//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n = 0;
	char s[256];
	char v[256][256];
	while (scanf("%255s", s))
		strcpy(v[n++], s);
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		if (strlen(v[i]) > strlen(v[j]))
		{
			strcpy(s, v[i]);
			strcpy(v[i], v[j]);
			strcpy(v[j], s);
		}
	for (int i = 0; i < n; i++)
		cout << v[i] << endl;
	return 0;
}