# Programa: Ordenar3b
# Descripción:
#   Este programa ordena 3 valores



# Procedimiento para ordenar dos datos 
def OrdenarDos(y, z):
    
    aux = 0
    if (y > z):
        aux = y
        y = z
        z = aux

    return (y, z)


# Procedimiento para leer un dato 
def LeerDato(indice):

    dato = int(input("¿Dato {:1d}? ".format(indice)))
    return dato


if __name__ == "__main__":

    (valorUno, valorDos, valorTres) = (0,0,0) # Valores a ordena
    tecla = 'S'                         # Tecla de opción 

    while (tecla!='N'):
        # -- Leer los datos -- #
        valorUno = LeerDato(1)
        valorDos = LeerDato(2)
        valorTres = LeerDato(3)
    
        # -- Ordenar los datos -- # 
        valorUno, valorDos = OrdenarDos(valorUno, valorDos)
        valorUno, valorTres = OrdenarDos(valorUno, valorTres)
        valorDos, valorTres = OrdenarDos(valorDos, valorTres)
    
        #-- Escribir los resultados -- #
        print("Datos Ordenados = {:5d} {:5d} {:5d}".format(valorUno, valorDos, valorTres))
    
        #-- Comprobar si se continúa -- #
        tecla = ' '
        
        while ((tecla != 'S') and (tecla != 'N')):
            tecla = input("¿Desea continuar(S/N )? ..")
