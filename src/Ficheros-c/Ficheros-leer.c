#include <stdio.h>

int main() {
    // Abrir archivo en modo lectura ("r")
    FILE *fptr = fopen("archivo.txt", "r");
    if (fptr == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Leer y mostrar el contenido del archivo
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        printf("%s", buffer);
    }
    // printf("\n");

    // Cerrar el archivo
    fclose(fptr);
    return 0;
}
