/* ********************************************************
* Programa: Floydl
*
* Descripci�n:
*   Este programa imprime el tri�ngulo de Floyd
*   con los n�meros correlativos de 1 a N
*   El valor de N se lee como dato
******************************************************** */

#include <stdio.h>

int main() {

  int N;          /* �ltimo n�mero a imprimir */
  int linea = 1;  /* contador de lineas*/
  int ultimo = 1; /* �ltimo n�mero de la linea */

  /*-- Leer l�mite de la serie --*/
  printf( "�L�mite de la serie? " );
  scanf ("%d", &N );

  /*-- Imprimir el tri�ngulo mediante un bucle de n�meros --*/
  for (int k = 1; k <= N; k++) {
    /* saltar de linea, si es necesario */
    if (k > ultimo) {
      printf( "\n" );
      linea++;
      ultimo = ultimo+linea;
    }
    /*-- imprimir el n�mero k --*/
    printf( "%5d", k );
  }

  /*-- Acabar la �ltima l�nea --*/
  if (N > 0) {
    printf( " \n" );
  }
}
