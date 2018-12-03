# Programa: Triangulo (Versión inicial)
# Descripción:
#   Este programa escribe el borde de un triángulo
#   aproximadamente equilátero. usando asteriscos.
#   La altura del triángulo, en líneas de texto, se lee como dato.


if __name__ == "__main__":

    altura = 0 # altura del triángulo
    
    #-- Leer altura deseada --#
    altura = int(input("¿Altura? "))

    # -- Escribir el vértice superior -- #
    texto = ""
    if altura > 0:
        for k in range(1, altura):
          texto += " "
        texto += "*"
        print(texto)
        texto = ""

    #-- Imprimir los bordes laterales --#
    for k in range(2, altura):
        #print("k = ",k)
        #-- Espaciado hasta lateral izquierdo --#
        for j in range(1, altura-k+1):
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
    for k in range(1, altura):
        texto += " *" # asteriscos espaciados

    print(texto)