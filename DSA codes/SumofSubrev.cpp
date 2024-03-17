#include<bits/stdc++.h>
using namespace std;
vector<int>data;
vector<vector<int>> path;
int total;

void subset(int x,int i,int sum, vector<int>temp)
{
    if(x==total)
    {
        path.push_back(temp);
        return;
    }
    if(sum==0 || x>total)
        return;

    //cout <<x <<" " << i << " "<< sum<<endl;
    temp[i]=1;
    subset(x+data[i],i+1,sum-data[i],temp);
    temp[i]=0;
    subset(x,i+1,sum-data[i],temp);
}

int main()
{
    int n,sum=0;
    cin >> n >>total;
    vector<int>temp(n,0);
    for(int i=0 ; i<n ; i++)
    {
        int val;
        cin >> val;
        data.push_back(val);
        sum+=val;
    }
    subset(0,0,sum,temp);
    cout <<"Amount of path: "<< path.size() <<endl;
    cout << "Paths: "<<endl;
//    for(int i=0 ; i<data.size() ; i++)
//    {
//        cout << data[i]<<" ";
//    }
//    cout << endl;
    for(int i=0 ; i<path.size() ; i++)
    {
        for(int j=0 ; j<path[i].size() ; j++)
        {
            cout << path[i][j] <<" ";
        }
        cout << endl;
    }
}
/*
6 30
5 10 12 13 15 18

4 9
3 4 5 6
*/

