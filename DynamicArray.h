#pragma once
#include <iostream>

template <typename T>
class DynamicArray
{
private:
	// Pointer to first array element
	T* array;
	// Size of array
	size_t size;
public:
	DynamicArray();
	DynamicArray(size_t size);
	DynamicArray(const DynamicArray& other);
	~DynamicArray();
	T& operator[](size_t index);
	DynamicArray operator *(const DynamicArray<T> &dynamicArray);
	// Prefix
	DynamicArray& operator --();
	// Postfix
	DynamicArray operator--(int);
	void resize(size_t newSize);
	const T getMin() const;
	const T getMax() const;

	const size_t getSize() const;
	void print(); 
	const T getSum(size_t from, size_t to) const;
	const T getSumBetweenFirstAndSecondPositiveElements() const;
};
template<typename T>
DynamicArray<T>::DynamicArray()
{
	array = nullptr;
	size = 0;
}
template <typename T>
const T DynamicArray<T>::getSumBetweenFirstAndSecondPositiveElements() const
{
	size_t firstIndex = 0;
	for (size_t i = 0; i < size; i++)
		if (array[i] > 0)
		{
			firstIndex = i;
			break;
		}
	size_t secondIndex = 0;
	for (size_t i = firstIndex + 1; i < size; i++)
	{
		if (array[i] > 0)
		{
			secondIndex = i;
			break;
		}
	}
	return getSum(firstIndex, secondIndex);
}
template <typename T>
DynamicArray<T>::DynamicArray(size_t size)
	: size(size)
{
	// Allocate memory
	array = new T[size];
}
template<typename T>
 DynamicArray<T>::DynamicArray(const DynamicArray& other)
	 : size(other.size)
{
	 array = new T[size];
	 for (size_t i = 0; i < size; i++)
		 array[i] = other.array[i];
}
template <typename T>
DynamicArray<T>::~DynamicArray()
{
	// Free memory if pointer exists
	if(array)
		delete[] array;
}
template<typename T>
T& DynamicArray<T>::operator[](size_t index)
{
	return array[index];
}

template<typename T>
DynamicArray<T> DynamicArray<T>::operator*(const DynamicArray<T> &passedArray)
{
	DynamicArray<T> dynamicArray(this->size);
	for (size_t i = 0; i < this->size; i++)
		dynamicArray[i] = array[i] * passedArray.array[i];
	return dynamicArray;
	
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator--()
{
	for (size_t i = 0; i < size; i++)
		--array[i];
	return *this;
}


template<typename T>
DynamicArray<T> DynamicArray<T>::operator--(int)
{
	DynamicArray dynamicArray(*this);
	--(*this);
	return dynamicArray;
}

template<typename T>
void DynamicArray<T>::resize(size_t newSize)
{
	// Allocate memory for new array
	T* newArray = new T[newSize];
	try
	{
		// Copies array
		for (size_t i = 0; i < size; i++)
		{
			newArray[i] = array[i];
		}
	}
	catch (const std::exception &e)
	{
		// If memory don't locate free it
		delete[] newArray;
	}
	size = newSize;
	// Free old array memory
	delete[] array;
	array = newArray;
}

template<typename T>
const T DynamicArray<T>::getMin() const
{
	T min = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (min > array[i])
			min = array[i];
	}
	return min;
}

template<typename T>
const T DynamicArray<T>::getMax() const
{
	T max = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return max;
}

template<typename T>
const size_t DynamicArray<T>::getSize() const
{
	return size;
}

template<typename T>
void DynamicArray<T>::print()
{
	// Prints elements of array
	for (size_t i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

template<typename T>
const T DynamicArray<T>::getSum(size_t from, size_t to) const
{
	T sum = 0;
	for (size_t i = from + 1; i < to; i++)
		// Type must has + operator
		sum += array[i];
	return sum;
}

