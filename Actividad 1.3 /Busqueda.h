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

        int BusquedaBinaria(vector<T> Vec, int start, int end, string val, bool(*compare1)(T &a, string &b), bool(*compare2)(T &a, string &b)){
            if(start <= end){
                int mid = (start+end)/2; 
                if((*compare1)(Vec.at(mid), val)) 
                    return mid; 
                else if((*compare2)(Vec.at(mid), val))
                    return BusquedaBinaria(Vec, start, mid-1, val, compare1, compare2); 
                else
                    return BusquedaBinaria(Vec, mid+1, end, val, compare1, compare2); 
           }
           return -1; 
        };

        void BusquedaSecuencial_P2(vector<T> Vec, string val, bool(*compare)(T &a, string &b), int *index_start, int *index_final){
            *index_start = -1;
            *index_final = -1;  // They start at -1 in case we dont find the values we are searching for
            for(size_t i = 0; i < Vec.size(); i++){
                if((*compare)(Vec[i], val)){
                    *index_start = i; 
                    break; 
                }
            }

            for (size_t i = *index_start; i < Vec.size(); i++)
            {
                if(!(*compare)(Vec[i], val)){
                    *index_final = i; 
                    break; 
                }
            }
        }; 


}; 