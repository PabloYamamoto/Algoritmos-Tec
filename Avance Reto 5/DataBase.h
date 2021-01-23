/*
Clase de DataBase para definir leer los datos del archivo csv
Pablo Yamamoto - A01022382 
Santiago Kohn - A01029109
Fecha de creación - 24/09/2020
Fecha de última modificación - 23/11/2020
*/

#include <vector>
#include <map>
#include <fstream>
#include "Registration.h"
#include "Graph.h"

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
        return source_ip_company.substr(0, last_digit);
    }

    Graph<string> create_graph_date_company(string fecha)
    {
        Graph<string> Grafo;
        map<string, int> ip_idx;
        bool finish = false;
        int idx = 0;
        string company_ip = this->company_ip();
        for (vector<Registration>::iterator it = All_Registrations.begin(); it != All_Registrations.end(); it++)
        {
            if (it->getDate() == fecha)
            {
                string source_ip = it->getSource_IP();
                if (source_ip != "-")
                {
                    if (ip_idx.find(source_ip) == ip_idx.end())
                    {
                        ip_idx.insert(pair<string, int>(source_ip, idx));
                        Grafo.add_node(source_ip);
                        idx++;
                    }

                    string destination_ip = it->getDestination_IP();
                    size_t last_digit = destination_ip.find_last_of(".\\");
                    if (company_ip == destination_ip.substr(0, last_digit))
                    {
                        if (ip_idx.find(destination_ip) == ip_idx.end())
                        {
                            ip_idx.insert(pair<string, int>(destination_ip, idx));
                            Grafo.add_node(destination_ip);
                            idx++;
                        }

                        Grafo.add_edge(ip_idx[source_ip], ip_idx[destination_ip]);
                    }
                }
                finish = true;
            }
            else if (finish)
                break;
        }
        return Grafo;
    }

    Graph<string> create_graph_date_web(string fecha)
    {
        Graph<string> Grafo;
        map<string, int> ip_idx;
        bool finish = false;
        int idx = 0;
        string company_ip = this->company_ip();
        for (vector<Registration>::iterator it = All_Registrations.begin(); it != All_Registrations.end(); it++)
        {
            if (it->getDate() == fecha)
            {
                string source_ip = it->getSource_IP();
                if (source_ip != "-" )
                {
                    if (ip_idx.find(source_ip) == ip_idx.end())
                    {
                        ip_idx.insert(pair<string, int>(source_ip, idx));
                        Grafo.add_node(source_ip);
                        idx++;
                    }

                    string destination_ip = it->getDestination_IP();
                    if (it->getDestination_Port() == "443")
                    {
                        if (ip_idx.find(destination_ip) == ip_idx.end())
                        {
                            ip_idx.insert(pair<string, int>(destination_ip, idx));
                            Grafo.add_node(destination_ip);
                            idx++;
                        }

                        Grafo.add_edge(ip_idx[source_ip], ip_idx[destination_ip]);
                    }
                }
                finish = true;
            }
            else if (finish)
                break;
        }
        return Grafo;
    }


};