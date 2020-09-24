#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N =1e5+5;
#define P pair<int, int>

vector<P> adj[N];
vector<int> vis(N, false);

//  returns the  minimum spanning tree weight
int prims(int src)
{
    int mst=0;
    priority_queue<P, vector<P>, greater<P> >pq;      // {weight, node}  min heap of pairs
    pq.push({0,src});  // initially the weight is zero for source node

    while(!pq.empty())
    {
        P tmp =pq.top();
        pq.pop();
        int curr= tmp.second;
        int wt =tmp.first;

        if(vis[curr] ==false)         //   if current node is not visited
        {
            vis[curr]= true;         //     visit the current node
            mst += wt;               //     add the current weight to minimum spanning tree weight

            for(auto x :adj[curr])     //  visit the adjacency list of current node
            {
                int to =x.first;
                int weight =x.second;
                if(vis[to] ==false)          // if the node in adj is not visited push it in queue
                pq.push({weight, to});
            }
        }
    }

    return mst;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    int ans =prims(1);    // source node  as parameter
  cout<<ans<<endl;



    return 0;
}


//  The time complexity of the Prim’s Algorithm is O((V+E)logV),
//  because each vertex is inserted in the priority queue only once and insertion in priority queue take logarithmic time.
