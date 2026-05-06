#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define random 10000
void guardarNumerosAleatoriosTexto(const char *nombreArchivo, int cantidad) {
    FILE *archivo = fopen(nombreArchivo, "w");  // Abrir archivo en modo texto para escritura
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escribir\n");
        return;
    }

    // Generar números aleatorios y escribirlos en el archivo
    for (int i = 0; i < cantidad; i++) {
        int numero = rand() % random;  // Generar número aleatorio entre 0 y 99
        fprintf(archivo, "%d ", numero);  // Escribir el número en el archivo
    }

    fclose(archivo);  // Cerrar el archivo
    printf("Números aleatorios guardados en %s.\n", nombreArchivo);
}

void guardarNumerosAleatoriosBinario(const char *nombreArchivo, int cantidad) {
    FILE *archivo = fopen(nombreArchivo, "wb");  // Abrir archivo en modo binario para escritura
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escribir\n");
        return;
    }

    // Generar números aleatorios y escribirlos en el archivo
    for (int i = 0; i < cantidad; i++) {
        int numero = rand() % random;  // Generar número aleatorio entre 0 y 99
        fwrite(&numero, sizeof(int), 1, archivo);  // Escribir el número en el archivo
    }

    fclose(archivo);  // Cerrar el archivo
    printf("Números aleatorios guardados en %s.\n", nombreArchivo);
}


int main() {
    srand(time(NULL));  // Inicializar la semilla para la generación de números aleatorios

    int cantidad = 10000;  // Número de aleatorios a generar

    // Guardar números aleatorios en un archivo de texto
    guardarNumerosAleatoriosTexto("numeros.txt", cantidad);

    // Guardar números aleatorios en un archivo binario
    guardarNumerosAleatoriosBinario("numeros.bin", cantidad);

    return 0;
}
