//Selection Sort
#include<iostream>
using namespace std;
int main()
{
    int n,temp;
    cout << "Enter amount: ";
    cin >> n ;
    int arr[n];
    for (int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }
    for (int i=0 ; i<n-1 ; i++)
    {
        int mini =i;
        for (int j=i+1 ; j<n ; j++)
        {
            if(arr[mini]>arr[j])
            {
                mini =j;
            }
        }
        if (mini!=i)
        {
            temp=arr[i];
            arr[i]=arr[mini];
            arr[mini]=temp;
        }
    }
    for (int i=0 ; i<n ; i++)
    {
        cout << arr[i] <<"  ";
    }
    return 0;
}
