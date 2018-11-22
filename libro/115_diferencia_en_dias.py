# Programa: DiferenciaEnDias
# Descripción:
#   Este programa calcula los días entre dos fechas de forma
#   aproximada, contando todos meses de 30 días, y los años de 365

if __name__ == "__main__":

    (dia1, mes1, anno1) = (0,0,0)       # primera fecha #
    (dia2, mes2, anno2) = (0,0,0)       # segunda fecha #
    (diasFecha1, diasFecha2) = (0,0)    # días desde inicio del año
    diferencia = 0                      # diferencia en días #
    
    #-- Leer los datos --#
    dia1, mes1, anno1 = input("¿Primera fecha (dd,mm,aaaa)?").split(",")
    dia1, mes1, anno1 = int(dia1), int(mes1), int(anno1)

    dia2, mes2, anno2 = input("Segunda fecha (dd,mm,aaaa)?").split(",")
    dia2, mes2, anno2 = int(dia2), int(mes2), int(anno2)

    #--Calcular la diferencia--#
    #--Calcular los días desde principio del año--#
    diasFecha1 = (mes1 - 1)*30 + dia1
    diasFecha2 = (mes2 - 1)*30 + dia2
    
    #--Ca1cular la diferencia total en días--#
    diferencia = (anno2 - anno1)*365 + diasFecha2 - diasFecha1

    #--Imprimir el resultado--#
    print("Desde {:02d}/{:02d}/{:04d}".format(dia1, mes1, anno1))
    print("Hasta {:02d}/{:02d}/{:04d}".format(dia2, mes2, anno2))
    print( "Hay {0:5d} días".format(diferencia))
  