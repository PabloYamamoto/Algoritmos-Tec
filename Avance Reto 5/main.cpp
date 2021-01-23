/*
main para responder las preguntas del reto
Pablo Yamamoto - A01022382 
Santiago Kohn - A01029109
Fecha de creación - 23/11/2020
Fecha de última modificación - 23/11/2020
*/

#include "ConexionesComputadora.h"
#include <map>
#include <set>

int main()
{

    string file_name = "nuevo7.csv";
    DataBase<Registration> DB(file_name, ',');
    cout << "Loaded \n";

    vector<Graph<string>> Graphs_per_day_company;
    vector<Graph<string>> Graphs_per_day_web;
    set<string> fechas;

    for (vector<Registration>::iterator it = DB.All_Registrations.begin(); it != DB.All_Registrations.end(); it++)
    {
        fechas.insert(it->getDate());
    }
    fechas.erase("");
    // int index = 1;
    // // for (auto a : fechas)
    // // {
    // //     cout << "Fecha número: " << index << " - " << a <<endl;
    // //     index++;
    // // }
    // cout << endl;
    for (set<string>::iterator it = fechas.begin(); it != fechas.end(); it++)
    {
        Graphs_per_day_company.push_back(DB.create_graph_date_company(*it));
    }
    for (set<string>::iterator it = fechas.begin(); it != fechas.end(); it++)
    {
        Graphs_per_day_web.push_back(DB.create_graph_date_web(*it));
    }
    // cout << "grafos" << endl;
    // cout << fechas.size() << endl;
    // cout << Graphs_per_day_company.size() << endl;
    // for (vector<Graph<string>>::iterator it = Graphs_per_day_company.begin(); it != Graphs_per_day_company.end(); it++)
    // {
    //     cout << endl;
    //     it->print_edges();
    //     cout << endl;
    // }
    string A;
    cout << "Ingresa una ip de la compañía: (10.219.19.(...)): ";
    cin >> A;
    A = DB.company_ip() + "." + A;
    cout << A << endl;

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 1" << endl;
    int i = 0;
    bool mayor = true;
    for (set<string>::iterator it = fechas.begin(); it != fechas.end(); it++)
    {
        cout << "Fecha: " << *it << endl;
        cout << Graphs_per_day_company[i].count_edges(A) << endl;
        mayor *= Graphs_per_day_company[i].compare_edges(A);
        i++;
    }
    if (mayor)
        cout << "La ip " << A << " si es la ip con mas conexiones a computadoras de la empresa en todas las fechas." << endl;
    else
        cout << "La ip " << A << " no es la ip con mas conexiones a computadoras de la empresa en todas las fechas." << endl;
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 2" << endl;
    int j = 0;
    for (set<string>::iterator it = fechas.begin(); it != fechas.end(); it++)
    {
        cout << "Fecha: " << *it << endl;
        cout << Graphs_per_day_company[j].count_edges_per_val(A) << endl;
        j++;
    }
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";

    string B;
    cout << "Ingresa una ip de la compañía anomala: (53.107.42.102 y 201.26.102.115): ";
    cin >> B;

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 3" << endl;
    int k = 0;
    for (set<string>::iterator it = fechas.begin(); it != fechas.end(); it++)
    {
        cout << "Fecha: " << *it << endl;
        cout << Graphs_per_day_web[k].count_edges_per_val(B) << endl;
        k++;
    }
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";

    string C;
    cout << "Ingresa una ip de la compañía con cantidad anomala de conexiones: (30.187.216.38 - play.google.com): ";
    cin >> C;

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 4" << endl;
    int l = 0;
    for (set<string>::iterator it = fechas.begin(); it != fechas.end(); it++)
    {
        cout << "Fecha: " << *it << endl;
        cout << Graphs_per_day_web[l].count_edges_per_val(C) << endl;
        l++;
    }
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";

}
