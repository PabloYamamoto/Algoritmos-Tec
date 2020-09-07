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
    int count = 100000; 
    for (size_t i = 0; i < count; i++)
    {
       arr.push_back((int)rand() % 256); 
    }
    
    cout << "================================================= SELECTION SORT ==========================================================" << endl; 
    cout << "Unsorted" << endl; 
    // print_vector(arr, 10); 
    cout << endl; 


    SelectionSort<int> SelSort; 
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    SelSort.Sort(arr); 
    STOP_TIMING(t1);
    cout << "Sorted" << endl; 
    // print_vector(arr, 10); 
    cout << "===========================================================================================================================" << endl; 
    SHOW_TIMING(t1, "SELECTION SORT ");
    cout << "===========================================================================================================================" << endl; 

    cout << endl; 
    cout << endl; 

    //BUBBLE SORT

    vector<int> arr_2; 
    int count_2 = 100000; 
    for (size_t i = 0; i < count_2; i++)
    {
       arr_2.push_back((int)rand() % 306); 
    }

    cout << "================================================== BUBBLE SORT ============================================================" << endl; 
    cout << "Unsorted" << endl; 
    // print_vector(arr_2, 10); 
    cout << endl; 
    
    BubbleSort<int> BS; 
    DECLARE_TIMING(t2);
    START_TIMING(t2);
    BS.Sort(arr_2); 
    STOP_TIMING(t2); 
    cout << "Sorted" << endl; 
    // print_vector(arr_2, 10); 
    cout << "===========================================================================================================================" << endl; 
    SHOW_TIMING(t2, "BUBBLE SORT ");
    cout << "===========================================================================================================================" << endl; 

    //INSERTION SORT

    vector<int> arr_3; 
    int count_3 = 100000; 
    for (size_t i = 0; i < count_3; i++)
    {
       arr_3.push_back((int)rand() % 892); 
    }

    cout << "================================================== INSERTION SORT ============================================================" << endl; 
    cout << "Unsorted" << endl; 
    // print_vector(arr_3, 100); 
    cout << endl; 
    
    InsertionSort<int>IS; 
    DECLARE_TIMING(t3);
    START_TIMING(t3);
    IS.Sort(arr_3); 
    STOP_TIMING(t3); 
    cout << "Sorted" << endl; 
    // print_vector(arr_3, 100); 
    cout << "===========================================================================================================================" << endl; 
    SHOW_TIMING(t3, "INSERTION SORT ");
    cout << "===========================================================================================================================" << endl; 


    //MERGE SORT

    vector<int> arr_4; 
    int count_4 = 100000; 
    for (size_t i = 0; i < count_4; i++)
    {
       arr_4.push_back((int)rand() % 762); 
    }

    cout << "================================================== MERGE SORT ============================================================" << endl; 
    cout << "Unsorted" << endl; 
    // print_vector(arr_4, 100); 
    cout << endl; 
    
    MergeSort<int> MS; 
    DECLARE_TIMING(t4);
    START_TIMING(t4);
    MS.Sort(arr_4); 
    STOP_TIMING(t4); 
    cout << "Sorted" << endl; 
    // print_vector(arr_4, 100); 
    cout << "===========================================================================================================================" << endl; 
    SHOW_TIMING(t4, "MERGE SORT ");
    cout << "===========================================================================================================================" << endl; 


    return 0; 
}

