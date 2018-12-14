
#include <stdio.h>
#include <string.h>

typedef char Cadena[5];
Cadena caracteres = "abcd";

typedef char NombreDia[3];
typedef NombreDia TipoSemana[8];
TipoSemana dias = {"Lu", "Ma", "Mi", "Ju", "Vi", "Sa", "Do"};

typedef char NombreMes[11];      /* Nombre de un mes, Ej. "Enero" */
typedef NombreMes TipoMes[13];   /* Meses de un año, de enero a diciembre */
const TipoMes meses = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "DICIEMBRE"};

typedef int DiasMes[12];
DiasMes diasmensuales = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {


  for(int i = 0; i < 4; i++){
    printf("%c \n", caracteres[i]);
  }

  for(int i = 0; i<4; i++){
    printf("%c \n", caracteres[4-i]);
  }

  for (int i=0; i<7; i++){
    printf("%s \n", dias[i]);
  }

  for (int j=0; j<12; j++){
    printf("%2d - ", diasmensuales[j]);
  }
  printf("mes %s \n", meses[0]);

  printf("%-12s          %4d\n", "enero", 1645);
  printf("%-12s          %4d\n", "septiembre", 1645);
  printf("%s           %4d\n", "septiembre", 1645);

  printf("%2d   ", int(2.85));
}

