#include <iostream>
#include <new> // Requerido para std::bad_alloc

using namespace std;

int main() {
    try {
        // Intentar asignar una cantidad muy grande de memoria
        size_t largeSize = static_cast<size_t>(-1);
        int* array = new int[largeSize]; // Debería lanzar std::bad_alloc
        delete[] array; // Liberar memoria (si la asignación es exitosa)
    } catch (const bad_alloc& e) {
        // Manejar la excepción si no se puede asignar memoria
        cout << "Excepción capturada: " << e.what() << endl;
    }
    return 0;
}
