#include <iostream>
#include <stdlib.h>
#include "Sorter.h"
#include "../mytimer.h"

template<typename T>
void print_vector(vector<T> &arr, int N){
    for (size_t i = 0; i < arr.size() && i<N; i++)
    {
        cout << arr[i] << ", "; 
    }
    cout << endl; 
    
}

int main(){
    
    //SLECTION SORT
    
    vector<int> arr; 
    int count = 10; 
    for (size_t i = 0; i < count; i++)
    {
       arr.push_back((int)rand() % 256); 
    }
    
    cout << "================================================= SELECTION SORT ==========================================================" << endl; 
    cout << "Unsorted" << endl; 
    print_vector(arr, 10); 
    cout << endl; 


    SelectionSort<int> SelSort; 
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    SelSort.Sort(arr); 
    STOP_TIMING(t1);
    cout << "Sorted" << endl; 
    print_vector(arr, 10); 
    cout << "===========================================================================================================================" << endl; 
    SHOW_TIMING(t1, "SELECTION SORT ");
    cout << "===========================================================================================================================" << endl; 

    cout << endl; 
    cout << endl; 

    //BUBBLE SORT

    vector<int> arr_2; 
    int count_2 = 10; 
    for (size_t i = 0; i < count_2; i++)
    {
       arr_2.push_back((int)rand() % 306); 
    }

    cout << "================================================== BUBBLE SORT ============================================================" << endl; 
    cout << "Unsorted" << endl; 
    print_vector(arr_2, 10); 
    cout << endl; 
    
    BubbleSort<int> BS; 
    DECLARE_TIMING(t2);
    START_TIMING(t2);
    BS.Sort(arr_2); 
    STOP_TIMING(t2); 
    cout << "Sorted" << endl; 
    print_vector(arr_2, 10); 
    cout << "===========================================================================================================================" << endl; 
    SHOW_TIMING(t2, "BUBBLE SORT ");
    cout << "===========================================================================================================================" << endl; 


    return 0; 
}

