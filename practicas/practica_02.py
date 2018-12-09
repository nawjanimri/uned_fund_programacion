import pdb


def pinta_rombo(num_lados):

	print("pintando rombo")
	
	num_linea = 1

	while num_linea < num_lados+1:

		linea = next_linea(num_linea, num_lados)
		print(linea)

		if len(linea) == 1:
			break

		num_linea =  num_linea + 1


def next_linea(num_linea, num_lados):

	secuencia = "@.o."
	espacio = " "
	
	# print espacios:
	num_espacios = num_lados - num_linea
	texto_espacios = espacio * num_espacios

	# print caracteres hasta el centro:
	posicion = len(texto_espacios)
	texto_caracteres = ""
	caracter = ""

	while posicion < num_lados:

		caracter = next_caracter(caracter)
		texto_caracteres += caracter
		posicion += 1

	return texto_espacios + texto_caracteres

	# print invierte linea:

def next_caracter(caracter_actual):

	if caracter_actual == "":
		return "@"
	elif caracter_actual == "@":
		return "."
	elif caracter_actual ==".":
		return "o"
	elif caracter_actual == "o":
		return "."


if __name__ == "__main__":
	
	num_lados = ""
	texto_num_lados_permitido = "El número de lados debe ser un número entre 1 y 20"

	try:
		num_lados = int(input("¿número de lados del rombo?"))

		pdb.set_trace()

		if num_lados is None or num_lados==0 or num_lados>20 or num_lados<0:
			print(texto_num_lados_permitido)
			print("{} no permitido".format(num_lados))
		else:
			pinta_rombo(num_lados)
	except:
		print(texto_num_lados_permitido)


