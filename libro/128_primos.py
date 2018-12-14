# Programa: Primos
# Descripción:
#  Este programa imprime una tabla de números primos, tabulando a cuatro columnas

# Función para ver si un valor "k" es un número primo
COLUMNAS = 4 # Columnas a imprimir

def EsPrimo(k):
    
    for d in range(2, k):
        if(k%d == 0):
            return False
    return True


def ImprimirTabulando(primos):
    
    texto = ""
    for p in primos:    
        texto+="{:15d}".format(p)

    print(texto)


# Programa principal
if __name__ == "__main__":

    N = 100     # Rango de números a analizar si son primos
    primos = [] # Números primos a imprimir
    
    # Se calculan los números primos y se imprimen
    for k in range(1, N+1):
        if (EsPrimo(k)):
            primos.append(k)
        
        # Los números primos se imprimen en 4 columnas
        if len(primos)==COLUMNAS:
            ImprimirTabulando(primos)
            primos = []

    ImprimirTabulando(primos) # Imprimo última fila de números primos
  