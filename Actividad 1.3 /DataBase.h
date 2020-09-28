#include <vector>
#include <map>
#include <fstream>
#include "Registration.h"

using namespace std;

template<class T>
#pragma once
class DataBase
{
public:
    vector<T> All_Registrations;

    DataBase(string file_name, char punctation_mark)
    {
        ifstream MyFile;
        MyFile.open(file_name);

        string date, time, source_ip, source_port, source_hostname, destination_ip, destination_port, destination_hostname;

        // Counter for printing the Registrations if enabeled
        // int i = 0;
        while (!MyFile.eof())
        {
            getline(MyFile, date, punctation_mark);
            getline(MyFile, time, punctation_mark);
            getline(MyFile, source_ip, punctation_mark);
            getline(MyFile, source_port, punctation_mark);
            getline(MyFile, source_hostname, punctation_mark);
            getline(MyFile, destination_ip, punctation_mark);
            getline(MyFile, destination_port, punctation_mark);
            getline(MyFile, destination_hostname, '\n');

            All_Registrations.push_back(Registration(date, time, source_ip, source_port, source_hostname, destination_ip, destination_port, destination_hostname));

            // The code below prints all the registrations

            // cout << "Resgistration number " << i << " == ";
            // All_Registrations.at(i).print();
            // i++;
        }
        MyFile.close();
    };
    ~DataBase(){};

    string next_day(string actual_day)
    {
        int day = stoi(actual_day.substr(0, 2));
        day++;
        return to_string(day) + actual_day.substr(2);
    };

    string company_ip()
    {
        string source_ip_company = "-";
        int i = 0;
        while (source_ip_company == "-")
        {
            source_ip_company = All_Registrations.at(i).getSource_IP();
            i++;
        }
        size_t last_digit = source_ip_company.find_last_of(".\\");
        return source_ip_company.substr(0, last_digit) + ".0";
    }

    void findMail(map<string, int> &memory)
    {
        for (auto registration : All_Registrations)
        {
            string name = registration.getDestination_Hostname();
            map<string,int>::iterator it = memory.find(name);
            if (it != memory.end())
                memory.at(name)++;
            else
                memory.insert(pair<string, int>(name,1));
        }
        memory.erase("-");
        int currentMax = 0;
        string keyMax;
        for (map<string,int>::iterator it = memory.begin(); it != memory.end(); ++it)
        {
            if (it->second > currentMax)
            {
                keyMax = it->first;
                currentMax = it->second;
            }
        }
        cout << "El correo usado en la empresa es " << keyMax << " con " << currentMax << " entradas. \n";
    }
};