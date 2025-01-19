#include<bits/stdc++.h>
using namespace std;
// define the class 
class node{
    public:
    int data;
    node* next; 

  //object of the class node
    node(int val){
        data = val;
        next = NULL;
    }
};

// insert at the end of the node
void insert(node* &head, int val){
    node * n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
     while(temp->next != NULL){
        temp = temp->next;
     }
     temp->next =n;
     return;
}

// insert at the start of the node
void insertAThaed(node* &head,int val){
    node* n = new node(val);
    node* temp = head;
    n->next = temp;
    head= n;
    return; 
}

// traversing through the whole linked list and printion all the elements one by one
void traverse(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
    return;
}

// delete a node on basis of a key value;
void deletion(node* &head,int key){
    node* temp = head;
    while(temp->next->data != key){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
int main(){
    node* head = NULL;

   insert(head,1);
   insert(head,2);
   insert(head,3);
   insertAThaed(head,0);  // insert at the beginning
   traverse(head);
   deletion(head,2);  // delete the node with value 2
   traverse(head);  // print the updated list
 
return 0;
}