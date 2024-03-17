#include<bits/stdc++.h>
using namespace std;
vector <pair<int,int>> data[100];
priority_queue<pair<int,int>> line;
vector<int>status(100);
vector<int>cost(100,1000);
vector<int>node(100);

void relax(int x)
{
    for(int j=0; j<data[x].size(); j++)
    {
        if(status[data[x][j].first]==0 && data[x][j].second < cost[data[x][j].first])
        {
            cost[data[x][j].first]=data[x][j].second;
            node[data[x][j].first]=x;
            line.push({-cost[data[x][j].first],data[x][j].first});
        }
    }
}
void Prims(int n,int s)
{
    cost[s]=0;
    line.push({-cost[s],s});
    while(!line.empty())
    {
        int temp=line.top().second;
        line.pop();
        status[temp]=1;
        relax(temp);
    }
}
int main()
{
    int n,e,s,cst=0;
    cin >> n >> e >> s;
    for(int i=0; i<e; i++)
    {
        int s,d,w;
        cin >> s >> d>> w ;
        data[s].push_back({d,w});
        data[d].push_back({s,w});
    }
    Prims(n,s);
    cout << "Edges and Weights: "<<endl;
    for(int i=1; i<=n; i++)
    {
        cst += cost[i];
        cout << i << " " << node[i] <<" -- ";
        cout << cost[i] << endl;
    }
    cout << "Total cost: "<<cst;
}

/*
8 10 1
1 2 6
2 3 4
1 3 5
1 7 10
1 8 14
3 4 9
3 6 2
5 6 15
6 7 8
7 8 3
*/
