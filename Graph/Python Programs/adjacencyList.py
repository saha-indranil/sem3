# Write a Python program to implement Graph using Adjacency list along with the following function:
# a. To count number of vertices and edges present in a graph.
# b. To find the adjacent vertices of a given vertex.
# c. To search a node in a given graph.


class AdjNode:
    def __init__(self, value):
        self.vertex = value
        self.next = None


class Graph:
    def __init__(self, num):
        self.V = num
        self.graph = [None] * self.V

    def addEdge(self, s, d):
        node = AdjNode(d)
        node.next = self.graph[s]
        self.graph[s] = node

        node = AdjNode(s)
        node.next = self.graph[d]
        self.graph[d] = node

    def printGraph(self):
        for i in range(self.V):
            print("\nVertex", i, end="")
            temp = self.graph[i]
            while temp:
                print(" -> {}".format(temp.vertex), end="")
                temp = temp.next


if __name__ == "__main__":
    n = int(input("Enter Number of Vertices: "))
    m = int(input("Enter Number of Edges: "))
    graph = Graph(n)
    for i in range(m):
        u, v = map(int, input("Add Edge Between: ").split())
        graph.addEdge(u, v)
    graph.printGraph()


"""
    0-----1
   /  \   |      6
  3    \  |    /  \
  |     \ |   7----5
  4 ---- 2

"""

# OUTPUT
# Enter Number of Vertices: 8
# Enter Number of Edges: 9
# Add Edge Between: 0 1
# Add Edge Between: 0 2
# Add Edge Between: 0 3
# Add Edge Between: 1 2
# Add Edge Between: 2 4
# Add Edge Between: 3 4
# Add Edge Between: 5 6
# Add Edge Between: 5 7
# Add Edge Between: 6 7

# Vertex 0 -> 3 -> 2 -> 1
# Vertex 1 -> 2 -> 0
# Vertex 2 -> 4 -> 1 -> 0
# Vertex 3 -> 4 -> 0
# Vertex 4 -> 3 -> 2
# Vertex 5 -> 7 -> 6
# Vertex 6 -> 7 -> 5
# Vertex 7 -> 6 -> 5
