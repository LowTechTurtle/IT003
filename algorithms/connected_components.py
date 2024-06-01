from graph import *
from BFS_DFS_ShortestPath import *
def UCC(graph):
    UCC_num = 0
    for vertex in graph.vertices:
        vertex.explored = 0
    for vertex in graph.vertices:
        if vertex.explored == 0:
            UCC_num += 1
            queue = [vertex]
            while queue != []:
                v = queue.pop(0)
                v.key = UCC_num
                for edge in v.adjacent_edge:
                    if v == edge.tail:
                        if edge.head.explored == 0:
                            edge.head.explored = 1
                            queue.append(edge.head)
                    elif v == edge.head:
                        if edge.tail.explored == 0:
                            edge.tail.explored = 1
                            queue.append(edge.tail)