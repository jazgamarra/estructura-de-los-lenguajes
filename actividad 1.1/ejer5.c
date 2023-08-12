/*
Estructuras y punteros 
Jaz Gamarra 10/08/23
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nombre[100];
    char autor[100];
    int anhoPublicacion;
} Libro;

void ingresarLibros (Libro * libros, int N) {
    for (int i = 0; i < N; i++) {
        printf("\nIngrese los datos de libro \n- - - - - - - - - - - - - - - -\n", i + 1);

        printf("Ingrese el ID del libro %d: ", i + 1);
        scanf("%d", &libros[i].id);
        printf("Ingrese el nombre del libro %d: ", i + 1);
        scanf("%s", libros[i].nombre);
        printf("Ingrese el autor del libro %d: ", i + 1);
        scanf("%s", libros[i].autor);
        printf("Ingrese el año de publicación del libro %d: ", i + 1);
        scanf("%d", &libros[i].anhoPublicacion);
    }
}

void imprimirLibros (Libro * libros, int N) {
    printf("\nListado de libros ingresados: \n- - - - - - - - - - - - - - - -\n");
    for (int i = 0; i < N; i++) {
        printf("Libro %d:\n", i + 1);
        printf("  ID: %d\n", libros[i].id);
        printf("  Nombre: %s\n", libros[i].nombre);
        printf("  Autor: %s\n", libros[i].autor);
        printf("  Año de publicación: %d\n", libros[i].anhoPublicacion);
    }
}

int main() {
    int N;

    // solicitar al usuario la cantidad de libros 
    printf("Ingrese la cantidad de libros: ");
    scanf("%d", &N);

    // dimensionar el array de libros de manera dinámica
    Libro* libros = (Libro*)malloc(N * sizeof(Libro));
    if (libros == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }
    
    ingresarLibros(libros, N); 
    imprimirLibros(libros, N);

    // Liberar la memoria asignada dinámicamente
    free(libros);

    return 0;
}
