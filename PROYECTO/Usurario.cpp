#include "Usuario.h"

void agregarUsuario(vector<Usuario> &usuarios)
{
    Usuario u;
    cout << "Ingrese el DNI: ";
    cin >> u.dni;
    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline(cin, u.nombre);
    cout << "Ingrese el email: ";
    getline(cin, u.email);
    cout << "Ingrese el teléfono: ";
    getline(cin, u.telefono);

    usuarios.push_back(u);
    cout << "Usuario agregado exitosamente!" << endl;
}

void eliminarUsuario(vector<Usuario> &usuarios)
{
    int dni;
    cout << "Ingrese el DNI del usuario a eliminar: ";
    cin >> dni;

    auto it = remove_if(usuarios.begin(), usuarios.end(), [&](Usuario &u)
                        { return u.dni == dni; });
    if (it != usuarios.end())
    {
        usuarios.erase(it, usuarios.end());
        cout << "Usuario eliminado exitosamente!" << endl;
    }
    else
    {
        cout << "Usuario no encontrado!" << endl;
    }
}

void listarUsuarios(const vector<Usuario> &usuarios)
{
    for (const auto &u : usuarios)
    {
        cout << "DNI: " << u.dni << endl;
        cout << "Nombre: " << u.nombre << endl;
        cout << "Email: " << u.email << endl;
        cout << "Teléfono: " << u.telefono << endl;
        cout << "---------------------------" << endl;
    }
}
