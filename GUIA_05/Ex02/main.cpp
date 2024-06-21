#include <iostream>
#include <string>
using namespace std;

// Definición de la estructura para representar un cliente
struct Cliente
{
    string nombre;
    int unidadesSolicitadas;
    double precioPorUnidad;
    string estado;
};

// Función para calcular el monto total de la factura
double calcularMontoTotal(const Cliente &cliente)
{
    return cliente.unidadesSolicitadas * cliente.precioPorUnidad;
}

// Función para mostrar los detalles del cliente
void mostrarDetallesCliente(const Cliente &cliente)
{
    cout << "Nombre del cliente: " << cliente.nombre << endl;
    cout << "Unidades solicitadas: " << cliente.unidadesSolicitadas << endl;
    cout << "Precio por unidad: $" << cliente.precioPorUnidad << endl;
    cout << "Estado: " << cliente.estado << endl;
    cout << "Monto total: $" << calcularMontoTotal(cliente) << endl;
}

int main()
{
    // Ejemplo de creación de un cliente
    Cliente cliente1;
    cliente1.nombre = "Juan Perez";
    cliente1.unidadesSolicitadas = 10;
    cliente1.precioPorUnidad = 25.5;
    cliente1.estado = "Moroso";

    // Mostrar detalles del cliente
    mostrarDetallesCliente(cliente1);

    return 0;
}