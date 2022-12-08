from queue import Queue


def colorEdges(ptr, teams, colours, visited):
    q = Queue()
    c = 0

    colored = set()

    if visited[ptr]:
        return

    visited[ptr] = True

    for i in range(len(teams[ptr])):
        if colours[teams[ptr][i][1]] != -1:
            colored.add(colours[teams[ptr][i][1]])

    for i in range(len(teams[ptr])):
        if not visited[teams[ptr][i][0]]:
            q.put(teams[ptr][i][0])

        if colours[teams[ptr][i][1]] == -1:
            while c in colored:
                c += 1
            colours[teams[ptr][i][1]] = c

            colored.add(c)
            c += 1

    while not q.empty():
        temp = q.get()

        colorEdges(temp, teams, colours, visited)
    return


if __name__ == "__main__":
    empty = set()

    teams = []

    colours = []

    visited = [False] * 100000

    ver = int(input("Enter the number of vertices: "))
    edge = int(input("Enter the number of edges: "))

    teams = [[] for _ in range(ver)]
    colours = [-1] * edge
    for i in range(edge):
        x, y = map(int, input().split())
        teams[x].append([y, i])
        teams[y].append([x, i])

    colorEdges(0, teams, colours, visited)

    d = {i: [] for i in range(1, 10)}
    for i in range(edge):
        print("Match {} occurs {}".format(i + 1, colours[i] + 1))
        d[colours[i] + 1].append(i + 1)
        
    
    print(d)

