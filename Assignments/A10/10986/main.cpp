/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the Sending Email problem.
 * @date 2022-09-29
 *
 */
// Sources:
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
// Minor change to code. Removed hardcoding and switched C-arrays to std:vector.
// Changed djikstra function from printing full array of shortest paths to
// only returning the shortest path from source to destination.
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int V, vector<int> &dist, vector<bool> &sptSet)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
int dijkstra(int V, vector<vector<int>> &G, int src, int dest)
{
    vector<int> dist(V); // The output array. dist[i] will hold the
				         // shortest
	                     // distance from src to i
    
    vector<bool> sptSet(V); // sptSet[i] will be true if vertex i is
					       // included in shortest
	                       // path tree or shortest distance from src to i is
	                       // finalized

	// Initialize all distances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(V, dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && G[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + G[u][v] < dist[v])
				dist[v] = dist[u] + G[u][v];
	}

	return dist[dest];
}

int main()
{   
    int N; // # of cases
	int caseNum = 0; // ID of case
    int n; // # of servers (vertices)
    int m; // # of cables (edges)
    int s; // sender server
    int t; // receiver server
    int w; // weight of edge
    int p0; // start point of edge
    int p1; // end point of edge
    vector<vector<int>> G;
    
    // # cases
    cin >> N;
	
    // Loop for N cases
    while(N)
    {
		caseNum++;
        cin >> n >> m >> s >> t;
        // Create graphs
        G.resize((n), vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            cin >> p0 >> p1 >> w;
            G[p0][p1] = w;
            G[p1][p0] = w;
        }

        int shortPath = dijkstra(n, G, s, t);
		cout << "Case #" << caseNum << ": ";
		(shortPath != INT_MAX) ? cout << shortPath : cout << "unreachable";
		cout << '\n';
        G.clear();
        N--;
    }

    return 0;
}