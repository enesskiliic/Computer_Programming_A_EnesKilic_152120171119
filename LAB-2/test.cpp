#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string data;
    Node *next;

    Node(string word) : data(word), next(nullptr) {}
};

void addWord(Node *&head, const string &word)
{
    Node *newNode = new Node(word);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}

void undoLast(Node *&head)
{
    if (head == nullptr)
    {
        cout << "Nothing to undo!\n";
        return;
    }

    if (head->next == nullptr)
    {
        cout << "Removed: [" << head->data << "]\n";
        delete head;
        head = nullptr;
        return;
    }

    Node *current = head;
    while (current->next->next != nullptr)
        current = current->next;

    cout << "Removed: [" << current->next->data << "]\n";
    delete current->next;
    current->next = nullptr;
}

void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty -> NULL\n";
        return;
    }

    Node *current = head;
    while (current != nullptr)
    {
        cout << "[" << current->data << "]";
        if (current->next != nullptr)
            cout << " -> ";
        current = current->next;
    }
    cout << " -> NULL\n";
}

int main()
{
    Node *head = nullptr;
    string input;

    cout << "Type a word to add \nUNDO to remove last \nEXIT to quit\n\n";

    while (true)
    {
        cin >> input;

        if (input == "EXIT")
        {
            cout << "See you!\n";
            break;
        }
        else if (input == "UNDO")
        {
            undoLast(head);
        }
        else
        {
            addWord(head, input);
        }

        display(head);
        cout << "\n";
    }
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}