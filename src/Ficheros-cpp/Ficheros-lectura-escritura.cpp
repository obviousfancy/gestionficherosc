#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // Abrir archivo en modo lectura y escritura
    fstream archivo("archivo_cpp.txt", ios::in | ios::out | ios::app);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    // Escribir al archivo
    archivo << "Añadiendo texto en modo lectura/escritura\n";

    // Leer desde el archivo
    archivo.seekg(0);  // Volver al inicio del archivo
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();  // Cerrar archivo
    return 0;
}
