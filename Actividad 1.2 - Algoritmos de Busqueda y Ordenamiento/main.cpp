#include "Busqueda.h"
#include "Sorter.h"


int main(){
    
    while (true){
        cout << "==================================================================" << endl; 

        cout << "Selecciona el algorimo para ordenar los datos del vector" << endl; 
        cout << endl; 
        cout << "1.- InsertionSort" << endl; 
        cout << "2.- BubbleSort" << endl; 
        cout << "3.- QuickSort" << endl; 
        cout << "4.- Salir del programa" << endl; 
        cout << endl; 
        cout << "==================================================================" << endl; 
        int opción; 
        cout << "Opción: "; cin >> opción;
         cout << "==================================================================" << endl; 

        if(opción == 4){
            cout << endl; 
            cout << "Programa terminado" << endl; 
            cout << endl; 
            break; 
        }
        
        while (true){
            cout << endl; 
            cout << "==================================================================" << endl; 
            cout << "Selecciona el Alogritmo de Busqueda" << endl; 
            cout << endl; 
            cout << "1.- Busqueda Lineal" << endl; 
            cout << "2.- Busqueda Binaria" << endl; 
            cout << endl; 
            cout << "==================================================================" << endl; 
            int busqueda; 
            cout << "Opción: "; cin >> busqueda; 
            cout << "==================================================================" << endl; 

            vector<int> vec; 
            for(int i = 0; i < 100; i++){
                vec.push_back((int)rand() % 500); 
            }


    

            if(opción == 1 and busqueda == 1){
                InsertionSort<int> IS; 
                cout << "Desordenado: " << endl; 
                IS.show(vec); 
                cout << "Ordenado: " << endl; 
                IS.Sort(vec); 
                IS.show(vec); 
                int val; 
                cout << "Ingresa un valor el cual quieras buscar: "; cin >> val; 
                Busqueda<int> BL; 
                int indice = BL.BusquedaSecuencial(vec, val); 
                cout << "==================================================================" << endl;
                if(indice == -1){
                    cout << "El número " << val << " no se encontró en el vector" << endl;  
                    cout << "==================================================================" << endl;
                    break; 
                }
                
                else{
                    cout << "El número " << val << " se encontró en el índice " << indice << endl;  
                    cout << "==================================================================" << endl;
                    break; 
                }
            }
           
            if(opción == 1 and busqueda == 2){
                InsertionSort<int> IS; 
                cout << "Desordenado: " << endl; 
                IS.show(vec); 
                cout << "Ordenado: " << endl; 
                IS.Sort(vec); 
                IS.show(vec); 
                int val; 
                cout << "Ingresa un valor el cual quieras buscar: "; cin >> val; 
                Busqueda<int> BB; 
                int indice = BB.BusquedaBinaria(vec, 0, vec.size()-1, val); 
                cout << "==================================================================" << endl;
                if(indice == -1){
                    cout << "El número " << val << " no se encontró en el vector" << endl;  
                    cout << "==================================================================" << endl;
                    break; 
                }
                else{
                    cout << "El número " << val << " se encontró en el índice " << indice << endl;  
                    cout << "==================================================================" << endl;
                    break; 
                }   
                
            }

            if(opción == 2 and busqueda == 1){
                BubbleSort<int> BS; 
                cout << "Desordenado: " << endl; 
                BS.show(vec); 
                cout << "Ordenado: " << endl; 
                BS.Sort(vec); 
                BS.show(vec); 
                int val; 
                cout << "Ingresa un valor el cual quieras buscar: "; cin >> val; 
                Busqueda<int> BL; 
                int indice = BL.BusquedaSecuencial(vec, val); 
                cout << "==================================================================" << endl;
                if(indice == -1){
                    cout << "El número " << val << " no se encontró en el vector" << endl;  
                    cout << "==================================================================" << endl;
                    break; 
                }
                else{
                    cout << "El número " << val << " se encontró en el índice " << indice << endl;  
                    cout << "==================================================================" << endl;
                    break;
                } 
            }

            if(opción == 2 and busqueda == 2){
                BubbleSort<int> BS; 
                cout << "Desordenado: " << endl; 
                BS.show(vec); 
                cout << "Ordenado: " << endl; 
                BS.Sort(vec); 
                BS.show(vec); 
                int val; 
                cout << "Ingresa un valor el cual quieras buscar: "; cin >> val; 
                Busqueda<int> BB; 
                int indice = BB.BusquedaBinaria(vec, 0, vec.size()-1, val); 
                cout << "==================================================================" << endl;
                if(indice == -1){
                    cout << "El número " << val << " no se encontró en el vector" << endl;  
                    cout << "==================================================================" << endl;
                    break; 
                }
                else{
                    cout << "El número " << val << " se encontró en el índice " << indice << endl;  
                    cout << "==================================================================" << endl;
                    break;
                } 
            }

            if(opción == 3 and busqueda == 1){
                QuickSort<int> QS; 
                cout << "Desordenado: " << endl; 
                QS.show(vec); 
                cout << "Ordenado: " << endl; 
                QS.Sort(vec); 
                QS.show(vec); 
                int val; 
                cout << "Ingresa un valor el cual quieras buscar: "; cin >> val; 
                Busqueda<int> BL; 
                int indice = BL.BusquedaSecuencial(vec, val); 
                cout << "==================================================================" << endl;
                if(indice == -1){
                    cout << "El número " << val << " no se encontró en el vector" << endl;  
                    cout << "==================================================================" << endl;
                    break; 
                }
                else{
                    cout << "El número " << val << " se encontró en el índice " << indice << endl;  
                    cout << "==================================================================" << endl;
                    break;
                } 
            }

            if(opción == 3 and busqueda == 2){
                QuickSort<int> QS; 
                cout << "Desordenado: " << endl; 
                QS.show(vec); 
                cout << "Ordenado: " << endl; 
                QS.Sort(vec); 
                QS.show(vec); 
                int val; 
                cout << "Ingresa un valor el cual quieras buscar: "; cin >> val; 
                Busqueda<int> BB; 
                int indice = BB.BusquedaBinaria(vec, 0,vec.size()-1, val); 
                cout << "==================================================================" << endl;
                if(indice == -1){
                    cout << "El número " << val << " no se encontró en el vector" << endl;  
                    cout << "==================================================================" << endl;
                    break; 
                }
                else{
                    cout << "El número " << val << " se encontró en el índice " << indice << endl;  
                    cout << "==================================================================" << endl;
                    break;
                } 
            }


            
        
        
        }   //Terminación While interno
            
        
    
    } //Terminación While externo
    return 100; 

}