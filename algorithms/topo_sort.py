def TopoSort(graph):
    for vertex in graph.vertices:
        vertex.explored = 0
    curLabel = len(graph.vertices)
    for v in graph.vertices:
        if v.explored == 0:
            curLabel = Topo_DFS(v, curLabel)

def Topo_DFS(vertex, curLabel):
    if vertex.explored == 1:
        return curLabel
    vertex.explored = 1 
    for edge in vertex.adjacent_edge:
        if edge.tail == vertex:
            curLabel = Topo_DFS(edge.head, curLabel) 
    vertex.key = curLabel
    
    return curLabel - 1

def rev_TopoSort(graph):
    for vertex in graph.vertices:
        vertex.explored = 0
    curLabel = len(graph.vertices)
    for v in graph.vertices:
        if v.explored == 0:
            curLabel = rev_Topo_DFS(v, curLabel)

def rev_Topo_DFS(vertex, curLabel):
    if vertex.explored == 1:
        return curLabel
    vertex.explored = 1 
    for edge in vertex.adjacent_edge:
        if edge.head == vertex:
            curLabel = rev_Topo_DFS(edge.tail, curLabel) 
    vertex.key = curLabel
    
    return curLabel - 1
