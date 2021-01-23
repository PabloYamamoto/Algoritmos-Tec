
/*
Archivo main donde respoderemos las preguntas principales de este avance del reto
Pablo Yamamoto - A01022382 
Santiago Kohn - A01029109
Fecha de creación - 8/11/2020
Fecha de última modificación - 8/11/2020
*/

#include "ConexionesComputadora.h"
#include<functional>
#include<set>

bool compare_morethan(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool compare_lessthan(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}
int main()
{
    string file_name = "nuevo7.csv";
    DataBase<Registration> DB(file_name, ',');
    cout << "Loaded \n";
    //map<string, int> memory = DB.conexionesPorDia("10-8-2020");
    set<string> fechas;
    for (auto conexion : DB.All_Registrations)
    {
        fechas.insert(conexion.getDate());
        
    }

    for (auto fecha : fechas)
    {
        cout << fecha << endl;
        DB.top(5, fecha, &compare_morethan, &compare_lessthan);
    }
}