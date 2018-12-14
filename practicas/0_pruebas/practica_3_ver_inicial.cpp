/* *************************************
* NOMBRE: #Jose Manuel#
* PRIMER APELLIDO: #Alvarez#
* SEGUNDO APELLIDO: #Bautista#
* DNI: #29488955B#
* EMAIL: #jalvarez1623@alumno.uned.es#
***************************************/

#include <stdio.h>

int mes;                         /* Mes que se va a representar del calendario */
int anno;                        /* A�o del Mes que se va a representar */
int bisiesto;                    /* 1 si es a�o bisiesto, 0 si no lo es*/
typedef char NombreMes[11];      /* Nombre de un mes, Ej. "Enero" */
typedef NombreMes TipoMes[13];   /* Meses de un a�o, de enero a diciembre */
const TipoMes meses = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "DICIEMBRE"};
typedef char NombreDia[3];       /* Nombre de un d�a, Ej. "Lu" para lunes */
typedef NombreDia TipoSemana[8]; /* D�as de una semana, de lunes a domingo */
const TipoSemana dias = {"LU", "MA", "MI", "JU", "VI", "SA", "DO"};
typedef int DiasMes[12];
const DiasMes diasmensuales = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int unoenero1601 = 0;     /* Fu� lunes, primer d�a de la semana, �ndice 0. */

void LeerMes(){
  printf("�Mes (1..12)?");
  scanf("%2d", &mes);
  mes = mes-1;
}

void LeerAnno(){
  printf("�Anno (1601...3000)?");
  scanf("%4d", &anno);
}

int EsBisiesto(int anno){
  if (anno%4==0){
    if (anno%100==0){
      if(anno%400==0){
        return 1; /* S� es bisiesto */
      }
      else{
        return 0; /* No es bisiesto */
      }
    }
    else{
      return 1; /* S� es bisiesto */
    }
  }
  else{
    return 0; /* No es bisiesto */
  }
}

int NumeroBisiestosHasta(int anno){
  int num_bisiestos = 0;          /* N�mero de a�os bisiestos hasta el a�o indicado */
  for (int i=1601; i<anno; i++){
    num_bisiestos = num_bisiestos + EsBisiesto(i);
  }

  printf("Hasta el anno %4d hay %4d bisiestos \n", anno, num_bisiestos);

  return num_bisiestos;
}

int PrimerDiaDelMes(int mes, int anno){
  int num_dias; /* N�mero de d�as que han trascurrido entre el 1 enero 1601 y el mes indicado */

  /* Numero de d�as hasta el 1 de enero del a�o indicado */
  int num_annos;
  int num_bisiestos;
  int num_dias_hasta_1_enero;
  int dia_del_1_enero;
  int dia_1_del_mes;
  int num_dias_hasta_mes;
  typedef char nombre[3];

  num_bisiestos = NumeroBisiestosHasta(anno);
  num_annos = anno - 1601;
  num_dias_hasta_1_enero = num_annos*365 + num_bisiestos;

  printf("numero de dias hasta 1 enero de %4d = %5d \n", anno, num_dias_hasta_1_enero);

  /* El primer d�a de ese a�o cae en el d�a */
  dia_del_1_enero = num_dias_hasta_1_enero%7;
  printf("Cae en el d�a de la semana = %s \n", dias[dia_del_1_enero]);

  /* Y el primer d�a de ese mes cae en el d�a */
  num_dias_hasta_mes = 0;
  for (int i=0; i<mes; i++){
    if (i==1){
      if (EsBisiesto(anno)==1){
        num_dias_hasta_mes = num_dias_hasta_mes+29;
      }
      else{
        num_dias_hasta_mes = num_dias_hasta_mes+28;
      }
    }
    else{
      num_dias_hasta_mes = num_dias_hasta_mes + diasmensuales[i];
    }
  }

  printf("N�mero de d�as hasta mes %s = %3d \n", meses[mes], num_dias_hasta_mes);

  num_dias_hasta_mes = num_dias_hasta_1_enero + num_dias_hasta_mes;
  dia_1_del_mes = num_dias_hasta_mes%7;

  printf("Y el primer d�a del mes %s cae en el d�a de la semana = %s \n", meses[mes], dias[dia_1_del_mes]);

  return dia_1_del_mes;
}

void ImprimeMes(int mes, int anno, int primerdia){

  int num_dias_mes;
  int dia_semana;


  num_dias_mes = diasmensuales[mes];
  printf("%s                  %4d    \n", meses[mes], anno);
  printf("===========================\n");
  printf("LU  MA  MI  JU  VI | SA  DO\n");
  printf("===========================\n");


  /* D�as en blanco hasta el primer d�a del  mes */
  dia_semana = 0; /* Lunes */
  for (int i=0; i<primerdia; i++){
    printf("  . ");
    dia_semana = dia_semana+1;
  }

  /* D�as del  mes */
  for (int i=1; i<num_dias_mes+1; i++){
    dia_semana = dia_semana+1;
    printf(" %2d ", i);
    if(dia_semana==7){
      printf("\n");
      dia_semana = 0;
    }
  }

  /* D�as en blanco hasta completar el mes */
  for (int i=dia_semana; i<7; i++){
    printf("  . ");
    dia_semana = dia_semana+1;
  }
}



/*===================*\
  Programa principal
\*===================*/
int main(){

  int primerdia;
  LeerMes();
  LeerAnno();

  printf("Mes %s y anno %4d", meses[mes], anno);

  printf("\n");


  if ((anno>1600)&&(anno<3001)){
    bisiesto  = EsBisiesto(anno);

    printf("�Es bisiesto? = %1d \n", bisiesto);

    primerdia = PrimerDiaDelMes(mes, anno);
    ImprimeMes(mes, anno, primerdia);
  }
}
