from graph_dijkstra import *
from heap_dijkstra import *

def Dijkstra(s, graph):
    X = []
    H = heap()
    s.key = 0
    for v in graph.vertices:
        if v != s:
            v.key = float("inf")

    for v in graph.vertices:
        H.add(v)
    
    while H.empty() == False:
        w = H.extract_min()
        x = 0
        node = s
        for edge in w.adjacent_edge:
            if edge.head == w:          
                x = edge.weight
                node = edge.tail
        w.key = node.key + x
        X.append(w)
        
        for edge in w.adjacent_edge:
            if edge.tail == w:
                y = H.delete(edge.head.index)
                y.key = min(y.key, w.key + edge.weight)
                H.add(y)


s = vertex()
g = ALGraph(s)
v = vertex()
g.add_vertex(s, v, 1)
w = vertex()
g.add_vertex(s, w, 4)
g.new_edge(v, w, 2)
t = vertex()
g.add_vertex(v, t, 6)
g.new_edge(w, t, 3)
Dijkstra(s, g)
print(g)