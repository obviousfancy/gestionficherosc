#include <stdio.h>

int main() {
    // Abrir archivo en modo escritura ("w")
    FILE *fptr = fopen("archivo.txt", "w");
    if (fptr == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Escribir en el archivo
    fprintf(fptr, "Hola, mundo en un archivo!\n");
    char cadena[] = "añadi desde una variable\n"; 
    fprintf(fptr,"%s",cadena);
    // int numero = 10;
    // fprintf(fptr,"%i",numero);
    // Cerrar el archivo
    fclose(fptr);

    printf("Archivo escrito con éxito.\n");
    return 0;
}
