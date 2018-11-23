# Programa: Ordenar3
# Descripción:
#   Este programa ordena tres valores y los guarda ordenados
#   de menor a mayor en las mismas variables que se leen


if __name__ == "__main__":

    (valUno, valDos, valTres) = (0,0,0) # Datos a ordenar
    
    #-- Leer los datos --#
    valUno, valDos, valTres = input("¿Datos)?").split(",")
    valUno, valDos, valTres = int(valUno), int(valDos), int(valTres)

    #pdb.set_trace()

    #--Primer Paso: Ordenar los dos primeros datos--#
    if (valUno > valDos):
        auxiliar = valUno
        valUno  = valDos
        valDos  = auxiliar
    
    #--Segundo Paso: Situar el tercer dato -#
    if (valTres < valUno):
        auxiliar  = valTres
        valTres   = valDos
        valDos    = valUno
        valUno    = auxiliar
    elif (valTres < valDos):
        auxiliar  = valDos 
        valDos    = valTres
        valTres   = auxiliar

    print(valUno, valDos, valTres)
    #--Tercer Paso: Escribir el resultado--#
    print( "Datos Ordenados = {:5d} {:5d} {:5d}".format(valUno, valDos, valTres))
  