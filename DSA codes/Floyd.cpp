#include<bits/stdc++.h>
using namespace std;

void Print(vector<vector<int> >Rvec)
{
    for(int i=0; i<Rvec.size(); i++)
    {
        for(int j=0; j<Rvec[i].size(); j++)
        {
            if(Rvec[i][j]>1000)
            {
                cout << "*" <<"  ";
            }
            else
            {
                cout << Rvec[i][j]<<"  ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n,e,sou,des;
    cout << "enter number of nodes: ";
    cin >>n;
    vector<vector<int>>data(n,vector<int>(n,10000));
    cout << "enter number of edges: ";
    cin >> e;
    for(int i=0 ; i<e ; i++)
    {
        cin >> sou >> des >> data[sou-1][des-1];
    }
    for(int i=0 ; i<n ; i++)
    {
        data[i][i]=0;
    }
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ;j++)
        {
            for(int k=0 ; k<n ;k++)
            {
                data[j][k]=min(data[j][k],data[j][i]+data[i][k]);
                cout << "iteration: " << i <<" "<<j<<endl;
                Print(data);
            }
        }
    }
    cout<<"shortest paths: "<<endl;
    Print(data);
}
/*
6 9
1 2 1
1 3 5
2 3 2
3 5 2
2 5 1
2 4 2
4 5 3
4 6 1
5 6 2
*/
