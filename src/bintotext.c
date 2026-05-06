#include <stdio.h>
#include <string.h>

int main(){
//Leer un binario y escribir en txt

    FILE *file = fopen("prac.bin", "wb");
    if(file == NULL){
        printf("Error al abrir el archivo\n");
        return 1;
    }

    int numero = 65536;
    float pi = 3.14159;
    char mensaje[] = "Hola Mundohh";

    // Escribir datos binarios en el archivo
    fwrite(&numero, sizeof(int), 1, file);  // Escribir un entero
    fwrite(&pi, sizeof(float), 1, file);    // Escribir un flotante
    fwrite(mensaje, sizeof(mensaje), 1, file);  // Escribir cadena de texto

    // Cerrar el archivo
    fclose(file);

    FILE *archivo = fopen("prac.bin", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    int numeror;
    float pir;
    char mensajer[14];  // Longitud suficiente para "Hola Mundo" + '\0'


// Leer los datos binarios del archivo
    fread(&numeror, sizeof(int), 1, archivo);  // Leer un entero
    fread(&pir, sizeof(float), 1, archivo);    // Leer un flotante
    fread(mensajer, sizeof(mensajer), 1, archivo);  // Leer la cadena de texto

    // Mostrar los datos leídos
    printf("Numero: %d\n", numeror);
    printf("Pi: %f\n", pir);
    printf("Mensaje: %s\n", mensajer);

    // Cerrar el archivo
    fclose(archivo);


    FILE *fptr = fopen("archivo.txt", "w");
    if (fptr == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Escribir en el archivo
    fprintf(fptr,"%i", numeror);
    fprintf(fptr,"\n");
    fprintf(fptr,"%s",mensajer);
    fprintf(fptr,"\n");
    fprintf(fptr,"%f",pir);
    // int numero = 10;
    // fprintf(fptr,"%i",numero);
    // Cerrar el archivo
    fclose(fptr);




    printf("Archivo escrito con éxito.\n");
    return 0;
}