# Programa: CalcularDias
# Este programa calcula los dias que faltan para el cumpleaños de una persona
import datetime as dt

'''==========================================
	En el módulo datetime están definidos:
  	datetime = Tipo de valor FECHA y todas las operaciones necesarias entre fechas
 	============================================='''

if __name__ == "__main__":

    #--- Obtener la fecha del cumpleaños como datetime ------#
    formato = "%d/%m/%Y" # fecha en formato 30/12/2018

    fecha_bien = False
    while fecha_bien == False:
        
        fechaCumple = dt.datetime.strptime(input("¿cuándo es tu próximo cumpleaños?"),formato) 
        fechaHoy    = dt.datetime.now() # Fecha de hoy
        
        if fechaCumple<fechaHoy:
            print("La fecha del próximo cumple está mal, debe ser superior al día de hoy \n")
            fecha_bien = False
        else:
            fecha_bien = True
   
    #-- Calcular los dias que faltan para el cumpleaños --#  
    dias_para_cumple = (fechaCumple-fechaHoy).days+1
    print( "Faltan {0:4d} días para tu cumpleaños".format(dias_para_cumple))
 