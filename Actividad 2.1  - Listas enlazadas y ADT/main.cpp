#include "LinkedList.h"

int main(){

    int A[] = {10, 10, 10, 10, 20, 30, 40, 50}; 
    LinkedList<int> list(A, 8); 
    
    cout << endl; 
    cout << "============================= Count Function =============================" << endl;
    cout << "Original list: " << endl; 
    list.Display(); 
    cout << "Searching for item: 10 " << endl; 
    cout << "Item found " << list.Count(10) << " times "<< endl;
    cout << "==========================================================================" << endl; 
    cout << endl; 
    cout << "========================= Sorted Insert Function =========================" << endl;
    cout << "Original list: " << endl; 
    list.Display(); 
    cout << "Inserting: 20 " << endl; 
    list.SortedInsert(list.NewNode(20)); 
    list.Display(); 
    cout << "==========================================================================" << endl;
    cout << endl; 
    cout << "======================== Remove Duplicates Function ======================" << endl;
    cout << "Original list: " << endl; 
    list.Display(); 
    list.RemoveDuplicate(); 
    list.Display(); 
    cout << "==========================================================================" << endl;
    cout << endl; 
    cout << "============================ Reverse Function ============================" << endl;
    cout << "Original list: " << endl; 
    list.Display(); 
    list.Reverse(); 
    list.Display(); 
    cout << "==========================================================================" << endl;
    cout << endl; 
    cout << "============================ Delete Function ============================" << endl;
    cout << "Original list: " << endl; 
    list.Display(); 
    list.~LinkedList<int>();  
    list.Display(); 
    cout << "==========================================================================" << endl;





}