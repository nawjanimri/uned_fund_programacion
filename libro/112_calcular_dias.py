# Programa: CalcularDias
# Este programa calcula los dias que faltan para el cumpleaños de una persona
import datetime as dt

'''==========================================
	En el módulo datetime están definidos:
  	datetime = Tipo de valor FECHA y todas las operaciones necesarias entre fechas
 	============================================='''

def calcula_dias_para_cumple(hoy, cumple):

    cumple_este_anno = dt.datetime(hoy.year, cumple.month, cumple.day)

    if cumple_este_anno>hoy:
        delta_dias = cumple_este_anno-hoy
        return delta_dias.days+1

    elif cumple_este_anno<hoy:
        cumple_prox_anno = dt.datetime(hoy.year+1, cumple.month, cumple.day)
        delta_dias = cumple_prox_anno-hoy
        return delta_dias.days+1
    else:
        return 0


if __name__ == "__main__":

    #--- Obtener la fecha del cumpleaños ------#
    formato = "%d/%m/%Y" # fecha en formato 30/12/2018
    # fecha como datetime:
    fechaCumple = dt.datetime.strptime(input("¿cuándo es tu próximo cumpleaños?"),formato) 

    #- Obtener la fecha de hoy --# 
    fechaHoy = dt.datetime.now()

    #-- Calcular los dias que faltan para el cumpleaños --# 
    dias_para_cumple = calcula_dias_para_cumple(fechaHoy, fechaCumple)

    #-- Imprimir el resultado --# 
    print( "Faltan {0:4d} días para tu cumpleaños".format(dias_para_cumple))




  

  