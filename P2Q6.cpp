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

struct GridNode{
    string val;
    int x;
    int y;
    vector<GridNode*> *Edges;
};

struct GridNode* newGridNode(string val) 
{  
    struct GridNode* GridNode = (struct GridNode*)malloc(sizeof(struct GridNode)); 
    GridNode->val = val;
    return(GridNode); 
}

struct GridGraph{
    vector <GridNode*> allNodes;
    int totalNodes=0;

    void addGridNode(int x, int y, string nodeVal){
        struct GridNode *Cool = newGridNode(nodeVal);
        Cool->x = x;
        Cool->y = y;
        allNodes.push_back(Cool);
        totalNodes++;
    }
    void addUndirectedEdge(GridNode* first, GridNode* second){
        if(abs(first->x - second->x )<= 1){
            if(abs(first->y - second->y )<= 1){
                first->Edges->push_back(second);
                second->Edges->push_back(first);
            }
        }
    }
    void removeUndirectedEdge(GridNode *first, GridNode *second){
        first->Edges->erase(remove(first->Edges->begin(),first->Edges->end(),(second)),first->Edges->end());
        second->Edges->erase(remove(second->Edges->begin(),second->Edges->end(),(first)),second->Edges->end());
    }
    unordered_set<GridNode*> getAllNodes(){
        unordered_set<GridNode*> setOfAllNodes;
        for (GridNode* &i: allNodes) {
            setOfAllNodes.insert(i);
        }
        return setOfAllNodes;
    }
};

GridGraph createRandomGridGraph(int n){
    GridGraph* poop;
    for(int i = 0; i < n^2; i++){
        for(int X = 0; X < n; X++){
            for(int Y = 0; Y < n; Y++){
                poop->addGridNode( X,  Y, to_string(poop->totalNodes));
            }
        }
    }
    vector<GridNode*>::iterator it = poop->allNodes.begin(); 
    for(; it!=poop->allNodes.end();it++){
        if(((*it)->x -1)!=-1){
            if (rand()%2 == 1){

            }
        }
    }
    for(int i = 0; i < n^2; i++){
        addUndirectedEdge()
    }
}
















int main(){




    return 0;
}