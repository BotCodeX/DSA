#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>items;
typedef vector<int> type;
vector<type>data(100,type (100));

void Print_mat(int n,int weight)
{
    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=weight ; j++)
        {
            cout << data[i][j]<<" ";
        }
        cout << endl;
    }
}

int main()
{
    int n,weight;
    cout << "enter element number and weight: ";
    cin >> n >>weight;
    cout << "enter Weight and Profit: ";
    for(int i=0 ; i<n ; i++)
    {
        int w,p;
        cin >> w >>p;
        items.push_back({w,p});
    }


    for(int i=0 ; i<=n ; i++)
        data[i][0]=0;
    for(int i=0 ; i<=weight ; i++)
        data[0][i]=0;

    for(int i=1 ; i<=n ; i++)
    {
        int w = items[i-1].first;
        int p = items[i-1].second;
        for(int j=1 ; j<=weight ; j++)
        {
            if(w<=j)
            {
                if((p+data[i-1][j-w])>data[i-1][j])
                {
                    data[i][j]=p+data[i-1][j-w];
                }
                else
                {
                    data[i][j]=data[i-1][j];
                }
            }
            else
            {
                data[i][j]=data[i-1][j];
            }
        }
    }
    Print_mat(n,weight);


    vector<int>taken_item(n,0);
    int i=n;
    int j=weight;
    while(i!=0)
    {
        //cout << i << " " <<pr<<endl;
        if(data[i][j]!=data[i-1][j])
        {
            taken_item[i-1]= 1;
            j = j - items[i-1].first;
        }
        i--;
    }
    for(int i=0 ; i<n ; i++)
    {
        cout << taken_item[i]<<" ";
    }
}

/*
4 5
2 3
3 4
4 5
5 6

*/
