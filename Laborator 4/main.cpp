#include "Sort.h"
#include <stdlib.h>
#include <iostream>

int main() {
    Sort c1(10, 10, 100);
    c1.BubbleSort(true);
    c1.Print();
    int v[5] = { 5,76,54,91,42 };
    Sort c2(v, 5);
    c2.InsertSort(false);
    c2.Print();
    Sort c3(5,43,12,77,97,54);
    c3.QuickSort(true);
    c3.Print();
    const char c[] = "6,4,5,9,1";
    Sort c4(c);
    c4.BubbleSort(false);
    c4.Print();
    return 0;
}