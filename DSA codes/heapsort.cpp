#include<bits/stdc++.h>
using namespace std;

vector<int>data;

void Heapify(int n)
{
    cout << "yes 1"<<endl;
    int large , left = 2*n , right = 2*n+1;
    if( left<data.size() && data[large]<data[left])
    {
        large=left;
        cout <<"no" <<endl;
    }
    else
    {
        large=n;
    }

    if( right<data.size() && data[large]<data[right])
    {
        large=right;
        cout <<"no 1" <<endl;
    }
    if(large!=n)
    {
        swap(data[large],data[n]);
        cout <<"no 1" <<endl;
        Heapify(large);
    }
    cout << "yes"<<endl;
}

void Build_Heap()
{
    for(int i=(data.size()-1)/2 ; i>0 ; i--)
    {
        cout << i <<endl;
        Heapify(i);

    }
}

void Heap_Sort()
{
    Build_Heap();

    for(int i=data.size()-1 ; i>0 ; i--)
    {
        swap(data[i],data[1]);
        Heapify(1);
    }
}

int main()
{

    data.push_back(-1);
    int n,val;
    cout << "Enter amount of data: ";
    cin >>n;
    cout << "Enter Data: ";
    while(n--)
    {
        cin >> val;
        data.push_back(val);
    }

    for(int i=1 ; i<data.size() ; i++)
    {
        cout << data[i] << "  ";
    }

    Heap_Sort();

    cout << "Sorted Data: ";
    for(int i=1 ; i<data.size() ; i++)
    {
        cout << data[i] << "  ";
    }
}

// 8 5 2 6 1
