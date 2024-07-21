#include "Usuario.h"
#include "algorithm"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

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
    cout << "\n"
         << endl;
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

vector<Usuario> cargarDatosUsuario()
{
    vector<Usuario> usuarios;
    ifstream archivo("usuarios.txt");
    string linea;

    while (getline(archivo, linea))
    {
        stringstream ss(linea);
        string dni, nombre, email, telefono;

        getline(ss, dni, ',');
        getline(ss, nombre, ',');
        getline(ss, email, ',');
        getline(ss, telefono, ',');

        Usuario u;
        u.dni = stoi(dni);
        u.nombre = nombre;
        u.email = email;
        u.telefono = telefono;

        usuarios.push_back(u);
    }
    archivo.close();
    return usuarios;
}

void escribirDatosUsuario(const vector<Usuario> &usuarios)
{
    ofstream archivo("usuarios.txt");
    for (const auto &u : usuarios)
    {
        archivo << u.dni << "," << u.nombre << "," << u.email << "," << u.telefono << endl;
    }
    archivo.close();
}
