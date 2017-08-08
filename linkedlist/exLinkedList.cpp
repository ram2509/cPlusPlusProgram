#include<iostream>
using namespace std;

class node{
public :
   int data;
   node* next; ///self referential pointer , that pointing to object of the same class

   node(int d){
    data = d;
    next = NULL;
   }
};

//insert node at front
void insertNodeAtFront(node*& head, int data){
     if(head == NULL){
        ///create the first node
        head = new node(data);
        return;
     }

     node* n = new node(data);
     n->next = head;
     head = n;
     return;
}

//insert node at position
void insertNodeAtPosition(node*& head, int data, int position){
    //base case
    if(head==NULL){
        insertNodeAtFront(head,data);
    }
    else{
        //travel to position n-1
        node* temp = head;
        int p = 1;
        while(p<=position-1){
            temp = temp->next;
             p++;
        }

        node* n = new node(data);
        n->next = temp->next;
        temp->next = n;
        return;
    }

}

void takeInput(node*& head){
      int d;
      cin>>d;
      while(d!=-1){
         insertNodeAtFront(head,d);
         cin>>d;
      }
}

void displayNode(node*& head){
     while(head!=NULL){
        cout<<head->data<<"=>";
        head = head->next;
     }
}
///overload the ostream & istream

void operator<<(ostream &os,node*& head){
    displayNode(head);
}

void operator>>(istream &is, node*& head){
    takeInput(head);
}

int main(){

   node* head = NULL;
   cin>>head;
   cout<<head;
   cout<<"Enter the data & position"<<endl;
   int data,position;
   cin>>data;
   cin>>position;
   insertNodeAtPosition(head,data,position);
   return 0;
}
