/** Programa: SumarNumeros*/
/* Este peograma calcula e imprime la suma
de los números correlativos desde 4 hasta 45.

El algoritmo empleado es del de la progresión:
suma = (Final - Inicial + 1) * (Inicial + Final)/2 */

#include <stdio.h>

int main(){
  printf("La suma de los números desde 4 hasta 45\n");
  printf("Es igual a:");
  printf("%5d\n", (45-4+1)*(4+45)/2);
}
