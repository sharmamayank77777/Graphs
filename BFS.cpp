#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class graph{

    public:
        map<int,list<int>> adj;        //adjacency list declaration

        /* addEdges function takes vertices u and v between which edge exist and set it, also it take direction which 
           shows whether the graph is directed or undirected
        */
        void addEdgde(int u,int v,bool direction)
        {
            // direction = 0 -> undirected
            // direction = 1 -> directed

            //create an edge from u -> v
            adj[u].push_back(v);

            //checking id directed or not
            if(direction==0)
            {
                adj[v].push_back(u);
            }
        }

        /*printing adjacency list*/
        void print() 
        {
            for(auto i:adj){
                //printing vertex
                cout<< i.first <<" -> ";
                //printing neighbour of vertex i
                for(auto j:i.second)
                    cout<<j<<", ";
                cout<<"\b"<<endl; 
            }
        }

        // dfs-traversal of graph
        void dfs(map<int,bool> &vis,vector<int> &ans,int ver)
        {
                vis[ver]=true;
                //storing visited element
                ans.push_back(ver);
                //exploring neighbours
                for(auto j:adj[ver])
                {
                    //if not visited push into queue to traverse
                    if(vis[j]==false)
                    {
                        dfs(vis,ans,j);
                    }
                }
        }
    
        
};

int main()
{
    graph g;  // class object
    int v,e;        //v-->vertices and e--> edges
    cout<<"Enter number of vertices : ";
    cin>>v;
    cout<<"\nEnter number of edges : ";
    cin>>e;

    cout<<"Enter the edges nodes : \n";
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        //undirected graph
        g.addEdgde(u,v,0); 
    }
    g.print();

    //bfs traverasal
    map<int,bool> visited;
    vector<int> ans;

    //for visiting all components 
    for(int i=1;i<=v;i++)
    {
        if(!visited[i])
        g.dfs(visited,ans,i);
    }

    //printing bfs traversal
    cout<<"BFS Travesal of graph : ";
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    
    return 0;

}
/*
1 2
1 3
2 1
2 5 
2 6
3 1
3 4
3 7
4 3
4 8
5 2
6 2
7 3
7 8
8 4
8 7
*/
