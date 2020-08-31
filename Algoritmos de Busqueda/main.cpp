#include "Busqueda.h"


int main(){
    vector<int> Vec; 
    for (size_t i = 0; i < 10; i++)
    {
        Vec.push_back((int)rand()% 300); 
    }

    Busqueda<int> Ejemplo; 
    Ejemplo.DesplegarVector(Vec); 
    

    return 0; 
}