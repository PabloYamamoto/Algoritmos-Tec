/*
Archivo main donde respoderemos las preguntas principales de este avance del reto
Pablo Yamamoto - A01022382 
Santiago Kohn - A01029109
Fecha de creación - 3/10/2020
Fecha de última modificación - 
*/

#include "ConexionesComputadora.h"
#include <map>

int main()
{
    string file_name = "nuevo7.csv";
    DataBase <Registration>DB(file_name, ',');

    vector<Registration> dominios; // Agregar dominios que no pertenezcan al dominio reto.com.
   
    map<string, ConexionesComputadora<Registration>> dic;

    vector<Registration> source_host; // Agregar computadoras que no pertenezacan a server.reto.com o dhcp

    for(auto registration : DB.All_Registrations)
    {
        

        string dom_host = registration.getSource_Hostname();
        if(dom_host != "server.reto.com" and dom_host != "-")
        {
            source_host.push_back(registration); 
        }

        string dom = registration.getSource_Hostname(); 
        size_t first_point = dom.find_first_of(".\\");
        string new_dom = dom.substr(first_point+1, dom.length()-1);
        if(new_dom != "reto.com")
        {
            dominios.push_back(registration);
            continue; 
        }

        string ip = registration.getSource_IP(); 
        map<string, ConexionesComputadora<Registration>>::iterator it = dic.find(ip);
        if (it == dic.end() and ip != "-")
        {
            ConexionesComputadora<Registration> Prueba (ip, dom, &DB); 
            dic.insert(pair<string, ConexionesComputadora<Registration>> (ip, Prueba)); 
        }


        


    }



    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 1" << endl; 
    cout << "Haciendo un filtro de dominions fuente, no encontramos ningún dominio anómalo" << endl;
    cout << "Fuentes anómalas: " << dominios.size() << endl; 
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << endl; 
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 2" << endl; 
    for(auto ips : dominios)
    {
        cout << "Ip del dominio: " << ips.getSource_Hostname() << " --- " << ips.getSource_IP() << endl; 
    }
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << endl; 

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 3" << endl; 
    
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << endl; 

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 4" << endl; 
    cout << "Tamaño del vector sin server.reto.com o servidor dhcp: " << source_host.size() << endl; 
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << endl; 

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 5" << endl; 
    
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << endl; 

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 6" << endl; 
    
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << endl; 

    // cout << "Tamaño mapa: " << dic.size() << endl; 
    // for (map<string,ConexionesComputadora<Registration>>::iterator it = dic.begin(); it != dic.end(); ++it)
    // {
    //     cout << it->first << endl; 
    // }

    return 100; //Regresamos un 100 porque eso queremos sacar en esta entrega profe
}