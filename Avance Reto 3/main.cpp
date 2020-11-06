/*
Archivo main donde respoderemos las preguntas principales de este avance del reto
Pablo Yamamoto - A01022382 
Santiago Kohn - A01029109
Fecha de creación - 3/10/2020
Fecha de última modificación - 
*/

#include "ConexionesComputadora.h"
#include <map>
#include <set>


int main()
{
    string file_name = "nuevo7.csv";
    DataBase <Registration>DB(file_name, ',');

    set<string> dominios; // Agregar dominios que no pertenezcan al dominio reto.com.
    set<string> dominiosreto; 
    map<string, ConexionesComputadora<Registration>> dic;

    set<string> dest_host; // Agregar computadoras que no pertenezacan a server.reto.com o dhcp
    vector<string> anormales = {"yduke2bmt3r1u7rzh6sg.net", "58j2kpx5vvrydowklljm.ru"}; 
    set<string> ips_raros; 

    for(auto registration : DB.All_Registrations)
    {
        

        string dom_SH = registration.getSource_Hostname(); 
        string dom_DH = registration.getDestination_Hostname(); 
        size_t first_pointSH = dom_SH.find_first_of(".\\");
        size_t first_pointDH = dom_DH.find_first_of(".\\");
        string new_domSH = dom_SH.substr(first_pointSH+1, dom_SH.length()-1);
        string new_domDH = dom_DH.substr(first_pointDH+1, dom_DH.length()-1);
        
        if(new_domDH != "reto.com")
        {
            dominios.insert(dom_DH); 
             
        }
        else
        {
            dominiosreto.insert(dom_DH); 
        }
        

        
        string ip = registration.getSource_IP();                                                // Punto número 2 - parte 1
        map<string, ConexionesComputadora<Registration>>::iterator it = dic.find(dom_SH);
        if (it == dic.end() and ip != "-")
        {
            ConexionesComputadora<Registration> Prueba (ip, dom_SH, &DB); 
            dic.insert(pair<string, ConexionesComputadora<Registration>> (dom_SH, Prueba)); 
        }


        string ip_2 = registration.getDestination_IP();                                                // Punto número 2 - parte 2
        map<string, ConexionesComputadora<Registration>>::iterator it2 = dic.find(dom_DH);
        if (it2 == dic.end() and ip_2 != "-")
        {
            ConexionesComputadora<Registration> Prueba2 (ip_2, dom_DH, &DB); 
            dic.insert(pair<string, ConexionesComputadora<Registration>> (dom_DH, Prueba2)); 
        }


        if(dom_DH == "yduke2bmt3r1u7rzh6sg.net" or dom_DH == "58j2kpx5vvrydowklljm.ru")
        {
            ips_raros.insert(registration.getDestination_IP()); 
        }


        if(dom_DH != "server.reto.com" and dom_DH != "-" and registration.getSource_Port() != "68" and registration.getDestination_Port() != "67")
        {
            dest_host.insert(ip_2); 
        }


    }


    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 1" << endl; 
    cout << endl; 
    cout << "Fuentes anómalas: " << anormales.size() << endl;
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << endl; 
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";

    cout << "Pregunta 2" << endl; 
    cout << endl; 
    cout << "Las Ips de las conexciones anormales son: " << endl; 
    for(auto ip : ips_raros)
    {
        cout << ip << endl; 
    }
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << endl; 
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";

    cout << "Pregunta 3" << endl; 
    cout << endl; 
    int cont = 0; 
   
    for(auto dom : dominiosreto)
    {
        int sizeconx = dic[dom].get_conexionesEntrantes()->size(); 
        if( sizeconx > 0)
        {
            cont++; 
            cout << "El dominio: " << dom << " tiene " << sizeconx << " conexiones entrantes" << endl; 
        }
        
    }
    cout << endl; 
    cout << "Cantidad computadoras: " << cont << endl; 
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << endl; 

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 4" << endl; 
    cout << endl; 
    for(auto ip : dest_host)
    {
        cout << ip << endl; 
    }
    cout << endl; 
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << endl; 

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 5" << endl; 
    cout << "En el documento" << endl; 
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << endl; 

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << "Pregunta 6" << endl; 
    cout << endl; 
    for(auto ip : dest_host)
    {
       for(set<string>::iterator it = ips_raros.begin(); it != ips_raros.end(); it++)
       {
           if(ip == *it)
           {
               cout << "Tuvo una conexión con " << *it << endl; 
           }
       }
    }
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-··-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·- \n";
    cout << endl; 

    

    return 100; //Regresamos un 100 porque eso queremos sacar en esta entrega profe
}