#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std; 

template<typename T>
class Busqueda{
    
    public: 
        Busqueda(){}; 

        ~Busqueda(){}; 

        

       
        T BusquedaSecuencial(vector<T> Vec, T val){
            for(int i = 0; i < Vec.size(); i++){
                if(Vec.at(i) == val){
                    return i; 
                }
            }
            return -1; 
            
        }; 

    

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