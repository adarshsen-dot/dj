#include <bits/stdc++.h>
using namespace std;

class Node
{
    // doubly linked list
public:
    int data;
    Node *prev;
    Node *next;
    // constructor
    Node(int d)
    {
        // at the starting

        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    // constuctor deleting for node
    ~Node()
    {

        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "memory free for Node with data " << val << endl;
    }
};
// function for a printing a linked list
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
// function for length of a linked list
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
// inset at head funtion
void insertAthead(Node*&head,Node*&tail, int d)
{
    //empty list
    if (head==NULL)
    {
        Node*temp=new Node(d);
        head=temp;
        tail=temp;


    }
    else{
        Node *temp = new Node(d);
             temp->next = head;
               head->prev = temp;
           head = temp;


    }
   
}
// insert at tail (function )
void insertAtTail(Node *&tail,Node*& head ,int d)
{
    if (tail==NULL)
    {
        Node*temp= new Node(d);
        tail= temp;


    }
    else{
        Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
} 

    }

   


// and now insert at position
void insertAtPosition(Node *&tail, Node *&head, int position, int d)

{
    if (position == 1)
    {
        insertAthead(head,tail, d);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < position - 1)

    {
        temp = temp->next;
        count++;
    }
    //inserting at last position
    if (temp->next == NULL)

    {
        insertAtTail(tail,head,d);
        return ;
         
}

    // creating a node ofr d

    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;

    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}
void deletenode(int position, Node*&head)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{


        //main steps of this
        //01st- curr->prev= null
        //2nd- prev->next= curr->next
        //3rd- curt->next= NULL
        //memory free
        Node*curr = head;
        Node*prev= NULL;
        int count= 1;
        while(count<position)
        {
            prev=curr;
            curr= curr->next;
            count++;
            delete curr;
        }


        
          }
}

int main()
{
    // main function code
    // for calling insert at tail function you have to first declaretail like this
    Node * tail = NULL;

    Node *head = NULL;
    cout << getlength(head) << "\n";
    print(head);
    insertAthead(head,tail,13);
    print(head);
    insertAthead(head,tail, 56);
    insertAthead(head,tail, 22);
    print(head);

    // insertAtTail(tail,90);//insetattailfunction

    print(head);
    insertAtPosition(tail, head, 2, 56);
    print(head);
    cout <<"head-.data"<< head->data << endl;
    cout << "tail-.data"<<tail->data << endl;
    deletenode(1,head);
    print (head);
 cout <<"head->data"<< head->data << endl;
    cout << "tail->data"<<tail->data << endl;


    return 0;
}