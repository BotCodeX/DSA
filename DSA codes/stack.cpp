#include<iostream>
using namespace std;

struct Stack
{
    int data;
    Stack *next;

    Stack(int x)
    {
        data=x;
        next=NULL;
    }
};

Stack *top;

void push(int x)
{
    Stack *temp = new Stack(x);
    if(top!=NULL)
    {
        temp->next=top;
        top=temp;
    }
    else
    {
        top = temp;
    }
}

int pop()
{
    if(top!=NULL)
    {
        Stack *temp = top;
        top=top->next;
        return temp->data;
    }
    else
    {
        cout << "List is EMPTY"<<endl;
        return -1;
    }
}

bool IsEmpty()
{
    if(top==NULL)
        return true;
    else
        return false;
}

void print()
{
    Stack *temp = top;
    while(temp!=0)
    {
        cout<< temp->data<< endl;
        temp=temp->next;
    }
}

int Size()
{
    Stack *temp = top;
    int amount = 0;
    while(temp!=NULL)
    {
        temp=temp->next;
        amount++;
    }
    return amount;
}

int main()
{
    top = NULL;

    return 0;
}
