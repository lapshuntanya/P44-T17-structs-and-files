﻿#pragma once
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

template <typename T>
void randArray(T arr[], int size, int a = 1, int b = 10)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (b - a + 1) + a;
	}
}
template <typename T>
void printArray(T arr[], int size, int w_cout = 5)
{
	for (int i = 0; i < size; i++)
	{
		cout.width(w_cout);
		cout << arr[i];
	}
	cout << endl;
}

//знаходження індексу максимального елемента масиву
template <typename T>
int indexMaxElement(T arr[], int size)
{
	T a = arr[0];
	int indexa;
	for (int i = 1; i < size; i++)
	{
		if (a < arr[i])
			a = arr[i];
			indexa = i;
	}
	return indexa;
}
//знаходження індексу мінімального елемента масиву
template <typename T>
int indexMinElement(T arr[], int size)
{
	T a = arr[0];
	int indexa;
	for (int i = 1; i < size; i++)
	{
		if (a > arr[i])
			a = arr[i];
			indexa = i;
	}
	return indexa;
}

// Знаходження суми всіх елементів масиву
template <typename T>
T sumArray(T arr[], int size)
{
	T sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

//знаходження заданого значення в масиві
template <typename T>
int search(T arr[], const int size, T key)
{
	int indexkey;
	for (int i = 0; i < size; i++)
	{
		if (key == arr[i])
		{
			indexkey = i;
			return indexkey;
		}
		
	}
	return -1;
}
 
 
template <typename T>
void addItemBack(T*& arr, int& size, T value)
{
	//1
	T* tmp = new T[size + 1];
	//2
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	//3
	tmp[size] = value;
	//4
	if(arr != nullptr) delete[] arr;
	//5
	arr = tmp;
	//6
	size++;
}
template <typename T>
void addItemFront(T*& arr, int& size, T value)
{	

	T* tmp = new T[size + 1];
	//2
	for (int i = 0; i < size; i++)
	{
		tmp[i + 1] = arr[i];
	}
	//3
	tmp[0] = value;
	//4
	if (arr != nullptr) delete[] arr;
	//5
	arr = tmp;
	//6
	size++;
}




void createArrayBetween(int* arr, int size, int from, int to, int*& sub_arr, int& sub_size)
{
	//1
	sub_size = to - from + 1;
	sub_arr = new int[sub_size];
	for (int i = 0; i < sub_size; i++) 
	{
		sub_arr[i] = arr[from + i];
	}
}

template <typename T>
int myCountIf(T* arr, int size, bool (*func)(T value))
{
	int amount = 0;
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]) == true)
		{
			amount++;

		}
	}
	return amount;
}

template <typename T>
T mySumIf(T* arr, int size, bool (*func)(T value))
{
	T sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]) == true)
		{
			sum += arr[i];

		}
	}
	return sum;
}

template <typename T>
int myFindIf(T* arr, int size, bool (*func)(T value))
{
	int index_first = 0;
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]) == true)
		{
			index_first = i;
			break;
		}
	}
	return index_first;
}

template <typename T>
void myReplaceIf(T* arr, int size, bool (*func)(T), T value)
{
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]) == true)
		{
			arr[i] = value;
			
		}
	}
}

template <typename T>
void myRemoveIf(T*& arr, int& size, bool (*func)(T))
{
	int count = myCountIf(arr, size, func);
	if (count == 0)return;
	
	T* tmp = new T[size - count];
	
	for (int i = 0, j = 0; i < size; i++)
	{
		if (func(arr[i]) == false)
		{
			tmp[j] = arr[i];
			j++;
		}
		
	}
	
	if (arr != nullptr) delete[] arr;
	
	arr = tmp;
	size -= count;
}

template <typename T>
void myCopyIf(T* arr, int size, T*& arr_copy, int& size_copy, bool (*func)(T)){
	size_copy = myCountIf(arr, size, func);
	if (size_copy == 0) return;
	if (arr_copy != nullptr) delete[] arr_copy;

	arr_copy = new T[size_copy];

	for (int i = 0, j = 0; i < size; i++)
	{
		if (func(arr[i]) == true)
		{
			arr_copy[j] = arr[i];
			j++;
		}

	}

}
template <typename T>
int findLast_if(T* arr, int size, bool (*func)(T value))
{
	int index_last = 0;
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i]) == true)
		{
			index_last = i;
			
		}
	}
	return index_last;
}

template <typename T>
void sort(T* arr, int size, bool (*cmp)(T, T)) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (cmp(arr[j], arr[j + 1])) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


template <typename T>
void addItemPos(T*& arr, int& size, int pos, T value)
{
	T* tmp = new T[++size];
	//2
	for (int i = 0; i < size; i++)
	{
		if (i < pos)tmp[i] = arr[i];
		else if (i == pos) tmp[i] = value;
		else tmp[i] = arr[i - 1];
	}

	//4
	if (arr != nullptr) delete[] arr;
	//5
	arr = tmp;
}