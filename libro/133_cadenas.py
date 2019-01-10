# Programa: Cadenas
# Descripción:
#   Ejemplo de manejo de cadenas de caracteres


# Programa principal
if __name__ == "__main__":
  nombre = ""
  apellido = ""
  texto = ""
  resul = 0

  (nombre, apellido) = input("Nombre y Apellido?").split()
  print("Datos: {} - {}".format(nombre, apellido))
  print("Longitudes: {0:4d} {1:4d}".format(len(nombre), len(apellido)))
  texto = nombre 
  print("Texto copiado: {}".format(texto))
  texto = texto + apellido
  print("Texto concatenado: {}".format(texto))

  if (apellido == nombre):
    print("Nombre y Apellido iguales")
  else:
    palabras = [nombre, apellido]
    palabras.sort()
    print("{} es anterior a {}".format(palabras[0], palabras[1]))

