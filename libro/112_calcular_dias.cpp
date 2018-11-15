/* Programa: Ca1cu1arDias */
/* Este programa calcula los dias que faltan para el cumplea�os de una persona */

#include <stdio.h>
#include <fechas.h>

/*==========================================
En el m�dulo fechas.h est�n definidos:
  T_fecha = Tipo de valor FECHA
  LeerFecha = Procedimiento para leer una fecha
  EscribirFecha = Procedimiento para escribir una fecha
  DiasEntre = Funci�n para calcular los dias que hay
  entre dos fechas
  Hoy = Variable en la que se mantiene actualizada la
  fecha de hoy.
=============================================*/
int main() {
  T_fecha fechaCumple;/* Cumplea�os */
  T_fecha fechaHoy;   /* Fecha de hoy */
  int dias;           /* D�as que faltan */

  /*--- Obtener la fecha del cumplea�os ------*/{
    printf("�Cu�l es tu pr�ximo cumplea�os?");
    LeerFecha(fechaCumple);
  }

  /*- Obtener la fecha de hoy --*/ {
    fechaHoy = Hoy;
  }

  /*-- Calcular los dias que faltan para el cumplea�os --*/ {
    dias = DiasEntre(fechaHoy, fechaCumple );
  }

  /*-- Imprimir el resultado --*/ {
    printf( "\ nFaltan%4d", dias);
    printf( " dias para tu cumplea�os" );
  }
}
