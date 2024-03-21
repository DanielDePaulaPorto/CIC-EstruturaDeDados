from Exemplos.OO.Empregado import Empregado

class Gerente(Empregado):

    def __init__(self,nome, idade,salario):
        super().__init__(nome, idade,salario)

    def calcula_salario(self, perc):
        self.salario *= perc

    def saudacao(self):
        print("Olá, sou um Gerente!")



gerente = Gerente("Nome",30,1000)
gerente.calcula_salario(5)

print("calcula_salario: " + str(gerente.getSalario()))

gerente.apresentacao()
gerente.apresentacao("E aí?!")

