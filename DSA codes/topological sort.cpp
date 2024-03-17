#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ver,edge;
    cout << "Enter the amount of vertice and edge : ";
    cin >> ver >> edge;

    vector<vector<int>> graph(ver);
    vector<int>indegree(ver,0);

    cout << "Enter Edges: ";
    for(int i=0 ; i<edge ;i++)
    {
        int x,y;
        cin >> x >>y;
        graph[x].push_back(y);
        indegree[y]++;
    }
    queue<int> data;
    for(int i=0 ; i<ver ; i++)
    {
        if(indegree[i]==0)
        {
            data.push(i);
        }
    }
    while(!(data.empty()))
    {
         int n=data.front();
         data.pop();
         cout << n <<endl;
         for(int i=0 ; i<graph[n].size() ; i++)
         {
             indegree[graph[n][i]]--;
             if(indegree[graph[n][i]]==0)
             {
                 data.push(graph[n][i]);
             }
         }
    }
}
