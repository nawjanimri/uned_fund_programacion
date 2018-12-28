
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


typedef int TipoMedidas[100];       /* Medidas de una presa */
typedef char TipoTexto[7];         /* Nombre de la presa */

typedef struct Presa{

  TipoMedidas medidas;
  TipoTexto nombre;
  int capacidad;                  /* Capacidad de la presa */
  int i_ultima_medida;            /* Referencia de la última medida añadida */

  /* Alta de presa */
  Presa Init(TipoTexto nombrepresa, int capacidadpresa);
  /* Nueva medida */
  void NuevaMedicion(int volumen);
  /* Imprime las medidas */
  void ImprimeMedidas();
};

Presa Presa::Init(TipoTexto nombrepresa, int capacidadpresa){
    strcpy(nombre, nombrepresa);
    capacidad = capacidadpresa;
    i_ultima_medida = 0;
    return Presa;
  }

void Presa::NuevaMedicion(int volumen){
  if (volumen > capacidad){
    printf("El volumen embalsado supera la capacidad de la presa.\n");
    return;
  }
  medidas[i_ultima_medida] = volumen;
  i_ultima_medida = i_ultima_medida + 1;
}

void Presa::ImprimeMedidas(){
  printf("Medidas de la presa %s:\n", nombre);
  for (int i = 0; i<i_ultima_medida; i++){
    printf("Fecha X medida %d \n", medidas[i]);
  }
}

int main() {

  /*Presa presa1 = {{},"Jucar", 15000, 0};*/
  Presa presa1 = Presa.Init("Presa1", 12000);
  /*presa1.NuevaMedicion(500000);*/
  presa1.NuevaMedicion(2000);
  presa1.ImprimeMedidas();


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

