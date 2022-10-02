/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the Mice and Maze problem.
 * @date 2022-09-29
 *
 */
// Sources:
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
// Minor change to code. Changed Graph::shortestPath to return shortest path from sender to
// receiver instead of printing all shortest paths.
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
#define INF 0x3f3f3f3f
#define newl '\n'
// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph {
	int V; // No. of vertices

	// In a weighted graph, we need to store vertex
	// and weight pair for every edge
	list<iPair>* adj;

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);

	// prints shortest path from s
	int shortestPath(int s, int t);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	//adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
int Graph::shortestPath(int src, int dest)
{
	// Create a priority queue to store vertices that
	// are being preprocessed. This is weird syntax in C++.
	// Refer below link for details of this syntax
	// https://www.geeksforgeeks.org/implement-min-heap-using-stl/
	priority_queue<iPair, vector<iPair>, greater<iPair> >
		pq;

	// Create a vector for distances and initialize all
	// distances as infinite (INF)
	vector<int> dist(V, INF);

	// Insert source itself in priority queue and initialize
	// its distance as 0.
	pq.push(make_pair(0, src));
	dist[src] = 0;

	/* Looping till priority queue becomes empty (or all
	distances are not finalized) */
	while (!pq.empty()) {
		// The first vertex in pair is the minimum distance
		// vertex, extract it from priority queue.
		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted distance (distance must be first item
		// in pair)
		int u = pq.top().second;
		pq.pop();

		// 'i' is used to get all adjacent vertices of a
		// vertex
		list<pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			// Get vertex label and weight of current
			// adjacent of u.
			int v = (*i).first;
			int weight = (*i).second;

			// If there is shorted path to v through u.
			if (dist[v] > dist[u] + weight) {
				// Updating distance of v
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

    return dist[dest];
}

int main()
{   int numCases; // # cases
    int N;        // # cells
    int E;        // ID of exit cell
    int T;        // count-down timer
    int M;        // # edges
    int pA;       // point A
    int pB;       // point B
    int w;        // weight
    int mExit;   // # mice that exit maze
    cin >> numCases;
    
    while(numCases)
    {
        mExit = 0;
        cin >> N >> E >> T >> M;
        
        Graph G(N);
        
        // Add M edges to graph
        for (int i = 0; i < M; i++)
        {
           cin >> pA >> pB >> w;
           G.addEdge(pA-1, pB-1, w); // orignally designed for 0 to N-1
        }
        
        // Count # of mice that left the maze
        for(int i = 1; i <= N; i++)
        {
            if(G.shortestPath(i-1,E-1) <= T)
            mExit++;
        }

        cout << mExit << newl;
        if(numCases > 1)
        cout << newl;
        numCases--;
    }
    return 0;
}