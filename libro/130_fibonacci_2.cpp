/* ********************************************************
* Programa: Fibonacci2
*
* Descripci�n:
*   Este programa imprime todos los t�rminos
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
int TABultima;      /* �ltima columna */
int TABancho;       /* ancho de cada columna */


/*=========================================
  Procedimiento para iniciar la tabulaci�n
  con los par�metros indicados
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
  int termino;    /* t�rmino de la serie */
  int anterior;   /* t�rmino anterior */
  int aux;

/*-- Iniciar la tabulaci�n --*/
  IniciarTabulacion(6, 11);

/*-- Generar el comienzo de la serie --*/
  anterior = 0;   /* primer n�mero de la serie */
  termino = 1;    /* segundo n�mero de la serie */
  ImprimirTabulando( anterior );
  ImprimirTabulando( termino );

/*-- Generar resto de la serie --*/
  while (INT_MAX - termino >= anterior){
    aux       = termino + anterior ;  /* siguiente n�mero de la serie, suma de los anteriores */
    anterior  = termino;
    termino   = aux;
    ImprimirTabulando( termino );
  }
    printf( "\n" );
}
