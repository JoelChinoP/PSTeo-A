//
// Created by VICTUS on 21/06/2024.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    //Inicializamos el archivo frases
    ofstream fs("frases.txt");

    string frase;
    cout << "Escriba 10 frases:" << endl;


    //Hacemos un for para ingresar las 10 frases
    for(int i = 0; i < 10; i++){
        cout << "Frase " << i+1 << ": ";
        getline(cin, frase);
        fs << frase << endl;
    }
    fs.close();


    //Ahora entramos al archivo para poder hacer la lectura
    ifstream fr("frases.txt");
    if (!fr.is_open()) {
        cerr << "Error al abrir el archivo frases.txt" << endl;
        return 1;
    }

    cout << "\nLas frases almacenadas son: " << endl;
    while (getline(fr, frase)) {
        cout << frase << endl;
    }
    fr.close();

    return 0;
}
