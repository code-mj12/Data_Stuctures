#include <iostream>
using namespace std;

template <typename T> 
class Array { 
private: 
    T *ptr; 
    int size;
    int count = 0;
public: 
    Array(T arr[], int s); 
    void Insert_at_end(int v);
    void Remove_data_item( int v);
    void Insert_in_middle( int v, int in);
    void print(); 
    void Replace_data_item(int v1, int v2);
    bool IsEmpty();
    void Clear_the_list();
}; 
  
template <typename T> 
Array<T>::Array(T arr[], int s) { 
    ptr = new T[s]; 
    size = s; 
    for(int i = 0; i < size; i++) 
        ptr[i] = arr[i]; 
} 
  
template <typename T> 
void Array<T>::print() { 
    for (int i = 0; i < size; i++) 
        if (ptr[i] != 0) {
            cout<< *(ptr + i) << " ";
        }
    cout<<endl; 
}
template <typename T>
void Array<T>::Insert_at_end( int v) {
    ptr[count] = v;
    count++;
}

template <typename T>
void Array<T>::Remove_data_item( int v) {
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] == v) {
            ptr[i] = 0;
            //put for loop
            /*for (int j = i; j < size; j++)
            {
                if ((j + 1) > size) {

                }
                ptr[j]=ptr[j+1]
            }*/
        }
    }
}

template <typename T>
void Array<T>::Insert_in_middle( int v, int in) {
    int temp = ptr[in];
    ptr[in] = v;
    count++;
    ptr[count] = temp;
}


template <typename T>
void Array<T>::Replace_data_item(int v1, int v2) {
    for (int i = 0; i < size; i++) {
        if (ptr[i] == v1) {
            ptr[i] = v2;
            break;
        }
    }
}


template <typename T>
bool Array<T>::IsEmpty() {
    if (count != 0) {
        return false;
    }
    else{
        return true;
    }
}


template <typename T>
void Array<T>::Clear_the_list() {
    for (int i = 0; i < count; i++) {
        ptr[i] = 0;
    }
    count = 0;
}