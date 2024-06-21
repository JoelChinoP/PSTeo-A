#include <iostream>
#include <string>
#include <vector>
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

// Función para listar clientes en estado moroso
void listarClientesMorosos(const vector<Cliente> &clientes)
{
    cout << "Clientes en estado moroso:" << endl;
    for (const auto &cliente : clientes)
    {
        if (cliente.estado == "Moroso")
        {
            cout << "- " << cliente.nombre << endl;
        }
    }
}

// Función para listar clientes pagados con factura mayor a cierta cantidad
void listarClientesPagados(const vector<Cliente> &clientes, double montoMinimo)
{
    cout << "Clientes pagados con factura mayor a $" << montoMinimo << ":" << endl;
    for (const auto &cliente : clientes)
    {
        if (cliente.estado == "Pagado" && calcularMontoTotal(cliente) > montoMinimo)
        {
            cout << "- " << cliente.nombre << " (Monto: $" << calcularMontoTotal(cliente) << ")" << endl;
        }
    }
}

int main()
{
    // Ejemplo de creación de clientes
    vector<Cliente> listaClientes = {
        {"Juan Perez", 10, 25.5, "Moroso"},
        {"María Gómez", 20, 18.75, "Pagado"},
        {"Carlos Rodríguez", 15, 30.0, "Pagado"},
        {"Juan Perez 1", 10, 25.5, "Moroso"},
        {"Juan Perez 2", 100, 25.5, "Pagado"},
        {"Juan Perez 3", 100, 24.5, "Pagado"},
        {"Juan Perez 4", 10, 25.5, "Moroso"},
        // Agrega más clientes aquí...
    };

    // Mostrar detalles de los clientes
    for (const auto &cliente : listaClientes)
    {
        mostrarDetallesCliente(cliente);
        cout << endl;
    }

    // Listar clientes en estado moroso
    listarClientesMorosos(listaClientes);

    // Listar clientes pagados con factura mayor a $500
    double montoMinimo = 500.0;
    listarClientesPagados(listaClientes, montoMinimo);

    return 0;
}