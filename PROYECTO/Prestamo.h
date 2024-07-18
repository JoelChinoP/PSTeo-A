#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Prestamo
{
    int codigoRegistro;
    int dniUsuario;
    string fechaPrestamo;
    string fechaDevolucion;
};

void establecerPrestamo(vector<Prestamo> &prestamos);
void establecerDevolucion(vector<Prestamo> &prestamos);
void listarPrestamos(const vector<Prestamo> &prestamos);

#endif // PRESTAMO_H