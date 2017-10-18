#include<iostream>
#include<list>
using namespace std;

class AdjacencyList{
   int V;
   list<int> *adjList;

   public :
       AdjacencyList(int v){
         V = v;
         adjList = new list<int>[V];
       }

       void addEdge(int u,int v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
       }

       void printAdjList(){
        ///iterative over all element array
        for(int i=0;i<V;i++){
            cout<<i<<"->";
            for(int vertex:adjList[i]){
                cout<<vertex<<",";
            }
            cout<<endl;
        }
       }
};

int main(){
  AdjacencyList a(5);
  a.addEdge(0,1);
  a.addEdge(0,4);
  a.addEdge(1,4);
  a.addEdge(1,3);
  a.addEdge(1,2);
  a.addEdge(2,3);
  a.addEdge(3,4);
  a.printAdjList();
  return 0;
}
