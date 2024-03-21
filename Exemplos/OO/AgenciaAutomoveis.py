from Exemplos.OO.Automovel import Automovel

class AgenciaAutomoveis:
    def __init__(self):
        self.gol = Automovel("Volkswagen", "Gol", "Prata", 2022)
        self.monza = Automovel("Chevrolet", "Monza", "Vermelho", 1995)

# Criando uma instância da classe AgenciaAutomoveis
agencia = AgenciaAutomoveis()

# Acessando os atributos dos objetos gol e monza
print("Carro Gol:")
print("Marca:", agencia.gol.marca)
print("Modelo:", agencia.gol._modelo)
print("Modelo:", agencia.gol.getModelo())
print("Ano:", agencia.gol.ano)
print("Cor:", agencia.gol.cor)

print("\nCarro Monza:")
print("Marca:", agencia.monza.marca)
print("Modelo:", agencia.monza._modelo)
print("Ano:", agencia.monza.ano)
print("Cor:", agencia.monza.cor)