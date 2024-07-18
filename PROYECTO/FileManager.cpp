#include "FileManager.h"
#include <fstream>
#include <stdexcept>

void guardarRegistrosEnFichero(const vector<Registro> &registros)
{
    ofstream outFile("registros.txt");
    if (!outFile)
    {
        throw FileException("Error al abrir el fichero para guardar registros");
    }

    for (const auto &r : registros)
    {
        outFile << r.codigo << ',' << r.nombre << ',' << r.autor << ',' << r.anioPublicacion << ',' << r.precio << '\n';
    }

    outFile.close();
    cout << "Registros guardados exitosamente en registros.txt!" << endl;
}

void cargarRegistrosDesdeFichero(vector<Registro> &registros)
{
    cout<<"gaaa"<<endl;
    ifstream inFile("registros.txt");
    if (!inFile)
    {
        throw FileException("Error al abrir el fichero para cargar registros");
    }

    registros.clear();
    Registro r;
    char delim;
    while (inFile >> r.codigo >> delim >> r.nombre >> delim >> r.autor >> delim >> r.anioPublicacion >> delim >> r.precio)
    {
        registros.push_back(r);
    }

    inFile.close();
    cout << "Registros cargados exitosamente desde registros.txt!" << endl;
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
