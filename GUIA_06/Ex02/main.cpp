#include <iostream>
#include <fstream>
#include <cstdlib> // Para std::system
using namespace std;

struct Tdato {
    int b;
    char s[100];
};

int main() {
    int x = 0; // Inicializamos x
    double f = 0.0; // Inicialimos f
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; // Agregamos valores al arreglo
    char nombre[] = "Ejercicios ficheros binarios"; // Definimos una frase en un arreglo de caracteres
    Tdato p = {0, ""}; // Inicializamos la estructura (Tdato)
    
    ifstream f1;
    ofstream f2;

    // Imprimir el directorio de trabajo actual para depuración
    cout << "Directorio de trabajo actual: ";
    system("pwd");

    // Verificar si entrada.dat existe y sus permisos
    cout << "Verificando existencia y permisos del archivo entrada.dat" << endl;
    ifstream testFile("entrada.dat");
    if (!testFile) {
        cerr << "El fichero entrada.dat no existe o no se puede leer." << endl;
        return 1;
    } else {
        cout << "El fichero entrada.dat existe y es accesible." << endl;
    }
    testFile.close();
   
    // Intentar abrir los archivos
    cout << "Intentando abrir el archivo entrada.dat para lectura." << endl;
    f1.open("entrada.dat", ios::binary);
    if (!f1.is_open()) {
        cerr << "Error al abrir el fichero entrada.dat" << endl;
        return 1;
    } else {
        cout << "Archivo entrada.dat abierto exitosamente para lectura." << endl;
    }

    cout << "Intentando abrir el archivo salida.dat para escritura." << endl;
    f2.open("salida.dat", ios::binary);
    if (!f2.is_open()) {
        cerr << "Error al abrir el fichero salida.dat" << endl;
        return 1;
    } else {
        cout << "Archivo salida.dat abierto exitosamente para escritura." << endl;
    }
   
    // Escribimos datos en el fichero salida.dat
    f2.write(reinterpret_cast<const char*>(&x), sizeof(x));
    f2.write(reinterpret_cast<const char*>(&f), sizeof(f));
    f2.write(reinterpret_cast<const char*>(a), 5 * sizeof(a[0])); // Solo las primeras 5 posiciones de a
    f2.write(nombre, 10); // Solo los primeros 10 caracteres de nombre
    f2.write(reinterpret_cast<const char*>(&p), sizeof(p));
   
    f2.close();
    cout << "Datos escritos en el archivo salida.dat." << endl;
   
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
    cout << "Lectura de datos desde el archivo entrada.dat completada." << endl;
   
    return 0;
}
