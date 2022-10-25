'''
`file`: main.cpp
`author`: Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
`brief`: A solution to the Oreon UVA problem.
`date`: 2022-10-13
'''
# Sources:
# https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
# Minor change in the code for the class, I removed print statements that I did not
# need, and printed the edges as specified in Oreon problem statement.

from collections import defaultdict

# Class to represent a graph


class Graph:

    def __init__(self, vertices):
        self.V = vertices  # No. of vertices
        self.graph = []  # default dictionary
        # to store graph

    # function to add an edge to graph
    def addEdge(self, u, v, w):
        self.graph.append([u, v, w])

    # A utility function to find set of an element i
    # (uses path compression technique)
    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])

    # A function that does union of two sets of x and y
    # (uses union by rank)
    def union(self, parent, rank, x, y):
        xroot = self.find(parent, x)
        yroot = self.find(parent, y)

        # Attach smaller rank tree under root of
        # high rank tree (Union by Rank)
        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot

        # If ranks are same, then make one as root
        # and increment its rank by one
        else:
            parent[yroot] = xroot
            rank[xroot] += 1

    # The main function to construct MST using Kruskal's
        # algorithm
    def KruskalMST(self):

        result = []  # This will store the resultant MST

        # An index variable, used for sorted edges
        i = 0

        # An index variable, used for result[]
        e = 0

        # Step 1:  Sort all the edges in
        # non-decreasing order of their
        # weight.  If we are not allowed to change the
        # given graph, we can create a copy of graph
        self.graph = sorted(self.graph,
                            key=lambda item: item[2])

        parent = []
        rank = []

        # Create V subsets with single elements
        for node in range(self.V):
            parent.append(node)
            rank.append(0)

        # Number of edges to be taken is equal to V-1
        while e < self.V - 1:

            # Step 2: Pick the smallest edge and increment
            # the index for next iteration
            u, v, w = self.graph[i]
            i = i + 1
            x = self.find(parent, u)
            y = self.find(parent, v)

            # If including this edge does't
            #  cause cycle, include it in result
            #  and increment the indexof result
            # for next edge
            if x != y:
                e = e + 1
                result.append([u, v, w])
                self.union(parent, rank, x, y)
            # Else discard the edge

        minimumCost = 0
        #print("Edges in the constructed MST")
        for u, v, weight in result:
            minimumCost += weight
            #print("%d -- %d == %d" % (u, v, weight))
            print(f"{chr(u+65)}-{chr(v+65)} {weight}")
        #print("Minimum Spanning Tree", minimumCost)

if __name__ == "__main__":
    # Read no. of cases
    numCases: int = int(input())

    # Loop for specified # of cases
    for c in range(1, numCases+1):
        # Read no. of tunnels
        numTunnels: int = int(input())

        # Create graph with specified no. of vertices
        g = Graph(numTunnels)

        # Matrix of ints
        matrix:list[list[int]] = []

        # Read in matrix and format it
        for r in range(0,numTunnels):
            matrix.append(list(map(int,input().split(", "))))
        
        # If edge weight is not 0, add the edge
        for i in range(0,numTunnels):
            for j in range(0, numTunnels):
                if matrix[i][j]:
                    g.addEdge(i,j, matrix[i][j])
        
        # Print resulting MST
        print(f"Case {c}:")
        g.KruskalMST()
