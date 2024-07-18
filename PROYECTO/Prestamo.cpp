
#include "algorithm"
#include "Prestamo.h"

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void establecerPrestamo(vector<Prestamo> &prestamos)
{
    Prestamo p;
    cout << "\nIngrese el código del registro: ";
    cin >> p.codigoRegistro;
    cout << "Ingrese el DNI del usuario: ";
    cin >> p.dniUsuario;
    cout << "Ingrese la fecha de préstamo (YYYY-MM-DD): ";
    cin.ignore();
    getline(cin, p.fechaPrestamo);
    p.fechaDevolucion = "No devuelto";

    prestamos.push_back(p);
    cout << "Préstamo establecido exitosamente!" << endl;
}

void establecerDevolucion(vector<Prestamo> &prestamos)
{
    int codigoRegistro;
    cout << "\nIngrese el código del registro del préstamo a devolver: ";
    cin >> codigoRegistro;

    auto it = find_if(prestamos.begin(), prestamos.end(), [&](Prestamo &p)
                      { return p.codigoRegistro == codigoRegistro; });
    if (it != prestamos.end())
    {
        cout << "Ingrese la fecha de devolución (YYYY-MM-DD): ";
        cin.ignore();
        getline(cin, it->fechaDevolucion);
        cout << "Devolución establecida exitosamente!" << endl;
    }
    else
    {
        cout << "Préstamo no encontrado!" << endl;
    }
}

void listarPrestamos(const vector<Prestamo> &prestamos)
{
    const int anchoCodigo = 15;
    const int anchoDNI = 12;
    const int anchoFechaPrestamo = 15;
    const int anchoFechaDevolucion = 17;

    // Imprimir cabecera
    cout << "\n" << endl;
    cout << left << setw(anchoCodigo) << "Código Registro"
         << left << setw(anchoDNI) << "DNI Usuario"
         << left << setw(anchoFechaPrestamo) << "Fecha Préstamo"
         << left << setw(anchoFechaDevolucion) << "Fecha Devolución" << endl;

    // Imprimir línea de separación
    cout << string(anchoCodigo + anchoDNI + anchoFechaPrestamo + anchoFechaDevolucion, '-') << endl;

    // Imprimir préstamos
    for (const auto &p : prestamos)
    {
        cout << left << setw(anchoCodigo) << p.codigoRegistro
             << left << setw(anchoDNI) << p.dniUsuario
             << left << setw(anchoFechaPrestamo) << p.fechaPrestamo
             << left << setw(anchoFechaDevolucion) << (p.fechaDevolucion.empty() ? "No devuelto" : p.fechaDevolucion) << endl;
    }
    cout << string(anchoCodigo + anchoDNI + anchoFechaPrestamo + anchoFechaDevolucion, '-') << endl;
    cout << "" << endl;
}
