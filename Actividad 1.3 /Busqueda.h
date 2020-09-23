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

}; 