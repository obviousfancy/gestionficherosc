#include <stdio.h>
#include <string.h>

// Definimos la estructura Persona
struct Persona {
    char nombre[50];
    int edad;
};

// Función para guardar una estructura Persona en un archivo binario
void guardarPersona(const char *nombreArchivo, struct Persona *persona) {
    FILE *archivo = fopen(nombreArchivo, "wb");  // Abrir archivo en modo binario para escritura
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escribir\n");
        return;
    }

    fwrite(persona, sizeof(struct Persona), 1, archivo);  // Escribir la estructura en el archivo
    fclose(archivo);  // Cerrar el archivo
    printf("Datos guardados en el archivo binario.\n");
}

// Función para leer una estructura Persona desde un archivo binario
void leerPersona(const char *nombreArchivo, struct Persona *persona) {
    FILE *archivo = fopen(nombreArchivo, "rb");  // Abrir archivo en modo binario para lectura
    if (archivo == NULL) {
        printf("Error al abrir el archivo para leer\n");
        return;
    }

    fread(persona, sizeof(struct Persona), 1, archivo);  // Leer la estructura desde el archivo
    fclose(archivo);  // Cerrar el archivo
}

int main() {
    struct Persona p1;

    // Asignar valores a la estructura
    strcpy(p1.nombre, "Juan Perez");
    p1.edad = 30;

    // Guardar la persona en el archivo binario
    guardarPersona("personas.bin", &p1);

    // Crear otra variable de tipo Persona para leer los datos
    struct Persona p2;

    // Leer la persona desde el archivo binario
    leerPersona("personas.bin", &p2);

    // Mostrar los datos leídos
    printf("Nombre: %s\n", p2.nombre);
    printf("Edad: %d\n", p2.edad);

    return 0;
}
