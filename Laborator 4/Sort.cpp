#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdio.h> 
#include <time.h>
#include <stdarg.h>
#include <iostream>
using namespace std;

Sort::Sort(int nr_elemente, int min_element, int max_element) 
{
    this->vector = new int[nr_elemente];
    this->count = nr_elemente;
    time_t t;
    srand((unsigned)time(&t));
    for (int i = 0; i < nr_elemente; i++) 
    {
        int random = min_element + rand() % (min_element - max_element + 1);
        this->vector[i] = random;
    }
}

Sort::Sort(int* vector, int nr_elemente) 
{
    this->vector = new int[nr_elemente];
    this->count = nr_elemente;
    for (int i = 0; i < nr_elemente; i++) 
    {
        this->vector[i] = vector[i];
    }
}
Sort::Sort(int count, ...) 
{
    this->vector = new int[count];
    this->count = count;
    va_list v1;
    va_start(v1, count);
    for (int i = 0; i < count; i++) 
    {
        this->vector[i] = va_arg(v1, int);
    }
    va_end(v1);
}
Sort::Sort(const char* c) 
{
    int i = 0;
    char* aux = new char[strlen(c) + 1];
    strcpy(aux, c);
    char* p = strtok(aux, ",");
    while (p)
    {
        i++;
        p = strtok(NULL, ",");
    }
    strcpy(aux, c);
    this->vector = new int[i];
    this->count = i;
    i = 0;
    p = strtok(aux, ",");
    while (p)
    {
        this->vector[i++] = atoi(p);
        p = strtok(NULL, ",");
    }
}
int Sort::GetElementsCount() 
{
    return this->count;
}
int Sort::GetElementFromIndex(int index) 
{
    return this->vector[index];
}

void Sort::BubbleSort(bool ascendent) 
{
    for (int i = 0; i < GetElementsCount() - 1; i++) 
    {
        for (int j = 0; j < GetElementsCount() - i - 1; j++) 
        {
            if (ascendent ? (this->vector[j] > this->vector[j + 1]) : (this->vector[j] < this->vector[j + 1])) 
            {
                swap(this->vector[j], this->vector[j + 1]);
            }
        }
    }
}

void Sort::Print() 
{
    for (int i = 0; i < GetElementsCount(); i++) 
    {
        cout << this->vector[i] << " ";
    }
    cout << endl;
}

void Sort::InsertSort(bool ascendent)
{
    for (int i=0; i < GetElementsCount(); i++)
    {
        int aux = this->vector[i];
        int j = i - 1;
        while (j >= 0 && (ascendent?GetElementFromIndex(j) > aux:GetElementFromIndex(j)<aux))
        {
            this->vector[j + 1] = this->vector[j];
            j = j - 1;
        }
        this->vector[j + 1] = aux;
    }
}

int Sort::partition( int low, int high, bool ascendent)
{
    int pivot = this->vector[high];
    int j= low - 1; 
    for (int i = low; i < high; i++) 
    {
        // If current element is smaller than the pivot
        if(ascendent?this->vector[i]<=pivot:this->vector[i]>=pivot)
        {
            j++; 
            swap(this->vector[i],this->vector[j]);
        }
    }
    swap(this->vector[j+1], this->vector[high]);
    return j + 1;
}

void Sort::QuickSort(int low, int high, bool ascendent) 
{
    if (low < high) 
    {
        int partition_index = partition(low, high, ascendent);
        QuickSort(low, partition_index - 1, ascendent);
        QuickSort(partition_index + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent) 
{
    QuickSort(0, GetElementsCount() - 1, ascendent);
}