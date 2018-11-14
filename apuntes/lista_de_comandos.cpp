# Estructura básica del lenguaje:
#include <stdio.h>
// aquí se declaran variables globales y externas
int main() {
/* Este es un comentario ignorado por el compilador */
  int index; // declaración de una variable
  index = 13;
  printf("El valor de index is %d\n", index);
  index = 27;
  printf("El valor de index is %d\n", index);
  return 0;
}

# Constantes
define PI 3.1416

#Palabras claves del lenguaje C:
auto, double, int, struct, break, else, long, switch, case, enum, register, typedef, char,
extern, return, union, const, float, short, unsigned, continue, for, signed, void, default,
goto, sizeof, volatile, do, If, static, while

# Tipos de datos:
char (1 byte)
int (2 bytes)
float (4 bytes)
double (8 bytes)
void

# Listas:
int digitos [10]; //arreglo de 10 enteros. Los subíndices // válidos son del 0 a 9.
int valores[] = {3,4,5,6,7}; // arreglo de longitud 5

# Sentencias de control:
while(expr){
  //bloque de código a repetir
  break //Interrumpe el bucle
}

do {
  //bloque de código a repetir
  break //Interrumpe el bucle
}
while (expr);

for(expr1; expr2; expr3){
  //bloque de código a repetir
  break //Interrumpe el bucle
}

if(expr){
  //bloque de código
}

if(expr){
  //bloque1
}
else{
  //bloque2
}

switch(expr)
{
  case constante1: instrucciones
  case constante2: instrucciones
  case constante3: instrucciones
  . . .
  default: instrucciones
}
