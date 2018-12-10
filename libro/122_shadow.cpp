/* ********************************************************
* Programa: Shadow
*
* Descripción:
*   Ejemplo de ocultación de nombres globales
******************************************************** */

#include <stdio.h>

int Global;
int Exterior = 50;

void Interior(){
  const int Exterior = 30;
  Global = Exterior*Exterior;
}

void Secundario(){
  Interior();
  Exterior = Global/2;
}

void Primario( int & Exterior, int & Interior) {
  Secundario();
  Interior = Exterior - 5;
}


int main() {
  int Interior = 40;

  Primario( Interior , Interior );
  printf( "%5d%5d%5d\n", Global, Exterior, Interior);
}
