def rev_TopoSort(graph):
    l = []
    for vertex in graph.vertices:
        vertex.explored = 0
    curLabel = len(graph.vertices)
    for v in graph.vertices:
        if v.explored == 0:
            curLabel = rev_Topo_DFS(v, curLabel, l)
    
    return l

def rev_Topo_DFS(vertex, curLabel, l):
    if vertex.explored == 1:
        return curLabel
    vertex.explored = 1 
    for edge in vertex.adjacent_edge:
        if edge.head == vertex:
            curLabel = rev_Topo_DFS(edge.tail, curLabel, l) 
    vertex.key = curLabel
    l.append(vertex)
    
    return curLabel - 1

def DFS_SCC(numSCC, v):
    if v.explored == 1:
        return
    v.explored = 1
    v.key = numSCC
    for edge in v.adjacent_edge:
        if edge.tail == v:
            DFS_SCC(numSCC, edge.head)

def Korasaju(graph):
    #run rev_topo sort on graph is like running topo sort on rev_graph
    l = rev_TopoSort(graph) # a list of magical ordering vertex xd
    for vertex in graph.vertices:
        vertex.explored = 0
    
    numSCC = 0
    for i in range(len(l)-1, -1, -1):
#    for i in range(0, len(l)):
        v = l[i]
        if v.explored == 0:
            numSCC += 1
            DFS_SCC(numSCC, v)
