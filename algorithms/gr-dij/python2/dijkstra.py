"""
Python 2 Port from Python 3 based on
https://github.com/FOSS-UCSC/FOSSALGO/blob/master/algorithms/gr-dij/python3/dijkstra.py
"""

# Library for INT_MAX
import sys

class Graph(object):

	def __init__(self, vertices):
		self.V = vertices
		self.graph = [[0] * vertices for _ in xrange(vertices)]

	def printSolution(self, dist):
		print u"Vertex Distance from Source"
		for node in xrange(self.V):
			print node, u"to", dist[node]

	# A utility function to find the vertex with
	# minimum distance value, from the set of vertices
	# not yet included in shortest path tree
	def minDistance(self, dist, sptSet):

		# Initilaize minimum distance for next node
		min1 = sys.maxsize

		# Search not nearest vertex not in the
		# shortest path tree
		for v in xrange(self.V):
			if dist[v] < min1 and sptSet[v] == False:
				min1 = dist[v]
				min_index = v

		return min_index

	# Funtion that implements Dijkstra's single source
	# shortest path algorithm for a graph represented
	# using adjacency matrix representation
	def dijkstra(self, src):

		dist = [sys.maxsize] * self.V
		dist[src] = 0
		sptSet = [False] * self.V

		for cout in xrange(self.V):

			# Pick the minimum distance vertex from
			# the set of vertices not yet processed.
			# u is always equal to src in first iteration
			u = self.minDistance(dist, sptSet)

			# Put the minimum distance vertex in the
			# shotest path tree
			sptSet[u] = True

			# Update dist value of the adjacent vertices
			# of the picked vertex only if the current
			# distance is greater than new distance and
			# the vertex in not in the shotest path tree
			for v in xrange(self.V):
				if self.graph[u][v] > 0 and \
					sptSet[v] == False and \
					dist[v] > dist[u] + self.graph[u][v]:
					dist[v] = dist[u] + self.graph[u][v]
		print u"From 0 to " + unicode(cout)
		self.printSolution(dist)

# Driver program
g = Graph(9)
g.graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
		[4, 0, 8, 0, 0, 0, 0, 11, 0],
		[0, 8, 0, 7, 0, 4, 0, 0, 2],
		[0, 0, 7, 0, 9, 14, 0, 0, 0],
		[0, 0, 0, 9, 0, 10, 0, 0, 0],
		[0, 0, 4, 14, 10, 0, 2, 0, 0],
		[0, 0, 0, 0, 0, 2, 0, 1, 6],
		[8, 11, 0, 0, 0, 0, 1, 0, 7],
		[0, 0, 2, 0, 0, 0, 6, 7, 0]
		];

g.dijkstra(0);
