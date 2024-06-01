from graph import *

def BFS(graph, s):
    for v in graph.vertices:
        v.explored = 0
    s.explored = 1
    queue = [s]
    while queue != []:
        v = queue.pop(0)
        for e in v.get_edge():
            if e.tail == v:
                if e.head.explored == 0:
                    queue.append(e.head)
                    e.head.explored = 1

def DFS(graph, s):
    for v in graph.vertices:
        v.explored = 0
    s.explored = 1
    stack = [s]
    while stack != []:
        v = stack.pop()
        for e in v.get_edge():
            if e.tail == v:
                if e.head.explored == 0:
                    stack.append(e.head)
                    e.head.explored = 1

def shortest_path(graph, s):
    for v in graph.vertices:
        v.explored = 0
        v.key = float("inf")
    s.explored = 1
    s.key = 0
    queue = [s]
    while queue != []:
        v = queue.pop(0)
        for e in v.get_edge():
            if e.tail == v:
                if e.head.explored == 0:
                    e.head.explored = 1
                    e.head.key = e.tail.key + 1
                    queue.append(e.head)

