#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std; 

template<typename T>
class Busqueda{
    private: 
        vector<T> Elementos; 
    public: 
        Busqueda(){
            for (size_t i = 0; i < 10; i++)
            {
                Elementos.push_back((int)rand()% 300); 
            }
        }; 

        ~Busqueda(){}; 

        void DesplegarVector(){
            for(int i = 0; i < Elementos.size(); i++){
                cout << Elementos.at(i) << "\t"; 
            }
            cout << endl; 
        };

        void OrdenarArreglo(){
            sort(Elementos.begin(), Elementos.end()); 
        }; 

        T BusquedaSecuencial(T val){
            for(int i = 0; i < Elementos.size(); i++){
                if(Elementos.at(i) == val){
                return i; 
                }
                
            }
            return -1; 
        }; 

        T BusquedaSecuencialOredenada(T val){
            OrdenarArreglo(); 
            for(int i = 0; i<Elementos.size(); i++){
                if(Elementos.at(i) > val){
                    return -1; 
                    break; 
                }
                if(Elementos.at(i) == val){
                    return i; 
                }
            }
        }; 


        T BusquedaSecuencialOredenada2(T val){
            OrdenarArreglo(); 
            for(int i = 0; i < Elementos.size(); i+=2){
                if(val > Elementos.at(i)){
                    i--; 
                }
                if(val == Elementos.at(i)){
                    return i; 
                }      
            }
            return -1; 

        }; 

        T BusquedaBinaria(T val, int start=0, int end = 0 ){
            if(end == 0) end = Elementos.size(); 
            while(start <= end){
                int mid = (start+end)/2; 
                if(Elementos.at(mid) == val){
                    return mid; 
                }
                else if(val > Elementos.at(mid)){
                    return BusquedaBinaria(val, mid+1, end); 
                }
                else{
                    return BusquedaBinaria(val, start, mid-1); 
                }
            }
            return -1; 
        };

}; 