#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N =1e5;
vector<int> adj[N];
vector<bool> vis(N, false);


void dfs(int src)
{
    vis[src] =true;

    for(auto x :adj[src])
    {
        if(vis[x] ==false)
         dfs(x);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int connected_components =0;

    for(int i=1; i<=n; i++)             // iterating over every vertex in graph
    {
        if(vis[i] ==false)
         {
             dfs(i);                         // call dfs if the vertex is not visited
              connected_components++;         //  increment count of connected component every time dfs is called
         }
    }


   cout<<connected_components<<endl;         // number of connected components will be equal to the number of times dfs is called.

    return 0;
}
