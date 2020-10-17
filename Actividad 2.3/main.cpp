/*
Clase de ConexionesComputadora para definir cada ip de la computadora y sus conexiones. 
Pablo Yamamoto - A01022382 
Santiago Kohn - A01029109
Fecha de creación - 12/10/2020
Fecha de última modificación - 13/10/2020
*/

#include "ConexionesComputadora.h"

using namespace std;

int main()
{
    string file_name = "equipo7.csv";
    DataBase <Registration>DB(file_name, ',');
    int num;
    bool it = true;
    do{
        cout << "Ingrese un numero entre el 1 y 150 (13 aparece en el documento): ";
        cin >> num;
        if (num > 0 && num < 151)
            it = false;
        else
            cout << "El numero escogido esta fuera del rango, intentelo de nuevo." << endl;
    }while(it);

    string ip_address = DB.company_ip()+to_string(num);
    int i = 0;
    string name;

    while (i != DB.All_Registrations.size())
    {
        if (DB.All_Registrations.at(i).getSource_IP() == ip_address)
        {
            name = DB.All_Registrations.at(i).getSource_Hostname();
            break;
        }
        i++;
    }
    ConexionesComputadora <Registration> computadora(ip_address, name, &DB);

    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";
    cout << "La conexión que usaremos es: " << ip_address << endl << endl;

    string ultima = computadora.get_conexionesEntrantes()->top();
    cout << "La última conexión que recibió fue de: " <<  ultima << endl;

    size_t last_digit = ultima.find_last_of(".\\");
    if (ultima.substr(0, last_digit) == ip_address.substr(0, last_digit))
        cout << "La conexión es Interna." << endl << endl;
    else
        cout << "La conexión es Externa." << endl << endl;
    
    cout << "Esta computadora tiene " << computadora.get_conexionesEntrantes()->size() << " conexiones entrantes." << endl;
    cout << "Esta computadora tiene " << computadora.get_conexionesSalientes()->size() << " conexiones salientes." << endl;
    
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";

    cout << "EXTRA:" << endl << endl;
    int num2;
    cout << "Ingrese el numero de conexiones seguidas que quiere revisar: ";
    cin >> num2;
    if (computadora.preguntaExtra(num2))
        cout << "Si tiene " << num2 << " conexiones seguidas a un mismo sitio web." << endl;
    else
        cout << "No tiene " << num2 << " conexiones seguidas a un mismo sitio web." << endl;
    
    cout << "·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-· \n";
}