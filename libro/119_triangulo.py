# Programa: Triangulo (Versión inicial)
# Descripción:
#   Este programa escribe el borde de un triángulo
#   aproximadamente equilátero. usando asteriscos.


if __name__ == "__main__":

    N = 7   # altura del triángulo
    
    # -- Escribir el vértice superior -- #
    texto = ""
    for k in range(1, N):
        texto += " "

    texto += "*"
    print(texto)

    #-- Imprimir los bordes laterales --#
    texto = ""
    for k in range(2, N):
        #print("k = ",k)
        #-- Espaciado hasta lateral izquierdo --#
        for j in range(1, N-k+1):
            #print("j = ", j)
            texto += " "
        texto += "*" # lateral izquierdo

        #-- Espaciado hasta lateral derecho --#
        for j in range(1, 2*k-2):
            #print("j2 = ", j)
            texto += " "
        texto += "*" # lateral derecho
        print(texto)
        texto = ""

    #-- Imprimir el borde inferior --#
    texto = "*"
    for k in range(1, N):
        texto += " *" # asteriscos espaciados

    print(texto)