class Edge(object):
    def __init__(self, tail, head):
        self.tail = tail
        self.head = head
    
    def __repr__(self):
        return f"tail: {self.tail.count}, head: {self.head.count}"
    
    def set_vertices(self, tail, head):
        self.tail = tail
        self.head = head

    def get_vertices(self):  
        return (self.tail, self.head)

class vertex(object):
    def __init__(self, explored = 0, key = 0, *args):
        self.adjacent_edge = [x for x in args]
        self.explored = explored
        self.key = key
    
    def __repr__(self):
        return f"Key={self.key} Explored = {self.explored}\n"
    
    def get_edge(self):
        return self.adjacent_edge
    
    def add_edge(self, edge):
        l = self.adjacent_edge
        l.append(edge)

    def get_key(self):
        return self.key

    def set_key(self, key):
        self.key = key

class ALGraph(object):
    def __init__(self, first_vertex):
        self.vertices = [first_vertex]
        self.edge = []
    
    def __repr__(self):
        return f"Vertices: {self.vertices}"
    
    def add_vertex(self, from_vertex, new_vertex, inv=False):
        self.vertices.append(new_vertex)
        if inv:
            edge = Edge(new_vertex, from_vertex)
        else:
            edge = Edge(from_vertex, new_vertex)

        self.edge.append(edge)
        new_vertex.add_edge(edge)
        from_vertex.add_edge(edge)

    def new_edge(self, from_vertex, to_vertex, inv=False):
        if inv:
            edge = Edge(to_vertex, from_vertex)
        else:
            edge = Edge(from_vertex, to_vertex)

        self.edge.append(edge)
        to_vertex.add_edge(edge)
        from_vertex.add_edge(edge)
 