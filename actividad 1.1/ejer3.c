/*
Factorial en c 
Jaz Gamarra 10/08/23
*/
#include <stdio.h>

long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;  // casos base: factorial de 0 y 1 es 1
    } else {
        return n * factorial(n - 1);  // llamada recursiva si aun no se llego al caso base 
    }
}

int main() {
    int numero;
    printf("Ingrese un número entero: ");
    scanf("%d", &numero);
    
    if (numero < 0) {
        printf("Factorial no definido para números negativos.\n");
    } else {
        long resultado = factorial(numero);
        printf("El factorial de %d es %llu\n", numero, resultado);
    }
    return 0;
}
