#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=1e9+7;


void undirected_graph(int nodes, int edges)
{
    vector<int> adjlist[nodes+1];
    for(int i=0; i<edges; i++)
    {
        int x,y;
        cin>>x>>y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);       // because graph is undirected

    }
    // traverse the adj list

    for(int i=1; i<=nodes; i++)
    {
        cout<<i<<" --> ";
        for(auto x: adjlist[i])
            cout<<x<<"  ";
        cout<<endl;
    }

}

void directed_graph(int nodes, int edges)
{
      vector<int> adjlist[nodes+1];
     // directed graph
        for(int i=0; i<edges; i++)
        {
            int x,y;
            cin>>x>>y;
            adjlist[x].push_back(y);
        }

        for(int i=1; i<=nodes; i++)
        {
            cout<<i<<" --> ";
            for(auto x :adjlist[i])
                cout<<x<<"  ";
            cout<<endl;
        }
}

void weighted_graph(int nodes, int edges)
{
    // weighted undirected graphs
        // use pair to store weights in adj list
        vector<pair<int,int>> adj[nodes+1];
        for(int i=0; i<edges; i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            adj[x].push_back({y,w});
            adj[y].push_back({x,w});
        }

        // traversing
        for(int i=1; i<=nodes; i++)
        {
            cout<<i<<" --> ";
            for(auto x: adj[i])
                cout<<x.first<<", wt= "<<x.second<<"  ";
            cout<<endl;
        }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int nodes, edges;
    cin>>nodes>>edges;


     undirected_graph(nodes, edges);
     cout<<endl;
     directed_graph(nodes, edges);
     cout<<endl;
     weighted_graph(nodes, edges);
     cout<<endl;

    return 0;
}
