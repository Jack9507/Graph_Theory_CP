#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N =1e5;
#define P pair<int, int>

vector<P> adj[N];
vector<bool> vis(N, false);
vector<int> dis(N, 1e9);
priority_queue<P ,vector<P>, greater<P> > pq;    // min heap of pairs

vector<int> dijkstra(int src, int n)
{
    // use min heap for bfs, store pair like {distance, node}

    pq.push({0,src});   // initially the distance is 0
    while(!pq.empty())
    {
        P tmp =pq.top();
        pq.pop();
        int curr =tmp.second;
        int min_dis =tmp.first;

        if(vis[curr] ==false)
         {
            vis[curr]= true;
            dis[curr] =min_dis;
            for(auto x : adj[curr])
            {
                int to = x.first;
                int wt =x.second;
                if(vis[to] == false)
                {
                    pq.push({dis[curr]+ wt, to});
                }
            }
         }
    }

    return dis;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        //  graph of pairs  {source, destination, weight}
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

       vector<int> dis =dijkstra(1,n);        // pass the source vertex and number of vertex

      for(int i=1; i<=n; i++)
      {
          cout<<"distance from source to "<<i<<" is = "<<dis[i]<<endl;
      }

    return 0;
}
