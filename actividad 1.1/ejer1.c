/*
Fibonacci y assembler 
Jaz Gamarra 10/08/23
*/

#include <stdio.h> 

int main() {
    int x,y,z; 

    while (1) {
        x = 0; 
        y = 1; 

        do {
            printf("%d\n", x);

            z = x + y; 
            x = y; 
            y = z; 
        } while (x < 256); 
    }
}

/*
-------------------------------------------------------------------------------------
a. Cuáles son las líneas del código que realizan la suma z = x + y;
-------------------------------------------------------------------------------------

    Las lineas son las siguientes: 

        movl	-12(%rbp), %edx
        movl	-8(%rbp), %eax
        addl	%edx, %eax
        movl	%eax, -4(%rbp)

    *** notas teoricas ***
    - edx y eax son "registros de proposito general" que se usan para almacenar datos en la cpu para realizar calculos. 
        - eax = acumulador extendido. 
        - edx = registro de datos extendido 

    - movl se usa para cargar datos de una ubicacion de memoria a un registro. 
        por el orden y los valores de declaracion en el codigo en c, podemos decir que... 
        - [-12(%rbp)] es una ubicacion de memoria que corresponde a x 
        - [-8(%rbp)] corresponde a y 

        entonces podemos decir que 
        - x se carga en edx 
        - y se carga en eax 

    - addl suma los valores de edx y eax. el resultado se almacena en eax, el registro que se usa para almacenar resultados y retorno de funciones 

    - se usa movl para almacenar el resultado en -4(%rbp) que corresponderia a z 

-------------------------------------------------------------------------------------b. Cuáles son las líneas de código que realizan el control y salto del flujo de 
ejecución?
-------------------------------------------------------------------------------------
Note que el codigo esta separado con distintas etiquetas. 
    - El ciclo infinito comienza en L3 
    - El ciclo do-while comieza en L2 

Las instrucciones que se usan para saltar entre estas etiquetas son  
    - jle	.L2: salto condicional que se usa para verificar la condicion antes de volver a .L2 
	- jmp	.L3: salto incondicional, hace cumplir el bucle infinito volviendo a .L3 siempre 

-------------------------------------------------------------------------------------
c. Cuál es la dirección en el registro de memoria para las tres variables x, y, z ?
-------------------------------------------------------------------------------------
-12(%rbp)]  -> x 
-8(%rbp)]   -> y 
-4(%rbp)    -> z

-------------------------------------------------------------------------------------
d. De qué depende el tamaño de los saltos en las direcciones de las variables? 
-------------------------------------------------------------------------------------
Depende de dos cosas: 
- Tamaño de los datos: Las variable son de tipo int, que ocupan 4 bytes

- Posición relativa: Las direcciones se miden en relación con el registro de base del marco (%rbp), que es como una referencia para el inicio de la porción de memoria asignada al codigo que estamos ejecutando. 

    Sabiendo el espacio que ocupa cada variable y que el rbp es un puntero que apunta al inicio de una porcion de memoria, podemos decir que:

    - x esta a 12 bytes despues de %rbp.
    - y está a 8 bytes despues de %rbp.
    - z esta a 4 bytes despues de %rbp.
    -  la distancia entre cada una es 4 bytes porque son ints 


*/
