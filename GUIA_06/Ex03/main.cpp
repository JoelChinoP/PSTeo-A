#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string frase;
    ofstream outfile("frases.txt", ios::app); // Abrir en modo de añadir al final del archivo

    if (!outfile) {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
        return 1;
    }

    cout << "Teclee frases (pulse Enter sin teclear nada para finalizar):" << endl;
    while (true) {
        getline(cin, frase);
        if (frase.empty()) {
            break; // Finaliza si el usuario pulsa Enter sin teclear nada
        }
        outfile << frase << endl;
    }

    outfile.close();

    ifstream infile("frases.txt");
    if (!infile) {
        cerr << "No se pudo abrir el archivo para lectura." << endl;
        return 1;
    }

    cout << "\nContenido del fichero 'frases.txt':" << endl;
    while (getline(infile, frase)) {
        cout << frase << endl;
    }

    infile.close();
    return 0;
}
