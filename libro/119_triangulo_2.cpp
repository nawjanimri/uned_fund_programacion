/* ********************************************************
* Programa: Triangulo2 (Versión corregida)
*
* Descripción:
*   Este programa escribe el borde de un triángulo aproximadamente
*   equilátero. usando asteriscos.
*   La altura del triángulo, en líneas de texto, se lee como dato.
******************************************************** */

#include <stdio.h>

int main() {

  int altura; /* altura del triángulo */

  /*-- Leer altura deseada --*/
  printf( "¿Altura? " );
  scanf( "%d" , &altura );

  /*-- Imprimir el vértice superior --*/
  if (altura > 0) {
    for (int k = 1; k <= altura-1; k++) {
      printf( " " );
    }
    printf( "*\n" );
  }

  /*-- Imprimir los bordes laterales --*/
  for (int k = 2; k <= altura-1; k++) {

    /*-- Espaciado hasta lateral izquierdo --*/
    for (int j = 1; j <= altura-k; j++) {
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
  if (altura> 1) {
    printf( "*" );
    for (int k = 1; k <= altura-1; k++) {
      printf( " *" );
    }
    printf( "\n" );
  }
}
