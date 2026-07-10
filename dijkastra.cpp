#include <iostream>
using namespace std;

const int INF = 1000000;

int main()
{
    int n = 5;

    int graph[5][5] =
    {
        {0,10,3,0,0},
        {0,0,1,2,0},
        {0,4,0,8,2},
        {0,0,0,0,7},
        {0,0,0,9,0}
    };

    int dist[5];
    bool visited[5];

    for(int i=0;i<n;i++)
    {
        dist[i]=INF;
        visited[i]=false;
    }

    dist[0]=0;

    for(int i=0;i<n-1;i++)
    {
        int u=-1;

        for(int j=0;j<n;j++)
        {
            if(!visited[j] && (u==-1 || dist[j]<dist[u]))
                u=j;
        }

        visited[u]=true;

        for(int v=0;v<n;v++)
        {
            if(graph[u][v]!=0 && dist[u]+graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    cout<<"Shortest Distance:\n";

    for(int i=0;i<n;i++)
        cout<<i<<" = "<<dist[i]<<endl;
}
