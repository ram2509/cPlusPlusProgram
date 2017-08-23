
#include<iostream>
using namespace std;

class node{
 public :
   int data;
   node *next,*prev;

   node(int d){
      data = d;
      next = NULL;
      prev = NULL;
   }
};

///insert node at end
void appendNodeAtEnd(node*& head,int data){
   node *temp = head;

   ///base node is empty
   if(head==NULL){
     head = new node(data);
     head->next = NULL;
     head->prev = NULL;
   }

   else{
    ///traverse to last node
      while(temp->next!=NULL){
          temp = temp->next;
      }
      node *n = new node(data);
      n->next = NULL;
      n->prev = temp;
      temp->next = n;
      temp = n;
      return;
   }
};

///insert node at front
void appendNodeAtFront(node*& head,int data){
       node *temp = new node(data);
       temp->next = head;
       temp->prev = NULL;
       head = temp;
}

///insert node at front
void takeInputAtFront(node*& head){
    cout<<"Insert node at front"<<endl;
    int data;
    cin>>data;
    appendNodeAtFront(head,data);
}

///insert data into linkedList
void takeInput(node*& head){
    cout<<"User can insert the data into linkedList upto user input is -1"<<endl;
    int data;
    cin>>data;
    while(data!=-1){
        appendNodeAtEnd(head,data);
        cin>>data;
    }
}

///display the linkedList
void display(node* head){
      node *temp = head;
      while(temp!=NULL){
        cout<<temp->data<<"==>";
         temp = temp->next;
      }
      cout<<endl;
}

int main(){
   node *head = NULL;
   takeInput(head);
   display(head);
   takeInputAtFront(head);
   display(head);
   return 0;
}
