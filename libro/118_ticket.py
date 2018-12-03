# Programa: Ticket
# Descripción:
#   Este programa elabora el ticket de entrada y los resúmenes de recaudación 
#   de un espectáculo.
#   El precio del ti cket depende de la edad del espectador (Niño, Joven, 
#   Adulto o Jubilado).


if __name__ == "__main__":

    PRECIO_BASE = 6.0   # Precio de la butaca
    butacas = 0         # Número de butacas vendidas  
    edad = 0            # Edad del cliente
    total_euros = 0.0   # Total de euros recaudados
    precio = 0          # Precio de cada butaca
    opcion = " "        # Opción del programa 
    tecla = " "         # Tecla Si/No
    texto = ""          # Texto que se imprime en cada ticket

    # -- Bucle hasta opción F de fin -- #
    while (opcion != 'F'):
        opcion = ' '
        while ((opcion != 'T') and (opcion != 'R') and (opcion != 'F')):
            opcion = input("Opción (Ticket, Resumen o Fin)?")

        #======================
        # Elaboración del Ticket
        #=======================

        if (opcion == 'T'):
            tecla = 'S'

            while (tecla == 'S'):
                edad = int(input("Edad? "))
                butacas +=1
                print(".-----------------------------." )
                print( "|      TICKET DE ENTRADA      |")
               
                if (edad < 6):           # niño, gratis
                    texto = " |Gratis "
                    precio = 0.0
                elif (edad < 18):       # joven, 50%
                    texto = "|Joven "
                    precio = PRECIO_BASE / 2.0
                elif (edad < 65):      # adulto, tarifa completa
                    texto = "|Adulto "
                    precio = PRECIO_BASE
                else:              # jubilado, 25%
                    texto =  "|Jubilado"
                    precio = PRECIO_BASE / 4.0
                
                total_euros = total_euros + precio
                print("{:17} Precio: {:>4.2f}|".format(texto, precio))
                print("'-----------------------------'" )
                
                tecla = ' '
                while ((tecla != 'S') and (tecla != 'N')):
                    tecla = input( "Otro Ticket(S/N)? " )

        #==============================================
        #   Elaboración del Resumen de la recaudación
        #==============================================
        if (opcion == 'R'):
            print( "    RESUMEN DE VENTAS " )
            print( "    ----------------- " )
            print( "{:4d} Butacas ".format(butacas))
            print( "Total Recaudado = {:10.2f}".format(total_euros))