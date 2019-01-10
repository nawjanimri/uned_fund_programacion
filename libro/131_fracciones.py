# Programa: Fracciones
# Descripción:
#   Este programa es una calculadora que suma,
#   resta, multiplica y divide fracciones


# Procedimiento para simplificar la fracción n/d 
def ReducirFraccion(n, d):
    
    divisor = 2

    while (divisor<=n) and (divisor<=d):
        while (n%divisor == 0) and (d%divisor == 0):
            n = n/divisor
            d = d/divisor
        divisor+=1
    return (n, d)


# Procedimiento para sumar fracciones:
#   n3'/d3' = n1/d1 + n2/d2
def SumarFracciones(n1, d1, n2, d2):
    
    n3 = n1*d2 + n2*d1
    d3 = d1*d2
    return ReducirFraccion(n3, d3)


# Procedimiento para restar fracciones:
#   n3'/d3' = n1/d1 - n2/d2
def RestarFracciones(n1, d1, n2, d2):
    
    return SumarFracciones(n1, d1, -n2, d2)


# Procedimiento para multiplicar fracciones:
#   n3'/d3' = n1/d1 * n2/d2
def MultiplicarFracciones(n1, d1, n2, d2):
    
    n3 = n1*n2
    d3 = d1*d2
    return ReducirFraccion(n3, d3)


# Procedimiento para dividir fracciones:
#   n3'/d3' = n1/d1 / n2/d2
def DividirFracciones(n1, d1, n2, d2):
    
    n3 = n1*d2
    d3 = d1*n2
    return ReducirFraccion(n3, d3)


# Procedimiento que lee una fracción y la simplifica
def LeerFraccion():
    
    n, d = input("").split("/")
    n, d = int(n), int(d)
    return ReducirFraccion(n, d)


# Procedimiento que escribe una fracción como n/d
def EscribirFraccion(n, d):
    
    return("{:2.0f}\\{:2.0f}".format(n, d))


# Programa principal
if __name__ == "__main__":

    num = 0             # Acumulador: Numerador
    den = 0             # Acumulador: Denominador
    nn, dd = 0, 0       # Nuevo operando a utilizar
    operacion = ' '     # Tecla de operación a realizar


    while (operacion != 'F'):
        # print("num y dem son = {}{}".format(num, den))
        operacion = input(">> ")
        if (operacion == '+'):
            nn, dd = LeerFraccion()
            num, den = SumarFracciones(num, den, nn, dd)
        elif (operacion == '-'):
            nn, dd = LeerFraccion()
            num, den = RestarFracciones(num, den, nn, dd)
        elif (operacion == '*'):
            nn, dd = LeerFraccion()
            num, den = MultiplicarFracciones(num, den, nn, dd)
        elif (operacion == '/'):
            nn, dd = LeerFraccion()
            num, den = DividirFracciones(num, den, nn, dd)
        elif (operacion == 'N'): # Nuevos cálculos
            num, den = LeerFraccion()
        elif (operacion == '='):
            print("        {}".format(EscribirFraccion(num, den)))
        elif (operacion == 'F'):
            print("Pulse +, -, *, / , N, =, o F")