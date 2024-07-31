class Arvore:
    def __init__(self, valor, temGato):
        self.raiz = valor
        self.temGato = temGato
        self.filhos = []


    def get_raiz(self):
        return self.raiz

    def __str__(self):
        return str(self.raiz)

    def imprimeArvore(self):
        retorno = [self.raiz]
        listaFilhos = []
        for filho in self.filhos:
            listaFilhos.append(filho.imprimeArvore())
        retorno.append(listaFilhos)
        return retorno

    def insereNo(self, filho):
        self.filhos.append(filho)

def calculaRestaurantesPossiveis(noRaiz, gatosConsecutivos, limiteGatosConsecutivos):
    temGato = 1 if noRaiz.temGato else 0
    gatosConsecutivos += temGato
    if gatosConsecutivos > limiteGatosConsecutivos:
        return 0
    else:
        if temGato == 0:
            gatosConsecutivos = 0
        if len(noRaiz.filhos) > 0:
            restaurantesPossiveis = 0
            for filho in noRaiz.filhos:
                restaurantesPossiveis += calculaRestaurantesPossiveis(filho, gatosConsecutivos, limiteGatosConsecutivos)

            return restaurantesPossiveis
        else:
            return 1


quantidadeNos, limiteGatos = [int(x) for x in input().split()]

listaGatos = [int(x) for x in input().split()]

nos = {}

for i in range(quantidadeNos):
    no = Arvore(i+1, listaGatos[i]==1)
    nos[i+1] = no

for i in range(quantidadeNos-1):
    aresta = [int(x) for x in input().split()]
    pai = nos[aresta[0]]
    filho = nos[aresta[1]]
    pai.insereNo(filho)

print(calculaRestaurantesPossiveis(nos[1],0,limiteGatos))

# 4 1
# 1 1 0 0
# 1 2
# 1 3
# 1 4

