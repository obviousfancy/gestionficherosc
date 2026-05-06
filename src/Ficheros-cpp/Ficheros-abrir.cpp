#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // Crear y abrir archivo en modo escritura ios::in | ios::out | ios::app
    ofstream archivo("archivo_cpp.txt",ios::app);
    if (archivo.is_open()) {
        // Escribir en el archivo
        archivo << "Hola, mundo en C++!\n";
        archivo.close();
        cout << "Archivo escrito con éxito." << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }

    return 0;
}
