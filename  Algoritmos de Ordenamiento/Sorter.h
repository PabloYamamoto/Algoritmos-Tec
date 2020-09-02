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

}; 

template<typename T>
class SelectionSort : public Sorter<T>{
    public:
        SelectionSort(){}; 
        ~SelectionSort(){}; 

        void Sort(vector<T> &arr){
            for(size_t i = 0; i < arr.size()-1; i++){
                size_t min = i; 
                for(size_t j = i+1; j < arr.size(); j++){
                    if(arr[j] < arr[min]){
                        min = j; 
                    }
                }
                Sorter<T>::swap(i, min, arr); 
            }
        }; 


}; 


template<typename T>
class BubbleSort : public Sorter<T>{
    public: 
        BubbleSort(){}; 
        ~BubbleSort(){}; 

        void Sort(vector<T> &arr){
            
            for (size_t i = 0; i < arr.size(); i++)
            {
                bool no_swap = true; 
                for (size_t j = i; j < arr.size()-1; j++)
                {
                    if(arr[j] < arr[j+1]){
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