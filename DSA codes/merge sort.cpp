#include<iostream>
using namespace std;

void Merge(int data[], int p,int q, int r)
{
    int n1=q-p+1, n2=r-q;
    int L[n1],R[n2];

    for(int i=0 ; i<n1 ; i++)
    {
        L[i]=data[p+i];
    }
    for(int j=0 ; j<n2 ; j++)
    {
        R[j]=data[q+j+1];
    }

    int i=0,j=0,k=p;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            data[k]=L[i];
            i++;
        }
        else
        {
            data[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        data[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        data[k]=R[j];
        j++;
        k++;
    }
}

void MergeSort(int data[],int p,int r)
{
    if(p<r)
    {
        int mid=(p+r)/2;
        MergeSort(data,p,mid);
        MergeSort(data,mid+1,r);
        Merge(data,p,mid,r);
    }
}

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
    MergeSort(data,0,n-1);

    for(int i=0 ; i<n ; i++)
    {
        cout << data[i]<<"\t";
    }
}
