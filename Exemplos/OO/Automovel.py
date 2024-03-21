class Automovel:
    def __init__(self, marca, modelo, cor, ano):
        self.marca = marca
        self._modelo = modelo
        self.cor = cor
        self.ano = ano
        self.estadoMotor = False

    def ligaMotor(self):
        self.estadoMotor = True

    def getModelo(self):
        return self._modelo

    def setAno(self, newAno):
        self.ano = newAno