#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e5;

vector<int> adj[N];     // adj list
bool cycle=false;
vector<bool> vis(N, false);

void dfs(int curr, int parent)
{
    vis[curr] =true;                    // visiting the current node
        for(auto x: adj[curr])
        {
            if(vis[x] ==false)
              dfs(x, curr);
            else if(x != parent)
              {
                  // this means an edge pointer to ancestor
                  // back edge found
                  cycle =1;
              }
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

       // initially call dfs with source ,  its parent to be some node which is not present in graph here it's 0.
       for(int i=0; i<=n; i++)
       {
           if(vis[i]== false)
            dfs(i,-1);
       }
    if(cycle)
        cout<<"Cycle detected"<<endl;
    else
        cout<<"No cycle in graph"<<endl;


    return 0;
}
