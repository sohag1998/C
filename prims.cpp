#include <iostream>
using namespace std;

const int INF = 1000000;

int main()
{
    int n = 5;

    int graph[5][5]=
    {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    int key[5];
    bool mst[5];
    int parent[5];

    for(int i=0;i<n;i++)
    {
        key[i]=INF;
        mst[i]=false;
    }

    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<n-1;count++)
    {
        int u=-1;

        for(int i=0;i<n;i++)
        {
            if(!mst[i] && (u==-1 || key[i]<key[u]))
                u=i;
        }

        mst[u]=true;

        for(int v=0;v<n;v++)
        {
            if(graph[u][v]!=0 &&
               !mst[v] &&
               graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }

    cout<<"Edges in MST\n";

    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<" - "<<i
            <<" = "<<key[i]<<endl;
    }
}
