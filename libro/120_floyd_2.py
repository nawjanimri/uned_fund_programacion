# Programa: Floydl
# Descripción:
#   Este programa imprime el triángulo de Floyd
#   con los números correlativos de 1 a N
#   El valor de N se lee como dato


if __name__ == "__main__":

    n = 0       # último número a imprimir
    linea = 0   # contador de lineas
    primero = 0 # primer número de la linea
    ultimo = 0  # último número de la linea
    
    #-- Leer límite de la serie --#
    n = int(input("¿Límite de la serie? "))

    #-- Imprimir el triángulo mediante un bucle de números --#
    texto = ""
    while (ultimo<n):
        #-- actualizar los límites --#
        linea += 1
        primero = ultimo+1
        ultimo = ultimo+linea
        
        # saltar de linea, si es necesario
        if ultimo>n:
            ultimo = n
            
        #-- imprimir los número k --#
        for k in range(primero, ultimo+1):
            texto += "{:5d}".format(k)

        print(texto)
        texto = ""

    print(texto) # imprime la última línea de números k pendientes

    #-- Acabar la última línea --#
    if n > 0:
        print("")