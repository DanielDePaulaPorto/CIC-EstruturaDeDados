
class FilaPrioridade:
    def __init__(self):
        self.fila_Jovens = []
        self.fila_60 = []
        self.fila_80 = []

    def adiciona_pessoa(self, idade):
        if idade >= 80:
            self.fila_80.append(idade)
        elif idade >= 60:
            self.fila_60.append(idade)
        else:
            self.fila_Jovens.append(idade)
    def size (self):
        return (len(self.fila_Jovens) + len(self.fila_60) + len(self.fila_80))

    def chama_proximo_fila(self):
        if len(self.fila_80) > 0:
            return self.fila_80.pop(0)
        elif len(self.fila_60) > 0:
            return self.fila_60.pop(0)
        elif len(self.fila_Jovens) > 0:
            return self.fila_Jovens.pop(0)
        else:
            print("Fila de prioridades vazia!!!")

    def __str__(self):
        return(f"{self.fila_80} {self.fila_60} {self.fila_Jovens}")


fila = FilaPrioridade()

fila.adiciona_pessoa(23)
fila.adiciona_pessoa(45)
fila.adiciona_pessoa(92)
fila.adiciona_pessoa(60)
fila.adiciona_pessoa(25)

print(fila)
fila.chama_proximo_fila()
print(fila)

fila.adiciona_pessoa(81)
fila.adiciona_pessoa(86)
fila.adiciona_pessoa(45)
fila.adiciona_pessoa(77)
fila.adiciona_pessoa(79)

print(fila)
fila.chama_proximo_fila()
print(fila)