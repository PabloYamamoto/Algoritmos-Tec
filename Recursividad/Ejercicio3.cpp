#include <iostream>
using namespace std; 

int sumarecursiva(int Matriz[][5], int rows, int cols){
    int contador; 
    if(cols == 0){
        return Matriz[rows][cols]+Matriz[rows-1][cols]; 
    }
    else{
        contador = Matriz[rows][cols] + Matriz[rows-1][cols]; 
    }
    return contador+sumarecursiva(Matriz, rows, cols-1); 
}



int main(){
    int Matriz[2][5]; 
    int num = 1; 
    for(int i = 0; i<2; i++){
        for(int j = 0; j<5; j++){
            Matriz[i][j] = num++; 
            cout << Matriz[i][j] << "\t"; 
        }
        cout << endl; 
    }

    cout << endl; 


    cout << endl; 
    int contador = 0; 
     for(int i = 0; i<2; i++){
        for(int j = 0; j<5; j++){
           contador += Matriz[i][j]; 
        }
    }

    cout << "La suma de los elementos usando for loops es: " << contador << endl; 
    cout << endl; 
    cout << "La suma de los elementos usando una función recursiva es: " << sumarecursiva(Matriz,1, 4) << endl; 
    cout << endl; 
}