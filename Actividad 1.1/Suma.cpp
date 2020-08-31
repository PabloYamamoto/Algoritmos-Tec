#include <iostream>
#include <math.h>
using namespace std; 


int SumaIterativa(int num){
    
    int contador=0;                     // 1
    for(int i = 0; i <= num; i++){      // n+1
        contador+=i;                    //2n
    }
    return contador;                    //1      O(n)
}

int SumaRecursiva(int n){               //O(n)
    if(n == 0){
        return 0; 
    }
    else{
        return SumaRecursiva(n-1)+n; 
    }
   
}

int SumaMatematica(int a, int m, int n){        //O(6) -> O(1)
    int S = (pow(a, m)-pow(a, n+1))/(1-a); 
    return S; 
   
}

int main(){
    cout << SumaIterativa(10) << endl; 
    cout << SumaRecursiva(10) << endl; 
    cout << SumaMatematica(2, 0, 9) << endl; 
}