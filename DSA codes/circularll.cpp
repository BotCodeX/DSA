#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int x)
    {
        data=x;
        next=NULL;
    }
};

node *head;

void InsertF(int x)
{
    node *temp = new node(x);
    if(head==NULL)
    {
        head=temp;
    }
    else if(head->next==NULL)
    {
        head->next = temp;
        temp->next = head;
        head=temp;
    }
    else
    {
        node *flag = head;
        do
        {
            flag=flag->next;
        }
        while(flag!=head);
        flag->next=temp;
        head=temp;
    }
}

void print()
{
    node *flag=head;
    if(head!=NULL)
    {
        do
        {
            cout<<flag->data<<endl;
            flag=flag->next;
        }
        while(flag!=head);
    }
    else
    {
        cout<<"LIST is EMPTY"<<endl;
    }
}

int main()
{
    head =NULL;
    InsertF(12);
    InsertF(22);
    InsertF(52);
    //print();
    cout << head->data;
    cout << head->next->data;
    return 0;
}
