//
// Created by VICTUS on 20/06/2024.
//

#ifndef PSTEO_A_PERSON_H
#define PSTEO_A_PERSON_H


class Person {
public:
    struct Persona {
        string nombre;
        string direccion;
        string telefono;
        int edad;
    };

    // Constructor
    Person();

    // Método para agregar una persona
    void agregarPersona(const string& nombre, const string& direccion, const string& telefono, int edad);

    // Métodos para mostrar información
    void mostrarNombres() const;
    void mostrarPersonasPorEdad(int edad) const;
    void mostrarPersonasPorInicial(char inicial) const;

private:
    vector<Persona> personas;
};


#endif //PSTEO_A_PERSON_H
