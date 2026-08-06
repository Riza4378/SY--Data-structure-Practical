#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node*previous;
	struct node*next;
};

int main()
{


    struct node*newnode=new (struct node);
  
    newnode->data=10;
    newnode->previous = newnode;
    newnode->next=newnode;
    
    newnode->data=20;
    newnode->previous = newnode;
    newnode->next=newnode;
  
    cout << "Data = " << newnode->data << endl;
    cout << "Previous node data = " << newnode->previous->data << endl;
    cout << "Next node data = " << newnode->next->data << endl;

   

  
  return 0;
}


