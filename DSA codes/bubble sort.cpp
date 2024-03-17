
//Bubble sort
#include<iostream>
using namespace std;
int main()
{
    int n,temp,mov=0;
    cout << "enter amount of data :";
    cin >> n;
    int arr[n];
    for (int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }
    for (int i=0 ; i<n ; i++)
    {
        bool flag  =false;
        for(int j=0 ; j<n ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1] = temp;
                flag = true;
                mov++;
            }
        }
        if(flag == false)
            break;
    }
    cout << "moves : " << mov <<endl;
    for (int i=0 ; i<n ; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}
