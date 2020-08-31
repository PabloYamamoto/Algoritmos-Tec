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
        Busqueda(){}; 
        ~Busqueda(){}; 

        void DesplegarVector(vector<T> Elementos);
        T BusquedaSecuencial(T val); 
        T BusquedaSecuencialOredenada(T val); 
        T BusquedaSecuencialOredenada2(T val); 
        T BusquedaBinaria(T val, int start, int end); 

}; 