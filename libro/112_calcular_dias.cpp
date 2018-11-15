/* Programa: Ca1cu1arDias */
/* Este programa calcula los dias que faltan para el cumpleaños de una persona */

#include <stdio.h>
#include <fechas.h>

/*==========================================
En el módulo fechas.h están definidos:
  T_fecha = Tipo de valor FECHA
  LeerFecha = Procedimiento para leer una fecha
  EscribirFecha = Procedimiento para escribir una fecha
  DiasEntre = Función para calcular los dias que hay
  entre dos fechas
  Hoy = Variable en la que se mantiene actualizada la
  fecha de hoy.
=============================================*/
int main() {
  T_fecha fechaCumple;/* Cumpleaños */
  T_fecha fechaHoy;   /* Fecha de hoy */
  int dias;           /* Días que faltan */

  /*--- Obtener la fecha del cumpleaños ------*/{
    printf("¿Cuál es tu próximo cumpleaños?");
    LeerFecha(fechaCumple);
  }

  /*- Obtener la fecha de hoy --*/ {
    fechaHoy = Hoy;
  }

  /*-- Calcular los dias que faltan para el cumpleaños --*/ {
    dias = DiasEntre(fechaHoy, fechaCumple );
  }

  /*-- Imprimir el resultado --*/ {
    printf( "\ nFaltan%4d", dias);
    printf( " dias para tu cumpleaños" );
  }
}
