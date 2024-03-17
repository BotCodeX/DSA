//Insertion Sort
#include<iostream>
using namespace std;
int main()
{
    int n,temp,i,j;
    cout << "Enter amount of data: ";
    cin >> n ;
    int arr[n];
    for (int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }
    for (i=1 ; i<n ; i++)
    {
        temp=arr[i];

        for (j=i-1 ; j>=0 && arr[j]>temp ; j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
    for (int i=0 ; i<n ; i++)
    {
        cout << arr[i] <<"  " ;
    }
    return 0;
}
