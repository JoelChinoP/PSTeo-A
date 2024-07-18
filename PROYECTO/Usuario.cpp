#include "Usuario.h"
#include "algorithm"

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void agregarUsuario(vector<Usuario> &usuarios)
{
    Usuario u;
    cout << "\nIngrese el DNI: ";
    cin >> u.dni;
    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline(cin, u.nombre);
    cout << "Ingrese el email: ";
    getline(cin, u.email);
    cout << "Ingrese el teléfono: ";
    getline(cin, u.telefono);

    usuarios.push_back(u);
    cout << "Usuario agregado exitosamente!" << endl;
}

void eliminarUsuario(vector<Usuario> &usuarios)
{
    int dni;
    cout << "\nIngrese el DNI del usuario a eliminar: ";
    cin >> dni;

    auto it = remove_if(usuarios.begin(), usuarios.end(), [&](Usuario &u)
                        { return u.dni == dni; });
    if (it != usuarios.end())
    {
        usuarios.erase(it, usuarios.end());
        cout << "Usuario eliminado exitosamente!" << endl;
    }
    else
    {
        cout << "Usuario no encontrado!" << endl;
    }
}

void listarUsuarios(const vector<Usuario> &usuarios)
{
    const int anchoDNI = 15;
    const int anchoNombre = 25;
    const int anchoEmail = 30;
    const int anchoTelefono = 15;

    // Imprimir cabecera
    cout << "\n" << endl;
    cout << left << setw(anchoDNI) << "DNI"
         << left << setw(anchoNombre) << "Nombre"
         << left << setw(anchoEmail) << "Email"
         << left << setw(anchoTelefono) << "Teléfono" << endl;

    // Imprimir línea de separación
    cout << string(anchoDNI + anchoNombre + anchoEmail + anchoTelefono, '-') << endl;

    // Imprimir usuarios
    for (const auto &u : usuarios)
    {
        cout << left << setw(anchoDNI) << u.dni
             << left << setw(anchoNombre) << u.nombre
             << left << setw(anchoEmail) << u.email
             << left << setw(anchoTelefono) << u.telefono << endl;
    }
    cout << string(anchoDNI + anchoNombre + anchoEmail + anchoTelefono, '-') << endl;
    cout << "" << endl;
}
