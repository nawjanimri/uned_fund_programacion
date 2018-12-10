# Programa: Perimetro
# Descripción:
#   Programa para calcular el perimetro de un triángulo dado por sus tres vértices

from math import sqrt
(xA, yA, xB, yB, xC, yC) = (0, 0, 0, 0, 0, 0) # Coordenadas de los puntos
perimetro = 0                                 # Valor del perimetro

'''
Procedimiento para leer las coordenadas X e Y de un punto.
  Para facilitar la identificación del punto, se tiene que
  pasar la letra que lo identifica como argumento.'''
def LeerCoordenadas(punto):
    
    print( "Punto {}".format(punto))
    x = float(input("¿Coordenada X ? "))
    y = float(input("¿Coordenada Y ? "))
    return (x, y)


# Procedimiento para leer las coordenadas de los 3 vértices
def LeerVertices():

    global xA, yA, xB, yB, xC, yC
    xA, yA = LeerCoordenadas('A')
    xB, yB = LeerCoordenadas('B')
    xC, yC = LeerCoordenadas('C')


# Función para calcular la distancia que hay entre dos puntos (xl,y1) y (x2,y2)
def Distancia(x1, y1, x2, y2 ):
 
    deltaX = x2 - x1
    deltaY = y2 - y1
    return sqrt( deltaX*deltaX + deltaY*deltaY)


'''Procedimiento para calcular el perimetro de un triágulo
    NOTA : Se utilizan variables globales dado el excesivo
         número de argumentos necesarios: Total 7 argumentos:
          3 puntos x 2 coordenada: 6 argumentos por valor
          Resultado en perimetro = 1 argumento por referencia'''
def CalcularPerimetro():

    global perimetro
    global xA, yA, xB, yB, xC, yC
    ladoAB = Distancia(xA, yA, xB, yB)
    ladoAC = Distancia(xA, yA, xC, yC)
    ladoBC = Distancia(xB, yB, xC, yC)
    perimetro = ladoAB + ladoAC + ladoBC


# Procedimiento para imprimir la variable global perimetro
def ImprimirPerimetro():

    print("El perímetro es igual a {0:5.2f}".format(perimetro))


if __name__ == "__main__":

    LeerVertices()
    CalcularPerimetro()
    ImprimirPerimetro()