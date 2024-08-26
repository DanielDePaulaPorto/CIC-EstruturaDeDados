vertices, arestas = [], []
for _ in range(int(input())):
    v, A, *vizinhos = input().split()
    vertices.append(int(v))
    for i in range(0, len(vizinhos), 2):
        arestas.append((int(vizinhos[i]), vertices[-1], int(vizinhos[i + 1])))

total = 0
arestas.sort(reverse=True)
agm = {v: set() for v in vertices}
while arestas:  # Kruskal
    t, o, d = arestas.pop()
    if d not in agm[o]:
        agm[o].add(d)
        agm[d].add(o)
        agm[o] |= agm[d]
        agm[d] |= agm[o]
        for v in agm[o]:
            agm[v] |= agm[o]

        total += t

print(f'R$ {total * 3.14:.2f}')
