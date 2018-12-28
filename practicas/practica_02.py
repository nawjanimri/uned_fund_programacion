'''
/**************************************
* NOMBRE: #Jose Manuel#
* PRIMER APELLIDO: #Alvarez#
* SEGUNDO APELLIDO: #Bautista#
* DNI: #29488955B#
* EMAIL: #jalvarez1623@alumno.uned.es#
***************************************/
'''
lado = 0                            # Lado del rombo
CARACTERES = "@.o.@.o.@.o.@.o.@.o." # caracteres del rombo
n_espacios = 0                      # Número de espacios al inicio de cada línea del rombo */
n_caracteres = 0                    # Número de caracteres que se imprimen en cada línea del rombo */

def LeerLadoRombo():
    
    global lado
    lado = int(input("¿Lado del rombo? "))


def RomboSuperior():
  
    texto = ""                          # Texto que forma cada línea
    global lado                         # Lado del rombo
    n_lineas = lado                     # Número de líneas que forman cada parte del rombo
    for linea in range(0, n_lineas):

        # Triángulo derecho
        n_espacios   = lado-linea-1
        n_caracteres = linea+1

        # Espacios antes de los caracteres
        for i in range(0, n_espacios):
            texto += " "

        # Caracteres */
        for j in range(0, n_caracteres):
            texto += CARACTERES[j]

        #Triángulo izquierdo
        # Caracteres:
        for k in range(2, n_caracteres+1):
            texto += CARACTERES[n_caracteres-k]

        print(texto)
        texto = ""

def RomboInferior():
    
    texto = ""                          # Texto que forma cada línea
    global lado                         # Lado del rombo
    n_lineas = lado                     # Número de líneas que forman cada parte del rombo */
    for linea in range(1, n_lineas):

        # Triángulo derecho
        n_espacios   = linea
        n_caracteres = lado-linea

        # Espacios antes de los caracteres
        for i in range(0, n_espacios):
            texto += " "
        
        # Caracteres */
        for j in range(0, n_caracteres):
           texto += CARACTERES[j]
        
        # Triángulo izquierdo
        # Caracteres */
        for k in range(2, n_caracteres+1):
            texto += CARACTERES[n_caracteres-k]

        print(texto)
        texto = ""


def imprime_rombo(num_lados):

    if num_lados>0 and num_lados<21:
        RomboSuperior()
        RomboInferior()


if __name__ == "__main__":
	
    #LeerLadoRombo()
    
    for i in range(0, 20):
        lado = i
        imprime_rombo(lado)


