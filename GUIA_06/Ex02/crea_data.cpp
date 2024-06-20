#include <iostream>
#include <fstream>
using namespace std;

struct Tdato {
    int b;
    char s[100];
};

int main() {
    // Datos a escribir en el archivo
    int x = 42;
    double f = 3.14;
    int a[5] = {1, 2, 3, 4, 5};
    char nombre[] = "Ejercicios ficheros binarios";
    Tdato p = {123, "Estructura de datos"};

    ofstream outFile("entrada.dat", ios::binary);

    if (!outFile) {
        cerr << "Error al crear el archivo entrada.dat" << endl;
        return 1;
    }

    // Escribir los datos en el archivo binario
    outFile.write(reinterpret_cast<const char*>(&x), sizeof(x));
    outFile.write(reinterpret_cast<const char*>(&f), sizeof(f));
    outFile.write(reinterpret_cast<const char*>(a), 5 * sizeof(a[0])); // Solo las primeras 5 posiciones de a
    outFile.write(nombre, 10); // Solo los primeros 10 caracteres de nombre
    outFile.write(reinterpret_cast<const char*>(&p), sizeof(p));

    outFile.close();

    cout << "Archivo entrada.dat creado y datos escritos exitosamente." << endl;

    return 0;
}
