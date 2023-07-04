// Dijksta Algorithm -> to find minimum distance fom source node to all other nodes

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
    vector<int> dijkstra(int ver,int edges, int src)
    {
        // distance is an answer vector contains all shortest distance
        vector<int> dist(ver);

        //initially initialising all vertice distance to infiinity(INT_MAX)
        for(int i=0;i<ver;i++)
        {
            dist[i]=INT_MAX;
        }

        // pair to fetch node and weight data from adj. list
        set <pair<int,int>> st;
        
        //set is used to store node with weight in a sorted order --> min. weight first 
        st.insert(make_pair(0,src));
        //initialising source distance with itself to 0
        dist[src]=0;

        //prcosessing till the set is not empty or we cover all nodes from adj. list
        while(!st.empty())
        {   
            // fetching data from set as pair of dest. node and weight
            auto top = *(st.begin());
            
            //taking out dest. node from top
            int topNode=top.second;
            
            //taking dist or weight from top
            int nodeDist=top.first;

            // deleting the node from set
            st.erase(st.begin());
            
            //exploring all neighbours of node
            for(auto neighbour : adj[topNode])
            {
                // checking if the dist of dest from cur. node is smaller than existing one
                if(nodeDist +  neighbour.second < dist[neighbour.first])
                {
                    //deleting the max. distance record
                    auto record= st.find(make_pair(dist[neighbour.first],neighbour.first));
                    if(record !=st.end())
                        st.erase(record);
                    
                    //updating distance 
                    dist[neighbour.first] = nodeDist + neighbour.second;
                    //inserting updated distance and node neighbour into set
                    st.insert(make_pair(dist[neighbour.first],neighbour.first)); 
                 }
            }

        }
        return dist; //returning vector of shortes distance
    }
};
int main()
{
    Graph g; // declaring grapgh object
    int v=5; // no. of vertices
    int e=7;   // no. of edges
    int src=0;  // source node

    //adding edges data & weight into adj.list
    g.addEdge(0,1,7);
    g.addEdge(0,2,1);
    g.addEdge(0,3,2);
    g.addEdge(1,2,3);
    g.addEdge(1,3,3);
    g.addEdge(1,4,1);
    g.addEdge(3,4,7);
    
    // call of display function
    g.display();

    // call of dijkstra func.
    vector<int> ans = g.dijkstra(v,e,src);

    //printing result i.e., min. distances from source
    cout<<"Shortest Distance from source "<<src<<"  to all other nodes are : ";
    for(auto i: ans)
    {
        cout<<i<<" ";
    }

    return 0;
}