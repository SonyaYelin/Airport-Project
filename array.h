#pragma once
#ifndef __ARRAY_H
#define __ARRAY_H

#pragma warning (disable: 4290)

// RESTRICTIONS ON T:
// 1- should have clone, operator==
template <class T>
class Array
{
protected:
	int  phisicalSize;
	int  logicalSize;
	T**  arr;

public:
	Array();
	Array(const Array& other);
	~Array();

	const Array& operator=(const Array& other);

	int      count() const { return logicalSize; }
	T&       operator[](int index)       throw (const char*);
	const T& operator[](int index) const throw (const char*);

	void add(const T& newVal);
	void remove(const T& remove);
};

template <class T>
Array<T>::Array() : phisicalSize(2), logicalSize(0)
{
	arr = new T*[phisicalSize];
	for (int i = 0; i < phisicalSize; i++)
		arr[i] = NULL;
}

template <class T>
Array<T>::Array(const Array<T>& other) : arr(NULL)
{
	*this = other;
}

template <class T>
Array<T>::~Array()
{
	for (int i = 0; i < logicalSize; i++)
		delete arr[i];
	delete[]arr;
}

template <class T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || index > logicalSize)
		throw "Index Out Of Bound (index)";
	return *arr[index];
}

template <class T>
const T& Array<T>::operator[](int index) const
{
	if (index < 0 || index > logicalSize)
		throw "Index Out Of Bound (index)";
	return *arr[index];
}

template <class T>
const Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		logicalSize = other.logicalSize;
		phisicalSize = other.phisicalSize;
		for (int i = 0; i < logicalSize; i++)
			delete arr[i];
		delete[]arr;

		arr = new T*[phisicalSize];
		for (int i = 0; i < logicalSize; i++)
			arr[i] = other.arr[i]->clone();
	}
	return *this;
}

template <class T>
void Array<T>::add(const T& newVal)
{
	if (logicalSize == phisicalSize)
	{
		phisicalSize *= 2;
		T** temp = new T*[phisicalSize];
		for (int i = 0; i < logicalSize; i++)
			temp[i] = arr[i];

		delete[]arr;
		arr = temp;
	}

	arr[logicalSize] = newVal.clone();
	logicalSize++;
}

template <class T>
void Array<T>::remove(const T& remove)
{
	for (int i = 0; i < logicalSize; i++)
	{
		if (*arr[i] == remove)
		{
			delete arr[i];
			for (int j = i + 1; j < logicalSize; j++)
				arr[j - i] = arr[j];
			logicalSize--;
			break;
		}
	}
}

#endif // __ARRAY_H