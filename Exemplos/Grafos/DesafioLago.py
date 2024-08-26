def lake_height(graph, visited, n, m):
    biggest = 0

    for i in range(n + 2):
        for j in range(m + 2):
            if not visited[i][j]:
                volume = 0
                queue = [(i, j)]
                visited[i][j] = True
                while len(queue) != 0:
                    cur = queue.pop()
                    volume += graph[cur[0]][cur[1]]
                    if not visited[cur[0]][cur[1] + 1]:
                        visited[cur[0]][cur[1] + 1] = True
                        queue.append((cur[0], cur[1] + 1))

                    if not visited[cur[0]][cur[1] - 1]:
                        visited[cur[0]][cur[1] - 1] = True
                        queue.append((cur[0], cur[1] - 1))

                    if not visited[cur[0] + 1][cur[1]]:
                        visited[cur[0] + 1][cur[1]] = True
                        queue.append((cur[0] + 1, cur[1]))

                    if not visited[cur[0] - 1][cur[1]]:
                        visited[cur[0] - 1][cur[1]] = True
                        queue.append((cur[0] - 1, cur[1]))
                biggest = volume if volume > biggest else biggest
    return biggest


if __name__ == '__main__':
    t = int(input())

    while t > 0:
        n, m = map(int, input().split())
        lake = [[] for _ in range(n)]
        visited = [[] for _ in range(n)]

        for i in range(n):
            aux = list(map(int, input().split()))
            visited[i].append(True)
            lake[i].append(0)
            for j in range(m):
                lake[i].append(aux[j])
                if aux[j] != 0:
                    visited[i].append(False)
                else:
                    visited[i].append(True)
            visited[i].append(True)
            lake[i].append(0)
        visited.insert(0, [True for _ in range(m + 2)])
        visited.append([True for _ in range(m + 2)])
        lake.insert(0, [True for _ in range(m + 2)])
        lake.append([True for _ in range(m + 2)])
        print(lake_height(lake, visited, n, m))
        t -= 1