/* ********************************************************
* Programa: Fibonacci2
*
* Descripción:
*   Este programa imprime todos los términos
*   de la serie de Fibonacci dentro del rango de
*   valores positivos del tipo lnt: (1 .. INT_MAX)
*   Se imprime tabulando a siete columnas
******************************************************** */

#include <stdio.h>
#include <limits.h>

/*==================
  Variable global
  ==================*/
int TABcolumna;     /* columna a imprimir */
int TABultima;      /* última columna */
int TABancho;       /* ancho de cada columna */


/*=========================================
  Procedimiento para iniciar la tabulación
  con los parámetros indicados
  =========================================*/
void IniciarTabulacion(int columnas, int ancho){
  TABultima  = columnas;
  TABancho   = ancho;
  TABcolumna = 1;
}

/*=======================================*\
  Procedimiento para imprimir tabulando
  a TABultima columnas de TABancho caracteres
\*=======================================*/
void ImprimirTabulando(int k) {
  /* Si se llega al final de las columnas definidas, se pasa a la siguiente fila */
  if (TABcolumna > TABultima) {
    TABcolumna = 1;
    printf( "\n" );
  }
  printf("%*d", TABancho, k);
  TABcolumna++;
}

/*===================*\
  Programa principal
\*===================*/
int main() {
  int termino;    /* término de la serie */
  int anterior;   /* término anterior */
  int aux;

/*-- Iniciar la tabulación --*/
  IniciarTabulacion(6, 11);

/*-- Generar el comienzo de la serie --*/
  anterior = 0;   /* primer número de la serie */
  termino = 1;    /* segundo número de la serie */
  ImprimirTabulando( anterior );
  ImprimirTabulando( termino );

/*-- Generar resto de la serie --*/
  while (INT_MAX - termino >= anterior){
    aux       = termino + anterior ;  /* siguiente número de la serie, suma de los anteriores */
    anterior  = termino;
    termino   = aux;
    ImprimirTabulando( termino );
  }
    printf( "\n" );
}
