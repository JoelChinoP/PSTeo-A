#include <iostream>
#include <fstream>
#include "InputException.h"
#include "ProcessorException.h"
#include "OutputException.h"

using namespace std;

// Función para leer un fichero
void readFile(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        throw InputException("No se puede abrir el fichero: " + filePath);
    }
    // Lógica de lectura del fichero
    file.close();
}

// Función de procesamiento
void process() {
    // Lógica de procesamiento
    bool error = false; // Simulación de error de procesamiento
    if (error) {
        throw ProcessorException("Error en el procesamiento");
    }
}

// Función para escribir en un fichero
void writeFile(const string& filePath) {
    ofstream file(filePath);
    if (!file.is_open()) {
        throw OutputException("No se puede abrir el fichero para escritura: " + filePath);
    }
    // Lógica de escritura del fichero
    file.close();
}

int main() {
    string inputFilePath;
    string outputFilePath;

    // Intentar leer el fichero de entrada
    while (true) {
        try {
            cout << "Ingrese la ruta del fichero de entrada: ";
            cin >> inputFilePath;
            readFile(inputFilePath);
            break; // Salir del bucle si la lectura es exitosa
        } catch (const InputException& e) {
            cout << "Excepción capturada: " << e.getMessage() << endl;
            // Volver a pedir la ruta del fichero
        }
    }

    // Intentar procesar los datos
    try {
        process();
    } catch (const ProcessorException& e) {
        cout << "Excepción capturada: " << e.getMessage() << endl;
        // Terminar el programa de forma ordenada
        return 1;
    }

    // Intentar escribir el fichero de salida
    while (true) {
        try {
            cout << "Ingrese la ruta del fichero de salida: ";
            cin >> outputFilePath;
            writeFile(outputFilePath);
            break; // Salir del bucle si la escritura es exitosa
        } catch (const OutputException& e) {
            cout << "Excepción capturada: " << e.getMessage() << endl;
            // Volver a pedir la ruta del fichero
        }
    }

    return 0;
}
