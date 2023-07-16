// Prims Algorithm -> to find minimum spanning tree

//Submitted by: Mayank Sharma (29)

#include<iostream> 
#include<unordered_map>
#include<list>
#include<set>
#include<vector>
using namespace std;

//class graph contain all necessary functionalities i.e., data members and functions
class Graph{
    public:
    //map to process graph as adjacency list
    unordered_map<int ,list <pair <int,int>>> adj;
    
    //addEdge function make take node and its edges and weight to store in list(undirected graph)
    void addEdge(int u,int v,int w)
    {
        pair<int,int> p = make_pair(v,w);
        adj[u].push_back(p);

        pair<int,int> q = make_pair(u,w);
        adj[v].push_back(q);

    }
    
    // display function to display stored graph as ordered pair of vertices along with weight
    void display()
    {
        for(auto x: adj){
            cout<<x.first<<" -- > ";
            for(auto y: x.second)
            cout<<"("<<y.first<<" , "<<y.second<<")";
            cout<<endl;
        }
    }
    
    //implementing dijkstra algorithm and returning answer as vector of shortest distance from source node
    vector<pair<pair<int,int> ,int>> Prims_Algo(int ver,int edges)
    {
        vector<int> key(ver+1);
        vector<bool> mst(ver+1);
        vector<int> parent(ver+1);

        for(int i=0;i<=ver;i++)
        {
            key[i]=INT_MAX;
            mst[i]=false;
            parent[i]=-1;
        } 

        key[1]=0;
        parent[1]=-1;
        for(int i=1;i<ver;i++)
        {
            int mini=INT_MAX;
            int u;
            //find min. nodes
            for(int v=1;v<=ver;v++)
            {
                if(mst[v]==false && key[v]<mini)
                {
                    mini=key[v];
                    u=v;
                }
                mst[u]=true;
                //exploring adjeacent nodes
                for(auto it: adj[u])
                {
                    int node=it.first;
                    int weight=it.second;
                    if(mst[v]==false && weight<key[node])
                    {
                        parent[node]=u;
                        key[node]=weight;
                    }
                }
            }
        }
        vector<pair<pair<int,int>, int>> result;
        for(int i=2;i<=ver;i++)
        {
            result.push_back({{parent[i],i},key[i]});
        }
        return result; 
    }
};
int main()
{
    Graph g; // declaring grapgh object
    int v=5; // no. of vertices
    int e=6;   // no. of edges

    //adding edges data & weight into adj.list
    g.addEdge(0,1,2);
    g.addEdge(0,3,6);
    g.addEdge(1,3,8);
    g.addEdge(1,2,3);
    g.addEdge(1,4,5);
    g.addEdge(2,4,7);
    
    // call of display function
    g.display();

    // call of dijkstra func.
    vector<pair<pair<int,int>,int>> ans = g.Prims_Algo(v,e);

    //printing result i.e., min. distances from source
    cout<<"MST :\n";
    for(auto i:ans)
    {
        cout<<i.first.first<<" "<<i.first.second<<" : "<<i.second;
        cout<<endl;
    }

    return 0;
}