#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,row=0,col=0;
    cin >> n;
    int matrix[n][n];
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for(int i=0 ; i<n ; i++)
    {
        int temp=1000;
        for(int j=0 ; j<n ; j++)
        {
            temp=min(temp,matrix[i][j]);
        }
        row+=temp;
    }
    for(int i=0 ; i<n ; i++)
    {
        int temp=1000;
        for(int j=0 ; j<n ; j++)
        {
            temp=min(temp,matrix[j][i]);
        }
        col+=temp;
    }
    cout << "Sum of min rows: " <<row<<endl;
    cout << "Sum of min columns: " <<col<<endl;
}
