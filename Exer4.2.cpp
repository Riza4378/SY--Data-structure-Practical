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

        cout << "\nTournament Teams:" << endl;

        do
        {
            cout << temp->teamName << " -> ";
            temp = temp->next;
        }
        while (temp != last->next);

        cout << "(Back to " << last->next->teamName << ")" << endl;
    }

    void simulateRounds(int rounds)
    {
        if (last == NULL)
        {
            cout << "No teams available." << endl;
            return;
        }

        Node *current = last->next;

        cout << "\n--- Tournament Match Rounds ---" << endl;

        for (int i = 1; i <= rounds; i++)
        {
            cout << "\nRound " << i << ":" << endl;

            Node *temp = current;

            do
            {
                cout << temp->teamName << " gets the turn." << endl;
                temp = temp->next;
            }
            while (temp != current);

            current = current->next;
        }
    }
};

int main()
{
    CircularLinkedList tournament;

    int n, rounds;
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

    cout << "\nEnter number of rounds: ";
    cin >> rounds;

    tournament.simulateRounds(rounds);

    return 0;
}

