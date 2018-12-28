'''
/**************************************
* NOMBRE: #Jose Manuel#
* PRIMER APELLIDO: #Alvarez#
* SEGUNDO APELLIDO: #Bautista#
* DNI: #29488955B#
* EMAIL: #jalvarez1623@alumno.uned.es#
**************************************
'''

MESES = ["ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO",
        "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"]
DIASMENSUALES = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

# Lee el dato del año solicitado al usuario 
def LeerMes():

    mes = int(input("¿Mes (1..12)?"))
    mes = mes-1
    print("el mes es: {}".format(mes))
    return mes


# Lee el dato del año solicitado al usuario 
def LeerAnno():
    
    anno = int(input("¿Año (1601...3000)?"))
    return anno


# Informa si el año indicado es bisiesto o no
def EsBisiesto(anno):

    if (anno%4==0 and anno%100!=0) or (anno%400==0):
        return 1
    else:
        return 0


# Devuelve el número de años bisiestos entre el año 1600 y el año especificado
def NumeroBisiestosHasta(anno):
    
    annos = anno - 1600
    num_bisiestos = int(annos/4)

    centenas = int(annos/100)
    num_bisiestos = num_bisiestos-centenas

    cuatrocenas = int(annos/400)
    num_bisiestos = num_bisiestos+cuatrocenas

    return num_bisiestos


def NumDiasMes(mes, anno):
    
    # En febrero se comprueba si es año bisiesto, para añadir 1 día más
    if mes==1 and EsBisiesto(anno):
        return DIASMENSUALES[mes]+1 
    else:
        return DIASMENSUALES[mes]


# Devuelve el número días de ese año hasta el día 1 del mes indicado 
def NumDiasHastaMes(mes, anno):
  
    num_dias = 0 # Número de días hasta el 1 del mes indicado. 

    # Si el año es bisiesto, se suma 1 sólo si el mes es superior a febrero:
    if EsBisiesto(anno):
        num_dias = num_dias + NumeroBisiestosHasta(anno) - 1
    else:
        num_dias = num_dias + NumeroBisiestosHasta(anno)

    # Se suman los días de todos los meses de ese año hasta el mes indicado 
    for i in range(0, mes):
        num_dias += NumDiasMes(i, anno) # Se le suman los días del mes 

    return num_dias


# Nombre del primer día del mes indicado 
def DiaSemanaPrimerDiaDelMes(mes, anno):
    
    annos = 0            # Número de años desde 1601 hasta el año indicado. 
    num_dias = 0         # Número de días hasta el 1 del mes indicado. 
    dia_semana = 0       # Número del día de la semana en que cae el día 1 del mes indicado.
                         # 0 para lunes, 1 martes, 3 miércoles, etc.

    # Teniendo en cuenta que el 1 de enero de 1601 fue lunes, dia 0
    annos      = anno - 1601
    num_dias   = annos*365 + NumDiasHastaMes(mes, anno)
    dia_semana = num_dias%7 # Día de la semana del primer día de ese mes
    return dia_semana


# Imprime el calendario del mes y año indicados 
def ImprimeMes(mes, anno):

    texto = "" # Texto de cada línea del calendario
    primerdia = DiaSemanaPrimerDiaDelMes(mes, anno)
    num_dias_mes = NumDiasMes(mes, anno)

    # Cabecera del calendario 
    print("{:10s}             {:4d}".format(MESES[mes], anno))
    print("===========================")
    print("LU  MA  MI  JU  VI | SA  DO")
    print("===========================")

    # Días en blanco hasta el primer día del  mes 
    dia_semana = 0 # Lunes 
    for i in range(0, primerdia):
        dia_semana = dia_semana+1
        if dia_semana==5:
            texto += " . | "
        else:
            texto += " .  "

    # Días del  mes 
    for i in range(1, num_dias_mes+1):
        dia_semana = dia_semana+1
        if dia_semana==5:
            texto += "{:2d} | ".format(i)
        else:
            texto += "{:2d}  ".format(i)
      
            if dia_semana==7:
                print(texto)
                texto = "" 
                dia_semana = 0


    # Días en blanco hasta completar el mes 
    if dia_semana > 0:
        for i in range(dia_semana, 7):
            dia_semana = dia_semana+1
            if dia_semana==5:
                texto += " . | "
            else:
                texto += " .  "

        print(texto)
        texto = ""


if __name__ == "__main__":
	  
    mes  = LeerMes()  # Mes que se va a representar del calendario 
    anno = LeerAnno() # Año del Mes que se va a representar 

    if (mes>=0 and mes<12) and (anno>1600 and anno<3001):
        print("\n")
        ImprimeMes(mes, anno)

