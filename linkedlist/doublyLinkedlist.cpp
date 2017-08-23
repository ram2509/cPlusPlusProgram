
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

///insert node at specific position
void appendNodeAtPosition(node*& head, int data, int position){
    node *temp = head;
    int i = 0;
    for(i=0;i<position;i++){
        temp=temp->next;
        if(temp==NULL){
            cout<<"The number of node present in the linkedList is less given position"<<endl;
        }
    }
    temp=temp->prev;
    node *n = new node(data);
    n->next=temp->next;
    n->prev=temp;
    temp->next->prev = n;
    temp->next = n;
    return;
}

///delete the node
void deleteNode(node*& head, int key){
   node *temp = head;
   node *old;
   while(temp!=NULL){
      if(temp->data==key){
         ///key present at first node
         if(temp==head){
            head=head->next;
            return;
         }
         else{
            ///key present at last node
            if(temp->next==NULL){
            old = temp->prev;
            old->next=NULL;
            }
            ///key present at intermediate node
            else{
                old=temp->prev;
                old->next=temp->next;
                temp->next->prev=old;
            }
         }

         delete(temp);
      }
      temp=temp->next;
   }
}
///delete node
void takeKeyToDeleteNode(node*& head){
     cout<<"Enter the key"<<endl;
     int key;
     cin>>key;
     deleteNode(head,key);
}

///insert node at specific position
void takeInputAtPosition(node*& head){
   cout<<"Insert node at specific position"<<endl;
   int data,position;
   cout<<"Enter node data"<<endl;
   cin>>data;
   cout<<"Enter index value"<<endl;
   cin>>position;
   appendNodeAtPosition(head,data,position);
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
   takeInputAtPosition(head);
   display(head);
   takeKeyToDeleteNode(head);
   display(head);
   return 0;
}
