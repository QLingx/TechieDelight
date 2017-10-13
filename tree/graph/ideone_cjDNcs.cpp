#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define N 8

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph 
{
public:
	// A array of vectors to represent adjacency list
	vector<int> adjList[N];

	// stores indegree of a vertex
	vector<int> indegree;

	// Constructor
	Graph(vector<Edge> edges)
	{
		// initalize indegree
		vector<int> temp(N, 0);
		indegree = temp;

		// add edges to the directed graph
		for (unsigned i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;		// source
			int dest = edges[i].dest;	// destination
			
			// add an edge from source to destination
			adjList[src].push_back(dest);
			
			// increment in-degree of destination vertex by 1
			indegree[dest]++;
		}
	}
};

// performs Topological Sort on a given DAG
bool doTopologicalSort(Graph const &graph, list<int> &L)
{
	vector<int> indegree = graph.indegree;

	// Set of all nodes with no incoming edges
	list<int> S;
	for (int i = 0; i < N; i++)
		if (!indegree[i])
			S.push_back(i);

	while (!S.empty())
	{
		// remove a node n from S
		int n = S.back();
		S.pop_back();

		// add n to tail of L
		L.push_back(n);

		for (int m : graph.adjList[n])
		{
			// remove edge from n to m from the graph
			indegree[m] -= 1;

			// if m has no other incoming edges then
			// insert m into S
			if (!indegree[m])
				S.push_back(m);
		}
	}

	// if graph has edges then graph has at least one cycle
	for (int u = 0; u < N; u++)
		for (int i : graph.adjList[u])
			if (indegree[i])
				return false;

	return true;
}

int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges =
	{
		{ 0, 6 }, { 1, 2 }, { 1, 4 }, { 1, 6 }, { 3, 0 }, { 3, 4 },
		{ 5, 1 }, { 7, 0 }, { 7, 1 }
	};

	// create a graph from edges
	Graph graph(edges);

	// Empty list that will contain the sorted elements
	list<int> L;

	// perform Topological Sort
	if (doTopologicalSort(graph, L))
		for (int i : L)	 // print topological order
			cout << i << " ";
	else
		cout << "Graph has at least one cycle. "
				 "Topological sorting is not possible";

	return 0;
}