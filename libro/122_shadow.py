# Programa: Shadow
# Descripción:
#   Ejemplo de ocultación de nombres globales

global_1 = 0
exterior = 50


def Interior():
  
  exterior = 30
  global global_1
  global_1 = exterior*exterior


def Secundario():
  
  Interior()
  global exterior
  exterior = global_1/2


def Primario( exterior, interior):
  
  Secundario()
  interior = exterior - 5


if __name__ == "__main__":

    interior = 40

    Primario(interior, interior)
    print( "{:5.0f}{:5.0f}{:5.0f}".format(global_1, exterior, interior))