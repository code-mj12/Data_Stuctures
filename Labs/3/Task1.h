#pragma once
#include <iostream>
using namespace std;

template <typename T, int N>
T* removeDuplicate(T(&Array)[N]) {
	T* newA = new T[N];
	int j = 0;
	for (int i = 0; i < N - 1; i++)
	{
		if (Array[i] != Array[i + 1]) {
			newA[j++] = Array[i];
		}
	}
	newA[j++] = Array[N - 1];

	T* A = new T[j];
	for (int i = 0; i < j; i++)
	{
		A[i] = newA[i];
	}
	return A;
}

template <typename T>

T* Intersection(T arr1[], T arr2[], int s1, int s2) {
	int a = 0;
	for (int i = 0; i < s1; i++)
	{
		for (int j = 0; j < s2; j++)
		{
			if (arr1[i] == arr2[j]) {		//tells the size of array to be created
				a++;
			}
		}
	}
	T* arr3 = new T[a];
	int y = 0;
	for (int i = 0; i < s1; i++)
	{
		for (int j = 0; j < s2; j++)
		{
			if (arr1[i] == arr2[j]) {		//
				arr3[y] = arr2[j];
				y++;
			}
		}
	}

	return arr3;
}

template <typename T>
T* Union(T arr1[], T arr2[], int s1, int s2) {
	int w = s1 + s2;
	T* arr3 = new T[50];
	int u = 0;
	for (int i = 0; i < s1; i++)
	{
		arr3[i] = arr1[i];
		u = i;
		//cout << "u is " << u;
	}
	u++;
	int j = 0;
	for (int i = 0; i < s2; i++)
	{
		bool f = true;
		for (int k = 0; k < s1; k++)
		{
			if (arr2[i] == arr1[k]) {
				f = false;
				//cout << "uuuuu" <<arr2[i]<< endl;
			}
		}
		if (f) {
			arr3[u++] = arr2[i];

		}
	}

	return arr3;
}