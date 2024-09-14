#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    // for deletion in linked list for free memory

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data" << value << endl;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // insert at start
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt, position - 1)
    {

        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr)
    {
        cout << "Position out of bounds" << endl;
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// void insertAtTail

void deleteNode(int position, Node *&head)
{
    // deleting first or start node
    if (position == 1)
    {

        Node *temp = head;
        head = head->next;
        // memory free stat node
        temp->next = NULL;
        delete temp;
    }
    else
    {

        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void checkforloop(Node*temp,int )

int main()
{//created new node
Node* node1= new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 13);
    print(head);
    insertAtHead(head, 76);
    print(head);
    insertAtHead(head, 56);

    print(head);
    insertAtTail(tail, 12);

    //  insertAtPosition(head, 6, 42); // Insert at position 2
    // print(head);
    deleteNode(3, head);
    print(head);
    
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    return 0;
}
