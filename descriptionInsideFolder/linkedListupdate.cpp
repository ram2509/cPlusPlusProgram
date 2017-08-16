///insert the node at any position i & length of the LinkedList..... continue....

#include<iostream>
using namespace std;

class node{
public :
    int data;
    node* next;

    node(int d){
       data = d;
       next = NULL;
    };
};

///insert node at front of the linkedList
void insertNodeAtFront(node*& head, int data){
    ///check node are exit are not
    if(head == NULL){
        head = new node(data);
        return;
    }

    node* n = new node(data);
    n->next = head;
    head = n;
}

///insert node at position i
void insertNodeAtPosition(node*& head, int data,int position){
     node* temp = head;
     ///base case
     if(position==1){
        insertNodeAtFront(head,data);
     }

     ///in other case
     else{

     for(int i=1; i<position-1; i++){
        temp = temp->next;
     }
     node* n = new node(data);
     n->next = temp->next;
     temp->next = n;

     }
}

///take input insert at position i
void takeInputInsertAtPositionI(node*& head){
     int position;
     int data;
     cout<<"Input the position where node is insert"<<endl;
     cin>>position;
     cout<<"Input the data which are insert at position"<<" "<<position<<endl;
     cin>>data;
     insertNodeAtPosition(head,data,position);
}

///take the input for linkedList
void takeInput(node*& head){
   cout<<"We can insert the data into linkedList upto user input is -1"<<endl;
   int d;
   cin>>d;
   while(d!=-1){
       insertNodeAtFront(head,d);
       cin>>d;
   };
};

///display the linkedList
void display(node* head){
   while(head!=NULL){
      cout<<head->data<<"=>";
      head = head->next;
   };
};

///length of linkedList
int linkedListLength(node* head){
    int length = 0;
    while(head!=NULL){
        length++;
        head = head->next;
    }
    return length;
}


int main(){
    node* head = NULL;
    takeInput(head);
    display(head);
   // display(head);
    cout<<endl;
    cout<<"Length of linkedList is"<<linkedListLength(head)<<endl;
    takeInputInsertAtPositionI(head);
    display(head);
    return 0;
}

