/*
Clase de DataBase para definir leer los datos del archivo csv
Pablo Yamamoto - A01022382 
Santiago Kohn - A01029109
Fecha de creación - 24/09/2020
Fecha de última modificación - 8/11/2020
*/

#include <vector>
#include <map>
#include <fstream>
#include "Registration.h"
#include "bst.h"

using namespace std;

template <class T>
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
        }
        MyFile.close();
    };
    ~DataBase(){};

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
        return source_ip_company.substr(0, last_digit) + ".";
    }

    map<string, int> conexionesPorDia(string fecha)
    {
        map<string,int> memory;
        size_t index_start;
        for (size_t i = 0; i < All_Registrations.size(); i++)
        {
            if (All_Registrations.at(i).getDate() == fecha)
            {
                index_start = i;
                break;
            }
        }
        for (size_t i = index_start; i < All_Registrations.size(); i++)
        {
            if (All_Registrations.at(i).getDate() == fecha)
            {
                string name = All_Registrations.at(i).getDestination_Hostname();
                size_t first_point = name.find_first_of(".\\");
                string sub_name = name.substr(first_point + 1, name.length() - 1);
                map<string, int>::iterator it = memory.find(name);
                if (it == memory.end() && sub_name != "reto.com" && name != "-")
                    memory.insert(pair<string, int>(name, 1));
                else if(it != memory.end())
                    memory.at(name)++;
            }
            else
                break;
        }
        return memory;
    }

    void top(int n, string fecha, bool (*morethan)(pair<string, int>, pair<string, int>), bool (*lessthan)(pair<string, int>, pair<string, int>))
    {
        map<string, int> memory = conexionesPorDia(fecha);
        BinarySearchTree<pair<string, int>>* BST = new BinarySearchTree<pair<string, int>>(morethan, lessthan);
        for (auto tuple : memory)
        {
            BST->insert_node_recursive(tuple);
        }
        vector <pair <string, int>> top;

        BST->top_N(&top);
        vector <pair <string, int>> top_n(top.begin(), top.begin()+n);
        for (auto n : top_n)
        {
            cout << n.first << " - " << n.second << endl;
        }
        delete BST;
    }
};