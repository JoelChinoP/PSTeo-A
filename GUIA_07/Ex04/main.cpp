#include <iostream>
#include <cmath> // Requerido para sqrt
#include <stdexcept> // Requerido para excepciones estándar

using namespace std;

// Clase de excepción personalizada para primer coeficiente cero
class PrimerCoeficienteCero : public runtime_error {
public:
    PrimerCoeficienteCero() : runtime_error("El primer coeficiente es cero, no es una ecuación cuadrática válida") {}
};

// Clase de excepción personalizada para no raíces reales
class NoRaicesReales : public runtime_error {
public:
    NoRaicesReales() : runtime_error("La ecuación no tiene raíces reales") {}
};

// Función para calcular las raíces cuadradas de una ecuación cuadrática
void raices(double a, double b, double c, double& raiz1, double& raiz2) {
    if (a == 0) {
        throw PrimerCoeficienteCero(); // Lanza excepción si el primer coeficiente es cero
    }
    
    double discriminante = b * b - 4 * a * c;
    if (discriminante < 0) {
        throw NoRaicesReales(); // Lanza excepción si no hay raíces reales
    }
    
    raiz1 = (-b + sqrt(discriminante)) / (2 * a); // Calcula la primera raíz
    raiz2 = (-b - sqrt(discriminante)) / (2 * a); // Calcula la segunda raíz
}

int main() {
    double a, b, c;
    cout << "Ingrese el coeficiente a: ";
    cin >> a; // Lee el coeficiente a desde la entrada estándar
    cout << "Ingrese el coeficiente b: ";
    cin >> b; // Lee el coeficiente b desde la entrada estándar
    cout << "Ingrese el coeficiente c: ";
    cin >> c; // Lee el coeficiente c desde la entrada estándar
    
    try {
        double raiz1, raiz2;
        raices(a, b, c, raiz1, raiz2); // Intenta calcular las raíces
        cout << "Las raíces de la ecuación son: " << raiz1 << " y " << raiz2 << endl; // Muestra las raíces
    } catch (const PrimerCoeficienteCero& e) {
        // Maneja la excepción para primer coeficiente cero
        cout << "Excepción capturada: " << e.what() << endl;
    } catch (const NoRaicesReales& e) {
        // Maneja la excepción para no raíces reales
        cout << "Excepción capturada: " << e.what() << endl;
    }
    
    return 0;
}
