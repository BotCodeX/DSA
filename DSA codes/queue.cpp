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
node *tail;

void Enqueue(int x)
{
    node *temp = new node(x);
    if(head == NULL && tail == NULL)
    {
        head=tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}

void Dequeue()
{
    if(head == NULL && tail == NULL)
    {
        cout << "Queue is Empty"<<endl;
    }
    else
    {
        cout << head->data<<endl;
        head = head->next;
    }
}

bool IsEmpty()
{
    if(head==NULL)
        return true;
    else
        return false;
}

void print()
{
    node *temp = head;
    while(temp!=0)
    {
        cout<< temp->data<< endl;
        temp=temp->next;
    }
}
int main()
{
    head=tail=NULL;

    cout << IsEmpty() << endl;

    Enqueue(1);
    Enqueue(3);
    Enqueue(6);
    Enqueue(7);
    print();

    Dequeue();
    Dequeue();

    print();
    cout << IsEmpty() << endl;
    return 0;
}
