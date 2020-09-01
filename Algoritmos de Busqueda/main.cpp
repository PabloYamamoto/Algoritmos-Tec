#include "Busqueda.h"
#include "../mytimer.h"

int main(){
    
    

    Busqueda<int> Ejemplo; 
    
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    int answer1 = Ejemplo.BusquedaSecuencial(7200); 
    STOP_TIMING(t1);
    cout << "==================================================================================================================" << endl; 
    SHOW_TIMING(t1, "Busqueda Secuencial ");
    cout << "El número 7200 se encontró en la posición: " << answer1 << endl;
    cout << "==================================================================================================================" << endl; 

    DECLARE_TIMING(t2);
    START_TIMING(t2);
    int answer2 = Ejemplo.BusquedaSecuencialOredenada(7200); 
    STOP_TIMING(t2);
    cout << "==================================================================================================================" << endl; 
    SHOW_TIMING(t2, "Busqueda Secuencial Ordenada ");
    cout << "El número 7200 se encontró en la posición: " << answer2 << endl;
    cout << "==================================================================================================================" << endl; 


    DECLARE_TIMING(t3);
    START_TIMING(t3);
    int answer3 = Ejemplo.BusquedaSecuencialOredenada2(7200); 
    STOP_TIMING(t3);
    cout << "==================================================================================================================" << endl; 
    SHOW_TIMING(t3, "Busqueda Secuencial Ordenada 2 ");
    cout << "El número 7200 se encontró en la posición: " << answer3 << endl;
    cout << "==================================================================================================================" << endl; 

    Ejemplo.OrdenarArreglo(); 
    
    DECLARE_TIMING(t4);
    START_TIMING(t4);
    int answer4 =  Ejemplo.BusquedaBinaria(7200); 
    STOP_TIMING(t4);
    cout << "==================================================================================================================" << endl; 
    SHOW_TIMING(t4, "Busqueda Binaria ");
    cout << "El número 7200 se encontró en la posición: " << answer4 << endl;
    cout << "==================================================================================================================" << endl; 

    return 0; 
}