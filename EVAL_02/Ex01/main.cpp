#include <iostream>
#include <string>
using namespace std;

// Definición de la estructura Alumno
struct Alumno {
    string nombre;
    string codigo;
    int edad;
    int telefono;
    int ordenLista;
};

// Función para buscar un alumno por código
void buscarPorCodigo(Alumno alumnos[], int tamano, string codigo) {
    bool encontrado = false;
    for (int i = 0; i < tamano; i++) {
        if (alumnos[i].codigo == codigo) {
            cout << "Alumno encontrado: " << alumnos[i].nombre << ", Código: " << alumnos[i].codigo 
                 << ", Edad: " << alumnos[i].edad << ", Teléfono: " << alumnos[i].telefono 
                 << ", Orden en lista: " << alumnos[i].ordenLista << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Alumno con código " << codigo << " no encontrado." << endl;
    }
}

// Función para buscar un alumno por orden de lista
void buscarPorOrdenLista(Alumno alumnos[], int tamano, int ordenLista) {
    bool encontrado = false;
    for (int i = 0; i < tamano; i++) {
        if (alumnos[i].ordenLista == ordenLista) {
            cout << "Alumno encontrado: " << alumnos[i].nombre << ", Código: " << alumnos[i].codigo 
                 << ", Edad: " << alumnos[i].edad << ", Teléfono: " << alumnos[i].telefono 
                 << ", Orden en lista: " << alumnos[i].ordenLista << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Alumno con orden de lista " << ordenLista << " no encontrado." << endl;
    }
}

int main() {
    int numAlumnos = 10;

    cin.ignore(); // Limpiar el buffer

    // Creación del array de alumnos
    Alumno* alumnos = new Alumno[numAlumnos];

    // Ingresar datos de los alumnos
    for (int i = 0; i < numAlumnos; i++) {
        cout << "Ingrese el nombre del alumno " << i + 1 << ": ";
        getline(cin, alumnos[i].nombre);
        cout << "Ingrese el código del alumno " << i + 1 << ": ";
        getline(cin, alumnos[i].codigo);
        cout << "Ingrese la edad del alumno " << i + 1 << ": ";
        cin >> alumnos[i].edad;
        cin.ignore(); // Limpiar el buffer
        cout << "Ingrese el teléfono del alumno " << i + 1 << ": ";
        cin >> alumnos[i].telefono;
        cin.ignore(); // Limpiar el buffer
        alumnos[i].ordenLista = i + 1; // Asignar automáticamente el orden en la lista
    }

    // Menú
    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Buscar alumno por código\n";
        cout << "2. Buscar alumno por orden de lista\n";
        cout << "3. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer

        switch (opcion) {
            case 1: {
                string codigo;
                cout << "Ingrese el código del alumno: ";
                getline(cin, codigo);
                buscarPorCodigo(alumnos, numAlumnos, codigo);
                break;
            }
            case 2: {
                int ordenLista;
                cout << "Ingrese el orden en la lista del alumno: ";
                cin >> ordenLista;
                cin.ignore(); // Limpiar el buffer
                buscarPorOrdenLista(alumnos, numAlumnos, ordenLista);
                break;
            }
            case 3:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 3);

    // Liberar la memoria asignada al array de alumnos
    delete[] alumnos;

    return 0;
}
