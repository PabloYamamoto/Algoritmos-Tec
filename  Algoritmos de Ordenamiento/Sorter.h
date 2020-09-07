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

class MergeSort : Sorter<T>
{
public:
    MergeSort(){};
    ~MergeSort(){};

    void sort(vector<T> &arr) { mergeSort(arr, 0, arr.size() - 1); };

    void mergeSort(vector<T> &arr, int begin, int end)
    {
        if (begin < end)
        {
            int mid = begin + (end - begin) / 2;

            mergeSort(arr, begin, mid);
            mergeSort(arr, mid + 1, end);

            merge(arr, begin, mid, end);
        }
    };

    void merge(vector<T> &arr, int begin, int mid, int end)
    {
        int i = begin;
        int j = mid + 1;
        vector<T> aux(arr);

        for (int k = begin; k <= end; k++)
        {
            if ((aux[i] < aux[j] || j > end) && i<=mid)
            {
                arr[k] = aux[i];
                i++;
            }
            else if (aux[i] >= aux[j] || i > mid)
            {
                arr[k] = aux[j];
                j++;
            }
        }
    };
};