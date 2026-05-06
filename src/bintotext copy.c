#include <stdio.h>

struct Datos
{

    int numero;
    float pi;
    char mensaje[11];  // Longitud suficiente para "Hola Mundo" + '\0'
};

void escribirBinario(const char *nombrearchivo, struct Datos *datos) {
    FILE *archivo = fopen(nombrearchivo, "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escribir\n");
        return;
    }

    fwrite(datos, sizeof(struct Datos), 1, archivo);
    fclose(archivo);
    printf("Datos guardados en el archivo binario.\n");
}



void leerBinario(const char *nombrearchivo, struct Datos *datos) {
    FILE *archivo = fopen(nombrearchivo, "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para leer\n");
        return;
    }

    fread(datos, sizeof(struct Datos), 1, archivo);
    fclose(archivo);
}

void escribirTexto(const char *nombreArchivo,struct Datos *datos)
{
    
    FILE *fptr = fopen(nombreArchivo, "w");
    if (fptr == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    // Escribir en el archivo
    fprintf(fptr,"%i", datos->numero);
    fprintf(fptr,"\n");
    fprintf(fptr,"%s",datos->mensaje);
    fprintf(fptr,"\n");
    fprintf(fptr,"%f",datos->pi);
    // int numero = 10;
    // fprintf(fptr,"%i",numero);
    // Cerrar el archivo
    fclose(fptr);
    printf("Archivo escrito con éxito.\n");


}

void leerTexto(const char *nombreArchivo,struct Datos *datos)
{
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    fscanf(archivo,"%i",&datos->numero);
    fscanf(archivo,"%s",datos->mensaje);
    fscanf(archivo,"%f",&datos->pi);

    fclose(archivo);
    printf("Datos leidos del archivo de texto.\n");

    printf("Numero: %i\n",datos->numero);
    printf("Mensaje: %s\n",datos->mensaje);
    printf("Pi: %f\n",datos->pi);
}

int main(){

    struct Datos d1;

    d1.numero = 65536;
    d1.pi = 3.14;
    strcpy(d1.mensaje,"Hola Mundo");

    escribirBinario("datos.bin",&d1);

    printf("Se han guardado los datos en el archivo binario\n");

    leerBinario("datos.bin",&d1);

    printf("Se han leido los datos del archivo binario\n");
    struct Datos d2;

    d2.numero = d1.numero;
    d2.pi = d1.pi;
    strcpy(d2.mensaje,d1.mensaje);

    escribirTexto("datos.txt",&d2);
    printf("Se han guardado los datos en el archivo texto\n");
    leerTexto("datos.txt",&d2);
    printf("Se han leido los datos en el archivo texto\n");

    return 0;
}