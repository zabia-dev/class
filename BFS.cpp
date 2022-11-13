#include <iostream>

using namespace std;

int n, m, k, i, j, graph[10][10], v;
int visited[10], step=1, connection[10];
int Queue[10], rear, Front;

int main()
{
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    cout<<"EDGES\n";

    for(k=1; k<=m; k++) {
        cin>>i>>j;
        graph[i][j]=1;
    }

    cout<<"Inputed adjacency matrix: "<<endl;
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }

    cout<<"Enter the starting vertex: ";
    cin>>v;
    cout<<"BFS ORDER: ";
    cout<<v<<" ";

    visited[v] = 1;

    while(step<n)
    {
        for(j=1; j<=n; j++)
        {
            if(graph[v][j]==1 && visited[j]==0 && connection[j]==0)
            {
                connection[j]=1;
                Queue[rear] = j;
                rear++;
            }
        }
        v = Queue[Front];
        Front++;
        cout<<v<<" ";
        visited[v]=1;
        connection[v] = 0;
        step++;
    }
}
