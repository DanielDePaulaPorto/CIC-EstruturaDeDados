class Arvore:
    def __init__(self, valor):
        self.raiz = valor
        self.filhoEsquerda = None
        self.filhoDireita = None

    def __str__(self):
        return str(self.raiz)

    def insereNoEsquerda(self, valor):
        filho = Arvore(valor)
        self.filhoEsquerda = filho
        return filho

    def insereNoDireita(self, valor):
        filho = Arvore(valor)
        self.filhoDireita = filho
        return filho

def imprimeArvoreEmOrdem(no):
    if no:
        imprimeArvoreEmOrdem(no.filhoEsquerda)
        print(no, end=' ')
        imprimeArvoreEmOrdem(no.filhoDireita)

def imprimeArvorePosOrdem(no):
    if no:
        imprimeArvorePosOrdem(no.filhoEsquerda)
        imprimeArvorePosOrdem(no.filhoDireita)
        print(no, end=' ')

def getArvorePosOrdem(no):
    posOrdem = []
    if no:
        posOrdem = getArvorePosOrdem(no.filhoEsquerda)
        posOrdem = posOrdem + getArvorePosOrdem(no.filhoDireita)
        posOrdem.append(no.raiz)
    return posOrdem


def criarArvorePreOrdem(noPai, valor):
    if valor < noPai.raiz:
        if noPai.filhoEsquerda:
            criarArvorePreOrdem(noPai.filhoEsquerda, valor)
        else:
            noPai.insereNoEsquerda(valor)
    else:
        if noPai.filhoDireita:
            criarArvorePreOrdem(noPai.filhoDireita, valor)
        else:
            noPai.insereNoDireita(valor)


def criarArvorePreOrdem2(noPai, valoresPreOrdem):
    if valoresPreOrdem:
        esquerda = [x for x in valoresPreOrdem if x < noPai.raiz] # nós que serão adicionados à esquerda
        direita = [x for x in valoresPreOrdem if x > noPai.raiz]  # nós que serão adicionados à direita
        if esquerda:
            filho = noPai.insereNoEsquerda(esquerda[0])
            criarArvorePreOrdem2(filho, esquerda[1:])
        if direita:
            filho = noPai.insereNoDireita(direita[0])
            criarArvorePreOrdem2(filho, direita[1:])

def criarArvorePreOrdem3(noPai, valoresPreOrdem):
    if valoresPreOrdem:
        pilha = [noPai]
        for entrada in valoresPreOrdem:
            if entrada < pilha[-1].raiz:
                filho = pilha[-1].insereNoEsquerda(entrada)
                pilha.append(filho)
            else:
                while pilha and pilha[-1].raiz < entrada:
                    ultimo = pilha.pop()
                filho = ultimo.insereNoDireita(entrada)
                pilha.append(filho)



# quantidadeNos = 9
# valoresPreOrdem = [8, 3, 1, 6, 4, 7, 10, 14, 13]

quantidadeNos = int(input())
valoresPreOrdem = list(map(int,input().split()))


raiz = Arvore(valoresPreOrdem[0])


# for item in valoresPreOrdem[1:]:
#     criarArvorePreOrdem(raiz, item)

# criarArvorePreOrdem2(raiz, valoresPreOrdem[1:])
# criarArvorePreOrdem3(raiz, valoresPreOrdem[1:])

imprimeArvorePosOrdem(raiz)