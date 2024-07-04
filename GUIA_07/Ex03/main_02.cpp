#include <iostream>
#include <stdexcept> // Requerido para std::invalid_argument

using namespace std;

int main() {
    try {
        int numero;
        cout << "Ingrese un número entero: ";
        cin >> numero;

        // Verificar si la entrada es válida
        if (cin.fail()) {
            throw invalid_argument("Entrada no es un número válido");
        }
        cout << "El número ingresado es: " << numero << endl;
    } catch (const invalid_argument& e) {
        // Manejar la excepción para entrada no válida
        cout << "Excepción capturada: " << e.what() << endl;

        // Limpiar cin y descartar la entrada incorrecta
        cin.clear();
        char c;
        while (cin.get(c) && c != '\n') {
            // Descartar caracteres en el buffer de entrada
        }
    }

    return 0;
}
