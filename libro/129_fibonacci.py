# Programa: Fibonacci
# Descripción:
#   Este programa imprime todos los términos de la serie de Fibonacci 
#   dentro del rango de valores positivos del tipo lnt: (1 .. INT_MAX)
#   Se imprime tabulando a cuatro columnas

import sys

COLUMNAS = 4 # Columnas a imprimir


def ImprimirTabulando(numeros):
    
    texto = ""
    for p in numeros:    
        texto+="{:15d}".format(p)
    print(texto)


def Fibonacci(num_1, num_2):

    fibo  = num_1 + num_2
    num_1 = num_2
    num_2 = fibo
    return (fibo, num_1, num_2)


# Programa principal
if __name__ == "__main__":

    N = sys.maxsize  # Rango de números a analizar
    anterior = 0    # Número "n"
    termino = 1     # # Número "n+Fibonacci"
    fibo = 0        # Número de Fibonacci calculado con números anterior y término
    numeros = []    # Números a imprimir

    numeros.append(0)
    numeros.append(1)

    # Serie de Fibonacci
    while(N - termino >= anterior):
        fibo, anterior, termino = Fibonacci(anterior, termino)
        numeros.append(fibo)

        # Los números se imprimen en 4 columnas
        if len(numeros)==COLUMNAS:
            ImprimirTabulando(numeros)
            numeros = []

    # Imprimir últimos números añadidos a la serie
    if len(numeros)>0:
        ImprimirTabulando(numeros)
        
       
