//write a program for reverse a linked list
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

};

Node*reverseLinkedlist(Node * head)
{
    if (head==NULL  || head->next=NULL)

    {
        return head;

    }
    Node* prev = NULL;
    Node* curr= head;
    Node* forward = NULL;
    while(curr!= NULL)
    {
        forward = curr->next;
        curr->next= prev ;
        prev= curr;
        curr= forward ;

    } 
    return prev;

}
//function to insert a node at the head of the linked list
void inserAthead(Node*&head,int value)
{


}



int main ()
{
    
        return 0;
}