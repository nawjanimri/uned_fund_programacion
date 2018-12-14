/* ********************************************************
* Programa: Fibonacci
*
* Descripci�n:
*   Este programa imprime todos los t�rminos
*   de la serie de Fibonacci dentro del rango de
*   valores positivos del tipo lnt: (1 .. INT_MAX)
*   Se imprime tabulando a cuatro columnas
******************************************************** */

#include <stdio.h>
#include <limits.h>

/*==================*\
  Variable global
\*==================*/
int columna;            /* columna a imprimir * /

/*=======================================*\
  Procedimiento para imprimir tabulando
  4 columnas de 15 caracteres
\*=======================================*/
void ImprimirTabulando(int k) {
  if (columna > 4) {
    columna = 1;
    printf( "\n" );
  }
    printf("%15d", k);
    columna++;
}

/*===================*\
  Programa principal
\*===================*/
int main() {
  int termino;    /* t�rmino de la serie */
  int anterior;   /* t�rmino anterior */
  int aux;

/*-- Iniciar la tabulaci�n --*/
  columna = 1;

/*-- Generar el comienzo de la serie --*/
  anterior = 0;
  termino = 1;
  ImprimirTabulando( anterior );
  ImprimirTabulando( termino );

/*-- Generar resto de la serie --*/
  while (INT_MAX - termino >= anterior){
    aux = termino + anterior ;
    anterior = termino;
    termino = aux;
    ImprimirTabulando( termino );
  }
    printf( "\n" );
}
