#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class T>
class Busqueda{
    private: 
        vector<T> Elementos; 
    public: 
        Busqueda(vector<T> Elementos){ this->Elementos=Elementos; } 
        ~Busqueda(); 

        T DesplegarVector(){
            for(int i = 0; i < Elementos.size(); i++){
                cout << Elementos.at(i) << "\t"; 
            }
        }

        T BusquedaSecuencial(T val){
            for(int i = 0; i < Elementos.size(); i++){
                if(Elementos.at(i) == val){
                    return i; 
                }
            }
    
        }

        T BusquedaSecuencialOredenada(T val){
           sort(Elementos.begin(), Elementos.end()); 
           for(int i = 0; i<Elementos.size(); i++){
               if(Elementos.at(i) > val){
                   return -1; 
                   break; 
               }
               else{
                   return i; 
               }
           }
        }


        T BusquedaSecuencialOredenada2(T val){

        }
        
        T BusquedaBinaria(T val, int start, int end){
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
        }

}; 



int main(){
    return 0; 
}