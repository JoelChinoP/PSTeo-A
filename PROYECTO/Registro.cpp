#include "Registro.h"
#include "algorithm"

void agregarRegistro(vector<Registro> &registros)
{
    Registro r;
    cout << "Ingrese el código: ";
    cin >> r.codigo;
    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline(cin, r.nombre);
    cout << "Ingrese el autor: ";
    getline(cin, r.autor);
    cout << "Ingrese el año de publicación: ";
    cin >> r.anioPublicacion;
    cout << "Ingrese el precio: ";
    cin >> r.precio;

    registros.push_back(r);
    cout << "Registro agregado exitosamente!" << endl;
}

void eliminarRegistro(vector<Registro> &registros)
{
    int codigo;
    cout << "Ingrese el código del registro a eliminar: ";
    cin >> codigo;

    auto it = remove_if(registros.begin(), registros.end(), [&](Registro &r)
                        { return r.codigo == codigo; });
    if (it != registros.end())
    {
        registros.erase(it, registros.end());
        cout << "Registro eliminado exitosamente!" << endl;
    }
    else
    {
        cout << "Registro no encontrado!" << endl;
    }
}

void buscarRegistro(const vector<Registro> &registros)
{
    int codigo;
    cout << "Ingrese el código del registro a buscar: ";
    cin >> codigo;

    auto it = find_if(registros.begin(), registros.end(), [&](const Registro &r)
                      { return r.codigo == codigo; });
    if (it != registros.end())
    {
        cout << "Código: " << it->codigo << endl;
        cout << "Nombre: " << it->nombre << endl;
        cout << "Autor: " << it->autor << endl;
        cout << "Año de Publicación: " << it->anioPublicacion << endl;
        cout << "Precio: " << it->precio << endl;
    }
    else
    {
        cout << "Registro no encontrado!" << endl;
    }
}

void actualizarRegistro(vector<Registro> &registros)
{
    int codigo;
    cout << "Ingrese el código del registro a actualizar: ";
    cin >> codigo;

    auto it = find_if(registros.begin(), registros.end(), [&](Registro &r)
                      { return r.codigo == codigo; });
    if (it != registros.end())
    {
        cout << "Ingrese el nuevo nombre: ";
        cin.ignore();
        getline(cin, it->nombre);
        cout << "Ingrese el nuevo autor: ";
        getline(cin, it->autor);
        cout << "Ingrese el nuevo año de publicación: ";
        cin >> it->anioPublicacion;
        cout << "Ingrese el nuevo precio: ";
        cin >> it->precio;

        cout << "Registro actualizado exitosamente!" << endl;
    }
    else
    {
        cout << "Registro no encontrado!" << endl;
    }
}

void listarRegistros(const vector<Registro> &registros)
{
    for (const auto &r : registros)
    {
        cout << "Código: " << r.codigo << endl;
        cout << "Nombre: " << r.nombre << endl;
        cout << "Autor: " << r.autor << endl;
        cout << "Año de Publicación: " << r.anioPublicacion << endl;
        cout << "Precio: " << r.precio << endl;
        cout << "---------------------------" << endl;
    }
}
