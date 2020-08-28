#include <iostream>
#include <vector>
using namespace std; 

int sum(vector<int> Vec, int n){
    int r; 
    if(n==0){
        return Vec[n]; 
    }
    else{
        r=Vec[n]+sum(Vec, n-1); 
    }
    return r; 
}


int main(){
    vector<int> Vec = {10, 20, 30, 40, 50, 60}; 
    cout << sum(Vec, Vec.size()) << endl; 
}