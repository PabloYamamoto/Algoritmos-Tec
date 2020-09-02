#include <iostream>
#include <stdlib.h>
#include "Sorter.h"

template<typename T>
void print_vector(vector<T> &arr, int N){
    for (size_t i = 0; i < arr.size() && i<N; i++)
    {
        cout << arr[i] << ", "; 
    }
    cout << endl; 
    
}

int main(){
    // vector<float> arr; 
    // int count = 10; 
    // for (size_t i = 0; i < count; i++)
    // {
    //    arr.push_back((float)rand() / RAND_MAX); 
    // }
    
    // cout << endl; 
    // cout << "Unsorted" << endl; 
    // cout << endl; 
    // print_vector(arr, 10); 


    // SelectionSort<float> SelSort; 
    // SelSort.Sort(arr); 

    // cout << endl; 
    // cout << "Sorted" << endl; 
    // cout << endl; 
    // print_vector(arr, 10); 





    vector<int> arr_2; 
    int count_2 = 10; 
     for (size_t i = 0; i < count_2; i++)
    {
       arr_2.push_back((int)rand() % 256); 
    }

    cout << endl; 
    cout << "Unsorted" << endl; 
    cout << endl; 
    print_vector(arr_2, 10); 


    BubbleSort<int> BS; 
    BS.Sort(arr_2); 

    cout << endl; 
    cout << "Sorted" << endl; 
    cout << endl; 
    print_vector(arr_2, 10); 



    return 0; 
}

