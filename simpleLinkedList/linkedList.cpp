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
void display(node*& head){
   while(head!=NULL){
      cout<<head->data<<"=>";
      head = head->next;
   };
};


int main(){
    node* head = NULL;
    takeInput(head);
    display(head);
    return 0;
}

