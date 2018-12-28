# Programa: Fibonacci2
# Descripción:
#   Este programa imprime todos los términos de la serie de Fibonacci 
#   dentro del rango de valores positivos del tipo lnt: (1 .. INT_MAX)
#   Se imprime tabulando a cuatro columnas

import sys

numeros = [] # Números a imprimir

def Fibonacci(num_1, num_2):

    fibo  = num_1 + num_2
    num_1 = num_2
    num_2 = fibo
    return (fibo, num_1, num_2)


# imprimir tabulando a TABultima columnas de TAB_ancho caracteres
def ImprimirTabulando(numeros, tab_ancho):
    
    texto = ""
    for numero in numeros:    
        texto+=("{num:{fill}{width}d}".format(num=numero, width=tab_ancho, fill= " "))
    print(texto)



# Programa principal
if __name__ == "__main__":

    TAB_columna = 1     # columna a imprimir 
    TAB_columnas = 6    # número de columnas a imprimir 
    TAB_ancho = 11      # ancho de cada columna 
    N = sys.maxsize     # Rango de números a analizar
    anterior = 0        # Número "n"
    termino = 1         # # Número "n+Fibonacci"
    fibo = 0            # Número de Fibonacci calculado con números anterior y término
    numeros = []        # Números a imprimir

    numeros.append(0)   # Primeros números de la serie
    numeros.append(1)
    TAB_columna +=2

    # Serie de Fibonacci
    while(N - termino >= anterior):
        fibo, anterior, termino = Fibonacci(anterior, termino)
        
        #ImprimirTabulando(fibo, TAB_ancho)
        numeros.append(fibo)

        TAB_columna += 1
        # Los números se imprimen en "TAB_ULTIMA" columnas
        # ImprimirTabulando(numeros)      
        if TAB_columna>TAB_columnas:
            TAB_columna = 1
            ImprimirTabulando(numeros, TAB_ancho)
            numeros = []
    
    # Imprimir últimos números añadidos a la serie
    if len(numeros)>0:
        ImprimirTabulando(numeros, TAB_ancho)
        
