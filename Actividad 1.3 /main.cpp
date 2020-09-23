#include "Registration.h"
#include "Busqueda.h"
//#include "Sorter.h"
#include <fstream>


using namespace std; 

template<typename T>
bool compare_equalto(T &a, T &b){
    return a.date() == b.date(); 
}

template<typename T>
bool compare_morethan(T &a, T &b){
    return a > b; 
}

template<typename T>
bool compare_lessthan(T &a, T &b){
    return a < b; 
}



int main(){
    ifstream MyFile; 
    MyFile.open("equipo7.csv"); 

    vector<Registratrion> All_Registrations = {}; 
    string date, time, source_ip, source_port, source_hostname, destination_ip, destination_port, destination_hostname;

    // Counter for printing the Registrations if enabeled
    // int i = 0; 
    while(!MyFile.eof()){
        getline(MyFile, date, ','); 
        getline(MyFile, time, ','); 
        getline(MyFile, source_ip, ','); 
        getline(MyFile, source_port, ','); 
        getline(MyFile, source_hostname, ','); 
        getline(MyFile, destination_ip, ','); 
        getline(MyFile, destination_port, ','); 
        getline(MyFile, destination_hostname, '\n'); 
        
        All_Registrations.push_back(Registratrion(date, time, source_ip, source_port, source_hostname, destination_ip, destination_port, destination_hostname)); 

        // The code below prints all the registrations

        // cout << "Resgistration number " << i << " == ";   
        // All_Registrations.at(i).print(); 
        // i++; 

    }

    cout << "==========================================================================" << endl; 
    cout << "Pregunta 1" << endl; 
    cout << "Número de registros: " << All_Registrations.size()-1 << endl; 
    cout << "==========================================================================" << endl;

    cout << "==========================================================================" << endl; 
    cout << "Pregunta 2" << endl; 
    Busqueda<Registratrion> BS; 

    BS.BusquedaSecuencial_P2(All_Registrations, ); 
    cout << "==========================================================================" << endl;

    
   
  
    MyFile.close(); 
}

