#include <cmath>
#include <string>
#include <cstdio>
#include <list> 
#include <iterator> 
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue> 
#include <ostream>
#include<bits/stdc++.h> 
#include<set>
#include <unordered_set>

using namespace std;

//It seems I have too many overloads.

struct node{
    int val;
    vector<node*> *Edges;
};

struct node* newNode(int val) 
{  
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->val = val;
    node->Edges = new vector<struct node*>;
    return(node); 
}

//temp here, cut and paste later.
//How to recognize fail case? Where all edges exhausted?
struct GraphSearch {
    GraphSearch();
    vector<node*> visited;
    vector<int> adjacencyList;
    vector<node*> *Path = new vector<node*>;
    node *originalStart = NULL;

    vector<node*> *DFSRec(node *start, node *end){
        //Save originalStart.
        if(originalStart == NULL){
            originalStart = start;
        }
        //cout<<"a\n";
        //first visit this node
        visited.push_back(start);
        //iterate through the Edges, if the Edge is not in visited,  call DFS on it!
        //What if no Edges? No, there are always edges.
        vector <node*>::iterator it = start->Edges->begin();
        //cout<<"b\n";
        for(; it!=start->Edges->end();it++){
            //look for this edged vector in visited
            vector <node*>::iterator itV;
            itV = find (visited.begin(), visited.end(), *it);
            
            if (itV == visited.end()){ //if not found in visited, do DFS on it
                //cout<<"Anybody there? I'm at node: "<<start->val<<"\n";
                Path = DFSRec((*it), end);
                //never gets here, lol.
                //cout<<"I'm here... I'm at node: "<<start->val<<"\n";
            }
            
        }
        //cout<<"c\n";
        //I've decided to push this into Path if end is in it OR if we are at end.
        if(start == end){
            //cout<<"End found!I'm at node: "<<start->val<<"\n";
            Path->push_back(start);
            //Path->insert(Path->begin(),start);
        }
        else if(Path->empty() != true){
            if(Path->front() == end){
                //cout<<"I'm on the path back! I'm at node: "<<start->val<<"\n";
                Path->push_back(start);
                //Path->insert(Path->begin(),start);
            }
        }
        if(Path->empty() != true){
            if(Path->front() == end && Path->back() == originalStart){
                reverse(Path->begin(),Path->end()); 
            }
        }
        //Fail case, return null
        if(start == originalStart && Path->empty() == true){
            return NULL;
        }
        
        return Path;
        
    }
    
    void printPath(vector<node*> *Path){
        if(Path == NULL){
            cout << "No DFS Path! \n";
            return;
        }
        vector <node*>::iterator it = Path->begin();
        cout << "Print out the DFS Path! \n";
        for(; it!=Path->end();it++){
            cout << "Node : " << (*it)->val <<"\n";
        }

    }
    
    //vector <node**> BFTRec(Graph *graph){//I give up.
        //I got my queue.
        //Now I will process every vertex in graph.
        /*Graph *poop = graph;
        vector <node*>::iterator it = poop->allNodes.begin();
        for(; it!=poop->allNodes.end();it++){
            
            vector <node*>::iterator itV;
            //from here i split into a helper, recursion function that processes all edges of one node..
            BFTRecHelper(poop,it,itV);
            */
        //}
    //};
    //i don't know what it returns yet
    //vector <node*> BFTRecHelper(Graph *poop, vector <node*>::iterator it, vector <node*>::iterator itV){
        //vector <node*> output;
        /*itV = find (visited.begin(), visited.end(), *it);
        if (itV == visited.end()){ //the node wasn't found!
            //add it to visited, then add to queue.
            visited.push_back(*it);
            queue.push_back(*it);
            BFTRecHelper(poop,it,itV);
        }*/
        //return output;
    //};

    /*
    vector<node*> visited;
    vector<int> adjacencyList;
    vector<node*> *Path = new vector<node*>;
    node *originalStart = NULL;
    */
    list<node*> queue; 
    vector <node*>::iterator start;
    node* x;
    vector <node*> *BFTIter(struct Graph *graph){
        Graph *poop = graph;
        vector <node*> *output;
        //first case
        vector <node*>::iterator it = poop->allNodes.begin();
        visited.push_back(*it);
        queue.push_back(*it);
        
        while(!queue.empty()){
            x = queue.front();
            //Save output here
            output->push_back(x);

            queue.pop_front();
            //now process edges.
            vector <node*>::iterator it2 = x->Edges->begin();
            for(; it!=x->Edges->end();it++){
                //look for this edged vector in visited
                vector <node*>::iterator itV;
                itV = find (visited.begin(), visited.end(), *it);
                if (itV == visited.end()){ 
                    visited.push_back((*itV));
                    queue.push_back(*itV);
                }
                
            }

        }
        return output;
    }
    
};

GraphSearch :: GraphSearch(){
    vector<node*> *Path;
}

struct Graph {
    Graph();
    vector <node*> allNodes;
    int totalNodes=0;
    //create adjacencyList here
    vector<int> adjacencyList[10000];

    void addNode(int nodeVal){
        struct node *cream = newNode(nodeVal);
        allNodes.push_back(cream);
        totalNodes++;
    }
    void addUndirectedEdge(node *first, node *second){
        first->Edges->push_back(second);
        adjacencyList[first->val].push_back(second->val);
        second->Edges->push_back(first);
        adjacencyList[second->val].push_back(first->val);
    }
    void removeUndirectedEdge(node *first, node *second){
        first->Edges->erase(remove(first->Edges->begin(),first->Edges->end(),(second)),first->Edges->end());
        second->Edges->erase(remove(second->Edges->begin(),second->Edges->end(),(first)),second->Edges->end());
    }

    unordered_set<node*> getAllNodes(){
        unordered_set<node*> setOfAllNodes;
        for (node* &i: allNodes) {
            setOfAllNodes.insert(i);
        }
        return setOfAllNodes;
    }
    
};

Graph :: Graph(){
    //I hope this fixes it.
    //Graph();
}

Graph createRandomUnweightedGraphIter(int n){
    Graph temp;
    for(int i = 0; i < n; i++){
        temp.addNode(i);
    }
    for(int i = 0; i < n; i++){
        int x = (rand()%(temp.totalNodes-1));
        temp.addUndirectedEdge(temp.allNodes[i], temp.allNodes[x]);
    }
    return temp;
}

Graph createLinkedList(int n){
    Graph temp;
    for(int i = 0; i < n; i++){
        temp.addNode(i);
    }
    for(int i = 1; i < n; i++){
        temp.addUndirectedEdge(temp.allNodes[i], temp.allNodes[i-1]);
    }
    return temp;
}



void printAllValues(Graph test, int i, int firstrun, vector <node*>::iterator it1, vector <node*>::iterator it2, int totalNodes){
    it1 = test.allNodes.begin();
    int count = 0;
    while (count!=totalNodes){
        if(firstrun==0){
            firstrun = 1;
        }
        else{
            it1++;
        }
        if((*it1)->Edges->begin() != (*it1)->Edges->end()){
            it2 = (*it1)->Edges->begin();
            cout <<"val of node "<<(*it1)->val<<" is: "<< (*it1)->val<< "\n";
            for (; it2 != (*it1)->Edges->end(); it2++,i++){
                //cout <<"val of node "<<(*it1)->val<<" is: "<< (*it1)->val<< "\n";
                cout <<"val of edge "<<i<<" is: "<< (*it2)->val << "\n";
            }
        }
        //print val once even if no edges.
        if((*it1)->Edges->begin() == (*it1)->Edges->end()){
            cout <<"val of node "<<(*it1)->val<<" is: "<< (*it1)->val<< "\n";
        }
        cout <<"No more edges for this node. \n";
        i = 0;
        count++;
    }
    cout <<"Finished. \n";
}

void printAdjacencyList(vector<int> adjacencyList[], int A) 
{ 
    cout << "Adjacency list\n";
    for (int a = 0; a < A; ++a) 
    { 
        cout << "Node: ";
        cout << a << "\n"; 
        for (auto x : adjacencyList[a]) 
           cout << x << "\n"; 
    } 
} 

vector<node*> *BFTRecLinkedList(Graph* graph){
    vector<node*> *output;
    GraphSearch temp;
    //*output = temp.BFTRec(graph);
    return output;
}

vector<node*> *BFTIterLinkedList(Graph* graph){
    //must run a 10,000 node linked list on this.
    vector<node*> *output;
    GraphSearch temp;
    output = temp.BFTIter(graph);
    return output;
}
  

int main(){
    Graph test = createLinkedList(10000);
    vector<node*> *BFTIterHugeReturn = BFTIterLinkedList(&test);
    //
    return 0;
}