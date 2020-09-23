#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std; 

template<typename T>
class Busqueda{
    
    public: 
        Busqueda(){}; 
        ~Busqueda(){}; 

        T BusquedaBinaria(vector<T> Vec, int start, int end, int val){
           if(start <= end){
               int mid = (start+end)/2; 
               if(Vec.at(mid) == val) return mid; 
               else if(Vec.at(mid) > val){
                   return BusquedaBinaria(Vec, start, mid-1, val); 
               }
               else{
                   return BusquedaBinaria(Vec, mid+1, end, val); 
               }
           }
           return -1; 
        };

        T BusquedaSecuencial_P2(vector<T> Vec, T val){
            int index_start = -1, index_final = -1;  // They start at -1 in case we dont find the values we are searching for
            for(size_t i = 0; i < Vec.size(); i++){
                if(Vec.at(i) == val){
                    index_start = i; 
                    break; 
                }
            }

            for (size_t i = index_start; i < Vec.size(); i++)
            {
                if(Vec.at(i) > val){
                    index_final = i-1; 
                    break; 
                }
            }
            
            return index_start, index_final; 
            
            
        }; 


}; 