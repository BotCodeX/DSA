#include<bits/stdc++.h>
using namespace std;
vector<int> parent(1000);

void Make(int v)
{
    parent[v]=v;
}
int Find(int v)
{
    if(v==parent[v]) return v;
    return Find(parent[v]);
}
void Union(int a,int b)
{
    a=Find(a);
    b=Find(b);
    if(a!=b)
    {
        parent[b]=a;
    }
}
int main()
{
    int n,e,cost=0;
    cin >> n>>e;
    vector<pair<int,pair<int,int>>> data;
    for(int i=0 ; i<e ; i++)
    {
        int u,v,w;
        cin >> u >>v >>w;
        data.push_back(make_pair(w,make_pair(u,v)));
    }
    sort(data.begin(),data.end());

    for(int i=1  ; i<=n ; i++)
        Make(i);

    cout << "Connected Edges: "<<endl;
    for(int i=0 ; i<data.size() ; i++)
    {
        int w,u,v;
        w = data[i].first;
        u = data[i].second.first;
        v = data[i].second.second;
        if(Find(u)==Find(v)) continue;
        Union(u,v);
        cost+=w;
        cout << u << " " << v <<endl;
    }
    cout << "Cost: " << cost << endl;
}
