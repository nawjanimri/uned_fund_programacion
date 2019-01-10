/* ********************************************************
* Programa: Calendario
*
* Descripción:
*  Programa para el cálculo del dia de la semana
*  que corresponde a una fecha comprendida entre:
*  1/1/1989 Y 31/ 12/2088
******************************************************** */

#include <stdio.h>

typedef enum TipoDia {
  Lunes, Martes, Miercoles, Jueves, Viernes, Sabado,
  Domingo
};

typedef enum TipoMes {
  Enero, Febrero, Marzo, Abril, Mayo, Junio , Julio,
  Agosto, Septiembre, Octubre, Noviembre, Diciembre
};

typedef struct TipoFecha {
  int dia;
  TipoMes mes;
  int anno;
};

/*=================================================
  Función para sumar dias de la semana cíclicamente
  =================================================*/
TipoDia SumarDias( TipoDia dia, int n ) {
  const int DiasSemana = 7;
  int aux;

  aux = (int(dia) + n) % DiasSemana;
  return TipoDia(aux);
}

/*=================================================
  Función para calcular el dia de la semana
  que corresponde a una fecha
  =================================================*/
TipoDia DiaDeLaSemana( TipoFecha fecha ) {
  const int OrigenA = 89; /*Primer anno que se considera */
  TipoDia TreintaUnoDiciembre88 = Sabado; /*Ese dia fue sabado*/

  bool bisiesto;
  int IncreBisis, IncreAnnos, IncreDias;
  TipoMes M = fecha.mes;
  int A = fecha.anno;

  /* El incremento de días de la semana que cada mes
    introduce respecto al 31 de enero */
  if (M == Enero) {
    IncreDias = 0;
  } else if (M == Febrero) {
    IncreDias = 3;
  } else if (M == Marzo) {
    IncreDias = 3;
  } else if (M == Abril) {
    IncreDias = 6;
  } else if (M == Mayo) {
    IncreDias = 1;
  } else if (M == Junio) {
    IncreDias = 4;
  } else if (M == Julio) {
    IncreDias = 6;
  } else if (M == Agosto) {
    IncreDias = 2;
  } else if (M == Septiembre) {
    IncreDias = 5;
  } else if (M == Octubre) {
    IncreDias = 0;
  } else if (M == Noviembre) {
    IncreDias = 3;
  } else {
    IncreDias = 5;
  }

  bisiesto = (A % 4) == 0;
  if (A < OrigenA) {
    A=A+100;  /* Si el año es inferior a 89 se considera que es posterior al 2000 */
  }

  IncreAnnos = A - OrigenA;    /* Años pasados desde el 89 */
  IncreBisis = IncreAnnos/4;  /* Bisiestos pasados */
  IncreDias = IncreDias + fecha.dia + IncreAnnos + IncreBisis;
  if (bisiesto && (M > Febrero)) {
    IncreDias++;
  }

  return SumarDias(TreintaUnoDiciembre88, IncreDias);
}

/*=================================================
  Procedimiento para escribir el día de la semana
  =================================================*/
void EscribirDia(TipoDia S) {
  if (S == Lunes){
    printf( "Lunes" );
  } else if (S == Martes) {
    printf( "Martes" );
  } else if (S == Miercoles) {
    printf( "Miércoles" );
  } else if (S == Jueves) {
    printf( "Jueves" );
  } else if (S == Viernes){
    printf( "Viernes" );
  } else if (S == Sabado) {
    printf( "Sábado" );
  } else {
    printf( "Domingo" );
  }
}

/*=================================================
  Procedimiento para leer una fecha (mes en número)
  =================================================*/
void LeerFecha( TipoFecha & fecha ) {
  int mes;
  scanf( "%d/%d/%d", &fecha.dia , &mes , &fecha.anno );
  fecha.mes = TipoMes( mes-1 );
  if (fecha.anno >= 100) {
    fecha.anno = fecha.anno % 100; /*Los años se ponen con 2 cifras */
  }
}

/*=====================================
  Procedimiento para escribir una fecha
  =====================================*/
void EscribirFecha( TipoFecha fecha ) {
  printf( "%02d/%02d/%02d", fecha.dia, int(fecha.mes+1), fecha.anno );
}

/*==================
  Programa principal
  ==================*/
int main () {
  TipoFecha fecha; /* fecha a manejar */
  char tecla;      /* tecla pulsada */
  TipoDia Hoy;
  TipoMes Pasado;

  Hoy = Miercoles;
  Pasado = Noviembre;
  tecla = 'S';

  while (tecla!='N') {
    printf( "¿Dia Mes Año(DD/ MM/ AA)? " ) ;
    LeerFecha( fecha );
    printf( "Fecha : " );
    EscribirFecha( fecha ) ;
    printf(" Día de la semana: " ) ;
    EscribirDia( DiaDeLaSemana( fecha) );
    tecla = ' ';
    printf( "\n\n¿Otra Fecha(S/N)? " );
    while ((tecla != 'S') && (tecla != 'N')) {
      scanf( "%c" , &tecla );
    }
  }
}

