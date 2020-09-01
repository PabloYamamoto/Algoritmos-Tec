#include "Busqueda.h"


int main(){
    
    

    Busqueda<int> Ejemplo; 
    cout << endl; 
    Ejemplo.DesplegarVector(); 
    cout << endl; 

    Ejemplo.OrdenarArreglo(); 
    Ejemplo.DesplegarVector();
    cout << endl; 
    cout << Ejemplo.BusquedaBinaria(130) << endl; 
    
    

    return 0; 
}