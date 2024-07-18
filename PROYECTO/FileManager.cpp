#include "FileManager.h"
#include <fstream>
#include <stdexcept>

void guardarRegistrosEnFichero(const vector<Registro> &registros)
{
    ofstream outFile("registros.dat", ios::binary);
    if (!outFile)
    {
        throw FileException("Error al abrir el fichero para guardar registros");
    }

    for (const auto &r : registros)
    {
        outFile.write(reinterpret_cast<const char *>(&r), sizeof(Registro));
    }

    outFile.close();
    cout << "Registros guardados exitosamente!" << endl;
}

void cargarRegistrosDesdeFichero(vector<Registro> &registros)
{
    ifstream inFile("registros.dat", ios::binary);
    if (!inFile)
    {
        throw FileException("Error al abrir el fichero para cargar registros");
    }

    registros.clear();
    Registro r;
    while (inFile.read(reinterpret_cast<char *>(&r), sizeof(Registro)))
    {
        registros.push_back(r);
    }

    inFile.close();
    cout << "Registros cargados exitosamente!" << endl;
}

void guardarUsuariosEnFichero(const vector<Usuario> &usuarios)
{
    ofstream outFile("usuarios.dat", ios::binary);
    if (!outFile)
    {
        throw FileException("Error al abrir el fichero para guardar usuarios");
    }

    for (const auto &u : usuarios)
    {
        outFile.write(reinterpret_cast<const char *>(&u), sizeof(Usuario));
    }

    outFile.close();
    cout << "Usuarios guardados exitosamente!" << endl;
}

void cargarUsuariosDesdeFichero(vector<Usuario> &usuarios)
{
    ifstream inFile("usuarios.dat", ios::binary);
    if (!inFile)
    {
        throw FileException("Error al abrir el fichero para cargar usuarios");
    }

    usuarios.clear();
    Usuario u;
    while (inFile.read(reinterpret_cast<char *>(&u), sizeof(Usuario)))
    {
        usuarios.push_back(u);
    }

    inFile.close();
    cout << "Usuarios cargados exitosamente!" << endl;
}

void guardarPrestamosEnFichero(const vector<Prestamo> &prestamos)
{
    ofstream outFile("prestamos.dat", ios::binary);
    if (!outFile)
    {
        throw FileException("Error al abrir el fichero para guardar préstamos");
    }

    for (const auto &p : prestamos)
    {
        outFile.write(reinterpret_cast<const char *>(&p), sizeof(Prestamo));
    }

    outFile.close();
    cout << "Préstamos guardados exitosamente!" << endl;
}

void cargarPrestamosDesdeFichero(vector<Prestamo> &prestamos)
{
    ifstream inFile("prestamos.dat", ios::binary);
    if (!inFile)
    {
        throw FileException("Error al abrir el fichero para cargar préstamos");
    }

    prestamos.clear();
    Prestamo p;
    while (inFile.read(reinterpret_cast<char *>(&p), sizeof(Prestamo)))
    {
        prestamos.push_back(p);
    }

    inFile.close();
    cout << "Préstamos cargados exitosamente!" << endl;
}
