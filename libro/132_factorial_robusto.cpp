/* ********************************************************
* Programa: FactorialRobusto
*
* Descripción:
*   Este programa calcula el factorial de los primeros
*   números naturales, de forma recursiva
******************************************************** */

#include <stdio.h>
#include <limits.h>

int FactorialRobusto( int n ) {
  int f = 1;

  if (n < 0){
    throw 0;
  }

  for (int k = 2; k <= n; k++) {
    if (f > INT_MAX/k){
      throw k;
    }
    f = f * k;
  }
  return f;
}

void EscribirFactorial(int num){
  try{
    printf("%2d! vale:%10d\n", num, FactorialRobusto(num));
  }
  catch (int e){
    printf("%2d! excepción: ", num);
    if (e == 0){
      printf("Factorial de número negativo\n");
    }else{
      printf("Superado límite al evaluar %2d!\n", num);
    }
  }
}

int main() {

  for ( int i = 5; i >= - 2; i--) {
    EscribirFactorial( i );
  }
  printf( "\n" );
  for (int i = 6; i <= 15; i++) {
    EscribirFactorial( i );
  }
}
