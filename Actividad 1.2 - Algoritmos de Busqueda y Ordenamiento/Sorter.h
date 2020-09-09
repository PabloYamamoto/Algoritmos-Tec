#include <vector>
using namespace std; 


template<typename T>
class Sorter{
    public: 
        Sorter(){};  
        ~Sorter(){}; 

        void swap(int i, int j, vector<T> &arr){
            T temp = arr.at(i); 
            arr.at(i) = arr.at(j); 
            arr.at(j) = temp;  
        }

        virtual void Sort(vector<T> &arr){};

        void show(vector<T> &vec){
            cout << "==================================================================" << endl;

            for(T number : vec){
                cout << number << " "; 
                
            }
            cout << endl; 
            cout << "==================================================================" << endl;
            cout << endl; 
        }

}; 


template<typename T>
class BubbleSort : public Sorter<T>{
    public: 
        BubbleSort(){}; 
        ~BubbleSort(){}; 

        void Sort(vector<T> &arr){
            
            for (size_t i = 0; i < arr.size()-1; i++)
            {
                bool no_swap = true; 
                for (size_t j = 0; j < arr.size()-1; j++)
                {
                    if(arr[j] > arr[j+1]){
                        Sorter<T>::swap(j, j+1, arr); 
                        no_swap = false; 
                    }
                }
                if(no_swap == true){
                    break; 
                }
                
            }
            
        }


}; 


template<typename T>
class InsertionSort : public Sorter<T>{
    public: 
        InsertionSort(){}; 
        ~InsertionSort(){}; 
    
        void Sort(vector<T> &arr){
            T key; 
            for(int i = 1; i < arr.size(); i++){
                key = arr[i]; 
                int j = i -1; 
                while(j >= 0 and arr[j] > key){
                    arr[j+1] = arr[j]; 
                    j--; 
                }
                arr[j+1] = key; 
            }
        }; 

}; 




template <typename T>
class QuickSort : public Sorter<T>{
    public: 
        QuickSort(){}; 
        ~QuickSort(){}; 

        void Sort(vector<T> &arr){
            quicksort(arr, 0, arr.size()-1); 
        }; 

        void quicksort(vector<T> &arr, int low, int high){

            if(low < high){
                int piv = partition(arr, low, high);
                quicksort(arr, low, piv-1); 
                quicksort(arr, piv+1, high);  
            }

        }; 

        int partition(vector<T> &arr, int low, int high){
            T pivot = arr[high]; 
            int i = low-1; 
            int j; 
            for (j = low; j < high; j++)
            {
                if(arr[j] < pivot){
                    i++; 
                    Sorter<T>::swap(i, j, arr); 
                }
                
            }
            Sorter<T>::swap(i+1, high, arr); 
            return (i+1); 
            
        }; 
}; 
