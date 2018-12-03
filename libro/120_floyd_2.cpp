/* ********************************************************
* Programa: Floyd2
*
* Descripci�n:
*   Este programa imprime el tri�ngulo de Floyd
*   con los n�meros correlativos de 1 a N
*   El valor de N se lee como dato
******************************************************** */

#include <stdio.h>

int main() {

  int N;           /* �ltimo n�mero a imprimir */
  int linea = 0;   /* contador de lineas*/
  int primero = 0; /* primer n�mero de la linea */
  int ultimo = 0;  /* �ltimo n�mero de la linea */

  /*-- Leer l�mite de la serie --*/
  printf( "�Limite de la serie? " );
  scanf ("%d", &N );

  /*-- Imprimir el tri�ngulo mediante un bucle de n�meros --*/
  while (ultimo < N) {
    /*-- actualizar los l�mites --*/
    linea++;
    primero = ultimo+1;
    ultimo  = ultimo+linea;
    if (ultimo > N) {
      ultimo = N;
    }

    /*-- imprimir el n�mero k --*/
    for (int k = primero; k <= ultimo; k++){
      printf( "%5d", k );
    }
    /* saltar de linea, si es necesario */
    printf( "\n" );
  }
}
