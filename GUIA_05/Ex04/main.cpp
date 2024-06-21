#include <iostream>
#include <string>

using namespace std;

// Estructura para equipos de baloncesto
struct EquipoBaloncesto
{
    string nombre;
    int victorias;
    int derrotas;
    int perdidasBalon;
    int rebotesCogidos;
    string mejorAnotadorTriples;
    int triplesMejorAnotador;
};

// Estructura para equipos de fútbol
struct EquipoFutbol
{
    string nombre;
    int victorias;
    int derrotas;
    int empates;
    int golesAFavor;
    string goleadorEquipo;
    int golesGoleador;
};

// Función para mostrar la información de un equipo de baloncesto
void mostrarEquipoBaloncesto(EquipoBaloncesto &equipo)
{
    cout << "Nombre del equipo: " << equipo.nombre << endl;
    cout << "Número de victorias: " << equipo.victorias << endl;
    cout << "Número de derrotas: " << equipo.derrotas << endl;
    cout << "Número de pérdidas de balón: " << equipo.perdidasBalon << endl;
    cout << "Número de rebotes cogidos: " << equipo.rebotesCogidos << endl;
    cout << "Nombre del mejor anotador de triples: " << equipo.mejorAnotadorTriples << endl;
    cout << "Número de triples del mejor anotador: " << equipo.triplesMejorAnotador << endl;
}

// Función para mostrar la información de un equipo de fútbol
void mostrarEquipoFutbol(EquipoFutbol &equipo)
{
    cout << "Nombre del equipo: " << equipo.nombre << endl;
    cout << "Número de victorias: " << equipo.victorias << endl;
    cout << "Número de derrotas: " << equipo.derrotas << endl;
    cout << "Número de empates: " << equipo.empates << endl;
    cout << "Número de goles a favor: " << equipo.golesAFavor << endl;
    cout << "Nombre del goleador del equipo: " << equipo.goleadorEquipo << endl;
    cout << "Número de goles del goleador: " << equipo.golesGoleador << endl;
}

int main()
{
    // Crear un equipo de baloncesto y asignar valores
    EquipoBaloncesto equipoBaloncesto = {
        "Arequipa Bulls",
        10,
        5,
        20,
        150,
        "Juan Perez",
        60};

    // Crear un equipo de fútbol y asignar valores
    EquipoFutbol equipoFutbol = {
        "Arequipa FC",
        8,
        6,
        4,
        30,
        "Carlos Gomez",
        15};

    // Mostrar la información de los equipos
    cout << "Información del equipo de baloncesto:" << endl;
    mostrarEquipoBaloncesto(equipoBaloncesto);

    cout << "\nInformación del equipo de fútbol:" << endl;
    mostrarEquipoFutbol(equipoFutbol);

    return 0;
}
