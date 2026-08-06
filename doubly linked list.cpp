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
	struct node* newnode=new (struct node);
	newnode->data=10;
	newnode->previous=NULL;
	newnode->next=NULL;
	
	cout<<"data ="<<newnode->data<<endl;
	cout<<"NULL ="<<newnode->previous<<endl;
	cout<<"NULL ="<<newnode->next<<endl;
	
	
	return 0;
	}	