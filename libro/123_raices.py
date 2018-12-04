# Programa: Raices
# Descripción:
#   Este programa calcula las raíces de una ecuación de 
#   segundo grado: ax2 + bx + c

import math

# Función para calcular el discriminante 
def Discriminante(a, b, c):
    return b*b - 4.0*a*c;


# Procedimiento de lectura de un coeficiente
def LeerValor(grado):
    valor = int(input("¿Coeficiente de grado {:1d}? ".format(grado)))
    return valor


if __name__ == "__main__":
  
    (valorA, valorB, valorC) = (0, 0, 0)  # Coeficientes de la ecuación 
    (parteUno, parteDos) = (0, 0)      # Variables intermedias de cálculo 
    valorD = 0                  # Discriminante de la ecuación 

    valorA = LeerValor(grado = 2)
    valorB = LeerValor(grado = 1)
    valorC = LeerValor(grado = 0)

    if (valorA == 0.0):
        if (valorB == 0.0):
            if (valorC == 0.0):
                print("Ecuación no válidan")
            else:
                print("Solución imposible")
        else:
            print("Raíz única {:10.2f}".format(-valorC/valorB))

    else:
        parteUno = -valorB/(2.0*valorA)
        valorD = Discriminante(valorA, valorB, valorC)
    
    if (valorD >= 0.0):
        parteDos = math.sqrt(valorD)/(2.0*valorA)
        print("Raíces reales:" )
        print("{:10.2f} y ".format(parteUno+parteDos))
        print("{:10.2f} ".format(parteUno-parteDos))
    else:
        parteDos = math.sqrt(-valorD)/(2.0*valorA)
        print("Raíces complejas :\n" )
        print("Parte real =       {:10.2f} y ".format(parteUno))
        print("Parte imaginaria = {:10.2f}".format(parteDos))