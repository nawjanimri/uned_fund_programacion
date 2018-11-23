/* ********************************************************
* Programa: TrianguloDeNumeros
*
* Descripción:
*   Este programa escribe un triángulo de dígitos.
*   La altura se lee como dato y debe ser menor de 10
******************************************************** */

#include <stdio.h>

int main() {

  const int centro = 35; /* Posición del eje del triángulo */
  const int inicial = 1; /* Dígito inicial : superior y laterales */
  int nivel;

  /*-- Leer los datos --*/
  printf( "¿Altura del triángulo??" );
  scanf( "%d", &nivel );

  /*-- Una iteración por cada línea del triángulo --*/
  for (int altura = inicial; altura <= nivel; altura++) {

    /*-- Paso l: Situar primer número de cada linea --*/{
      for (int indice = 1; indice < centro-altura; indice++) {
        printf( " " );
      }
      printf( "%d", inicial);
    }

    /*-- Paso 2; Primera mitad de la linea del triángulo
      Escribir números consecutivos hasta altura--*/{
      for (int indice = inicial+1; indice<=altura; indice++) {
        printf( "%1d", indice );
      }
    }

    /*-- Paso 3°: Segunda mitad de la línea del triángulo.
      Escribir números decrecientes hasta Inicial --*/{
      for (int indice = altura-1; indice >= inicial; indice--) {
        printf( "%1d" , indice );
      }
    }

    /*-- Paso 4: Situar primer número de cada linea --*/{
      printf( "\n" );
    }
  }
}

