/* Programa: SumarDosNumeros */
/* Obtener la suma de dos n�meros enteros */

#include <stdio.h>

int main(){
  int dato1, dato2, suma;

  printf("Dar dos n�meros: ");
  scanf("%d", &dato1);
  scanf("%d", &dato2);
  printf("\n");

  suma = dato1 + dato2;
  printf("La suma es %10d\n", suma);
  return 0;
}
