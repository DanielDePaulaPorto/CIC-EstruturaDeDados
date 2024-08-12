class ExercicioGrafo:
    def todosOsCaminhosParaOAlvo(self, graph: list[list[int]]):
        # lista de todos os caminhos
        caminhos = []

        # funcao recursiva que vai percorrer o grafo
        def procurarAlvo(graph, verticeAtual, verticeFinal, caminhoAtual):
            # copia o caminho feito ate agora (evita a perda de informacao durante as chamadas recursivas)
            caminhoAtual = caminhoAtual.copy()

            # adiciona o vertice atual
            caminhoAtual.append(verticeAtual)

            # se chegamos ao destino, adicionamos o caminho feito, e retornamos
            if verticeAtual == verticeFinal:
                caminhos.append(caminhoAtual)
                return
            else:
                # vizinhos do vertice atual
                for adjacente in graph[verticeAtual]:
                    procurarAlvo(graph, adjacente, verticeFinal, caminhoAtual)

        procurarAlvo(graph, 0, len(graph)-1, [])
        return caminhos

# grafo = [[1,2],[3],[3],[]]
# grafo = [[4,3,1],[3,2,4],[3],[4],[]]
grafo = [[1,7],[2,3,4],[4,5],[4,5],[5],[6,7],[],[]]

exercicioGrafo = ExercicioGrafo()

print(exercicioGrafo.todosOsCaminhosParaOAlvo(grafo))