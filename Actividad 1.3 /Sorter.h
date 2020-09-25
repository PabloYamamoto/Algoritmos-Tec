#include <iostream>
#include <vector>
using namespace std; 


#pragma once
template<typename T>
class Sorter{
    public: 
        Sorter(){};  
        ~Sorter(){}; 

        void swap(int i, int j, vector<T> &arr){
            T temp = arr.at(i); 
            arr.at(i) = arr.at(j); 
            arr.at(j) = temp;  
        }; 

        virtual void sort(vector<T> &arr, bool(*compare)(T &a, T &b)){};

        void show(vector<T> &vec){
            cout << "==================================================================" << endl;

            for(T number : vec){
                cout << number << " "; 
                
            }
            cout << endl; 
            cout << "==================================================================" << endl;
            cout << endl; 
        }; 

}; 

template <typename T>
class Quicksort : public Sorter<T>
{
    public:
    Quicksort() {};
    ~Quicksort() {};

    void sort(std::vector<T> &arr, bool (*compare)(T &a, T &b))
    {
        quicksort(arr, 0, arr.size() - 1, compare);
    };

    void quicksort(std::vector<T> &arr, int low, int high, bool (*compare)(T &a, T &b))
    {
        if (low < high) 
        {
            int piv = partition(arr, low, high, compare);

            quicksort(arr, low, piv - 1, compare);
            quicksort(arr, piv + 1, high, compare);
        }
    };

    int partition(std::vector<T> &arr, int low, int high, bool (*compare)(T &a, T &b))
    {
        T pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high-1; j++)
        {
            if ((*compare)(arr[j], pivot))
            {
                i++;
                Sorter<T>::swap(i, j, arr);
            }
        }
        Sorter<T>::swap(i+1, high, arr);
        return (i+1);
    };
};