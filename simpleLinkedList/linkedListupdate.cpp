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
        return;
     }

     ///in other case
     else{

     for(int i=1; i<position-1; i++){
        temp = temp->next;
     }
     node* n = new node(data);
     n->next = temp->next;
     temp->next = n;
      //display(head);
     };
}

///insert at tail of the node
void insertNodeAtTail(node*& head,int data){
        insertNodeAtPosition(head,data,linkedListLength(head)+1);
        //display(head);
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
};

void takeInputInsertAtTail(node*& head){
    int data;
    cout<<"Enter the value of node"<<endl;
    cin>>data;
    insertNodeAtTail(head,data);
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

///Search Element - using recursion
node* searchElement(node* head,int key){
     ///base case
     if(head==NULL){
        return NULL;
     }

     if(head->data==key){
        return head;
     }

     return searchElement(head->next,key);
}





int main(){
    node* head = NULL;
    takeInput(head);
    display(head);
   // display(head);
    cout<<endl;
    cout<<"Length of linkedList is"<<linkedListLength(head)<<endl;
    int choice;
    cout<<"Enter 1 for insert the node at tail & enter 0 for insert the node at position i"<<endl;
    cin>>choice;
    if(choice==1){
        takeInputInsertAtTail(head);
    }
    else if(choice==0){
    takeInputInsertAtPositionI(head);
    }
    else{
        cout<<"You Enter wrong Input"<<endl;
    }
    display(head);
    cout<<endl;
    ///search element in linkedList
    cout<<"Enter key to search in the linkedList"<<endl;
    int key;
    cin>>key;
    cout<<"Key present at address"<<" "<<searchElement(head,key);
    return 0;
}

