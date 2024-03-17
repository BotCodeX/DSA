#include<bits/stdc++.h>
using namespace std;
vector< vector< pair<int,int>>> data(100);
vector<int> cost(100,1000);
vector<int>status(100);
vector<int>node(100);

int main()
{
    int n,e,sou;
    cin >> n >>e >>sou;
    for(int i=0 ; i<e ; i++)

    {
        int s,d,w;
        cin >> s >>d >>w;
        data[s].push_back(make_pair(d,w));
        data[d].push_back(make_pair(s,w));
    }
    cost[sou]=0 ;
    for(int i=0 ; i<n ; i++)
    {
        int c=1000,t;
        for(int j=1 ; j<=n ; j++)
        {
            if(status[j]==0 && cost[j]<c)
            {
                c = cost[j];
                t = j;
            }
        }
        for(int i=0 ; i<data[t].size() ; i++)
        {
            if(data[t][i].second < cost[data[t][i].first])
            {
                cost[data[t][i].first] = data[t][i].second ;
                node[data[t][i].first] = t;
            }
        }
        status[t]=1;
    }
    for(int i=1 ; i<=n ; i++)
    {
        cout << cost[i] <<endl;
    }
}
/*
4 5 0
0 1 3
0 2 2
1 2 4
1 3 1
2 3 5


5 7 1
1 2 10
1 3 5
2 4 1
3 2 3
3 4 9
3 5 2
5 4 6
*/


