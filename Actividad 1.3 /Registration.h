#include <iostream>
#include <string>
using namespace std; 

#pragma once
class Registratrion{
    private: 
        string date, time, source_ip, source_hostname, destination_ip, destination_hostname, source_port, destination_port; 
        
    public: 
        
        Registratrion(string date, string time, string source_ip, string source_port, string source_hostname, string destination_ip, string destination_port, string destination_hostname) : date{date}, time{time}, source_ip{source_ip}, source_port{source_port}, source_hostname{source_hostname}, destination_ip{destination_ip}, destination_port{destination_port}, destination_hostname{destination_hostname} {}; 
        ~Registratrion(){}; 

        void print(){
            cout << date << ", " <<  time << ", " <<  source_ip << ", "  << source_port << ", " << source_hostname << ", " << destination_ip << ", " << destination_port << ", " <<  destination_hostname << endl; 
        }
}; 


