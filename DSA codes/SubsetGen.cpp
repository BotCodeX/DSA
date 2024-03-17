#include<bits/stdc++.h>
using namespace std;
vector<int>data;
vector<vector<int>>subset;

void SubsetGen(vector<int>temp,int i)
{
    subset.push_back(temp);
    if(i==data.size())
        return;
    SubsetGen(temp,i+1);
    temp.push_back(data[i]);
    SubsetGen(temp,i+1);
}

int main()
{
    int n;
    cin >> n;
    vector<int>temp;
    for(int i=0 ; i<n ; i++)
    {
        int val;
        cin >> val;
        data.push_back(val);
    }
    SubsetGen(temp,0);
    cout << subset.size()<<endl;
    for(int i=0 ; i<subset.size() ; i++)
    {
        for(int j=0 ; j<subset[i].size() ; j++)
        {
            cout << subset[i][j] <<" ";
        }
        cout << endl;
    }
}
