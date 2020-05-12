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
#include <map>

using namespace std;

int indexcount = 0;
vector<int> adjacencyList[10000];
//vector<node*> visited;

struct node{
    string val;
    map<int,int> *Combined;
    map<int,int> *Visited;
    //I begrudingly care about node* this holds node* and index.
    map<node*,int> *Output;
    int index;
};

struct node* newNode(string val) 
{  
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->val = val;
    node->index = indexcount;
    indexcount++;
    return(node); 
}


struct WeightedGraph{
    WeightedGraph();
    vector <node*> allNodes;
    int totalNodes=0;
    

    void addNode(string nodeVal){
        struct node *cream = newNode(nodeVal);
        allNodes.push_back(cream);
        totalNodes++;
    }
    void addWeightedEdge(node *first, node *second, int edgeWeight){
        //I only care about indexes.
        first->Combined->insert(pair<int,int>(second->index,edgeWeight));
        //first->Combined->insert(pair<int,int>(second->index,edgeWeight));
        adjacencyList[(first->index)].push_back(second->index);
    }
    void removeWeightedEdge(node *first, node *second){
        first->Combined->erase(second->index);
    }
    unordered_set<node*> getAllNodes(){
        unordered_set<node*> setOfAllNodes;
        for (node* &i: allNodes) {
            setOfAllNodes.insert(i);
        }
        return setOfAllNodes;
    }
};

WeightedGraph createRandomCompleteWeightedGraph(int n){
    WeightedGraph temp;
    for(int i = 0; i < n; i++){
        int r = rand() % 26;
        char c = 'a' + r; 
        string str(1,c);
        temp.addNode(str);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i!=j){
                temp.addWeightedEdge(temp.allNodes[i], temp.allNodes[j], (rand() % 50));
            }
        }
    }
    return temp;
}

WeightedGraph createLinkedList(int n){
    WeightedGraph temp;
    for(int i = 0; i < n; i++){
        int r = rand() % 26;
        char c = 'a' + r; 
        string str(1,c);
        temp.addNode(str);
    }
    for(int i = 0; i < n-1; i++){
        temp.addWeightedEdge(temp.allNodes[i], temp.allNodes[i-1],1);
    }
    return temp;
}

map<node*,int> *djikstras(node* start){//unfinished
    //I'm working with nodes, with any number of edges. And the edges have weights.
    //I have start->Visited in my pocket. As well as indexcount.
    //Remember that edges are connections and weights are distances.
    //I use 100 instead of infinity.
    map<int,int>::iterator it;
    //everything now has a distance from start.
    for(int i = 0; i < indexcount; i++){
        it = start->Combined->find(i);
        if (it == start->Combined->end()){
            start->Combined->insert(i,100);
        }
    }
    node* current = start;

    


    //Last step, must convert my indexs back to node*
    /*
    map<node*,int>* Output;
    for(int i = 0; i < indexcount; i++){
        
        Output->insert(
        if (it == start->Combined->end()){
            start->Combined->insert(i,100);
        }
    }
    return start->Combined;*/
}


int main(){
    WeightedGraph poo;
    poo = createRandomCompleteWeightedGraph(10);




    return 0;
}