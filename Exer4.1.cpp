#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string teamName;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *last;

public:
    CircularLinkedList()
    {
        last = NULL;
    }

    void addTeam(string name)
    {
        Node *newNode = new Node;

        newNode->teamName = name;

        if (last == NULL)
        {
            last = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void displayTeams()
    {
        if (last == NULL)
        {
            cout << "No teams available." << endl;
            return;
        }

        Node *temp = last->next;

        cout << "\nTournament Teams in Robin Sequence:" << endl;

        do
        {
            cout << temp->teamName << " -> ";
            temp = temp->next;
        }
        while (temp != last->next);

        cout << "(Back to " << last->next->teamName << ")" << endl;
    }
};

int main()
{
    CircularLinkedList tournament;

    int n;
    string name;

    cout << "Enter number of teams: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter team " << i << " name: ";
        cin >> name;

        tournament.addTeam(name);
    }

    tournament.displayTeams();

    return 0;
}

