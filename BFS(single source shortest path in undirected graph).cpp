#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N =1e5;

vector<int> adj[N];

void bfs(int src)
{
    vector<bool> vis(N, false);      // visited array
    queue<int> q;
    q.push(src);
    vis[src]=true;
    while(!q.empty())
    {
        int curr= q.front();
        cout<<curr<<"  ";
        q.pop();

        // go in the adj list of current node
        for(auto x: adj[curr])
        {
            if(vis[x]==false)
            {
                vis[x]=true;
                q.push(x);
            }
        }
    }


}

// bfs for single source shortest path
vector<int> bfs1(int src)
{
    queue<int> q;
    vector<bool> vis(N, false);    // initially no node is visited
    vector<int> dis(N,-1);         //  initially dis is -1 for every node

    q.push(src);
    vis[src]= true;
    dis[src] =0;       // shortest dis from source node to itself is zero

    while(!q.empty())
    {
        int curr =q.front();
        q.pop();

        for(auto x :adj[curr])
        {
            if(vis[x] ==false)
            {
                vis[x] =true;
                q.push(x);
                dis[x] =dis[curr] +1;       // distance to child node is 1 + dis of it's parent
            }
        }
    }
    return dis;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nodes,edges;
    cin>>nodes>>edges;


      // make graph i.e adj list

      for(int i=0; i<edges; i++)
      {
          int x,y;
          cin>>x>>y;
          adj[x].push_back(y);
          adj[y].push_back(x);
      }

      cout<<"BFS traversal "<<endl;
      bfs(0);    // simple traversing
      cout<<endl<<endl;

      cout<<"Single source shortest path "<<endl;
      vector<int> res =bfs1(0);

      cout<<"shortest distance from root/source node to every node "<<endl;
      for(int i=0; i<=nodes; i++)
        cout<<i<<" dis= "<<res[i]<<endl;





    return 0;
}
