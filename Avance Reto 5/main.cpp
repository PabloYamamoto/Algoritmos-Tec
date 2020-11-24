/*
main para responder las preguntas del reto
Pablo Yamamoto - A01022382 
Santiago Kohn - A01029109
Fecha de creación - 23/11/2020
Fecha de última modificación - 23/11/2020
*/

#include "ConexionesComputadora.h"
#include "Graph.h"
#include <map>
#include <set>

int main()
{

    string file_name = "nuevo7.csv";
    DataBase<Registration> DB(file_name, ',');
    cout << "Loaded \n";

   
    
    vector<Graph<string>> Graphs_per_day; 
    set<string> fechas;
    
    for (vector<Registration>::iterator it = DB.All_Registrations.begin(); it!=DB.All_Registrations.end(); it++)
    {
        fechas.insert(it->getDate());
    }



    

    
    
        

}
