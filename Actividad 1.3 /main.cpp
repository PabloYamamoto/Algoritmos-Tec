#include "Registration.h"
#include "Busqueda.h"
//#include "Sorter.h"
#include <fstream>


using namespace std; 

// template<typename T>
// bool compare_lessthan(T &a, T &b){
//     return a < b; 
// }


int main(){
    ifstream MyFile; 
    MyFile.open("equipo7.csv"); 

    vector<Registratrion> All_Registrations = {}; 
    string date, time, source_ip, source_port, source_hostname, destination_ip, destination_port, destination_hostname;

    while(MyFile.good()){
        getline(MyFile, date, ','); 
        getline(MyFile, time, ','); 
        getline(MyFile, source_ip, ','); 
        getline(MyFile, source_port, ','); 
        getline(MyFile, source_hostname, ','); 
        getline(MyFile, destination_ip, ','); 
        getline(MyFile, destination_port, ','); 
        getline(MyFile, destination_hostname, '\n'); 
        
        All_Registrations.push_back(Registratrion(date, time, source_ip, source_port, source_hostname, destination_ip, destination_port, destination_hostname)); 
       


    }


   
   
   

    MyFile.close(); 
}

