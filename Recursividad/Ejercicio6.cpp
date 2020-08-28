#include <iostream>
#include <string>
using namespace std;

string InvierteString(string palabra)
{
    if (palabra.size() < 2)
        return palabra;
    return palabra.back() + InvierteString(palabra.substr(0,palabra.size()-1));
}

void palindromo(string palabra)
{
    string str = InvierteString(palabra);
    if (palabra == str)
        cout << palabra << " es un palindormo" << endl;
    else
        cout << palabra << " no es un palindormo" << endl;
}

int main()
{
    string str = "RECONOCER";
    string str2 = "ADA";
    string str3 = "ODA";
    string str4 = "HOLO";

    palindromo(str); 
    palindromo(str2); 
    palindromo(str3); 
    palindromo(str4); 


}