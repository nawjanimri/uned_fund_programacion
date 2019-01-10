# Programa: Fatorial Robusto
# Descripción:
#   Este programa es una calculadora que suma,
#   resta, multiplica y divide fracciones
import sys

class NumeroException(BaseException):
    def __init__(self, numero):
        self.numero = numero

# Procedimiento para simplificar la fracción n/d
def FactorialRobusto(n):

    f = 1

    if n<0:
        raise NumeroException(numero=0)

    for k in range(2, n+1):
        if f>sys.maxsize:
            raise NumeroException(numero=f)
        f = f*k

    return f


def EscribirFactorial(num):

  try:
    fact = FactorialRobusto(num)
    print("{0:2d}! vale:{1:10d}".format(num, fact))
  
  except NumeroException as e:
    if e.numero == 0:
      print("{0:2d}! excepción: Factorial de número negativo".format(num))
    else:
      print("{0:2d}! excepción: Superado límite al evaluar {1:2d}!".format(num, num))


# Programa principal
if __name__ == "__main__":

    for i in range(5, -3, -1):
        EscribirFactorial(i)
  
    for i in range(6, 16):
        EscribirFactorial(i)