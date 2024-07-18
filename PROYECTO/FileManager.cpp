#include "FileManager.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;

void guardarRegistrosEnFichero(const vector<Registro> &registros)
{
    ofstream outFile("registros.txt", ios::app); // Abre el archivo en modo append
    if (!outFile)
    {
        throw FileException("\nError al abrir el fichero para guardar registros");
    }

    for (const auto &r : registros)
    {
        outFile << r.codigo << ',' << r.nombre << ',' << r.autor << ',' << r.anioPublicacion << ',' << r.precio << '\n';
    }

    outFile.close();
    cout << "\nRegistros añadidos exitosamente" << endl;
}

void cargarRegistrosDesdeFichero(vector<Registro> &registros)
{
    cout << "\nIniciando carga de registros..." << endl;
    ifstream inFile("registros.txt");
    if (!inFile)
    {
        throw FileException("Error al abrir el fichero para cargar registros");
    }

    registros.clear();
    string line;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        Registro r;
        string temp;

        getline(ss, temp, ',');
        r.codigo = stoi(temp);
        getline(ss, r.nombre, ',');
        getline(ss, r.autor, ',');
        getline(ss, temp, ',');
        r.anioPublicacion = stoi(temp);
        getline(ss, temp, ',');
        r.precio = stod(temp);

        registros.push_back(r);
    }

    inFile.close();
    cout << "Registros cargados exitosamente..." << endl;
}
void guardarUsuariosEnFichero(const vector<Usuario> &usuarios)
{
    ofstream outFile("usuarios.txt");
    if (!outFile)
    {
        throw FileException("Error al abrir el fichero para guardar usuarios");
    }

    for (const auto &u : usuarios)
    {
        outFile << u.dni << ',' << u.nombre << ',' << u.email << ',' << u.telefono << '\n';
    }

    outFile.close();
    cout << "Usuarios guardados exitosamente en usuarios.txt!" << endl;
}

void cargarUsuariosDesdeFichero(vector<Usuario> &usuarios)
{
    ifstream inFile("usuarios.txt");
    if (!inFile)
    {
        throw FileException("Error al abrir el fichero para cargar usuarios");
    }

    usuarios.clear();
    Usuario u;
    char delim;
    while (inFile >> u.dni >> delim >> u.nombre >> delim >> u.email >> delim >> u.telefono)
    {
        usuarios.push_back(u);
    }

    inFile.close();
    cout << "Usuarios cargados exitosamente desde usuarios.txt!" << endl;
}
void guardarPrestamosEnFichero(const vector<Prestamo> &prestamos)
{
    ofstream outFile("prestamos.txt");
    if (!outFile)
    {
        throw FileException("Error al abrir el fichero para guardar préstamos");
    }

    for (const auto &p : prestamos)
    {
        outFile << p.codigoRegistro << ',' << p.dniUsuario << ',' << p.fechaPrestamo << ',' << p.fechaDevolucion << '\n';
    }

    outFile.close();
    cout << "Préstamos guardados exitosamente en prestamos.txt!" << endl;
}

void cargarPrestamosDesdeFichero(vector<Prestamo> &prestamos)
{
    ifstream inFile("prestamos.txt");
    if (!inFile)
    {
        throw FileException("Error al abrir el fichero para cargar préstamos");
    }

    prestamos.clear();
    Prestamo p;
    char delim;
    while (inFile >> p.codigoRegistro >> delim >> p.dniUsuario >> delim >> p.fechaPrestamo >> delim >> p.fechaDevolucion)
    {
        prestamos.push_back(p);
    }

    inFile.close();
    cout << "Préstamos cargados exitosamente desde prestamos.txt!" << endl;
}
