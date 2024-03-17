#include<iostream>
using namespace std;
void mer(int arr[], int low, int  mid,int up)
{
    int carray[up];
    int i,j,k;
    i=low;
    j=mid ;
    k =low;
    while(i<mid && j <up)
    {
        if(arr[i]<=arr[j])
        {
            carray[k]=arr[i];
            i++;
        }
        else
        {
            carray[k]=arr[j];
            j++;
        }
        k++;
        cout <<i<<j<<endl;
    }
    if(i>=mid)
    {
        while(j<=up)
        {
            carray[k]=arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            carray[k]=arr[i];
            i++;
            k++;
        }
    }
    for (int x=0 ; x<up ;x++)
    {
        arr[x]=carray[x];
    }
    for (int x=0 ; x<up ;x++)
    {
        cout << arr[x]<<"   ";
    }
    //return ;
}

int main ()
{
    int arr1[10]= {3,5,9,12,18,2,7,11,17,23};
    mer(arr1,0,5,9);
    return 0;
}
