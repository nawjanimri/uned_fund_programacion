# Programa: TrianguloDeNumeros
# Descripción:
#   Este programa escribe un triángulo de dígitos.
#   La altura se lee como dato y debe ser menor de 10


if __name__ == "__main__":

    CENTRO = 35   # Posición del eje del triángulo
    INICIAL = 1  # Dígito inicial : superior y laterales */
    nivel = 0
    CARACTERES = "@.o.@.o.@.o.@.o.@.o.@.o.@.o.@.o."
    
    #-- Leer los datos --#
    nivel = int(input("¿Altura del triangulo?"))

    if nivel>20:
        exit()

    linea = ""
    #-- Una iteración por cada línea del triángulo --#
    for altura in range(INICIAL, nivel+1):

        #-- Paso l: Situar primer número de cada linea --#
        for indice in range(1, CENTRO-altura):
            linea +=" "

        #print("{0:1d}".format(INICIAL))

        # -- Paso 2: Primera mitad de la linea del triángulo. 
        #  Escribir números consecutivos hasta altura --#
        for indice in range(INICIAL-1, altura):
            linea += CARACTERES[indice]

        # -- Paso 3°: Segunda mitad de la línea del triángulo.
        #  Escribir números decrecientes hasta Inicial --#
        '''for indice in range(altura-1, INICIAL-1, -1):
            linea += "{0:1d}".format(indice)
        '''
        linea +=linea[-2::-1]

        print(linea)
        linea = ""

    #-- Una iteración por cada línea del triángulo --#
    for altura in range(altura-1, INICIAL-1, -1):
        
        #-- Paso l: Situar primer número de cada linea --#
        for indice in range(1, CENTRO-altura):
            linea +=" "

        #print("{0:1d}".format(INICIAL))

        # -- Paso 2: Primera mitad de la linea del triángulo. 
        #  Escribir números consecutivos hasta altura --#
        for indice in range(INICIAL-1, altura):
            linea += CARACTERES[indice]

        # -- Paso 3°: Segunda mitad de la línea del triángulo.
        #  Escribir números decrecientes hasta Inicial --#
        '''for indice in range(altura-1, INICIAL-1, -1):
            linea += "{0:1d}".format(indice)
        '''

        linea +=linea[-2::-1]

        print(linea)
        linea = ""