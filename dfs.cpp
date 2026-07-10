#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100];
bool visited[100];

void DFS(int node)
{
    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node])
    {
        if (!visited[next])
        {
            DFS(next);
        }
    }
}

int main()
{
    int n, e;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    cout << "Enter edges:\n";

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u); // Undirected Graph
    }

    cout << "DFS Traversal: ";
    DFS(0);

    return 0;
}
