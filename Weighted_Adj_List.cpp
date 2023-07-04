 #include<iostream>
#include<map>
#include<list>
#include<vector>
using namespace std;
template <typename T>

class graph{

    public:
        map<T,list<pair<T,float>>> adj;        //adjacency list declaration

        /* addEdges function takes vertices u and v between which edge exist and set it, also it take direction which 
           shows whether the graph is directed or undirected
        */
        void addEdgde(T u,T v,float wt,bool direction)
        {
            // direction = 0 -> undirected
            // direction = 1 -> directed

            //create an edge from u -> v
            adj[u].push_back({v,wt});

            if(direction==0)
            {
                adj[v].push_back({u,wt});
            }
        }

        /*printing adjacency list*/
        void print() 
        {
            for(auto i:adj){
                cout<< i.first <<" -> ";
                for(auto j:i.second)
                    cout<<"("<<j.first<<"|"<<j.second<<")"<<" ";
                cout<<"\b\b"<<endl; 
            }
        }
};

int main()
{
    graph<int> g;  // class object
    int v,e;        //v-->vertices and e--> edges
    cout<<"Enter number of vertices : ";
    cin>>v;
    cout<<"\nEnter number of edges : ";
    cin>>e;

    cout<<"Enter the edges nodes : \n";
    for(int i=0;i<e;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;      // vertex1, vertex2, weight
        //undirected graph
        g.addEdgde(u,v,wt,1); 
    }
    g.print();
    return 0;

}
/*
1 2 3
1 4 1
2 3 2
3 4 5
3 5 4
4 5 2
*/