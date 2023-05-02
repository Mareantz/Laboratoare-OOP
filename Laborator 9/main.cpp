#include "Map.h"
#include <stdio.h>
int main()
{
	Map<int, const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	printf("===========================\n");
	m[20] = "result";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	printf("m[30] before Set: %s\n", m[30]);
	m.Set(30,"Poo2");
	printf("m[30] after Set: %s\n", m[30]);
	if(m.Get(30, "Poo"))
		printf("m[30] after Get: %s\n", m[30]);
	else
		printf("m[30] not found\n");
	if (m.Get(40, "Poo"))
		printf("m[40] after Get: %s\n", m[30]);
	else
		printf("m[40] not found\n");
	printf("The map has %d elements\n", m.Count());
	m.Delete(20);
	printf("After deleting the element with the key 20, the map now looks like:\n");
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	if(m.Delete(20))
		printf("The element with the key 20 was deleted\n");
	else
		printf("The element with the key 20 was not found\n");
	Map<int, const char*>n;
	m[10]= "C++";
	m[20]= "Python";
	m[30]= "Poo";
	m[40]= "Poo2";
	if(m.Includes(n))
		printf("The map m includes the map n\n");
	else
		printf("The map m does not include the map n\n");
	if(n.Includes(m))
		printf("The map n includes the map m\n");
	else
		printf("The map n does not include the map m\n");
	n.Clear();
	printf("After delete the map n has %d elements\n", n.Count());
	return 0;
}