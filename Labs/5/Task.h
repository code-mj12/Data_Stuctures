#pragma once
#include <iostream>
using namespace std;

template <class T>
T minimum(T arr[], int size) {
	T min = arr[0];
	for (int i = 1; i < size ; i++)
	{
		if (min > arr[i]) {
			min = arr[i];
			cout << "fff" << min << i << endl;
		}
	}
	return min;
}

template <class T>
T area(T rad) {
	T a = (3.142 * rad * rad);
	return a;
}
template <class T>
T area(T len, T bred) {
	T a = (len * bred);
	return a;
}
