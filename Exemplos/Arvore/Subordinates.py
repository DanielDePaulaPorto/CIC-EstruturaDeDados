class Arvore:
    def __init__(self, valor):
        self.raiz = valor
        self.subordinados = 0
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

def preenchesubordinados(noRaiz):
    if len(noRaiz.filhos) == 0:
        noRaiz.subordinados = 0
        return 1
    else:
        for filho in noRaiz.filhos:
            noRaiz.subordinados += preenchesubordinados(filho)
        return 1 + noRaiz.subordinados

quantidadeFuncionarios = int(input())
subordinados = [int(x) for x in input().split()]

funcionarios = []
for i in range(quantidadeFuncionarios):
    funcionarios.append(Arvore(i+1))

for i in range(len(subordinados)):
    funcionarios[subordinados[i]-1].insereNo(funcionarios[i+1])

preenchesubordinados(funcionarios[0])

for i in range(quantidadeFuncionarios):
    print(funcionarios[i].subordinados, end=' ')

# 5
# 1 1 2 3


