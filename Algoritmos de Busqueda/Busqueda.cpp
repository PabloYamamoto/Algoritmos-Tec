#include "Busqueda.h"
#include <cstdlib>
#include <ctime>

template<class T>
Busqueda<T>::Busqueda(){
    srand((unsigned) time (0)); 
    for(T i = 0; i <= 10; i++){
        int random = (rand() % 1000)+1; 
        Elementos.push_back(random); 
    }
}


template<class T>
T Busqueda<T>::DesplegarVector(){
    for(T i = 0; i < Elementos.end(); i++){
        cout << Elementos[i] << "\t"; 
    }
    cout << endl; 
}


template<class T>
T Busqueda<T>::BusquedaSecuencial(T val){
    for(int i = 0; i < Elementos.end(); i++){
        if(Elementos[i] == val){
            return i; 
        }
    }
    return -1; 
}

// template<class T>
// T Arithametic<T>::add(){         EJEMPLO TEMPLATE
//     T c = 0; 
//     c = a+b; 
//     return c; 
// }

