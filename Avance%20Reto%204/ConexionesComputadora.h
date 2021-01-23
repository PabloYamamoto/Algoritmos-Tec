/*
Clase de ConexionesComputadora para definir cada ip de la computadora y sus conexiones. 
Pablo Yamamoto - A01022382 
Santiago Kohn - A01029109
Fecha de creación - 12/10/2020
Fecha de última modificación - 6/10/2020
*/

#include <queue>
#include <stack>
#include "DataBase.h"

using namespace std;

template <class T>
#pragma once
class ConexionesComputadora
{
    string ip, hostname;
    stack<T> conexionesEntrantes;
    queue<T> conexionesSalientes;

public:
    ConexionesComputadora(){};
    ConexionesComputadora(string ip, string hostname, DataBase<T> *vector) : ip{ip}, hostname{hostname}
    {
        for (int i = 0; i < vector->All_Registrations.size(); i++)
        {
            if (vector->All_Registrations.at(i).getDestination_IP() == ip)
                conexionesEntrantes.push(vector->All_Registrations.at(i) /*.getSource_IP()*/);
            if (vector->All_Registrations.at(i).getSource_IP() == ip)
                conexionesSalientes.push(vector->All_Registrations.at(i) /*.getDestination_IP()*/);
        }
    }
    ~ConexionesComputadora() {}

    string get_ip() { return ip; }
    string get_hostname() { return hostname; }
    stack<T> *get_conexionesEntrantes() { return &conexionesEntrantes; }
    queue<T> *get_conexionesSalientes() { return &conexionesSalientes; }
};
