#include<bits/stdc++.h>
using namespace std;
vector<int>data(100);
int n=-1;

void Heapify(int a)
{
    int large=a, left = 2*a+1, right = 2*a+2;
    if( left<n && data[large]<data[left])
    {
        large=left;
    }
    if( right<n && data[large]<data[right])
    {
        large=right;
    }
    if(large!=a)
    {
        swap(data[large],data[a]);
        Heapify(large);
    }
}
void Build_Heap()
{
    for(int i=n/2 -1; i>=0 ; i--)
    {
        Heapify(i);
    }
}
void Push(int x)
{
    n++;
    if(n!=100)
    {
        data[n]=x;
        Build_Heap();
    }
    else
    {
        cout << "Overflow"<<endl;
        n--;
    }
}
int Front()
{
    if(n==-1)
    {
        cout << "Queue is Empty"<<endl;
    }
    else
        return data[0];
}

void Pop()
{
    if(n!=-1)
    {
        swap(data[0],data[n]);
        Heapify(0);
        n--;
    }
}

bool Empty()
{
    if(n==-1)
        return true;
    else
        return false;
}
int Size()
{
    return n+1;
}
int main()
{
    int x,n;
    while(true)
    {
        printf("1. Push \n2. Pop \n3. Front\n");
        printf("4. Empty? \n5. Size \n6. Exit \n");
        printf("Enter Choice: ");
        int ch;
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            cout << "Enter Value: ";
            cin >> x;
            Push(x);
            break;
        case 2:
            Pop();
            break;
        case 3:
            cout << "Front Value is: "<< Front()<<endl;
            break;
        case 4:
            cout << "Empty? : " << Empty() <<endl;
            break;
        case 5:
            cout << "Size is: "<< Size() <<endl;
            break;
        case 6:
            return 0;
            break;
        default:
            continue;
        }
    }
}
