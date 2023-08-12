/*
Histograma de ocurrencias 
Jaz Gamarra 10/08/23
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_LETRAS_ABECEDARIO 26 
#define CANT_LETRAS_ALEATORIAS 1000


char* letrasMayusculasAleatorias(int longitud) {
    // asignar dinamicamente la memoria 
    char* mayusculas = (char*)malloc(longitud * sizeof(char));
    if (mayusculas == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    // cargar mayusculas de manera aleatoria 
    srand(time(NULL));
    for (int i = 0; i < longitud; i++) {
        mayusculas[i] = 'A' + rand() % CANT_LETRAS_ABECEDARIO; // Generar una letra mayúscula aleatoria
    }

    return mayusculas;
}

void imprimirMilLetras(char * arrayLetras, int longitud) {
    for (int i = 0; i < longitud; i++) {
        printf("%c ", arrayLetras[i]);
        if ((i + 1) % 20 == 0) {
            printf("\n"); // imprimir 20 letras por línea
        }
    }
    printf("\n");
}

void imprimirArray (int * array, int longitud) {
    for (int i = 0; i < CANT_LETRAS_ABECEDARIO; i++) {
        printf("%d ", array[i]); 
    }
}

void contarOcurrencias (char *array, int longitud, int *arrayContador) {
    for (int i = 0; i < longitud; i++) {
        char letra = array[i];
        arrayContador[letra - 'A']++; 
    }
}

void imprimirHistograma(int *frecuencias, int longitud) {
    printf("\n Histograma: \n"); 
    for (int i = 0; i < longitud; i++) {
        printf("(%c): ", 'A' + i);
        for (int j = 0; j < frecuencias[i]; j++) {
            printf("■");
        }
        printf("\n");
    }
}

int main() {
    int longitud = CANT_LETRAS_ALEATORIAS;
    char* arrayLetras = letrasMayusculasAleatorias(longitud);
    int arrayContador[CANT_LETRAS_ABECEDARIO] = {0};

    // Contar las ocurrencias de cada letra
    contarOcurrencias(arrayLetras, longitud, arrayContador);

    // Impresiones 
    imprimirMilLetras(arrayLetras, CANT_LETRAS_ALEATORIAS); 
    // imprimirArray(arrayContador, longitud); 

    // Crear histograma 
    imprimirHistograma(arrayContador, CANT_LETRAS_ABECEDARIO); 

    // liberar la posicion de memoria 
    free(arrayLetras);
}
