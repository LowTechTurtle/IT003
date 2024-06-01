import unittest
from graph import *
import random
from korasaju import *
class test_search_shortestpath(unittest.TestCase):
    def setUp(self):
        self.begin = vertex()
        self.graph = ALGraph(self.begin)
        for i in range(0, 1000):
            r = random.randint(1, 4)
            for j in range(0, r):
                temp_vertex = vertex()
                from_vertex = random.choice(self.graph.vertices)
                self.graph.add_vertex(from_vertex, temp_vertex)
    
    def test_korasaju(self):
        self.assertEqual(Korasaju(self.graph), None) #proof that it can run :)
        #correctly or not, it'll run xd
    
    def test_Korasaju(self):
        vertex1 = vertex()
        vertex2 = vertex()
        vertex3 = vertex()
        vertex4 = vertex()
        vertex5 = vertex()
        vertex6 = vertex()
        vertex7 = vertex()
        vertex8 = vertex()
        vertex9 = vertex()
        vertex10 = vertex()
        vertex11 = vertex()

        #SCC1
        graph = ALGraph(vertex1)
        graph.add_vertex(vertex1, vertex3)
        graph.add_vertex(vertex3, vertex5)
        graph.new_edge(vertex5, vertex1)

        #SCC2
        graph.add_vertex(vertex3, vertex11)

        #SCC3
        graph.add_vertex(vertex5, vertex7)
        graph.add_vertex(vertex5, vertex9)
        graph.new_edge(vertex7, vertex9)
        graph.add_vertex(vertex9, vertex4)
        graph.add_vertex(vertex9, vertex2)
        graph.new_edge(vertex2, vertex4)
        graph.new_edge(vertex4, vertex7)

        #SCC4
        graph.add_vertex(vertex2, vertex10)
        graph.add_vertex(vertex9, vertex8)
        graph.add_vertex(vertex11, vertex6)
        graph.new_edge(vertex11, vertex8)
        graph.new_edge(vertex8, vertex6)
        graph.new_edge(vertex6, vertex10)
        graph.new_edge(vertex10, vertex8)

        Korasaju(graph)
        print(graph)
        self.assertEqual(vertex1.key, 4)
        self.assertEqual(vertex3.key, 4)
        self.assertEqual(vertex5.key, 4)
        self.assertEqual(vertex11.key, 3)
        self.assertEqual(vertex7.key, 2)
        self.assertEqual(vertex9.key, 2)
        self.assertEqual(vertex2.key, 2)
        self.assertEqual(vertex4.key, 2)
        self.assertEqual(vertex8.key, 1)
        self.assertEqual(vertex6.key, 1)
        self.assertEqual(vertex10.key, 1)