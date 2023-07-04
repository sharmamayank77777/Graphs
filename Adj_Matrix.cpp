// Aadjacency Matrix Representation

#include<iostream>
using namespace std;
int main()
{
    int v,e;            // v --> vertices  &  e --> edges
    cout<<"Enter number of vertices : ";
    cin>>v;
    cout<<"\nEnter number of edges : ";
    cin>>e;

    int adj[v+1][v+1];      //adjacency matrix

    //assigning edges 0 initially
    for(int i=0;i<=v;i++)
    {
        for(int j=0;j<=v;j++)
        adj[i][j]=0;
    }

    // setting up edges
    cout<<"Enter Edges : \n";
    for(int i=0;i<e;i++)
    {
       int u,v;
       cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    //printing matrix to show the edges b/w vertices
    cout<<"\nEgdes exist between given vertices : \n";
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
1 2
1 4
2 3
3 4
3 5
4 5
*/