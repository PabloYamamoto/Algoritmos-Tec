#include "Registration.h"
#include "Busqueda.h"
#include "DataBase.h"
#include "Sorter.h"
#include <fstream>

using namespace std; 

template<typename T>
bool compare_equalto(T &a,string &b){
    return a.getDate() == b; 
}

template<typename T>
bool compare_equalto2(T &a, string &b){
    return a.getSource_Hostname() == b; 
}

template<typename T>
bool compare_morethan(T &a, string &b){
    return a.getSource_Hostname() > b; 
}

template<typename T>
bool compare_lessthan(T &a, T &b){
    return a.getSource_Hostname() < b.getSource_Hostname(); 
}

int main(){
    string file_name = "equipo7.csv";

    DataBase <Registration>DB(file_name, ',');
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";    
    cout << "Pregunta 1" << endl; 
    cout << "Número de registros: " << DB.All_Registrations.size()-1 << endl; 
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";    
    cout << "Pregunta 2" << endl; 
    string second_day = DB.next_day(DB.All_Registrations[0].getDate());
    cout << "Fecha de busqueda: " << second_day << endl;
    Busqueda<Registration> BS; 
    int start, final;
    BS.BusquedaSecuencial_P2(DB.All_Registrations, second_day, &compare_equalto, &start, &final); 
    cout << "Numero de registros: " << (final - start) << endl;
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";
    cout << "Pregunta 3" << endl; 
    Quicksort<Registration> QS;
    QS.sort(DB.All_Registrations, &compare_lessthan);
    vector <string> hostnames = {"jeffrey.reto.com", "betty.reto.com", "katherine.reto.com", "scott.reto.com", "benjamin.reto.com", "samuel.reto.com", "raymond.reto.com"};
    for (auto name : hostnames){
        cout << name;
        int found = BS.BusquedaBinaria(DB.All_Registrations, 0, DB.All_Registrations.size()-1, name,  &compare_equalto2, &compare_morethan);
        cout << (found > -1 ? " encontrado. \n" : " no ecnontrado. \n");
    }
    
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";   
    cout << "Pregunta 4" << endl; 
    cout << "dirección de la red interna de la compañía: " << DB.company_ip() << endl; 
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";   
    cout << "Pregunta 5" << endl; 
    cout << "server.reto.com: ";
    int found = BS.BusquedaBinaria(DB.All_Registrations, 0, DB.All_Registrations.size()-1, "server.reto.com",  &compare_equalto2, &compare_morethan);
    cout << (found > -1 ? " encontrado. \n" : " no ecnontrado. \n");
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";   
    cout << "Pregunta 6" << endl; 
    DB.findMail();
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";

}

