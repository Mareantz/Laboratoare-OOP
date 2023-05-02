#pragma once
template <typename Key, typename T>
class Map
{
	struct Data
	{
		Key key;
		T value;
		int i;
	};
	Data *data;
	int size;
	int currentIndex;
public:
	Map()
	{
		data = nullptr;
		size = 0;
		currentIndex = 0;
	}
	~Map()
	{
		if (data)
		{
			delete[] data;
			data = nullptr;
		}
	}
	T& operator[](Key key)
	{
		if (data == nullptr)
		{
			data = new Data[1];
			data[0].key = key;
			data[0].value = T();
			data[0].i = 0;
			size = 1;
			return data[0].value;
		}
		for (int i = 0; i < size; i++)
		{
			if (data[i].key == key)
			{
				return data[i].value;
			}
		}
		Data *newData = new Data[size + 1];
		for (int i = 0; i < size; i++)
		{
			newData[i] = data[i];
		}
		newData[size].key = key;
		newData[size].value = T();
		newData[size].i = currentIndex+1;
		delete[] data;
		data = newData;
		size++;
		currentIndex++;
		return data[size - 1].value;
	}
	class Iterator
	{
		Data* data;
		int index;
	public:
		Iterator(Data* data, int index)
		{
			this->data = data;
			this->index = index;
		}
		bool operator!=(const Iterator& comp)
		{
			return this->index != comp.index;
		}
		void operator++()
		{
			index++;
		}
		void operator++(int)
		{
			index++;
		}
		void operator--()
		{
			index--;
		}
		void operator--(int)
		{
			index--;
		}
	
		Data& operator*()
		{
			return data[index];
		}
		Data* operator->()
		{
			return &data[index];
		}
	};
	Iterator begin()
	{
		return Iterator(data, 0);
	}
	Iterator end()
	{
		return Iterator(data, size);
	}
	void Set(Key key, T value)
	{
		for (int i = 0; i < size; i++)
			if (this->data[i].key == key)
			{
				this->data[i].value = value;
				return;
			}
	}
	bool Get(const Key& key, T value)
	{
		for (int i = 0; i < size; i++)
			if (this->data[i].key == key)
			{
				this->data[i].value = value;
				return true;
			}
		return false;
	}
	int Count()
	{
		return size;
	}
	void Clear()
	{
		if (data)
		{
			delete[] data;
			data = nullptr;
		}
		size = 0;
	}
	bool Delete(const Key& key)
	{
		for(int i=0;i<size;i++)
			if (this->data[i].key == key)
			{
				for (int j = i; j < size - 1; j++)
				{
					this->data[j].key = this->data[j + 1].key;
					this->data[j].value = this->data[j + 1].value;
				}
				size--;
				return true;
			}
		return false;
	}
	bool Includes(const Map<Key,T>& map)
	{
		if (this->size > map.size)
			return false;
		for (int i = 0; i < this->size; i++)
		{
			bool ok = false;
			for (int j = 0; j < map.size; j++)
			{
				if (this->data[i].key == map.data[j].key)
					ok = true;
			}
			if (!ok)
				return false;
		}
		return true;
	}
};