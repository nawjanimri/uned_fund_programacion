# Programa: FactorialRecursivo
# Descripción:
#   Este programa calcula el factorial de los primeros
#   números naturales, de forma recursiva

def factorial_recursivo(n):
    if (n <= 1):
        return 1
    else:
        return n * factorial_recursivo(n-1)

if __name__ == "__main__":

    for i in range(1,11):
        print("{:2d}! vale:{:10d}".format(i, factorial_recursivo(i)))
