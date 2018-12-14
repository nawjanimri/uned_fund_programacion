/* ********************************************************
* Programa: ArbolGrande de Navidad
*
* Descripción:
*   Usa las mismas definiciones de procedimientos
*   que el programa anterior
******************************************************** */

#include <stdio.h>

/*==================*\
  Constante global
\*==================*/
const int centro = 20; /* Centro de cada linea */

/*==========================================================*\
  Procedimiento para imprimir N veces seguidas el carácter 'c'
\*==========================================================*/
void ImprimirN (char e, int N){
  for (int k =1; k <= N; k++){
    printf( "%c ", e);
  }
}

/*==========================================================*\
  Procedimiento para imprimir un trapecio de asteriscos con
  la base superior "ancho", altura "alto" y "avance" asteriscos
  más a cada lado en cada nueva linea
\*==========================================================*/
void ImprimirTrapecio(int ancho, int alto, int avance) {
  int anchura; /* número de asteriscos */

  anchura = ancho;
  for (int k = 1; k <= alto; k++) {
    ImprimirN( ' ', centro - anchura/2 );
    ImprimirN( '*', anchura );
    printf( "\n" ) ;
    anchura = anchura + 2*avance;
  }
}

/*==========================================================*\
  Procedimiento para imprimir 3 líneas seguidas con:
      ancho
      ancho+2
      y ancho+4 asteriscos
\*==========================================================*/
void ImprimirRama(int ancho) {
  ImprimirTrapecio( ancho, 3, 1 );
}

/*==========================================================*\
  Procedimiento para imprimir un rectángulo de
  ancho x alto asteriscos
\*==========================================================*/
void ImprimirRectangulo(int ancho, int alto){
  ImprimirTrapecio(ancho, alto, 0);
}

/*===================*\
  Programa principal
\*===================*/
int main() {
  int rama; /* Ancho de rama */

  /*-- Imprimir copa --*/
  rama = 1;
  for (int k = 1; k <= 5; k++) {
    ImprimirRama( rama );
    rama = rama + 2;
  }

  /*-- Imprimir tronco --*/
  ImprimirRectangulo( 3, 5 );

  /*-- Imprimir base --*/
  ImprimirRectangulo( 9, 2 );
}
