#include<bits/stdc++.h>
using namespace std;

vector<int>node[100];
vector<int>status(100,0);
queue<int>data;

void Neighbour(int n)
{
    for(int i=0 ; i<node[n].size() ; i++)
    {
        if(status[node[n][i]]==1)
        {
            data.push(node[n][i]);
            status[node[n][i]]=2;
        }
    }
}

void initStatus(int n)
{
    for(int i=1 ; i<=n ; i++)
    {
        status[i]=1;
    }
}

void bfs(int node, int edge, int sou)
{
    initStatus(node);

    data.push(sou);
    status[sou]=2;

    while(!(data.empty()))
    {
        int nTemp = data.front();
        data.pop();
        cout << nTemp << endl;

        Neighbour(nTemp);
    }
}

int main()
{
    int n,e,s;
    cout << "Enter number of nodes & edges: ";
    cin >> n >> e;
    for(int i=1 ; i<=e ; i++)
    {
        int x,y;
        cin >>x>>y;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    cout << "enter source: ";
    cin >> s;

    bfs(n,e,s);

    return 0;
}
