#include <iostream>
using namespace std; 



int TallestBuilding_V_LOG(int Skyline[][6], int row, int col, int end = 0, int start = 0){    
   int SupCol, returnCol; 
   if(end == 0){        //Inicializamos end o Lowebound para la busqueda binaria con 0, estos valores se actualizan cuando se vuelva a llamar a la función (forma recursiva)
       end = 5;         
   }
   int mid = (start+end)/2;         //Vamos a encontrar nuestro posición a la mitad de cada columna, en la primera llamada siempre caerá en la posición 2. (0+5)/2 = 2
   bool Building = false;           //Esta variable booleana nos ayudará en el futuro para saber si hay un cero o no, y con las variables nextCol nos movemos por cada columna
   for(int i = 0; i < col; i++){       //Un for para iterar sobre cada columna y una vez dentro, hacer una busqueda binaria. Lo hacemos de esta forma ya que cada columna es un arreglo ordenado, antes planeaba hacer un for para cada fila y una vez dentro hacer la busqueda binaria, pero eso no sirve porque el arreglo no esta ordenado, y un algortimo así nos regresa el primer cero que encuentre.
       if(Skyline[mid][i]==0){      //Primero se evalua si en la fila 2 en la columna i (en este caso, la columna 1 porque es la primera iteración) hay un cero.
           Building = true;         //Si esta condición es cierta, sabemos que hay un edificio en esa columna, entonces convertimos nuestra booleana en verdadero. 
           if(mid == 0){        //Sí nuestra posición de la mitad en algún momento es cero, regresamos el valor de que columna con i. 
               return i; 
           }
           int SupCol = TallestBuilding_V_LOG(Skyline, row, col, mid, start);  //Después vamos a obtener el valor superior en el que nos encontramos, por eso nuestro posición de la mitad se vuelve ahora la posición final de la siguiente llamada recursiva, y nuestro start se queda igual
           if(SupCol < 0){             //Aqui vemos si hay 0 o 1;  
               returnCol = i;       
           }
           else{
               returnCol = SupCol; 
           }
           break; 
       }
   }
   if(!Building  and ((mid+end)/2)==mid){        
       return -1;               //Si hay puros 1, significa que no hay edificio en esa columna y se regresa el -1 indicando eso
   }
   if(Building == true){                
       return returnCol; 
   }
   return TallestBuilding_V_LOG(Skyline, row, col, end, mid); //Al final hacemos una llamada con nuestra posición de la mitad como nuestro nuevo start, estamos iterando hacia abajo de la columna


   //Este algoritmo es de tipo O(logn) ya que va a iterar por la mitad de los datos en vez de una función exponencial que itera por todos los datos
   
}

int TallestBuilding_V_MPLUSN(int Skyline[][6], int number_col, int number_row, int col, int row ){
    if(Skyline[row][col]==0){           //Vemos si hay un edificio o un 0 con los valores de cada fila y columna, estos se irán actualizando con cada llamada recursiva
        return col; 
    }
    else if(number_row< row or number_col<col){         //Tenemos un control para evitar meternos con columnas o filas que no existan, ya que sin el control tendríamos un segmentation fault
        return -1; 
    }
    else if(col == number_col){         
        return TallestBuilding_V_MPLUSN(Skyline, number_col, number_row, 0, row+=1);        //Hacemos un update de la fila, por que ya llegamos al final 
    }
    else if(Skyline[row][col] != 0){
        return TallestBuilding_V_MPLUSN(Skyline, number_col, number_row, col+=1, row);  //Si no encontramos un 0 o edificio en cierta posición de la matriz, nos movemos de columna y empezamos a buscar en otra. 
    }
    return -1; 
}

int main(){
    int Skyline[5][6] = {
        {1,1,0,1,1,1}, 
        {1,1,0,0,0,1}, 
        {1,1,0,0,0,1}, 
        {0,1,0,0,0,1}, 
        {0,0,0,0,0,1}, 
    }; 

    cout << endl;  

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            cout << Skyline[i][j] << "\t"; 
        }
        cout << endl; 
    }
    cout << endl; 
    cout << "===========================================================" << endl; 
    cout << "TALLEST BUILDING USING MLOGN ALGORITHM IS: " << TallestBuilding_V_LOG(Skyline, 5, 6, 0, 0) << endl; 
    cout << "===========================================================" << endl; 
    cout << endl; 
    cout << "===========================================================" << endl; 
    cout << "TALLEST BUILDING USING M+N ALGORITHM IS: " << TallestBuilding_V_MPLUSN(Skyline, 5, 6, 0, 0) << endl; 
    cout << "===========================================================" << endl; 
   
    
   
    
}