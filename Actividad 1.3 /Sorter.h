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

        virtual void Sort(vector<T> &arr){};

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
class MergeSort : public Sorter<T>
{
public:
    MergeSort(){};
    ~MergeSort(){};

    void Sort(vector<T> &arr, bool(*compare)(T &a, T &b)) { 
        mergeSort(arr, 0, arr.size() - 1, bool(*compare)(T &a, T &b)
    };

    void mergeSort(vector<T> &arr, int begin, int end, bool(*compare)(T &a, T &b))
    {
        if (begin < end)
        {
            int mid = begin + (end - begin) / 2;

            mergeSort(arr, begin, mid, bool(*compare)(T &a, T &b)); 
            mergeSort(arr, mid + 1, end, bool(*compare)(T &a, T &b)); 

            merge(arr, begin, mid, end, bool(*compare)(T &a, T &b)); 
        }
    };

    void merge(vector<T> &arr, int begin, int mid, int end, bool(*compare)(T &a, T &b))
    {
        int i = 0;
        int j = mid - begin +1;
        vector<T> aux(arr.begin()+ begin, arr.begin()+end+1);

        for (int k = begin; k <= end; k++)
        {
            if (((*compare)(aux[i], aux[j])|| j > end-begin) && i<=mid-begin)
            {
                arr[k] = aux[i];
                i++;
            }
            else if (aux[i] >= aux[j] || i > mid-begin)
            {
                arr[k] = aux[j];
                j++;
            }
        }
    };
};