#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N =1e5;

vector<int> adj[N];
vector<bool> vis(N, false);
bool odd_cycle =false;

vector<int> clr(N);

void dfs(int curr, int par, int tmp_clr)
{
    clr[curr] =tmp_clr;   //give temporary color to current node
    vis[curr] =1;     // set visited to true

    for(auto x: adj[curr])
    {
        if(vis[x] == 0)
         dfs(x, curr, !tmp_clr);                  // assign opposite color to child node
        else if(x != par && clr[x] ==clr[curr])           //  if color of child is same as color of its parent then odd cycle exists
            odd_cycle =true;
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;      // nodes, edges
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    dfs(0,-1,1);

    if(odd_cycle)                          // if odd_length cycle exists then graph is not bipartite
        cout<<"Not Bipartite"<<endl;
    else
        cout<<"Bipartite Graph"<<endl;




    return 0;
}
