"""
    Adicionar valores
    Criar uma lista circular
    Retirar valor da lista circular
"""
from pythonds.basic.queue import Queue


class Seletor:
    def __init__(self) -> None:
        self.fila = Queue()

    def adicionaLista(self, lista):
        self.fila = lista;

    def acrescenta(self, nome):
        self.fila.enqueue(nome)

    def retira(self):
        return self.fila.dequeue()

    def rodar(self, qtd):
        while self.fila.size() > 1:
            for i in range(qtd - 1):
                nome = self.retira()
                self.acrescenta(nome)
            self.retira()
        return self.retira()


#
l = ["Josephus", "Timão", "Henrique", "Geronimus", "Cornelius"]

# qtd = int(input())
lista = Seletor()
for i in range(len(l)):
    lista.acrescenta(l[i])
n = int(input())
print(lista.rodar(n))