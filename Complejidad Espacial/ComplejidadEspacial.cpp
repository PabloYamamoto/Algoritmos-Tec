#include <iostream>
using namespace std; 

struct Array{
    int A[6]; 
    int length; 
}; 


int BusquedaBinaria(Array Arr, int key){
    int l, mid, h; 
    l = 0; 
    h = Arr.length-1; 

    while(l<=h){
        mid=(l+h)/2; 
        if(key == Arr.A[mid]){
            return mid; 
        }
        else if(key<Arr.A[mid]){
            h = mid-1; 
        }
        else{
            l = mid+1; 
        }
    }
    return -1; 
}



void BusquedaLog(int Skyline[5][6]){
    for(int i = 0; i <= 5; i++){
        Array Arr = {{}, 6}; 
        Arr.A[i] = Skyline[i][i];
        int answer = BusquedaBinaria(Arr, 0); 
        if(answer == -1){
            continue; 
        }
        else{
            cout << answer << endl; 
        }
        }
}


int main(){
    int Skyline[5][6] = {
        {1,1,0,1,1,1}, 
        {1,1,1,0,0,1}, 
        {0,0,1,1,0,1}, 
        {0,1,1,1,0,1}, 
        {0,0,0,1,0,1}, 
    }; 

    BusquedaLog(Skyline);


}