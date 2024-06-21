#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    string direccion;
    string telefono;
    int edad;
};

void mostrarNombres(const vector<Persona>& personas) {
    for (const auto& persona : personas) {
        cout << persona.nombre << endl;
    }
}

void mostrarPersonasPorEdad(const vector<Persona>& personas, int edad) {
    for (const auto& persona : personas) {
        if (persona.edad == edad) {
            cout << "Nombre: " << persona.nombre << ", Dirección: " << persona.direccion << ", Teléfono: " << persona.telefono << ", Edad: " << persona.edad << endl;
        }
    }
}

void mostrarPersonasPorInicial(const vector<Persona>& personas, char inicial) {
    for (const auto& persona : personas) {
        if (!persona.nombre.empty() && persona.nombre[0] == inicial) {
            cout << "Nombre: " << persona.nombre << ", Dirección: " << persona.direccion << ", Teléfono: " << persona.telefono << ", Edad: " << persona.edad << endl;
        }
    }
}

int main() {
    vector<Persona> personas;
    personas.reserve(50);  // Reservar espacio para 50 personas

    while (personas.size() < 50) {
        Persona p;
        cout << "Introduzca el nombre (o pulse Enter para finalizar): " << endl;
        getline(cin, p.nombre);

        if (p.nombre.empty()) {
            break;
        }

        cout << "Introduzca la dirección: "<< endl;
        getline(cin, p.direccion);

        cout << "Introduzca el teléfono: "<< endl;
        getline(cin, p.telefono);

        cout << "Introduzca la edad: "<< endl;
        cin >> p.edad;
        cin.ignore();  // Ignorar el salto de línea restante

        personas.push_back(p);
    }

    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Mostrar la lista de todos los nombres\n";
        cout << "2. Mostrar las personas de una cierta edad\n";
        cout << "3. Mostrar las personas cuya inicial sea la que el usuario indique\n";
        cout << "4. Salir del programa\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();  // Ignorar el salto de línea restante

        switch (opcion) {
            case 1:
                mostrarNombres(personas);
                break;
            case 2: {
                int edad;
                cout << "Introduzca la edad: ";
                cin >> edad;
                cin.ignore();  // Ignorar el salto de línea restante
                mostrarPersonasPorEdad(personas, edad);
                break;
            }
            case 3: {
                char inicial;
                cout << "Introduzca la inicial: ";
                cin >> inicial;
                cin.ignore();  // Ignorar el salto de línea restante
                mostrarPersonasPorInicial(personas, inicial);
                break;
            }
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Por favor, intente de nuevo.\n";
                break;
        }
    } while (opcion != 4);

    return 0;
}
