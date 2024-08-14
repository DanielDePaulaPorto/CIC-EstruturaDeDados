from pythonds import graphs


class Vertice:
    def __init__(self,valor):
        self.valor=valor
        self.vizinhos={}

    def __str__(self):
        return str(self.valor) +' - '+ str(self.vizinhos.keys())

class Grafo:
    def __init__(self):
        self.vertices = {}

    def adiciona_vertice(self,valor):
        novo_vertice = Vertice(valor)
        self.vertices[valor]=novo_vertice
        return novo_vertice

    def adiciona_aresta(self,vertice1,vertice2,peso):
        if vertice1 not in self.vertices.keys():
            self.adiciona_vertice(vertice1)
        if vertice2 not in self.vertices.keys():
            self.adiciona_vertice(vertice2)

        self.vertices[vertice1].vizinhos[vertice2] = peso

    def lista_vertices(self):
        print([i for i in self.vertices.keys()])

    def print_grafo(self):
        print([str(i) for i in self.vertices.values()])

g = Grafo()

vertice_V0 = g.adiciona_vertice('V0')
vertice_V1 = g.adiciona_vertice('V1')
vertice_V2 = g.adiciona_vertice('V2')
vertice_V3 = g.adiciona_vertice('V3')
vertice_V4 = g.adiciona_vertice('V4')
vertice_V5 = g.adiciona_vertice('V5')


g.adiciona_aresta('V0','V1',5)
g.adiciona_aresta('V0','V5',2)
g.adiciona_aresta('V1','V2',4)
g.adiciona_aresta('V2','V3',9)
g.adiciona_aresta('V3','V4',7)
g.adiciona_aresta('V3','V5',3)
g.adiciona_aresta('V4','V0',1)
g.adiciona_aresta('V5','V4',8)
g.adiciona_aresta('V5','V2',1)

g.lista_vertices()
print('---')
g.print_grafo()
