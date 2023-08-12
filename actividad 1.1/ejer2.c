/*
Funcion magica
Jaz Gamarra 10/08/23
*/
#include <stdio.h> 

int funcionMagica (int x) {
    int t = x, n=1; 

    while (t>=10) {
        n++; 
        t = t/10; 
    }
    return n; 
}

int main() {
    // Pruebas 
    printf("\n%d", funcionMagica (10));  
    printf("\n%d", funcionMagica (100));  
    printf("\n%d", funcionMagica (0.1)); 
    printf("\n%d", funcionMagica (0.125)); 
    printf("\n%d", funcionMagica (100.125)); 

}

/*

El codigo trabaja con divisiones sucesivas entre 10 para calcular la cantidad de digitos que tiene un numero entero. 

El parametro 'x' esta siendo inicializado como int, por ende al pasarle un numero decimal se realiza un casting de float a int, es decir, al pasarle 100.125 el programa lo convierte a 100 y trabaja solo con la parte entera. 


*/