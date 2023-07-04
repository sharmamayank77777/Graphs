#include<iostream>
#include<map>
#include<list>
using namespace std;
template <typename T>

class graph{

    public:
        map<T, list<T>> adj;        //adjacency list declaration

        /* addEdges function takes vertices u and v between which edge exist and set it, also it take direction which 
           shows whether the graph is directed or undirected
        */
        void addEdgde(T u,T v,bool direction)
        {
            // direction = 0 -> undirected
            // direction = 1 -> directed

            //create an edge from u -> v
            adj[u].push_back(v);

            if(direction==0)
            {
                adj[v].push_back(u);
            }
        }

        /*printing adjacency list*/
        void print() 
        {
            for(auto i:adj){
                cout<< i.first <<" -> ";
                for(auto j:i.second)
                    cout<<j<<",";
                cout<<"\b"<<endl; 
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
        int u,v;
        cin>>u>>v;
        //undirected graph
        g.addEdgde(u,v,1); 
    }
    g.print();
    return 0;

}