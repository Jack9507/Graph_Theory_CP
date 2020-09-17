#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MX= 1e5;
vector<int> adj[MX];


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    const int N =100;
    int matrix[N][N];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<"Adjacency matrix representation "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<matrix[i][j]<<'\t';
        }
        cout<<endl;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(matrix[i][j] ==1)
            {
                adj[i].push_back(j);
            }

        }
    }
   cout<<"Adjacency List representation"<<endl;

   for(int i=0; i<n; i++)
   {
       cout<<i<<" -> ";
       for(auto x: adj[i])
         cout<<x<<", ";
       cout<<endl;
   }


    return 0;
}
