#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char filename[256];
    cout << "Ingrese el nombre del fichero: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el fichero " << filename << endl;
        return 1;
    }

    char line[256];
    int line_count = 0;
    const int lines_per_page = 25;

    while (file.getline(line, 256)) {
        cout << line << endl;
        line_count++;
        if (line_count % lines_per_page == 0) {
            cout << "Pulse Enter para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    file.close();
    return 0;
}
