//Quick sort
#include<iostream>
using namespace std;

int Partition(int data[], int low, int high)
{
    int pivot=data[low];
    int i=low, j=high;
    while(i<j)
    {
        while(data[i]<=pivot)
        {
            i++;
        }
        while(data[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(data[i],data[j]);
        }
    }
    swap(data[j],data[low]);
    return j;
}

void QuickSort(int data[], int low,int high)
{
    int mid = (low+high)/2;
    if(low<mid)
    {
        int pos = Partition(data,low,mid);
        QuickSort(data,low,pos-1);
        QuickSort(data,pos+1,mid);
    }
}

int main()
{
    int n;
    cout << "Enter amount: ";
    cin >> n;
    int data[n];
    cout << "Enter data : ";
    for (int i=0 ; i<n ; i++)
    {
        cin >>data[i];
    }

    QuickSort(data,0,n-1);

    for (int i=0 ; i<n ; i++)
    {
        cout << data[i] << " " ;
    }
    return 0;
}
