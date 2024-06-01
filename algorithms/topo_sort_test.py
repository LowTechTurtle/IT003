import unittest
import random 
from graph import *
from topo_sort import *

class test_topo_sort(unittest.TestCase):
    def setUp(self):
        self.begin = vertex()
        self.graph = ALGraph(self.begin)
        for i in range(0, 100):
            r = random.randint(1, 4)
            for j in range(0, r):
                temp_vertex = vertex()
                from_vertex = random.choice(self.graph.vertices)
                self.graph.add_vertex(from_vertex, temp_vertex)

    def test_toposort(self):
        TopoSort(self.graph)
        for vertex in self.graph.vertices:
            for edge in vertex.adjacent_edge:
                self.assertLess(edge.tail.key, edge.head.key)


    def test_revtoposort(self):
        rev_TopoSort(self.graph)
        for vertex in self.graph.vertices:
            for edge in vertex.adjacent_edge:
                self.assertGreater(edge.tail.key, edge.head.key)
                print(f"{edge.tail.key} < {edge.head.key}")
