/* ********************************************************
* Programa: Floyd2
*
* Descripción:
*   Este programa imprime el triángulo de Floyd
*   con los números correlativos de 1 a N
*   El valor de N se lee como dato
******************************************************** */

#include <stdio.h>

int main() {

  int N;           /* último número a imprimir */
  int linea = 0;   /* contador de lineas*/
  int primero = 0; /* primer número de la linea */
  int ultimo = 0;  /* último número de la linea */

  /*-- Leer límite de la serie --*/
  printf( "¿Limite de la serie? " );
  scanf ("%d", &N );

  /*-- Imprimir el triángulo mediante un bucle de números --*/
  while (ultimo < N) {
    /*-- actualizar los límites --*/
    linea++;
    primero = ultimo+1;
    ultimo  = ultimo+linea;
    if (ultimo > N) {
      ultimo = N;
    }

    /*-- imprimir el número k --*/
    for (int k = primero; k <= ultimo; k++){
      printf( "%5d", k );
    }
    /* saltar de linea, si es necesario */
    printf( "\n" );
  }
}
