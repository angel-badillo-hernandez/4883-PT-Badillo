/**
 * @file main.cpp
 * @author Angel Badillo Hernandez (https://github.com/It-Is-Legend27/)
 * @brief A solution to the Claw Decomposition problem.
 * @date 2022-09-22
 *
 */
// Sources:
// https://replit.com/@rugbyprof/4883Bipartite2?v=1#main.cpp
// Minor change from int** dynamic 2D array to vector<vector<int>>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// This function returns true if graph
// G[V][V] is Bipartite, else false
bool isBipartite(vector<vector<bool>> G, int src, int V)
{
  // Create a color array to store colors
  // assigned to all veritces. Vertex
  // number is used as index in this array.
  // The value '-1' of colorArr[i]
  // is used to indicate that no color
  // is assigned to vertex 'i'. The value 1
  // is used to indicate first color
  // is assigned and value 0 indicates
  // second color is assigned.
  vector<int> colorArr(V);

  for (int i = 0; i < V; ++i)
    colorArr[i] = -1;

  // Assign first color to source
  colorArr[src] = 1;

  // Create a queue (FIFO) of vertex
  // numbers and enqueue source vertex
  // for BFS traversal
  queue<int> q;
  q.push(src);

  // Run while there are vertices
  // in queue (Similar to BFS)
  while (!q.empty())
  {
    // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
    int u = q.front();
    q.pop();

    // Return false if there is a self-loop
    if (G[u][u] == 1)
      return false;

    // Find all non-colored adjacent vertices
    for (int v = 0; v < V; ++v)
    {
      // An edge from u to v exists and
      // destination v is not colored
      if (G[u][v] && colorArr[v] == -1)
      {
        // Assign alternate color to this adjacent v of u
        colorArr[v] = 1 - colorArr[u];
        q.push(v);
      }

      // An edge from u to v exists and destination
      // v is colored with same color as u
      else if (G[u][v] && colorArr[v] == colorArr[u])
        return false;
    }
  }

  // If we reach here, then all adjacent
  // vertices can be colored with alternate color
  return true;
}

int main()
{
  int n; // # nodes (vertices)
  int p0; // start node of edge
  int p1; // end node of edge

  // 2D vector of bools
  vector<vector<bool>> G;

  // Read # nodes
  while (cin >> n && n)
  {
    G.resize(n, vector<bool>(n)); // Resize 2d array

    // Read start node & end node of edges and put on graph
    while(cin >> p0 && cin >> p1 && p0 && p1)
    {
      G[p0-1][p1-1] = 1;
      G[p1-1][p0-1] = 1;
    }
    
    // Check if graph is bipartite
    isBipartite(G, 0, G.size()) ? cout << "YES\n" : cout << "NO\n";
    G.clear();
  }
  return 0;
}