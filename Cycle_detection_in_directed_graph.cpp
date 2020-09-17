#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e5;
vector<int> adj[N];
int vis[N]={};      //   initially no node is visited
bool cycle =false;

/*
for directed graph visited array has 3 states :-
    0 -> node not visited
    1 -> visited and in call stack
    2 -> visited but not in current call stack
*/



void dfs(int curr)
{

        vis[curr] =1;    //  current node is being visited so it is in call stack

        for(auto x :adj[curr])
        {
            if(vis[x] == 0)
            {
                dfs(x);
            }

            else if(vis[x] == 1)
                cycle =true;
        }

    vis[curr]= 2;       //  current node is popped out from call stack
    return;

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
//        adj[y].push_back(x);
    }


     for(int i=0; i<n; i++)    // iterate to all nodes in graph
     {
         if(vis[i] == 0)
            dfs(i);
     }
    if(cycle)
        cout<<"Cycle detected"<<endl;
    else
        cout<<"No cycle in graph"<<endl;


    return 0;
}
