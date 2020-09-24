#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N =1e5;
vector<int> adj[N];
vector<bool> vis(N, false);
vector<int> res;
vector<int> indegree(N, 0);


// topological sort using DFS
/*
Complexity Analysis:

  Time Complexity: O(V+E).
      The below algorithm is simply DFS with an extra vector. So time complexity is the same as DFS .
  Auxiliary space: O(V).
      The extra space is needed for the resultant vector.
*/
void topological_sort_dfs(int curr)
{
    vis[curr]=true;
    for(auto x :adj[curr])
    {
        if(vis[x] ==false)
            topological_sort_dfs(x);
    }
    res.push_back(curr);
}


// topological sort using BFS
/*
   Time Complexity : O(V +E);
   Space Complexity : O(V)
*/
void topological_sort_bfs(int n)
{
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        if(indegree[i] ==0)
           {
               q.push(i);     //   push it in the queue
               vis[i]=true;   //   mark it visited
           }
    }

    while(!q.empty())
    {
        int curr =q.front();
        q.pop();
        res.push_back(curr);


        for(auto x: adj[curr])
        {
            if(vis[x] ==false)
                {
                    indegree[x] =indegree[x] - 1;
                    if(indegree[x] == 0)
                    {
                        q.push(x);      // push it in the queue
                        vis[x]=true;    //  mark it visited
                    }

                }
        }
    }

}


// Lexicographically Smallest Topological Ordering
/*
   Time Complexity : O(V*logV + E);
   Space Complexity : O(V)
*/
void topological_sort_minimal(int n)
{
        // we can use multiset or a min heap to store Vertices
        priority_queue<int, vector<int> , greater<int> > pq;         // min heap
        for(int i=0; i<n; i++)
        {
            if(indegree[i]== 0)        // source vertex
            {
                pq.push(i);
                vis[i]= true;
            }
        }


        while(!pq.empty())
        {
            int curr =pq.top();
            pq.pop();
            res.push_back(curr);

            for(auto x: adj[curr])
            {
                if(vis[x] ==false)
                {
                    indegree[x] =indegree[x] - 1;
                    if(indegree[x]==0)
                    {
                        pq.push(x);
                        vis[x]= true;
                    }
                }
            }

        }
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     int n=6;     // nodes/vertex
     int m= 6;   //  edges

     // graph (DAG)   hard coded
     adj[5].push_back(0);
     adj[5].push_back(2);
     adj[4].push_back(0);
     adj[4].push_back(1);
     adj[2].push_back(3);
     adj[3].push_back(1);

  for(int i=0; i<n; i++)
  {
      for(auto x: adj[i])
      {
           indegree[x]++;                       //  special in degree array for BFS solution
      }
  }

//  cout<<"In degree vector : "<<endl;
//  for(int i=0; i<n; i++)
//      cout<<i<<" has indegree = "<<indegree[i]<<endl;


//    for(int i=0; i<n; i++)
//    {
//        if(vis[i]==false)
//            topological_sort_dfs(i);
//    }
//
//    reverse(res.begin(), res.end());
//    for(int x: res)
//        cout<<x<<" ";
//   res.clear();    //  clear the resultant array for BFS solution


  // topological_sort_bfs(n);


    topological_sort_minimal(n);
    cout<<endl;

      // reverse(res.begin(), res.end());
      for(int x: res)
          cout<<x<<" ";
      cout<<endl;


    return 0;
}




/*
Notes: -    1. Topological sort is only possible for DAG (directed acyclic graph).
            2. Topological sort can be done using BFS and DFS both.
            3. BFS solution requires in-degree array.
            4. No in-degree array is required in DFS solution.
            5. Use Multiset or min heap to get lexicographically smallest topological ordering.
            6. A source vertex is a vertex with in_degree zero.
            7. A sink vertex is a vertex with out_degree zero.
            */
