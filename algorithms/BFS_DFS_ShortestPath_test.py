import unittest
from graph import *
import random
from BFS_DFS_ShortestPath import *
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
    
    def test_DFS(self):
        DFS(self.graph, self.begin)
        for vertex in self.graph.vertices:
            self.assertEqual(vertex.explored, 1)

    def test_BFS(self):
        BFS(self.graph, self.begin)
        for vertex in self.graph.vertices:
            self.assertEqual(vertex.explored, 1)

    def test_shortest_path(self):
        self.assertEqual(shortest_path(self.graph, self.begin), None)
        for vertex in self.graph.vertices:
            for edge in vertex.adjacent_edge:
                self.assertEqual(edge.head.key, edge.tail.key + 1)
