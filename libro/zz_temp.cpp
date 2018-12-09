
#include <stdio.h>

typedef char Cadena[5];
Cadena caracteres = "abcd";

int main() {
  for(int i = 0; i < 4; i++){
    printf("%c \n", caracteres[i]);
  }
}

