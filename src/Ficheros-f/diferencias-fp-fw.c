#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5  // Número de enteros a manejar

// Estructura simple para almacenar datos
struct Datos {
    int id;
    char nombre[50];
};

// Función para escribir datos en un archivo de texto
void escribirDatosTexto(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");  // Abrir archivo en modo texto para escritura
    if (archivo == NULL) {
        perror("Error al abrir el archivo para escribir");
        return;
    }

    struct Datos datos[N] = {
        {1, "Juan"},
        {2, "Maria"},
        {3, "Pedro"},
        {4, "Ana"},
        {5, "Luis"}
    };

    // Escribir datos en el archivo de texto usando fprintf
    for (int i = 0; i < N; i++) {
        fprintf(archivo, "ID: %d, Nombre: %s\n", datos[i].id, datos[i].nombre);
    }

    fclose(archivo);  // Cerrar el archivo
    printf("Datos guardados en %s.\n", nombreArchivo);
}

// Función para escribir datos en un archivo binario
void escribirDatosBinario(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");  // Abrir el archivo en modo binario para escritura
    if (archivo == NULL) {
        perror("Error al abrir el archivo para escribir");
        return;
    }

    struct Datos datos[N] = {
        {1, "Juan"},
        {2, "Maria"},
        {3, "Pedro"},
        {4, "Ana"},
        {5, "Luis"}
    };

    // Escribir datos en el archivo binario usando fwrite
    size_t elementosEscritos = fwrite(datos, sizeof(struct Datos), N, archivo);
    printf("Escritos %zu elementos en el archivo %s.\n", elementosEscritos, nombreArchivo);

    fclose(archivo);  // Cerrar el archivo
}

// Función para leer datos desde un archivo binario
void leerDatos(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");  // Abrir el archivo en modo binario para lectura
    if (archivo == NULL) {
        perror("Error al abrir el archivo para leer");
        return;
    }

    struct Datos datos[N];

    // Leer datos desde el archivo
    size_t elementosLeidos = fread(datos, sizeof(struct Datos), N, archivo);
    printf("Leídos %zu elementos del archivo %s.\n", elementosLeidos, nombreArchivo);

    // Mostrar los datos leídos
    for (size_t i = 0; i < elementosLeidos; i++) {
        printf("ID: %d, Nombre: %s\n", datos[i].id, datos[i].nombre);
    }

    fclose(archivo);  // Cerrar el archivo
}

int main() {
    const char *nombreArchivoTexto = "datos.txt";
    const char *nombreArchivoBinario = "datos.bin";

    // Escribir datos en el archivo de texto
    escribirDatosTexto(nombreArchivoTexto);

    // Escribir datos en el archivo binario
    escribirDatosBinario(nombreArchivoBinario);

    // Leer datos desde el archivo binario
    leerDatos(nombreArchivoBinario);

    return 0;
}
