#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

int main()
{
   
    struct node* first = new node;
    struct node* second = new node;

    first->data = 10;
    second->data = 20;

    first->next = second;
    second->next = NULL;

  
    struct node* newnode = new node;
    newnode->data = 30;
    newnode->next = NULL;


    struct node* temp = first;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

   
    temp->next = newnode;

   
    temp = first;

    cout << "Linked List after insertion at end: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}