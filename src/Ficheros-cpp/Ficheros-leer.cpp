#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Abrir archivo en modo lectura
    ifstream archivo("archivo_cpp.txt");
    if (archivo.is_open()) {
        string linea;
        // Leer línea por línea
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo." << endl;
    }

    return 0;
}
