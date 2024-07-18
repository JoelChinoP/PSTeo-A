#include <iostream>
#include "Registro.h"
#include "Usuario.h"
#include "Prestamo.h"
#include "FileManager.h"
#include "Exceptions.h"

using namespace std;

void showMenu() {
    cout << "\n1. Agregar Registro" << endl;
    cout << "2. Eliminar Registro" << endl;
    cout << "3. Buscar Registro" << endl;
    cout << "4. Actualizar Registro" << endl;
    cout << "5. Listar Registros" << endl;
    cout << "6. Guardar Registros en Fichero" << endl;
    cout << "7. Cargar Registros desde Fichero" << endl;
    cout << "8. Agregar Usuario" << endl;
    cout << "9. Eliminar Usuario" << endl;
    cout << "10. Listar Usuarios" << endl;
    cout << "11. Establecer Préstamo" << endl;
    cout << "12. Establecer Devolución" << endl;
    cout << "13. Listar Préstamos" << endl;
    cout << "0. Salir" << endl;
}

int main() {
    vector<Registro> registros;
    vector<Usuario> usuarios;
    vector<Prestamo> prestamos;

    int choice;
    do {
        showMenu();
        cout << "\nIngrese una opción: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    agregarRegistro(registros);
                    break;
                case 2:
                    eliminarRegistro(registros);
                    break;
                case 3:
                    buscarRegistro(registros);
                    break;
                case 4:
                    actualizarRegistro(registros);
                    break;
                case 5:
                    listarRegistros(registros);
                    break;
                case 6:
                    guardarRegistrosEnFichero(registros);
                    break;
                case 7:
                    cargarRegistrosDesdeFichero(registros);
                    break;
                case 8:
                    agregarUsuario(usuarios);
                    break;
                case 9:
                    eliminarUsuario(usuarios);
                    break;
                case 10:
                    listarUsuarios(usuarios);
                    break;
                case 11:
                    establecerPrestamo(prestamos);
                    break;
                case 12:
                    establecerDevolucion(prestamos);
                    break;
                case 13:
                    listarPrestamos(prestamos);
                    break;
                case 0:
                    cout << "\nSaliendo..." << endl;
                    break;
                default:
                    cout << "\nOpción no válida" << endl;
                    break;
            }
        } catch (const FileException& e) {
            cerr << "Error de archivo: " << e.what() << endl;
        } catch (const std::exception& e) {
            cerr << "Error: " << e.what() << endl;
        }

    } while (choice != 0);

    return 0;
}
