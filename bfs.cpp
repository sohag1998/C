#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100];
bool visited[100];

void BFS(int start)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : graph[node])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
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
        graph[v].push_back(u);
    }

    cout << "BFS Traversal: ";

    BFS(0);

    return 0;
}
