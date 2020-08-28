#include <iostream>
using namespace std;

int Extra(int Chocolates, int Envoltura)
{
    if (Chocolates < Envoltura)
        return 0;
    int extra = Chocolates / Envoltura;
    return extra + Extra(extra + (Chocolates % Envoltura), Envoltura);
}

int Chocolates(int Dinero, int Precio, int Envoltura)
{
    int Chocolates = Dinero/Precio;
    return Chocolates + Extra(Chocolates, Envoltura);
}

int main()
{
    int Dinero, Precio, Envoltura;

    cout << "Dinero: ";
    cin >> Dinero;
    cout << "Precio: ";
    cin >> Precio;
    cout << "Envoltura: ";
    cin >> Envoltura;
    int Res = Chocolates(Dinero, Precio, Envoltura);
   
    cout << "Total Chocolates: " << Res << endl;
    return 0;
}