/** Programa: Cilindro*/
/* C�lculo del �rea y el volumen de un cilindro */

#include <stdio.h>

int main(){
  printf("%s\n", "Dado un cilindro de dimensiones: ");
  printf("%s\n", "radio = 1,5 y altura = 5,6");
  printf("%s", "Su �rea es igual a: ");
  printf("%g\n", 2.0*3.1416*1.5*(1.5+5.6));
  printf("%s", "y su volumen es igual a:");
  printf("%20.8f\n", 3.1416*1.5*1.5*5.6);
}
