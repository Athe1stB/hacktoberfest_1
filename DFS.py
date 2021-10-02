from collections import defaultdict, deque
graph = defaultdict(list)
edges = int(input("Enter number of edges: "))
for _ in range(edges):
    p, q = input().split()
    graph[p].append(q)
    graph[q].append(p)

s = input("Start your traversal from which node ?: ")
q = deque()
q.append(s)
d = defaultdict(int)
d[s] = 1
while q:
    p = q.pop()


    print(p)

    for i in graph[p]:
        if not d[i]:
            d[i] = 1
            q.append(i)
