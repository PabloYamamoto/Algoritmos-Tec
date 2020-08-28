#include <iostream>
#include <string>

using namespace std;

int Invierte(int num)
{
    if (num < 10)
        return num;
    string str = to_string(num);
    return (int)str.front()-48 + Invierte(stoi(str.substr(1)))*10;
}

int main()
{
    int ans, num;
    num = 1234;
    cout << Invierte(num) << endl; 
}