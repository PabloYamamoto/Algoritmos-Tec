#include <iostream>
using namespace std; 

int MCD(int a, int b){
    if(b==0){
        return a; 
    }
    else{
        return MCD(b, a%b); 
    }
}

int main(){
    int a, b; 
    do
    {
       cout << "Ingresa el primer número "; cin >> a; 
       cout << endl; 
       if(a<0){
           cout << "El primer número tiene que ser positivo " << endl; 
       }
    } while (a<0);
     do
    {
       cout << "Ingresa el segundo número "; cin >> b; 
       cout << endl; 
       if(b<0){
           cout << "El segundo número tiene que ser positivo " << endl; 
       }
    } while (b<0);

    if(a>b){
        cout << "El máximo común divisor es: " << MCD(a,b) << endl; 
    }
    else{
        cout << "El máximo común divisor es: " << MCD(b, a) << endl; 
    }
    
    
}