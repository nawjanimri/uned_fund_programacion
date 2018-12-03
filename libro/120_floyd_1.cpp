/* ********************************************************
* Programa: Floydl
*
* Descripción:
*   Este programa imprime el triángulo de Floyd
*   con los números correlativos de 1 a N
*   El valor de N se lee como dato
******************************************************** */

#include <stdio.h>

int main() {

  int N;          /* último número a imprimir */
  int linea = 1;  /* contador de lineas*/
  int ultimo = 1; /* último número de la linea */

  /*-- Leer límite de la serie --*/
  printf( "¿Límite de la serie? " );
  scanf ("%d", &N );

  /*-- Imprimir el triángulo mediante un bucle de números --*/
  for (int k = 1; k <= N; k++) {
    /* saltar de linea, si es necesario */
    if (k > ultimo) {
      printf( "\n" );
      linea++;
      ultimo = ultimo+linea;
    }
    /*-- imprimir el número k --*/
    printf( "%5d", k );
  }

  /*-- Acabar la última línea --*/
  if (N > 0) {
    printf( " \n" );
  }
}
