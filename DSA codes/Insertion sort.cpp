#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Amount of Data: ";
    cin >> n;
    int data[n];
    cout << "Enter data : ";
    for(int i=0 ; i<n ; i++)
    {
        cin >> data[i];
    }

    for(int j=1 ; j<n ;j++)
    {
        int key=data[j];
        int i=j-1;
        while(i>=0 && data[i]>key)
        {
            data[i+1]=data[i];
            i-=1;
        }
        data[i+1]=key;
    }

    for(int i=0 ; i<n ; i++)
    {
        cout << data[i]<< "\t";
    }
    return 0;
}
