
def tomarCocaColaGelada(garrafasVazias):
    if garrafasVazias <2:
        return 0
    elif garrafasVazias == 2:
        return 1
    else:
        bebidas = garrafasVazias // 3
        sobra = garrafasVazias % 3
        return bebidas + tomarCocaColaGelada(bebidas+sobra)

print(tomarCocaColaGelada(81))



