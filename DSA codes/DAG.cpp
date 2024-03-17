#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int> vis(N,0);
stack<int> st;
vector<int> dist(N,1e5);


void shortestdist(int src,vector<pair<int,int>> vec[])
{
    dist[0]=0;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(dist[node]!=1e5)
        {
            for(auto it:vec[node])
            {
                if(dist[node]+it.second<dist[it.first])
                    dist[it.first]=dist[node]+it.second;
            }
        }
    }
}
void topological(int node,vector<pair<int,int>> vec[])
{
    vis[node]=1;
    for(auto it:vec[node])
    {
        if(!vis[it.first])
            topological(it.first,vec);
    }
    st.push(node);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> vec[n];
    for(int i=0; i<m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        vec[u].push_back({v,wt});
    }
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
            topological(i,vec);
    }
    shortestdist(0,vec);
    for(int i=0; i<n; i++)
    {
        cout<<"0 "<<i<<"->"<<dist[i]<<endl;
    }
    return 0;
}
