#include <iostream>
#include <string>
using namespace std;
struct EquipoBaloncesto {
    string nombre;
    int victorias;
    string mejorAnotadorTriples;
    int triplesAnotador;
};
struct EquipoFutbol {
    string nombre;
    int victorias, empates;
    string goleador;
    int golesGoleador;
};
void listadoMejoresAnotadoresTriples(EquipoBaloncesto* equipos, int numEquipos) {
    cout << "\nListado de los mejores anotadores de triples de cada equipo:\n";
    for (int i = 0; i < numEquipos; i++) {
        cout << "Equipo " << equipos[i].nombre << ": " << equipos[i].mejorAnotadorTriples
             << " con " << equipos[i].triplesAnotador << " triples.\n";
    }
}
void maximoGoleadorFutbol(EquipoFutbol* equipos, int numEquipos) {
    string maxGoleador;
    int maxGoles = 0;
    for (int i = 0; i < numEquipos; i++) {
        if (equipos[i].golesGoleador > maxGoles) {
            maxGoleador = equipos[i].goleador;
            maxGoles = equipos[i].golesGoleador;
        }
    }
    cout << "\nMaximo goleador de la liga de futbol: " << maxGoleador << " con " << maxGoles << " goles.\n";
}
void equipoGanadorLigaFutbol(EquipoFutbol* equipos, int numEquipos) {
    int maxPuntos = 0;
    string equipoGanador;
    for (int i = 0; i < numEquipos; i++) {
        int puntos = equipos[i].victorias * 3 + equipos[i].empates;
        if (puntos > maxPuntos) {
            maxPuntos = puntos;
            equipoGanador = equipos[i].nombre;
        }
    }
    cout << "\nEquipo ganador de la liga de futbol: " << equipoGanador << " con " << maxPuntos << " puntos.\n";
}
void equipoGanadorLigaBaloncesto(EquipoBaloncesto* equipos, int numEquipos) {
    int maxVictorias = 0;
    string equipoGanador;
    for (int i = 0; i < numEquipos; i++) {
        if (equipos[i].victorias > maxVictorias) {
            maxVictorias = equipos[i].victorias;
            equipoGanador = equipos[i].nombre;
        }
    }
    cout << "\nEquipo ganador de la liga de baloncesto: " << equipoGanador << " con " << maxVictorias << " victorias.\n";
}
int main() {
    int numEquiposBaloncesto, numEquiposFutbol;
    cout << "Ingrese el numero de equipos de baloncesto: ";
    cin >> numEquiposBaloncesto;
    EquipoBaloncesto* equiposBaloncesto = new EquipoBaloncesto[numEquiposBaloncesto];
    cout << "\nIngrese la informacion de los equipos de baloncesto:\n";
    for (int i = 0; i < numEquiposBaloncesto; i++) {
        cout << "Equipo " << i + 1 << ":\n";
        cout << "Nombre del equipo: ";
        cin.ignore();
        getline(cin, equiposBaloncesto[i].nombre);
        cout << "Numero de victorias: ";
        cin >> equiposBaloncesto[i].victorias;
        cout << "Nombre del mejor anotador de triples: ";
        cin.ignore();
        getline(cin, equiposBaloncesto[i].mejorAnotadorTriples);
        cout << "Numero de triples del mejor anotador de triples: ";
        cin >> equiposBaloncesto[i].triplesAnotador;
        cout << "\n";
    }
    cout << "Ingrese el numero de equipos de futbol: ";
    cin >> numEquiposFutbol;
    EquipoFutbol* equiposFutbol = new EquipoFutbol[numEquiposFutbol];
    cout << "\nIngrese la informacion de los equipos de futbol:\n";
    for (int i = 0; i < numEquiposFutbol; i++) {
        cout << "Equipo " << i + 1 << ":\n";
        cout << "Nombre del equipo: ";
        cin.ignore();
        getline(cin, equiposFutbol[i].nombre);
        cout << "Numero de victorias: ";
        cin >> equiposFutbol[i].victorias;
        cout << "Numero de empates: ";
        cin >> equiposFutbol[i].empates;
        cout << "Nombre del goleador: ";
        cin.ignore();
        getline(cin, equiposFutbol[i].goleador);
        cout << "Numero de goles del goleador: ";
        cin >> equiposFutbol[i].golesGoleador;
        cout << "\n";
    }
    listadoMejoresAnotadoresTriples(equiposBaloncesto, numEquiposBaloncesto);
    maximoGoleadorFutbol(equiposFutbol, numEquiposFutbol);
    equipoGanadorLigaFutbol(equiposFutbol, numEquiposFutbol);
    equipoGanadorLigaBaloncesto(equiposBaloncesto, numEquiposBaloncesto);
    delete[] equiposBaloncesto;
    delete[] equiposFutbol;
    return 0;
}
