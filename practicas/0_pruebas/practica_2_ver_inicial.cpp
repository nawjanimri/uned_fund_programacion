/* *************************************
* NOMBRE: #Jose Manuel#
* PRIMER APELLIDO: #Alvarez#
* SEGUNDO APELLIDO: #Bautista#
* DNI: #29488955B#
* EMAIL: #jalvarez1623@alumno.uned.es#
***************************************/

#include <stdio.h>

int lado;                /* Lado del rombo */
typedef char Cadena[21]; /* caracteres del rombo */
const Cadena caracteres = "@.o.@.o.@.o.@.o.@.o.";
int n_lineas;           /* N�mero de l�neas que forman cada parte del rombo */
int n_espacios;         /* N�mero de espacios al inicio de cada l�nea del rombo */
int n_caracteres;       /* N�mero de caracteres que se imprimen en cada l�nea del rombo */

void LeerLadoRombo(){
  printf("�Lado del rombo? ");
  scanf("%d", &lado);
}

void RomboSuperior(){
  n_lineas = lado;
  for (int linea = 0; linea<n_lineas; linea++){

    /* Tri�ngulo derecho */{
      n_espacios   = lado-linea-1;
      n_caracteres = linea+1;

      /* Espacios antes de los caracteres */
      for(int i = 0; i<n_espacios; i++){
        printf(" ");
      }
      /* Caracteres */
      for(int j = 0; j<n_caracteres; j++){
        printf("%c", caracteres[j]);
      }
    }
    /* Tri�ngulo izquierdo */{
      /* Caracteres */
      for(int k = 2; k<n_caracteres+1; k++){
        printf("%c", caracteres[n_caracteres-k]);
      }
    }
    printf("\n");
  }
}

void RomboInferior(){
  n_lineas = lado;
  for (int linea = 1; linea<n_lineas; linea++){

    /* Tri�ngulo derecho */{
      n_espacios   = linea;
      n_caracteres = lado-linea;

      /* Espacios antes de los caracteres */
      for(int i = 0; i<n_espacios; i++){
        printf(" ");
      }
      /* Caracteres */
      for(int j = 0; j<n_caracteres; j++){
        printf("%c", caracteres[j]);
      }
    }
    /* Tri�ngulo izquierdo */{
      /* Caracteres */
      for(int k = 2; k<n_caracteres+1; k++){
        printf("%c", caracteres[n_caracteres-k]);
      }
    }
    printf("\n");
  }
}


/*===================*\
  Programa principal
\*===================*/
int main(){

  LeerLadoRombo();
  printf("\n");

  if ((lado>0)&&(lado<21)){
    RomboSuperior();
    RomboInferior();
  }
}
