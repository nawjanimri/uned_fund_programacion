# Programa: ArbolDeNavidad
# Descripción:
#  Este programa imprime de Navidad, hecha con la silueta de un árbol asteriscos

CENTRO = 20 # Centro de cada linea


# Procedimiento para imprimir N veces seguidas el carácter 'c'
def ImprimirN (caracter, N):

    texto = ""
    for k in range(1, N+1):
        texto += caracter
    return texto


''' Procedimiento para imprimir un trapecio de asteriscos con
    la base superior "ancho", altura "alto" y "avance" asteriscos
    más a cada lado en cada nueva linea '''
def ImprimirTrapecio(ancho, alto, avance):
  
    anchura = 0       # Número de asteriscos
    espacios = ""     # Texto de espacios
    asteriscos = ""   # Texto de asteriscos
    anchura = ancho
    for k in range(1, alto):
        espacios    = ImprimirN(' ', CENTRO - int(anchura/2))
        asteriscos  = ImprimirN('*', anchura)
        print("{}{}".format(espacios, asteriscos))
        anchura = anchura + 2*avance

'''Procedimiento para imprimir 3 líneas seguidas con:
    ancho
    ancho+2
    y ancho+4 asteriscos'''
def ImprimirRama(ancho):
   
    ImprimirTrapecio(ancho, 4, 1)


#Procedimiento para imprimir un rectángulo de ancho x alto asteriscos
def ImprimirRectangulo(ancho, alto):
    
    ImprimirTrapecio(ancho, alto, 0)

# Programa principal
if __name__ == "__main__":

    #-- Imprimir copa --#

    rama = 1 # Ancho de rama
    
    for k in range(1, 6):
        ImprimirRama(rama);
        rama = rama + 2;

    #-- Imprimir tronco --#
    ImprimirRectangulo(3, 6)

    #-- Imprimir base --#
    ImprimirRectangulo(9, 3)

  