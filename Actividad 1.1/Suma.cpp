#include <iostream>
#include <math.h>
using namespace std; 


int SumaIterativa(int num){
    
    int contador=0; 
    for(int i = 0; i <= num; i++){
        contador+=i; 
    }
    return contador; 
}

int SumaRecursiva(int n){
    if(n == 0){
        return 0; 
    }
    else{
        return SumaRecursiva(n-1)+n; 
    }
   
}

int SumaMatematica(int a, int m, int n){
    int S = (pow(a, m)-pow(a, n+1))/(1-a); 
    return S; 
   
}

int main(){
    cout << SumaIterativa(10) << endl; 
    cout << SumaRecursiva(10) << endl; 
    cout << SumaMatematica(2, 0, 9) << endl; 
}