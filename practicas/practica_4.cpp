/* *************************************
* NOMBRE: #Jose Manuel#
* PRIMER APELLIDO: #Alvarez#
* SEGUNDO APELLIDO: #Bautista#
* DNI: #29488955B#
* EMAIL: #jalvarez1623@alumno.uned.es#
***************************************/

#include <stdio.h>
#include <string.h>

char opcion;  /* Opción del menú seleccionada */

typedef struct Presa{
  typedef int MedidasPresa[100];      /* Medida de una presa */
  typedef MedidasPresa medidas = {};  /* Medidas de una presa */

  typedef char NombrePresa[50];       /* Nombre de la presa */
  NombrePresa nombre;

  /* Nueva medida */
  void NuevaMedicion();
}


typedef struct Cuenca{

  typedef Presa presas;               /* Presas de la Cuenca */
  typedef char NombreCuenca[50];       /* Nombre de la Cuenca */
  NombreCuenca nombre;

  /* Alta presa */
  void AltaPresa();
}

typedef struct Region{
  typedef Cuenca cuencas[3];          /* Cuencas de la región */

  /* Alta cuenca/presa */
  void AltaCuenca();

  /* Registros */
  void Registros();

  /* Variaciones mensuales */
  void Variaciones();
}

void AltaCuenca(){
  printf("Alta cuenca \n");
}

void NuevaMedicion(){
  printf("Nueva medición \n");
}

void Registros(){
  printf("Registros \n");
}

void VariacionesMensuales(){
  printf("Variaciones Mensuales \n");
}

void Salir(){
  printf("Salir \n");
}

void Menu(){

  printf("Gestión de Reservas de Agua\n");
  printf("       Alta cuenca/presa          (Pulsar A)\n");
  printf("       Nueva medición             (Pulsar N)\n");
  printf("       Registros                  (Pulsar R)\n");
  printf("       Variaciones mensuales      (Pulsar V)\n");
  printf("       Salir                      (Pulsar S)\n");
  printf("Teclear una opcion valida (A|N|R|V|S)? ");
  scanf(" %c", &opcion);

  switch (opcion)
  {
    case 'A':
      AltaCuenca();
      break;
    case 'N':
      NuevaMedicion();
      break;
    case 'R':
      Registros();
      break;
    case 'V':
      VariacionesMensuales();
      break;
    case 'S':
      Salir();
      break;
  }
}

/*=====================*/
/*  Programa principal */
/*=====================*/
int main(){
  opcion = 'n';

  while (opcion!='S'){
    Menu();
  }
}
