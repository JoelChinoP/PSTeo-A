

#include "Prestamo.h"

void establecerPrestamo(vector<Prestamo> &prestamos)
{
    Prestamo p;
    cout << "Ingrese el código del registro: ";
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
    cout << "Ingrese el código del registro del préstamo a devolver: ";
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
    for (const auto &p : prestamos)
    {
        cout << "Código Registro: " << p.codigoRegistro << endl;
        cout << "DNI Usuario: " << p.dniUsuario << endl;
        cout << "Fecha Préstamo: " << p.fechaPrestamo << endl;
        cout << "Fecha Devolución: " << (p.fechaDevolucion.empty() ? "No devuelto" : p.fechaDevolucion) << endl;
        cout << "---------------------------" << endl;
    }
}
