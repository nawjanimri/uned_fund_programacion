# Programa: Calendario
# Descripción:
#   Programa para el cálculo del dia de la semana que corresponde
#   a una fecha comprendida entre 1/1/1989 Y 31/ 12/2088


from enum import Enum

TipoDia = Enum("TipoDia", "Lunes Martes Miercoles Jueves Viernes Sabado Domingo")
TipoMes = Enum("TipoMes", "Enero Febrero Marzo Abril Mayo Junio Julio "
                "Agosto Septiembre Octubre Noviembre Diciembre")


class TipoFecha():
    
    def __init__(self, dia, mes, anno):
    
        self.dia = dia
        self.mes = mes      # TipoMes
        self.anno = anno


# Función para sumar dias de la semana cíclicamente
def SumarDias(dia, n):
    
    diassemana = 7 
    aux = 0
    aux = (dia.value+n)%diassemana
    return TipoDia(aux)


# Función para calcular el dia de la semana que corresponde a una fecha
def DiaDeLaSemana(fecha):
    
    OrigenA = 89                            # Primer anno que se considera
    TreintaUnoDiciembre88 = TipoDia.Sabado  # Ese dia fue sabado

    bisiesto = False    # Si ese año es bisiesto
    increbisis = 0      # Incremento en número de días por años bisiestos desde el de referencia
    increannos = 0      # Incremento de años desde el de referencia
    incredias = 0       # Incremento de días de la semana que cada mes introduce 
                        # respecto al 31 de enero
    mes = fecha.mes
    anno = fecha.anno

    # El incremento de días de la semana que cada mes introduce respecto al 31 de enero:
    incrementos = { TipoMes.Enero:      0,
                    TipoMes.Febrero:    3,
                    TipoMes.Marzo:      3,
                    TipoMes.Abril:      6,
                    TipoMes.Mayo:       1,
                    TipoMes.Junio:      4,
                    TipoMes.Julio:      6,
                    TipoMes.Agosto:     2,
                    TipoMes.Septiembre: 5,
                    TipoMes.Octubre:    0,
                    TipoMes.Noviembre:  3,
                    TipoMes.Diciembre:  5
                    }
    incredias = incrementos[mes]               

    bisiesto = (anno % 4) == 0

    if anno < OrigenA:
        anno = anno+100  # Si el año es inferior a 89 se considera que es posterior al 2000

    increannos = anno - OrigenA   # Años pasados desde el 89
    increbisis = increannos/4     # Bisiestos pasados
    incredias  = incredias + fecha.dia + increannos + increbisis
    if (bisiesto and (mes.value > TipoMes.Febrero.value)):
        incredias = incredias +1

    return SumarDias(TreintaUnoDiciembre88, int(incredias))


# Procedimiento para leer una fecha (mes en número)
def LeerFecha():
    
    dia, mes, anno = input("¿Dia Mes Año(DD/ MM/ AA)?").split("/")
    dia = int(dia)
    mes = TipoMes(int(mes))
    anno = int(anno)
    fecha = TipoFecha(dia, mes, anno)

    if fecha.anno >= 100:
        fecha.anno = fecha.anno % 100 # Los años se ponen con 2 cifras
  
    return fecha


# Procedimiento para escribir una fecha
def EscribirFecha(fecha):

    print( "Fecha : {0:02d}/{1:02d}/{2:02d}".format(fecha.dia, fecha.mes.value, fecha.anno))


# Programa principal
if __name__ == "__main__":

    tecla = "S"

    while (tecla!="N"):
        fecha = LeerFecha()
        EscribirFecha(fecha) 
        diasemana = DiaDeLaSemana(fecha)
        nombredia = TipoDia(diasemana).name
        print(" Día de la semana: {}".format(nombredia)) 
        tecla = ' ' # tecla pulsada
        while (tecla != "S") and (tecla != "N"):
            tecla = input("¿Otra Fecha(S/N)?")
