#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "Registro.h"
#include "Usuario.h"
#include "Prestamo.h"
#include "Exceptions.h"

void guardarRegistrosEnFichero(const vector<Registro> &registros);
void cargarRegistrosDesdeFichero(vector<Registro> &registros);

void guardarUsuariosEnFichero(const vector<Usuario> &usuarios);
void cargarUsuariosDesdeFichero(vector<Usuario> &usuarios);

void guardarPrestamosEnFichero(const vector<Prestamo> &prestamos);
void cargarPrestamosDesdeFichero(vector<Prestamo> &prestamos);

#endif // FILEMANAGER_H
