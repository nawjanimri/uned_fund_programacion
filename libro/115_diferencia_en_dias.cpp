/* ********************************************************
* Programa: DiferenciaEnDias
*
* Descripción:
*   Este programa calcula los días entre dos fechas de forma
*   aproximada, contando todos meses de 30 días, y los años de 365
********************************************************* */

#include <stdio.h>

int main() {

  int dia1, mes1, anno1;      /* primera fecha */
  int dia2, mes2, anno2;      /* segunda fecha */
  int diasFecha1, diasFecha2; /* días desde inicio del año */
  int diferencia;             /* diferencia en días */

  /*-- Leer las fechas--*/ {
    printf( "¿Primera fecha (dd,mm,aaaa)?" );
    scanf( "%d,%d,%d", &dia1, &mes1, &anno1 );
    printf( "¿Segunda fecha (dd,mm,aaaa)?" );
    scanf( "%d,%d,%d", &dia2, &mes2, &anno2 );
  }
  /*--Calcular la diferencia--*/{
    /*--Calcular los días desde principio del año--*/ {
      diasFecha1 = (mes1 - 1)*30 + dia1;
      diasFecha2 = (mes2 - 1)*30 + dia2;
    }
    /*--Ca1cular la diferencia total en días--*/ {
      diferencia = (anno2 - anno1)*365 + diasFecha2 - diasFecha1;
    }
  }
  /*--Imprimir el resultado--*/ {
    printf( "Desde %2d/%2d/%4d \n", dia1, mes1, anno1);
    printf( "Hasta %2d/%2d/%4d \n", dia2, mes2, anno2);
    printf( "Hay %5d días \n", diferencia);
  }
}
