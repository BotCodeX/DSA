#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
Node *head;

void Print()
{

    Node *temp=head;
    while(temp!=NULL)
    {
        cout << temp->data << endl;
        temp=temp->next;
    }
}

void Insert (int x)
{
    Node *temp = new Node(x);
    temp->next=head;
    head=temp;
}

void Swap()
{
    Node *temp,*mx, *mn;
    temp=mx=mn=head;
    int te;
    while(temp!=NULL)
    {
        if(temp->data > mx->data)
            mx=temp;
        if(temp->data < mn ->data)
            mn=temp;
        temp=temp->next;
    }
    te=mx->data;
    mx->data = mn->data;
    mn->data = te;
}

void Sort()
{
    Node *flag1,*flag2;
    bool check;
    int exc;
    while(true)
    {
        check=false;
        flag1  = head;
        flag2 = head->next;
        while(flag2!=NULL)
        {
            if(flag1->data > flag2->data)
            {
                exc = flag1->data;
                flag1->data = flag2->data;
                flag2 ->data = exc;
                check=true;
            }
            flag1=flag1->next;
            flag2=flag2->next;
        }
        if(check==false)
        {
            cout<< "Sorted:"<<endl;
            return;
        }
    }
}

void Reverse()
{
    Node *prev=NULL , *nex = head, *cur=head;
    while(nex!=NULL)
    {
        nex = nex->next;
        cur->next = prev;
        prev = cur;
        cur=nex;
    }
    head = prev;
}

int main()
{
    Insert(21);
    Insert(78);
    Insert(130);
    Insert(9);
    Insert(23);

    //Print();
    //Sort();
    Reverse();
    cout <<endl <<endl;
    //Print();

    return 0;
}
