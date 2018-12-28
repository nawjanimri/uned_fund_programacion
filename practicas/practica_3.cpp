/* *************************************
* NOMBRE: #Jose Manuel#
* PRIMER APELLIDO: #Alvarez#
* SEGUNDO APELLIDO: #Bautista#
* DNI: #29488955B#
* EMAIL: #jalvarez1623@alumno.uned.es#
***************************************/

#include <stdio.h>
#include <string.h>

int mes;                         /* Mes que se va a representar del calendario */
int anno;                        /* Año del Mes que se va a representar */
typedef char NombreMes[11];      /* Nombre de un mes, Ej. "Enero" */
typedef NombreMes TipoMes[13];   /* Meses de un año, de enero a diciembre */
const TipoMes meses = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO",
                       "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};
typedef int DiasMes[12];
const DiasMes diasmensuales = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* Lee el dato del año solicitado al usuario */
void LeerMes(){
  printf("¿Mes (1..12)?");
  scanf("%2d", &mes);
  mes = mes-1;
}

/* Lee el dato del año solicitado al usuario */
void LeerAnno(){
  printf("¿Anno (1601...3000)?");
  scanf("%4d", &anno);
}

/* Informa si el año indicado es bisiesto o no*/
int EsBisiesto(int anno){
  if (anno%4==0 && anno%100!=0 || anno%400==0){
    return 1;
  } else{
    return 0;
  }
}

/* Devuelve el número de años bisiestos entre el año 1600 y el año especificado*/
int NumeroBisiestosHasta(int anno){
  int annos;
  int num_bisiestos = 0;
  int centenas;
  int cuatrocenas;

  annos = anno - 1600;
  num_bisiestos = int(annos/4);

  centenas = int(annos/100);
  num_bisiestos = num_bisiestos-centenas;

  cuatrocenas = int(annos/400);
  num_bisiestos = num_bisiestos+cuatrocenas;

  return num_bisiestos;
}

int NumDiasMes(int mes, int anno){
  if((mes==1)&&(EsBisiesto(anno))){
      return diasmensuales[mes]+1; /* En febrero se comprueba si es año bisiesto, para añadir 1 día más*/
  }
  else{
    return diasmensuales[mes];
  }
}

/* Devuelve el número días de ese año hasta el día 1 del mes indicado */
int NumDiasHastaMes(int mes, int anno){
  int num_dias = 0; /* Número de días hasta el 1 del mes indicado. */

  /* Si el año es bisiesto, se suma 1 sólo si el mes superior a febrero */
  if (EsBisiesto(anno)){
    num_dias = num_dias + NumeroBisiestosHasta(anno) - 1;
  }
  else{
    num_dias = num_dias + NumeroBisiestosHasta(anno);
  }

  /* Se suman los días de todos los meses de ese año hasta el mes indicado */
  for (int i=0; i<mes; i++){
    num_dias = num_dias + NumDiasMes(i, anno); /* Se le suman los días del mes */
  }
  return num_dias;
}

/* Nombre del primer día del mes indicado */
int DiaSemanaPrimerDiaDelMes(int mes, int anno){
  int annos;              /* Número de años desde 1601 hasta el año indicado. */
  int num_dias = 0;       /* Número de días hasta el 1 del mes indicado. */
  int dia_semana;         /* Número del día de la semana en que cae el día 1 del mes indicado.*/
                          /* 0 para lunes, 1 martes, 3 miércoles, etc.*/

  /* Teniendo en cuenta que el 1 de enero de 1601 fue lunes, dia 0*/
  annos      = anno - 1601;
  num_dias   = annos*365 + NumDiasHastaMes(mes, anno);
  dia_semana = num_dias%7; /* Día de la semana del primer día de ese mes*/
  return dia_semana;
}

/* Imprime el calendario del mes y año indicados */
void ImprimeMes(int mes, int anno){
  int num_dias_mes;
  int dia_semana;
  int primerdia;
  int espacios;

  primerdia = DiaSemanaPrimerDiaDelMes(mes, anno);
  num_dias_mes = NumDiasMes(mes, anno);

  /* Cabecera del calendario */
  printf("%-10s             %4d\n", meses[mes], anno);
  printf("===========================\n");
  printf("LU  MA  MI  JU  VI | SA  DO\n");
  printf("===========================\n");

  /* Días en blanco hasta el primer día del  mes */
  dia_semana = 0; /* Lunes */
  for (int i=0; i<primerdia; i++){
    dia_semana = dia_semana+1;
    if(dia_semana==5){
      printf(" . | ");
    }
    else{
       printf(" .  ");
    }
  }

  /* Días del  mes */
  for (int i=1; i<num_dias_mes+1; i++){
    dia_semana = dia_semana+1;
    if(dia_semana==5){
      printf("%2d | ", i);
    }
    else{
      printf("%2d  ", i);
      if(dia_semana==7){
        printf("\n");
        dia_semana = 0;
      }
    }
  }

  /* Días en blanco hasta completar el mes */
  if (dia_semana > 0){
    for (int i=dia_semana; i<7; i++){
      dia_semana = dia_semana+1;
      if(dia_semana==5){
        printf(" . | ");
      }
      else{
         printf(" .  ");
      }
    }
  }
  printf("\n");
}

/*=====================*/
/*  Programa principal */
/*=====================*/
int main(){

  LeerMes();
  LeerAnno();

  if ((mes>=0 && mes<12)&&(anno>1600 && anno<3001)){
    printf("\n");
    ImprimeMes(mes, anno);
  }
}
