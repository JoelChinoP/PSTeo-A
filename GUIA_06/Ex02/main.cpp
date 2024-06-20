#include <iostream>
#include <fstream>
using namespace std;

struct Tdato {
    int b;
    char s[100];
};

int main() {
    int x = 0; // Inicializamos x
    double f = 0.0; // Inicialimos f
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    char nombre[] = "Ejercicios ficheros binarios";
    Tdato p = {0, ""}; // Inicialimos la estructura (Tdato)
    
    ifstream f1;
    ofstream f2;
   
    f1.open("entrada.dat", ios::binary);
    f2.open("salida.dat", ios::binary);
   
    if (!f1.is_open() || !f2.is_open()) {
        cerr << "Error al abrir los ficheros" << endl;
        return 1;
    }
   
    // Escribimos datos en el fichero salida.dat
    f2.write(reinterpret_cast<const char*>(&x), sizeof(x));
    f2.write(reinterpret_cast<const char*>(&f), sizeof(f));
    f2.write(reinterpret_cast<const char*>(a), 5 * sizeof(a[0])); // Solo las primeras 5 posiciones de a
    f2.write(nombre, 10); // Solo los primeros 10 caracteres de nombre
    f2.write(reinterpret_cast<const char*>(&p), sizeof(p));
   
    f2.close();
   
    // Leer datos del fichero entrada.dat
    f1.read(reinterpret_cast<char*>(&x), sizeof(x));
    if (f1.gcount() != sizeof(x)) cerr << "Error al leer x" << endl;

    f1.read(reinterpret_cast<char*>(&f), sizeof(f));
    if (f1.gcount() != sizeof(f)) cerr << "Error al leer f" << endl;

    f1.read(reinterpret_cast<char*>(a), 5 * sizeof(a[0]));
    if (f1.gcount() != 5 * sizeof(a[0])) cerr << "Error al leer a" << endl;

    f1.read(nombre, 10);
    if (f1.gcount() != 10) cerr << "Error al leer nombre" << endl;
    nombre[10] = '\0';  // Añadir el carácter nulo al final para terminar la cadena

    f1.read(reinterpret_cast<char*>(&p), sizeof(p));
    if (f1.gcount() != sizeof(p)) cerr << "Error al leer p" << endl;
   
    f1.close();
   
    return 0;
}
