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
/*node* buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node* n = new node(data);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}*/

///build tree by iterative method
void buildIterativeTree(node*& root){
   int data;
   cin>>data;
   ///base case
   root = new node(data);

   ///iterative case
   queue<node*>q;
   q.push(root);
   while(!q.empty()){
      node *f = q.front();
      q.pop();
      int c1,c2;
      cout<<"Enter the Children of"<<f->data<<" ";
      cin>>c1>>c2;
      if(c1!=-1){
        f->left = new node(c1);
        q.push(f->left);
      }

      if(c2!=-1){
        f->right = new node(c2);
        q.push(f->right);
      }
   }
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

///find the max sum
class mySum{
  public:
   int inc;
   int exc;
};

mySum maxsum(node *root){
     mySum p;
     if(root==NULL){
        p.inc=0;
        p.exc=0;
        return p;
     }
   mySum left = maxsum(root->left);
   mySum right = maxsum(root->right);

   p.inc = root->data + left.exc + right.exc;
   p.exc = max(left.inc,left.exc) + max(right.inc,right.exc);
   return p;
}

int main(){
  node* root = NULL;
  buildIterativeTree(root);
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
  cout<<"Max sum of subSets"<<endl;
  mySum P = maxsum(root);
  int maxSum = max(P.inc,P.exc);
  cout<<maxSum<<endl;
  return 0;
}


