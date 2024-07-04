from pythonds.basic.stack import Stack
class FilaComDuasPilhas():
    def __init__(self):
        self.pilha1 = Stack()
        self.pilha2 = Stack()

    def enqueue(self, elemento):
        self.pilha1.push(elemento)

    def dequeue(self):
        return self.pilha2.pop()

    def move(self, pilha_Origem, pilha_Destino, string):
        quantidade = pilha_Origem.size()
        for i in range(quantidade):
            elemento = pilha_Origem.pop()
            pilha_Destino.push(elemento)
        if quantidade > 0:
            print("MOVE "+string+" "+str(quantidade))

    def drop(self, quantidade):
        if self.pilha1.size() == 0:
            self.move(self.pilha2, self.pilha1, "2->1")
        for i in range(quantidade):
            self.enqueue(i)
        print("DROP 1 "+str(quantidade))

    def take(self, quantidade):
        if self.pilha2.size() < quantidade :
            self.move(self.pilha1, self.pilha2, "1->2")
        for i in range(quantidade):
            self.dequeue()
        print("TAKE 2 "+str(quantidade))

while True:
    operacoes = int(input())
    if operacoes == 0:
        break
    fila = FilaComDuasPilhas()
    for i in range(operacoes):
        operacao = input()
        comando, quantidade = operacao.split(" ")
        if comando == "DROP":
            fila.drop(int(quantidade))
        elif comando == "TAKE":
            fila.take(int(quantidade))
    print("-----------")

'''
3
DROP 100
TAKE 50
TAKE 20
3
DROP 3
DROP 5
TAKE 8
0
'''