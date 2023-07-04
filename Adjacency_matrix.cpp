#include<iostream>
using namespace std;
int main()
{
    int v,e;
    cout<<"Enter number of vertices : ";
    cin>>v;
    cout<<"\nEnter number of edges : ";
    cin>>e;

    // dynamically allocated 2d array
    int **arr;
    arr=new int *[v];

    for(int i=0;i<v;i++)
    {
        arr[i]=new int[v];
    }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            arr[i][j]=0;
        }
    }

    int isEdge=0;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<"\nIs edge exist between node "<<(i+1)<<" to "<<(j+1) <<" (0/1 ): ";
            cin>>isEdge;
            
            if(isEdge==1)
                arr[i][j]=1;
        }
    }

    cout<<"\nEgdes exist between given vertices : \n";
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            // if(arr[i][j]==1)
            //     cout<<"("<<i+1<<" , "<<j+1<<")"<<endl;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}