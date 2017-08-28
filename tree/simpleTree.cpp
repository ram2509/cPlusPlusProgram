#include<iostream>
#include<queue>
using namespace std;

class node{
public :
   int data;
   node* left;
   node* right;

    node(int d){
      data = d;
      left = NULL;
      right = NULL;
    }
};

///build tree
node* buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node* n = new node(data);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

///display the tree or Preorder traversal
void preorder(node* root){
    ///base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

///display the tree in Inoreder traversal
void inorder(node* root){
   ///base case
   if(root==NULL){
      return;
   }
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
}

///display the tree in Postorder traversal
void postorder(node* root){
  ///base case
  if(root==NULL){
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

///level order traversal
void levelorder(node* root){
   queue<node*> q;
   q.push(root);
   while(!q.empty()){
       node *f = q.front();
       cout<<f->data<<" ";
       q.pop();
       if(f->left){
        q.push(f->left);
       }
       if(f->right){
        q.push(f->right);
       }
   }
}

///advance level order traversal
void advancelevelorder(node* root){
   queue<node*> q;
   q.push(root);
   q.push(NULL);
   while(!q.empty()){
     node *f = q.front();
     if(f==NULL){
        q.pop();
        cout<<endl;
        if(!q.empty()){
            q.push(NULL);
        }
     }
     else{
        cout<<f->data<<" ";
        q.pop();
        if(f->left){
             q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
     }
   }
}

///cout node;
int countNode(node* root){
    if(root==NULL){
        return 0;
    }
    return 1 + countNode(root->left) + countNode(root->right);
}

int height(node* root){
   if(root==NULL){
     return 0;
   }
   return 1 + max(height(root->left),height(root->right));
}

int main(){
  node* root = NULL;
  root = buildTree();
  cout<<"Root element of tree is"<<" "<<root->data<<endl;
  cout<<"Preorder traversal of tree is"<<endl;
  preorder(root);
  cout<<endl;
  cout<<"Root element is"<<" "<<root->data<<endl;
  cout<<"Inorder traversal of tree is"<<endl;
  inorder(root);
  cout<<endl;
  cout<<"Postorder traversal of tree is"<<endl;
  postorder(root);
  cout<<endl;
  cout<<"Level order traversal of tree is"<<endl;
  levelorder(root);
  cout<<endl;
  cout<<"Advance level order traversal of tree is"<<endl;
  advancelevelorder(root);
  cout<<"Height of tree is"<<" "<<height(root);
  cout<<endl;
  cout<<"Number of node is"<<" "<<countNode(root);
  return 0;
}


