#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>Positions;

bool Place(vector<int>board, int k, int i)
{
    for(int j=1 ; j<=k-1 ; j++)
    {
        if( board[j]==i || (abs(board[j]-i)==abs(j-k)))
            return false;
    }
    return true;
}

void Nqueens(vector<int>board, int k, int n)
{
    for(int i=1 ; i<=n ; i++)
    {
        if(Place(board,k,i))
        {
            board[k]=i;
            if(k==n)
                Positions.push_back(board);
            else
                Nqueens(board,k+1,n);
        }
    }
}

void PrintRes()
{
    cout << "Number of Solutions: "<<Positions.size()<<endl;
    cout << "Solutions: " <<endl;
    for(int i=0 ; i<Positions.size(); i++)
    {
        for(int j=1 ; j<Positions[i].size() ; j++)
        {
            cout << Positions[i][j]<<" ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int>board(n+1,0);
    Nqueens(board, 1, n);
    PrintRes();
    return 0;
}
