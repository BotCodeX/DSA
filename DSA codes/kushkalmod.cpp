#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,pair<int,int> > >data;
vector<int> sou(100);
vector<int> des(100);
vector<pair<int,int> > mst;

//20200104051

int main()
{
    int n,e;
    cin >> n >> e;
    for(int i=0 ; i<e ; i++)
    {
        int s,d,w;
        cin >> s >> d >>w;
        data.push(make_pair(-1*w,make_pair(s,d)));
        //data.push(make_pair(-1*w,make_pair(d,s)));
    }
    int cost=0;
    while(!(data.empty()))
    {
        int s = data.top().second.first;
        int d = data.top().second.second;
        if(sou[s]==0 || sou[d]==0 || des[s]==0 || des[d]==0)
        {
            mst.push_back(make_pair(s,d));
            sou[s]=1;
            des[s]=1;
            sou[d]=1;
            des[d]=1;
        }
        data.pop();
    }
    cout << "Nodes: "<<endl;
    for(int i=0 ; i<mst.size() ; i++)
    {
        cout << mst[i].first <<" "<< mst[i].second<<endl;
    }
}

/*
7 11
1 2 2
1 6 14
1 7 8
2 3 19
2 6 25
3 4 9
3 5 5
3 6 17
4 5 1
5 6 13
6 7 21
*/
