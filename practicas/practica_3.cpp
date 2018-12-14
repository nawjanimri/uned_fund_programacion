/* *************************************
* NOMBRE: #Jose Manuel#
* PRIMER APELLIDO: #Alvarez#
* SEGUNDO APELLIDO: #Bautista#
* DNI: #29488955B#
* EMAIL: #jalvarez1623@alumno.uned.es#
***************************************/

/* ERROR EN ENERO 2340. EL MES DEBERÍA EMPEZAR EN LUNES Y NO EN MARTES, COMO IMPRIME EL CÓDIGO ACTUAL


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

void LeerMes(){
  printf("¿Mes (1..12)?");
  scanf("%2d", &mes);
  mes = mes-1;
}

void LeerAnno(){
  printf("¿Anno (1601...3000)?");
  scanf("%4d", &anno);
}

int EsBisiesto(int anno){
  if (anno%4==0 && anno%100!=0 || anno%400==0){
    return 1;
  } else{
    return 0;
  }
}

/* BORRARRRRR */
/* Número de años bisiestos hasta el año indicado */
int NumeroBisiestosHasta2(int anno){
  int num_bisiestos = 0;
  for (int i=1601; i<anno; i++){
    num_bisiestos = num_bisiestos + EsBisiesto(i);
  }
  return num_bisiestos;
}


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

  /*
  if (anno>2800){
    num_bisiestos = num_bisiestos+3;
  }
  else if (anno>2400){
    num_bisiestos = num_bisiestos+2;
  }
  else if (anno>2000){
        num_bisiestos = num_bisiestos+1;
  }
  */

  return num_bisiestos;
}

/* Nombre del primer día del mes indicado */
int DiaSemanaPrimerDiaDelMes(int mes, int anno){
  int annos;              /* Número de años desde 1601 hasta el año indicado. */
  int dias_entre_annos;   /* Numero de días hasta el 1 de enero del año indicado. */
  int dias_hasta_mes = 0; /* Número de días hasta el 1 del mes indicado. */
  int dia_semana;         /* Número del día de la semana en que cae el día 1 del mes indicado.*/

  annos = anno - 1601;
  dias_entre_annos = annos*365 + NumeroBisiestosHasta(anno);

  /* Número días de ese año hasta el mes indicado */
  for (int i=0; i<mes; i++){
    if (i==1){                                      /* En febrero se comprueba si es año bisiesto */
      if (EsBisiesto(anno)==1){
        dias_hasta_mes = dias_hasta_mes+29;
      }
      else{
        dias_hasta_mes = dias_hasta_mes+28;
      }
    }
    else{
      dias_hasta_mes = dias_hasta_mes + diasmensuales[i]; /* Se le suman los días del mes */
    }
  }

  /* Teniendo en cuenta que el 1 de enero de 1601 fue lunes, dia 0*/
  dias_hasta_mes = dias_entre_annos + dias_hasta_mes; /* Número de días hasta el mes indicado: */
  dia_semana = dias_hasta_mes%7; /* Día de la semana del primer día de ese mes*/
  return dia_semana;
}

void ImprimeMes(int mes, int anno){
  int num_dias_mes;
  int dia_semana;
  int primerdia;
  int espacios;

  primerdia = DiaSemanaPrimerDiaDelMes(mes, anno);
  num_dias_mes = diasmensuales[mes];

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

  int num_bisiestos;

  LeerMes();
  LeerAnno();
  printf("\n");


  /*
  for (int i= 1601; i<1701; i++){
    printf("Numero de bisiestos hasta %4d = %4d \n", i, NumeroBisiestosHasta(i));
  }
  */


  if (anno>1600 && anno<3001){
    ImprimeMes(mes, anno);
  }


  /*
  for (int i = 1601; i<4000; i++){
    for (int j=0; j<12; j++){
      if ((i>1600)&&(i<3001)){
        ImprimeMes(j, i);
      }
    }
  }
  */
}
