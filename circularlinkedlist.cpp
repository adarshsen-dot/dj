#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

// Function to insert a new node with data 'd' after the node with element 'element' in the circular linked list
void insertNode(Node* &tail, int element, int d) {
    if (tail == NULL) {
        // If the list is empty, create a new node and make it the only node in the list
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    } else {
        // If the list is not empty, find the node with the given 'element' and insert a new node after it
        Node* curr = tail;
        while (curr->data != element) {
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

// Function to print the circular linked list starting from the tail
void print(Node* tail) {
    Node* temp = tail;
    do {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
}
void deleteNode(Node* &tail,int value)
{
    //empty list
    if (tail==NULL)
    {

        cout<<"list is empty ,please check again"<<endl;
        return;

    }
    else{

        //non empty
        //assuming that "value " is present in the linked list
        Node* prev = tail;
        Node * curr = prev ->next;
        while(curr-> data!= value)
        {
        prev= curr;
        curr= curr->next = NULL;
        delete curr;

        }
    }

}

int main() {
    Node* tail = NULL;
    // Insert a new node with data 3 after the node with element 5 in the circular linked list
    insertNode(tail, 5, 3);
    // Print the circular linked list
    print(tail);

    return 0;

}
