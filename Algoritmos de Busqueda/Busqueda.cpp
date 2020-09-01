// #include "Busqueda.h"


// template<typename T>
// void Busqueda<T>::DesplegarVector(vector<T> Elementos){
//     for(int i = 0; i < Elementos.size(); i++){
//         cout << Elementos.at(i) << "\t"; 
//     }
//     cout << endl; 
// }


// template<typename T>
// T Busqueda<T>::BusquedaSecuencial(T val){
//     for(int i = 0; i < Elementos.size(); i++){
//         if(Elementos.at(i) == val){
//             return i; 
//         }
                
//     }

// }

// template<typename T>
// T Busqueda<T>::BusquedaSecuencialOredenada(T val){
//     sort(Elementos.begin(), Elementos.end()); 
//     for(int i = 0; i<Elementos.size(); i++){
//         if(Elementos.at(i) > val){
//             return -1; 
//             break; 
//         }
//         else{
//             return i; 
//             }
//     }
// }

// template<typename T>
// T Busqueda<T>::BusquedaSecuencialOredenada2(T val){

// }


// template<typename T>
// T Busqueda<T>::BusquedaBinaria(T val, int start, int end){
//     while(start <= end){
//         int mid = (start+end)/2; 
//         if(Elementos.at(mid) == val){
//             return mid; 
//         }
//         else if(val > Elementos.at(mid)){
//             return BusquedaBinaria(val, mid+1, end); 
//         }
//         else{
//             return BusquedaBinaria(val, start, mid-1); 
//         }
//     }
// }