//
// Created by VICTUS on 21/06/2024.
//


#include <iostream>
#include <vector>

using namespace std;

//Hacemos la estructura del jugador
struct Jugador {
    string nombre;
    int dni;
    int edad;
    string correo;

};

//realizamos los metodos necesario para poder hacer el filtrado de los jugadores
void mostrarNombres(vector<Jugador>& personas) {
    for (const auto& jugador : personas) {
        cout << jugador.nombre << endl;
    }
}

void mostrarPersonasPorEdad(vector<Jugador>& jugador, int edad) {
    for (const auto& jugadores : jugador) {
        if (jugadores.edad == edad) {
            cout << "Nombre: " << jugadores.nombre << ", Dirección: " << jugadores.dni << ",\n"
                 << "Teléfono: " << jugadores.correo << ", Edad: " << jugadores.edad << endl;
        }
    }
}

void mostrarPersonasPorDNI(vector<Jugador>& jugador, int dni) {
    for (const auto& jugadores : jugador) {
        if (jugadores.dni == dni) {
            cout << "Nombre: " << jugadores.nombre << ", Dirección: " << jugadores.dni << ",\n"
                 << "Teléfono: " << jugadores.correo << ", Edad: " << jugadores.edad << endl;
        }
    }
}


int main(){


    vector<Jugador> jugadores;
    jugadores.reserve(10);

    //inicializacion de los jugadores

    while (jugadores.size() < 10) {
        Jugador j;
        cout << "Introduzca el nombre (o pulse Enter para finalizar): " << endl;
        getline(cin, j.nombre);

        if (j.nombre.empty()) {
            break;
        }

        cout << "Introduzca su dni : "<< endl;
        cin >> j.dni;

        // Sirve para ignorar el salto de línea restante
        cin.ignore();

        cout << "Introduzca su correo: "<< endl;
        getline(cin, j.correo);

        cout << "Introduzca la edad: "<< endl;
        cin >> j.edad;
        cin.ignore();

        jugadores.push_back(j);
    }

    int opcion;
    do {
        //realizamos el menu para poder ver los datos de los jugadores
        cout << "\nMenu:\n";
        cout << "1. Mostrar la lista de todos los nombres\n";
        cout << "2. Mostrar la lista de jugadores de una cierta edad\n";
        cout << "3. Mostrar al jugador con el numero de DNI\n";
        cout << "4. Salir del programa\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        //un switch para poder elegir que metodo usar
        switch (opcion) {
            case 1:
                mostrarNombres(jugadores);
                break;
            case 2: {
                int edad;
                cout << "Introduzca la edad: ";
                cin >> edad;
                cin.ignore();
                mostrarPersonasPorEdad(jugadores, edad);
                break;
            }
            case 3: {
                int dni ;
                cout << "Introduzca el DNI: ";
                cin >> dni;
                cin.ignore();  // Ignorar el salto de línea restante
                mostrarPersonasPorDNI(jugadores, dni);
                break;
            }
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no válida. Por favor, intente de nuevo.\n";
                break;
        }
    } while (opcion != 4);

    return 0;
}