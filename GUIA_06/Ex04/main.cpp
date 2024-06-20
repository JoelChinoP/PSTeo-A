#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void mostrarArchivoPorPantalla(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);  // Abrir el archivo

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    string linea;
    int contadorLineas = 0;

    // Leer y mostrar el archivo línea por línea
    while (getline(archivo, linea)) {
        cout << linea << endl;
        ++contadorLineas;

        // Pausa cada 25 líneas
        if (contadorLineas % 25 == 0) {
            cout << "Presiona Enter para mostrar las siguientes 25 líneas..." << endl;
            cin.get();  // Esperar a que el usuario presione Enter
        }
    }

    archivo.close();  // Cerrar el archivo al finalizar
}

int main() {
    string nombreArchivo;

    // Pedir al usuario el nombre del archivo
    cout << "Ingrese el nombre del archivo: ";
    getline(cin, nombreArchivo);

    // Mostrar el contenido del archivo
    mostrarArchivoPorPantalla(nombreArchivo);

    return 0;
}
