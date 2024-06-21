//
// Created by VICTUS on 20/06/2024.
//

#include "Person.h"
using namespace std;
class Person {

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
};