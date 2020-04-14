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
using namespace std;

struct node{
    string val;
    list <node> Edges;
};

struct node* newNode(string val) 
{  
  struct node* node = (struct node*)malloc(sizeof(struct node)); 
  node->val = val; 
  return(node); 
}

struct Graph {
    list <node> allNodes;
    void addNode(string nodeVal){
        struct node *cream = newNode(nodeVal);
        allNodes.push_back(*cream);
    }
    void addUndirectedEdge(node *first, node *second){
        first->Edges.push_back(*second);
        second->Edges.push_back(*first);
    }
    void removeUndirectedEdge(node *first, node *second){
        first->Edges.remove(*second);
        second->Edges.remove(*first);
    }
    list<node> getAllNodes(){
        return allNodes;
    }
    void createRandomUnweightedGraphIter(int n){
        for(int i = 0; i < n; i++){
            string randomString = ('a'+rand()%26) + ('a'+rand()%26) ('a'+rand()%26);
            addNode(randomString);
        }
        std::list<node>::iterator it;
        for (it = allNodes.begin(); it != allNodes.end(); it++){
            std::list<node>::iterator poop;
            for (poop = allNodes.begin(); poop != allNodes.end(); poop++){
                if(0 == rand()%(n-1)){
                    if(poop!=it){
                        break;
                    }
                }
            }
            addUndirectedEdge(&(*it),&(*(poop)));
        }
    }
    void createLinkedList(int n){
        for(int i = 0; i < n; i++){
            string randomString = ('a'+rand()%26) + ('a'+rand()%26) + ('a'+rand()%26);
            addNode(randomString);
        }
        std::list<node>::iterator it;
        std::list<node>::iterator next = allNodes.begin();
        next++;
        for (it = allNodes.begin(); next != allNodes.end(); it++){
            addUndirectedEdge(&(*it),&(*next));
            next++;
        }
    }

};

Graph :: Graph(){
}

struct GraphSearch {
    list <node> visited;
    list <node> DFSRec(node *start, node *end){
        visited.push_back(*start);
        if(start == end){
            return visited;
        }
        std::list<node>::iterator it;
        for (it = start->Edges.begin(); it != start->Edges.end(); it++){
            std::list<node>::iterator alreadyvisited;
            alreadyvisited = find(visited.begin(), visited.end(), &(*it));
            if(alreadyvisited == visited.end()){
                DFSRec(&(*it),end);
            }
        }
    }
};

int main(){
    return 0;
}