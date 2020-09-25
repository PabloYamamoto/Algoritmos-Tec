#include <iostream>
#include <string>
using namespace std; 

#pragma once
class Registration{
    private:
        string date;
        string time;
        string source_ip;
        string source_hostname;
        string destination_ip;
        string destination_hostname;
        string source_port;
        string destination_port;

    public: 
        Registration(string date, string time, string source_ip, string source_port, string source_hostname, string destination_ip, string destination_port, string destination_hostname) : date{date}, time{time}, source_ip{source_ip}, source_port{source_port}, source_hostname{source_hostname}, destination_ip{destination_ip}, destination_port{destination_port}, destination_hostname{destination_hostname} {}; 
        ~Registration(){}; 

        void print(){
            cout << date << ", " <<  time << ", " <<  source_ip << ", "  << source_port << ", " << source_hostname << ", " << destination_ip << ", " << destination_port << ", " <<  destination_hostname << endl; 
        }

        string getDate(){return date; }; 
        string getTime(){return time; }; 
        string getSource_IP(){return source_ip; };
        string getSource_Hostname(){ return source_hostname; }; 
        string getDestination_IP(){return destination_ip; };
        string getDestination_Hostname(){return destination_hostname; }; 
        string getSource_Port(){return source_port; }; 
        string getDestination_Port(){return destination_port; }; 
}; 


