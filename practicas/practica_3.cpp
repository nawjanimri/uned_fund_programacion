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
int anno;                        /* A�o del Mes que se va a representar */
typedef char NombreMes[11];      /* Nombre de un mes, Ej. "Enero" */
typedef NombreMes TipoMes[13];   /* Meses de un a�o, de enero a diciembre */
const TipoMes meses = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO",
                       "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};
typedef int DiasMes[12];
const DiasMes diasmensuales = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* Lee el dato del a�o solicitado al usuario */
void LeerMes(){
  printf("�Mes (1..12)?");
  scanf("%2d", &mes);
  mes = mes-1;
}

/* Lee el dato del a�o solicitado al usuario */
void LeerAnno(){
  printf("�Anno (1601...3000)?");
  scanf("%4d", &anno);
}

/* Informa si el a�o indicado es bisiesto o no*/
int EsBisiesto(int anno){
  if (anno%4==0 && anno%100!=0 || anno%400==0){
    return 1;
  } else{
    return 0;
  }
}

/* Devuelve el n�mero de a�os bisiestos entre el a�o 1600 y el a�o especificado*/
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
      return diasmensuales[mes]+1; /* En febrero se comprueba si es a�o bisiesto, para a�adir 1 d�a m�s*/
  }
  else{
    return diasmensuales[mes];
  }
}

/* Devuelve el n�mero d�as de ese a�o hasta el d�a 1 del mes indicado */
int NumDiasHastaMes(int mes, int anno){
  int num_dias = 0; /* N�mero de d�as hasta el 1 del mes indicado. */

  /* Si el a�o es bisiesto, se suma 1 s�lo si el mes superior a febrero */
  if (EsBisiesto(anno)){
    num_dias = num_dias + NumeroBisiestosHasta(anno) - 1;
  }
  else{
    num_dias = num_dias + NumeroBisiestosHasta(anno);
  }

  /* Se suman los d�as de todos los meses de ese a�o hasta el mes indicado */
  for (int i=0; i<mes; i++){
    num_dias = num_dias + NumDiasMes(i, anno); /* Se le suman los d�as del mes */
  }
  return num_dias;
}

/* Nombre del primer d�a del mes indicado */
int DiaSemanaPrimerDiaDelMes(int mes, int anno){
  int annos;              /* N�mero de a�os desde 1601 hasta el a�o indicado. */
  int num_dias = 0;       /* N�mero de d�as hasta el 1 del mes indicado. */
  int dia_semana;         /* N�mero del d�a de la semana en que cae el d�a 1 del mes indicado.*/
                          /* 0 para lunes, 1 martes, 3 mi�rcoles, etc.*/

  /* Teniendo en cuenta que el 1 de enero de 1601 fue lunes, dia 0*/
  annos      = anno - 1601;
  num_dias   = annos*365 + NumDiasHastaMes(mes, anno);
  dia_semana = num_dias%7; /* D�a de la semana del primer d�a de ese mes*/
  return dia_semana;
}

/* Imprime el calendario del mes y a�o indicados */
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

  /* D�as en blanco hasta el primer d�a del  mes */
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

  /* D�as del  mes */
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

  /* D�as en blanco hasta completar el mes */
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
