#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Registro
{
    int codigo;
    string nombre;
    string autor;
    int anioPublicacion;
    double precio;
};

void agregarRegistro(vector<Registro> &registros);
void eliminarRegistro(vector<Registro> &registros);
void buscarRegistro(const vector<Registro> &registros);
void actualizarRegistro(vector<Registro> &registros);
void listarRegistros(const vector<Registro> &registros);

#endif // REGISTRO_H
