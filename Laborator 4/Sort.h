#pragma once
class Sort {
    int* vector;
    int count;
    int partition(int low, int high,bool ascendent);
    void QuickSort(int low, int high, bool ascendent);
public:
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
    Sort(int nr_elemente, int min_element, int max_element);
    Sort(int* vector, int nr_elemente);
    Sort(int count, ...);
    Sort(const char* c);
    //Sort() : vector(new int[6]{ 1, 2, 3, 4, 5, 6 });
};