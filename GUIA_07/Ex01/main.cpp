#include <iostream>
using namespace std;

// Clase de excepción personalizada para división por cero
class DivisionPorCero {
public:
    // Mensaje de error para división por cero
    const char* mensaje() const {
        return "División por cero no permitida";
    }
};

// Función para realizar la división de dos números
double dividir(double numerador, double denominador) {
    if (denominador == 0) {
        throw DivisionPorCero(); // Genera una excepción si el denominador es cero
    }
    return numerador / denominador; // Devuelve el resultado de la división
}

int main() {
    double numerador, denominador;
    cout << "Ingrese el numerador: ";
    cin >> numerador; // Lee el numerador desde la entrada estándar
    cout << "Ingrese el denominador: ";
    cin >> denominador; // Lee el denominador desde la entrada estándar
    try {
        double resultado = dividir(numerador, denominador); // Intenta dividir los números
        cout << "El resultado de la división es: " << resultado << endl; // Muestra el resultado
    } catch (const DivisionPorCero& e) {
        cout << "Excepción capturada: " << e.mensaje() << endl; // Captura y muestra la excepción
    }
    return 0;
}
