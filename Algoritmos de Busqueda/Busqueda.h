#include <iostream>
#include <vector>
using namespace std; 

template<class T>
class Busqueda{
    private: 
        vector<T> Elementos; 
    public: 
        Busqueda(); 
        ~Busqueda(); 

        T DesplegarVector();
        T BusquedaSecuencial(T val); 
        T BusquedaSecuencialOredenada(T val); 
        T BusquedaSecuencialOredenada2(T val); 
        T BusquedaBinaria(T val); 

}; 