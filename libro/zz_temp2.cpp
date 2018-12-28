#include <stdio.h>

typedef int TipoMedidas[100];       /* Medidas de una presa */
typedef char TipoTexto[50];         /* Nombre de la presa */

typedef struct Presa {

  TipoMedidas medidas;
  TipoTexto nombre;
  Cadena caracteres;
  int capacidad;                      /* Capacidad de la presa */
  int i_ultima_medida;            /* Referencia de la última medida añadida */

  /* Nueva medida */
  void NuevaMedicion(int volumen);
  void ImprimeMedidas();
};

int main() {

}
