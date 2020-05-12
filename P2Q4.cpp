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
#include <string>

using namespace std;

int indexcount = 0;
vector<int> adjacencyList[10000];
//vector<node*> visited;

struct node{
    string val;
    vector<node*> *Edges;
    int index;
};

struct node* newNode(string val) 
{  
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->val = val;
    node->Edges = new vector<struct node*>;
    node->index = indexcount;
    indexcount++;
    return(node); 
}


struct DirectedGraph{
    DirectedGraph();
    vector <node*> allNodes;
    int totalNodes=0;
    

    void addNode(string nodeVal){
        struct node *cream = newNode(nodeVal);
        allNodes.push_back(cream);
        totalNodes++;
    }
    void addDirectedEdge(node *first, node *second){
        first->Edges->push_back(second);
        adjacencyList[(first->index)].push_back(second->index);
    }
    void removeDirectedEdge(node *first, node *second){
        first->Edges->erase(remove(first->Edges->begin(),first->Edges->end(),(second)),first->Edges->end());
        //adjacencyList[(first->index)].erase(remove(adjacencyList[(first->index)].begin(), adjacencyList[(first->index)].end(), (second)), adjacencyList[(first->index)].end());
    }
    unordered_set<node*> getAllNodes(){
        unordered_set<node*> setOfAllNodes;
        for (node* &i: allNodes) {
            setOfAllNodes.insert(i);
        }
        return setOfAllNodes;
    }
};

DirectedGraph createRandomDAGIter(int n){
    DirectedGraph temp;
    for(int i = 0; i < n; i++){
        int r = rand() % 26;
        char c = 'a' + r; 
        string str(1,c);
        temp.addNode(str);
    }
    for(int i = 0; i < n; i++){
        int x = (rand()%(temp.totalNodes-1));
        temp.addDirectedEdge(temp.allNodes[i], temp.allNodes[x]);
    }
    return temp;
}

DirectedGraph :: DirectedGraph(){
    DirectedGraph();
}

struct TopSort{
    vector<node*> Kahns(DirectedGraph graph){
        vector <node*> topOutput; 
        int size = graph.allNodes.size();
        vector<int> inDegree(size, 0);
        for (int i=0; i<size; i++) 
        { 
            vector<int>::iterator it; 
            for (it = adjacencyList[i].begin(); it!= adjacencyList[i].end();it++){
                inDegree[*it]++; 
            }
        }
        queue<int> QTPie; 
        for (int i = 0; i < size; i++) {
            if (inDegree[i] == 0){ 
                QTPie.push(i);  
            }
        }
        while (!QTPie.empty()) 
        { 
            //a is their indexes
            int a = QTPie.front(); 
            QTPie.pop(); 
            topOutput.push_back(graph.allNodes[a]); 
            vector<int>::iterator it; 
            for (it = adjacencyList[a].begin(); it != adjacencyList[a].end(); it++) 
                if (inDegree[*it] == 1){
                    QTPie.push(*it); 
                }
        }
        return topOutput; 
    }

    vector<node*> visited;
    stack <node*> Output;

    vector<node*> mDFS(DirectedGraph graph){
        //I will eventually mark every node as visited.
        //I will do a full DFS traversal with every node.
        //when a node has no unvisited neighbors, put it in the output stack.
        //At end, pop off and that is the sort.
        vector <node*>::iterator it = graph.allNodes.begin();
        for(; it!=graph.allNodes.end();it++){
            DFSRec((*it));
            visited.clear();
        }
        //Now pop the stack into a vector
        vector<node*> Ret;
        while(Output.empty() == false){
            Ret.push_back(Output.top());
            Output.pop();
        }
        return Ret;
        
    }

    

    void DFSRec(node *start){
        visited.push_back(start);
        vector <node*>::iterator it = start->Edges->begin();
        for(; it!=start->Edges->end();it++){
            vector <node*>::iterator itV;
            itV = find (visited.begin(), visited.end(), *it);
            if (itV == visited.end()){ 
                DFSRec((*itV));
            }
        }
        Output.push(start);
        //all start's neighbors visited here
        //i care if neighbors size is same as allnodes
        return;
    }
};

int main(){
    DirectedGraph Cry;
    Cry = createRandomDAGIter(1000);
    TopSort temp;
    vector<node*> Kahns =  temp.Kahns(Cry);

    DirectedGraph Pool;
    Pool = createRandomDAGIter(1000);
    TopSort Pie;
    vector<node*> mDFS =  temp.mDFS(Pool);



    return 0;
}