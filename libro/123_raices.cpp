/* ********************************************************
* Programa: Raices
*
* Descripción:
*   Este programa calcula las raíces de una ecuación
*   de segundo grado: ax2 + bx + c
***********************************************************/

#include <stdio.h>
#include <math.h>

/* Función para calcular el discriminante*/
float Discriminante( float a, float b, float c ) {
  return b*b - 4.0*a*c;
}

/* Procedimiento de lectura de un coeficiente */
void LeerValor( int grado, float & valor) {
  printf( "¿Coeficiente de grado %ld? ", grado );
  scanf( "%f" ,&valor );
}

int main() {
  float valorA, valorB , valorC;  /* Coeficientes de la ecuación */
  float parteUno, parteDos;       /* Variables intermedias de cálculo */
  float valorD;                   /* Discriminante de la ecuación */

  LeerValor( 2, valorA );
  LeerValor( 1, valorB );
  LeerValor( 0, valorC );
  if (valorA == 0.0) {
    if (valorB == 0.0) {
      if (valorC == 0.0) {
        printf( "Ecuación no válida\ n" );
      } else {
        printf( "Solución imposible\ n" );
      }
    } else {
      printf( "Raíz única %10.2f\ n", -valorC/ valorB );
    }
  }else{
    parteUno = -valorB/( 2.0*valorA);
    valorD = Discriminante( valorA, valorB, valorC );
    if (valorD >= 0.0) {
      parteDos = sqrt(valorD)/(2.0*valorA);
      printf( "Raíces reales : \ n" );
      printf( "%10.2f Y \ n", parteUno+parteDos );
      printf( "%10.2f \ n", parteUno-parteDos );
    } else {
        parteDos = sqrt(-valorD)/(2.0*valorA);
        printf( "Raíces complejas :\n" );
        printf( "Parte real =       %10.2f y\n", parteUno );
        printf( "Parte imaginaria = %10.2f \n", parteDos );
    }
  }
}
