/* Programa: Baldosas */
/* Este programa calcula el costo de las baldosas necesarias
...para cubrir una habitaci�n rectangular */

#include <stdio.h>

int main() {

  int largo, ancho; /* Dimensiones de la habitaci�n en m2 */
  int lado;         /* Lado de la baldosa en cm */
  int nLargo;       /* N�mero de baldosas a lo largo */
  int nAncho;       /* N�mero de baldosas a lo ancho */
  int baldosas ;    /* N�mero total de baldosas */
  float precio;     /* Precio de cada baldosa */
  float coste;      /* Coste total */


  /*-- Leer los datos --*/ {
    printf( "Dar el tama�o de la habitaci�n, en m\n" );
    printf( "�Largo, ancho? " );
    scanf( "%d, %d" ,&largo ,&ancho);
    printf( "�Lado de l a baldosa, en cm? " );
    scanf( "%d", &lado );
    printf( "�Precio de cada baldosa, en euros? ");
    scanf( "%f", &precio );

    /*--Calcular el n�mero de baldosas--*/{
      /*--Calcular las baldosas a lo largo, por exceso--*/ {
        nLargo = (largo*100 + lado - 1) / lado ;
      }
      /*--Calcular las baldosas a lo ancho, por exceso--*/ {
        nAncho = (ancho*100 + lado - 1) / lado;
      }
      /*--Calcular el n�mero total de baldosas--*/ {
        baldosas = nLargo * nAncho;
      }
    }
    /*--Calcular el coste total--*/ {
      coste = baldosas * precio;
    }
    /*--Imprimir el resultado--*/ {
      printf( "Total %5d baldosas\n", baldosas);
      printf( "Coste %8.2f euros\n", coste);
    }
  }
}
