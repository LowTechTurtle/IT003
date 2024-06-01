import unittest
from graph import *
import random
from korasaju import *
from connected_components import *
class test_search_shortestpath(unittest.TestCase):
    def setUp(self):
        self.begin = vertex()
        self.graph = ALGraph(self.begin)
        for i in range(0, 100):
            r = random.randint(1, 4)
            for j in range(0, r):
                temp_vertex = vertex()
                from_vertex = random.choice(self.graph.vertices)
                self.graph.add_vertex(from_vertex, temp_vertex)
        more = vertex()
        self.graph.vertices.append(more)
        for i in range(0, 10):
            more_temp_v = vertex()
            self.graph.add_vertex(more, more_temp_v)
        for edge in more.adjacent_edge:
            for i in range(0, 10):
                much_more_vertex = vertex()
                self.graph.add_vertex(edge.head, much_more_vertex)

    def DFS_check_key(self, vertex, key):
        for edge in vertex.adjacent_edge:
            if edge.head == vertex:
                if edge.tail.explored == 1:
                    edge.tail.explored = 0
                    self.assertEqual(edge.tail.key, key)
                    DFS_check_key(edge.tail, key)
            if edge.tail == vertex:
                if edge.head.explored == 1:
                    edge.tail.explored = 0
                    self.assertEqual(edge.head.key, key)
                    self.DFS_check_key(edge.head, key)
    
    def test_connected_component(self):
        self.assertEqual(UCC(self.graph), None)
        for vertex in self.graph.vertices:
            k = vertex.key
            self.DFS_check_key(vertex, k)
