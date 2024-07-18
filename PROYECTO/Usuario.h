#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Usuario
{
    int dni;
    string nombre;
    string email;
    string telefono;
};

void agregarUsuario(vector<Usuario> &usuarios);
void eliminarUsuario(vector<Usuario> &usuarios);
void listarUsuarios(const vector<Usuario> &usuarios);

#endif // USUARIO_H
