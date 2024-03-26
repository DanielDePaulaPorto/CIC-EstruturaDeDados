class Empregado:
    def __init__(self, nome, idade, salario):
        self.nome = nome
        self.idade = idade
        self.salario = salario

    def getIdade(self):
        return self.idade


    def getSalario(self):
        return self.salario

    def saudacao(self):
        print("Olá, sou um Empregado!")

    def apresentacao(self, saudacao="Olá"):
        if self.nome is not None:
            print(f"{saudacao}, meu nome é {self.nome}!")
        else:
            print(f"{saudacao}, sou uma pessoa sem nome!")