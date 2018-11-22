# Programa: Baldosas
# Este programa calcula el costo de las baldosas necesarias para cubrir una
# habitación rectangular


if __name__ == "__main__":

    largo = 0           # Dimensiones de la habitación en m2 #
    ancho = 0           # Dimensiones de la habitación en m2 #
    lado = 0            # Lado de la baldosa en cm #
    nLargo = 0          # Número de baldosas a lo largo #
    nAncho = 0          # Número de baldosas a lo ancho #
    baldosas = 0        # Número total de baldosas #
    precio = 0.0        # Precio de cada baldosa #
    Coste = 0.0         # Coste total #

    #-- Leer los datos --#
    print("Dar el tamaño de la habitación, en m\n")
    largo, ancho = input("¿Largo, ancho?").split(",")
    largo, ancho = int(largo), int(ancho)
    lado = int(input("¿Lado de la baldosa, en cm?"))
    precio = float(input("¿Precio de cada baldosa, en euros? "))

    #--Calcular el número de baldosas--#

    #--Calcular las baldosas a lo largo, por exceso--# 
    nLargo = int((largo*100 + lado - 1) / lado)

    #--Calcular las baldosas a lo ancho, por exceso--# 
    nAncho = int((ancho*100 + lado - 1) / lado)

    #--Calcular el número total de baldosas--# 
    baldosas = nLargo * nAncho

    #--Calcular el coste total--#
    coste = baldosas * precio

    #--Imprimir el resultado--# 
    print("Total {0:5d} baldosas\n".format(int(baldosas)))
    print("Coste {0:8.2f} euros\n".format(coste))
  