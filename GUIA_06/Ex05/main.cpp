#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct Contacto {
    string nombre;
    string direccion;
    string telefono;
    string email;
    short dia;
    short mes;
    short anio;
};

class Agenda {
private:
    vector<Contacto> contactos;
    const string NOMBRE_ARCHIVO = "agenda.dat";

public:
    Agenda() {
        cargarDatos();
    }

    ~Agenda() {
        guardarDatos();
    }

    void agregarContacto() {
    Contacto nuevo;

    cout << "Nombre: ";
    cin.ignore(); // Limpiamos el buffer de entrada
    getline(cin, nuevo.nombre);

    cout << "Dirección: ";
    getline(cin, nuevo.direccion);

    cout << "Teléfono móvil: ";
    getline(cin, nuevo.telefono);

    cout << "Email: ";
    getline(cin, nuevo.email);

    cout << "Día de nacimiento: ";
    cin >> nuevo.dia;

    cout << "Mes de nacimiento: ";
    cin >> nuevo.mes;

    cout << "Año de nacimiento: ";
    cin >> nuevo.anio;

    contactos.push_back(nuevo);
    cout << "Contacto agregado exitosamente." << endl;
}


    void mostrarNombres() {
        if (contactos.empty()) {
            cout << "No hay contactos en la agenda." << endl;
            return;
        }

        cout << "Nombres en la agenda:" << endl;
        for (const auto& contacto : contactos) {
            cout << contacto.nombre << endl;
        }
    }

    void mostrarContacto() {
        if (contactos.empty()) {
            cout << "No hay contactos en la agenda." << endl;
            return;
        }

        string nombre;
        cout << "Ingrese el nombre del contacto a buscar: ";
        cin.ignore();
        getline(cin, nombre);

        auto it = find_if(contactos.begin(), contactos.end(), [&nombre](const Contacto& c) {
            return c.nombre == nombre;
        });

        if (it != contactos.end()) {
            mostrarDetalleContacto(*it);
        } else {
            cout << "Contacto no encontrado." << endl;
        }
    }

    void eliminarContacto() {
        if (contactos.empty()) {
            cout << "No hay contactos en la agenda." << endl;
            return;
        }

        string nombre;
        cout << "Ingrese el nombre del contacto a eliminar: ";
        cin.ignore();
        getline(cin, nombre);

        auto it = remove_if(contactos.begin(), contactos.end(), [&nombre](const Contacto& c) {
            return c.nombre == nombre;
        });

        if (it != contactos.end()) {
            contactos.erase(it, contactos.end());
            cout << "Contacto eliminado exitosamente." << endl;
        } else {
            cout << "Contacto no encontrado." << endl;
        }
    }

private:
    void mostrarDetalleContacto(const Contacto& contacto) {
        cout << "Nombre: " << contacto.nombre << endl;
        cout << "Dirección: " << contacto.direccion << endl;
        cout << "Teléfono móvil: " << contacto.telefono << endl;
        cout << "Email: " << contacto.email << endl;
        cout << "Fecha de nacimiento: " << contacto.dia << "/" << contacto.mes << "/" << contacto.anio << endl;
    }

    void cargarDatos() {
        ifstream archivo(NOMBRE_ARCHIVO);
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                contactos.push_back(parseContacto(linea));
            }
            archivo.close();
            cout << "Datos cargados desde " << NOMBRE_ARCHIVO << endl;
        }
    }

    void guardarDatos() {
        ofstream archivo(NOMBRE_ARCHIVO);
        if (archivo.is_open()) {
            for (const auto& contacto : contactos) {
                archivo << contacto.nombre << "|" << contacto.direccion << "|" << contacto.telefono << "|" << contacto.email << "|" << contacto.dia << "|" << contacto.mes << "|" << contacto.anio << endl;
            }
            archivo.close();
            cout << "Datos guardados en " << NOMBRE_ARCHIVO << endl;
        } else {
            cout << "No se pudo guardar los datos en " << NOMBRE_ARCHIVO << endl;
        }
    }

    Contacto parseContacto(const string& linea) {
        Contacto contacto;
        stringstream ss(linea);
        getline(ss, contacto.nombre, '|');
        getline(ss, contacto.direccion, '|');
        getline(ss, contacto.telefono, '|');
        getline(ss, contacto.email, '|');
        ss >> contacto.dia;
        ss.ignore();
        ss >> contacto.mes;
        ss.ignore();
        ss >> contacto.anio;
        return contacto;
    }
};

int main() {
    Agenda agenda;
    int opcion;

    do {
        cout << "\n--- Menú ---" << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Mostrar nombres" << endl;
        cout << "3. Mostrar datos de un contacto" << endl;
        cout << "4. Eliminar contacto" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese su opción: ";
        
        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Por favor, ingrese un número: ";
        }

        switch (opcion) {
            case 1:
                agenda.agregarContacto();
                break;
            case 2:
                agenda.mostrarNombres();
                break;
            case 3:
                agenda.mostrarContacto();
                break;
            case 4:
                agenda.eliminarContacto();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}

