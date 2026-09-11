using namespace std;

#include <string>
#include <iostream>

int main() 
{
    string palabra;
    int contador = 0;
    cin >> palabra;
    for (int i = 0; i < palabra.length(); i++)
    {
        if (contador == 0 && palabra.at(i)=='T')
        {
            contador++;
        }
        if (contador == 1 && palabra.at(i)=='A'){
            contador++;
        }
        if (contador == 2 && palabra.at(i)=='P'){
            contador++;
        }
        if (contador == 3){
            cout << 'S';
            return 0;
        }
    }
    cout << 'N';
    return 0;
}