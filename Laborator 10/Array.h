#include <exception>
#include <iostream>
using namespace std;

class IndexOutOfBounds : public exception
{
	virtual const char* what() const throw()
	{
		return "Index is out of bounds!";
	}
};

class FullCapacity : public exception
{
	virtual const char* what() const throw()
	{
		return "Array is full!";
	}
};

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
	int Current;
	T* arr;
public:
	ArrayIterator()
	{
		Current = 0;
		arr = NULL;
	}
	ArrayIterator& operator ++ ()
	{
		if (Current < arr->Size)
			Current++;
		return *this;
	}
	ArrayIterator& operator -- ()
	{
		if (Current > 0)
			Current--;
		return *this;
	}
	bool operator= (ArrayIterator<T>&)
	{
		return Current == arr->Size;
	}
	bool operator!=(ArrayIterator<T>&)
	{
		return Current != arr->Size;
	}
	T* GetElement()
	{
		return arr->List[Current];
	}
};

template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
public:
	IndexOutOfBounds outOfBoundsException;
	FullCapacity capacityException;
	Array()
	{
		List = nullptr;
		Capacity = 0;
		Size = 0;
	}
	~Array()
	{
		for (int i = 0; i < Size; i++)
			delete List[i];
		delete[] List;
	}
	Array(int capacity)
	{
		Capacity = capacity;
		Size = 0;
		List = new T * [capacity];
		for (int i = 0; i < capacity; i++)
			List[i] = new T;
	}
	Array(const Array<T>& otherArray)
	{
		Size = otherArray.Size;
		Capacity = otherArray.Capacity;
		List = otherArray.List;
	}
	T& operator[] (int index)
	{
		try
		{
			if (index<0 || index>Size)
				throw outOfBoundsException;
			return *List[index];
		}
		catch (exception& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}
	}
	const Array<T>& operator += (const T& newElem)
	{
		try
		{
			if (Size == Capacity)
				throw capacityException;
			*(List[Size++]) = newElem;
			return *this;
		}
		catch (exception& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}
	}
	const Array<T>& Insert(int index, const T& newElem)
	{
		try
		{
			if (index < 0 || index > Capacity)
			{
				throw outOfBoundsException;
			}

			if (Size == Capacity)
			{
				throw capacityException;
			}

			for (int i = Size; i > index; i--)
			{
				List[i] = List[i - 1];
			}
			Size += 1;
			*(List[index]) = newElem;
			return *this;
		}
		catch (exception& e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}
	}
	const Array<T>& Insert(int index, const Array<T> otherArray)
	{
		try
		{
			if (index<0 || index>Size)
				throw outOfBoundsException;
			if (Size+otherArray.Size>=Capacity)
				throw capacityException;
			Array<T> temp = *this;
			temp.Size = Size + otherArray.Size;
			for(int i=0;i<index;i++)
				*temp.List[i] = *List[i];
			for (int i = index; i < otherArray.Size + index; i++)
				*temp.List[i] = *otherArray.List[i - index];
			for (int i = index + otherArray.Size; i < Size + otherArray.Size; i++)
				*temp.List[i] = *List[i - otherArray.Size];
			return temp;
		}
		catch (exception& e)
		{
			cout << "Exceeptie: " << e.what() << endl;
		}
	}
	const Array<T>& Delete(int index)
	{
		try
		{
			if (index<0 || index>Size)
				throw outOfBoundsException;
			for (int i = index; i < Size - 1; i++)
				*List[i] = *List[i + 1];
			delete List[Size];
			Size--;
			return *this;
		}
		catch (exception& e)
		{
			cout << "Exceeptie: " << e.what() << endl;
		}
	}
	bool operator=(const Array<T>& otherArray)
	{
		Size = otherArray.Size;
		Capacity = otherArray.Capacity;
		List = otherArray.List;
	}
	void Sort()
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (*List[i] > *List[j])
					swap(List[i], List[j]);
	}
	void Sort(int(*compare)(const T&, const T&))
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
				if (compare(*List[i], *List[j]) > 0)
					swap(List[i], List[j]);
	}
	void Sort(Compare* comparator)
	{
		{
			for (int i = 0; i < Size - 1; i++)
				for (int j = i + 1; j < Size; j++)
					if (comparator->CompareElements(*List[i], List[j]) > 0)
						swap(List[i], List[j]);
		}
	}
	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem)
	{
		int st = 0, dr = Size - 1, mij;
		while (st <= dr)
		{
			mij = (st + dr) / 2;
			if (*List[mij] == elem)
				return mij;
			if (*List[mij] < elem)
				st = mij + 1;
			else
				dr = mij - 1;
		}
		return -1;
	}
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
	{
		int st = 0, dr = Size - 1, mij;
		while (st <= dr)
		{
			mij = (st + dr) / 2;
			if (compare(*List[mij], elem) == 0)
				return mij;
			if (compare(*List[mij], elem) < 0)
				st = mij + 1;
			else
				dr = mij - 1;
		}
		return -1;
	}
	int BinarySearch(const T& elem, Compare* comparator)
	{
		int st = 0, dr = Size - 1, mij;
		while (st <= dr)
		{
			mij = (st + dr) / 2;
			if (comparator->CompareElements(*List[mij], elem) == 0)
				return mij;
			if (comparator->CompareElements(*List[mij], elem) < 0)
				st = mij + 1;
			else
				dr = mij - 1;
		}
		return -1;
	}
	int Find(const T& elem)
	{
		for (int i = 0; i < Size; i++)
			if (*List[i] == elem)
				return i;
		return -1;
	}
	int Find(const T& elem, int(*compare)(const T&, const T&))
	{
		for (int i = 0; i < Size; i++)
			if (compare(*List[i], elem) == 0)
				return i;
		return -1;
	}
	int Find(const T& elem, Compare* comparator)
	{
		for (int i = 0; i < Size; i++)
			if (comparator->CompareElements(*List[i], elem) == 0)
				return i;
		return -1;
	}
	int GetSize()
	{
		return this->Size;
	}
	int GetCapacity()
	{
		return this->Capacity;
	}
	ArrayIterator<T> GetBeginIterator()
	{
		return ArrayIterator<T>(this, 0);
	}
	ArrayIterator<T> GetEndIterator()
	{
		return ArrayIterator<T>(this, Size);
	}
};