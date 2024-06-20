#include <iostream>
#include <string>
using namespace std;

struct Persona
{
    string nombre;
    string apellido;
    int edad;
};


int main()
{
    Persona pers;
    cout << "Ingrese su nombre: " << endl;
    cin >> pers.nombre;

    cout << "Ingrese su apellido: " << endl;
    cin >> pers.apellido;

    cout << "Ingrese su edad: " << endl;
    cin >> pers.edad;

    cout << pers.nombre << ", " << pers.apellido << ", " << pers.edad << endl;


    return 0;
}
