#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory freed for Node with data " << data << endl;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getlength(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAthead(Node *&head, int d)
{
    if (head == NULL)
    {
        head = new Node(d);
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int d)
{
    if (tail == NULL)
    {
        tail = new Node(d);
        head = tail; // Update head when the list is empty
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        insertAthead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        cerr << "Invalid position" << endl;
        return;
    }

    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;

    if (temp->next != NULL)
    {
        temp->next->prev = nodetoinsert;
    }

    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

void deletenode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        if (temp->next != NULL)
        {
            temp->next->prev = NULL;
        }
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < position && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr == NULL)
        {
            cerr << "Invalid position" << endl;
            return;
        }

        prev->next = curr->next;

        if (curr->next != NULL)
        {
            curr->next->prev = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *tail = NULL;
    Node *head = NULL;

    cout << "Length: " << getlength(head) << "\n";
    print(head);

    insertAthead(head, 14);
    insertAthead(head, 56);
    insertAthead(head, 22);
    print(head);

    insertAtTail(tail, head, 90);
    print(head);

    insertAtPosition(tail, head, 2, 56);
    print(head);

    cout << "Head data: " << head->data << endl;
    cout << "Tail data: " << tail->data << endl;

    deletenode(1, head);
    print(head);

    return 0;
}
