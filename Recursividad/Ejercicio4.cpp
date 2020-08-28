#include <iostream>
using namespace std; 

int suma(int number){
    int contador; 
    if(number < 10){
        return number; 
    }
    else{
        contador = number%10 + suma(number/10); 
    }
    return contador; 
}

int main(){
    int number; 
    cout << "Ingresa cualquier número del 11 al infinito "; cin >> number; 
    cout << endl; 
    
    cout << "La suma de los digitos del número " << number << " es " << suma(number) << endl; 
}