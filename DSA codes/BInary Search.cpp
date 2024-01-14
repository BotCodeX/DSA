#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Amount of Data: ";
    cin >> n;
    int data[n];
    for(int i=0 ; i<n ; i++)
    {
        cin >> data[i];
    }
    int key;
    bool check=false;
    cout << "Enter Key : ";
    cin >> key;
    int i=0,j=n-1;
    int mid=(i+j)/2;
    while(i<=j)
    {
        if(data[mid]==key)
        {
            check=true;
            break;
        }
        else if(key>data[mid])
        {
            i=mid+1;
        }
        else
        {
            j=mid-1;
        }
        mid=(i+j)/2;
    }
    if(check)
     {
         cout << "Key Found"<<endl;
     }
     else
     {
         cout << "Key Not Found"<<endl;
     }

}
