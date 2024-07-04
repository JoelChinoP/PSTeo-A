#include <iostream>
#include <string>
using namespace std;

// Estructura de Libro
struct Libro {
    string titulo;
    string autor;
    int anio_publicacion;
};

// Función para imprimir el arreglo de libros despues de año especificado
void mostrarLibrosPublicadosDespuesDe(Libro libros[], int numLibros, int anio) {
    cout << "Libros publicados después de " << anio << ":" << endl;
    for (int i = 0; i < numLibros; ++i) {
        if (libros[i].anio_publicacion >= anio) {
            cout << "Titulo: " << libros[i].titulo << "\n\tAutor: " << libros[i].autor 
                 << "\n\tAño de publicación: " << libros[i].anio_publicacion << endl;
        }
    }
}

int main() {
    // Creamos un arreglo de libros
    int numLibros = 15;
    Libro libros[numLibros] = {
        {"Cien Años de Soledad", "Gabriel Garcia Marquez", 1967},
        {"Don Quijote de la Mancha", "Miguel de Cervantes", 1605},
        {"La Sombra del Viento", "Carlos Ruiz Zafon", 2001},
        {"1984", "George Orwell", 1949},
        {"El Principito", "Antoine de Saint-Exupery", 1943},
        {"La Sombra del Viento", "Carlos Ruiz Zafon", 2000},
        {"1984", "George Orwell", 1979},
        {"El Principito", "Antoine de Saint-Exupery", 1985},
        {"El Principito", "Antoine de Saint-Exupery", 2003},
        {"La Sombra del Viento", "Carlos Ruiz Zafon", 2004},
        {"1984", "George Orwell", 1990},
        {"El Principito", "Antoine de Saint-Exupery", 1995},
        {"Rayuela", "Julio Cortazar", 1963},
        {"Crimen y castigo", "Fiodor Dostoievski", 1866},
        {"Crónica de una muerte anunciada", "Gabriel Garcia Marquez", 1981}
    };

    int anio;
    cout << "Ingrese un año: ";
    cin >> anio;

    mostrarLibrosPublicadosDespuesDe(libros, numLibros, anio);

    return 0;
}