# Programa: Floydl
# Descripción:
#   Este programa imprime el triángulo de Floyd
#   con los números correlativos de 1 a N
#   El valor de N se lee como dato


if __name__ == "__main__":

    n = 0      # último número a imprimir
    linea = 1  # contador de lineas*/
    ultimo = 1 # último número de la linea
    
    #-- Leer límite de la serie --#
    n = int(input("¿Límite de la serie? "))

    #-- Imprimir el triángulo mediante un bucle de números --*/
    texto = ""
    for k in range(1, n+1):
        # saltar de linea, si es necesario
        if k > ultimo:
            linea += 1
            ultimo = ultimo+linea
            #-- imprimir los número k --*/
            print(texto)
            texto = ""
        texto += "{:5d}".format(k)

    print(texto) # imprime la última línea de números k pendientes

    #-- Acabar la última línea --*/
    if n > 0:
        print("")