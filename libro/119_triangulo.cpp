/* ********************************************************
* Programa: Triangulo (Versión inicial)
*
* Descripción:
*   Este programa escribe el borde de un triángulo
*   aproximadamente equilátero. usando asteriscos.
******************************************************** */

#include <stdio.h>

int main() {

  const int N = 7; /* altura del triángulo */

  /* -- Escribir el vértice superior --*/
  for (int k = 1; k <= N-1; k++) {
    printf( " " );
  }

  printf( "*\n" );

  /*-- Imprimir los bordes laterales --*/
  for (int k = 2; k <= N-1; k++) {

    /*-- Espaciado hasta lateral izquierdo --*/
    for (int j = 1; j <= N-k; j++) {
      printf( " " );
    }
    printf( "*" ); /* lateral izquierdo */

    /*-- Espaciado hasta lateral derecho --*/
    for (int j = 1; j <= 2*k-3; j++) {
      printf( " " );
    }
    printf( "*\n" ); /* lateral derecho */
  }

  /*-- Imprimir el borde inferior --*/
  printf( "*" );
  for (int k = 1; k <= N-1; k++) {
    printf( " *" ); /* asteriscos espaciados */
  }
  printf( "\n" );
}
