// Example program
#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <functional>
#include <limits>

using namespace std;

#define int_max 100000;
class graph 
{
    private: 
        list<pair<int,int>> *gr;
        int _numOfVertices;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minDistance; //min heap to store the minimum distant node
        int *dist; //to store the distance of each node from source
        bool *visited; //each node whose shortest distance has been calculated would be true and we will not process that node
        
    public:
        graph(int numOfVertices);
        void printGraph();
        void addEdge(int source, int destination, int weight);
        void shortestPath(int source);
        int getMinimumDistanceNode();
};
graph::graph(int numOfVertices) : _numOfVertices(numOfVertices)   
{
    cout<<"Constructor\n";
    gr = new list<pair<int,int>>(numOfVertices);
    dist = new int(numOfVertices);
    for (int i=0;i<numOfVertices;i++) 
        dist[i] = int_max;
    visited = new bool(numOfVertices);
    for (int i=0;i<numOfVertices;i++)
        visited[i] = false;
}

void
graph::addEdge(int source, int dest, int weight)
{
    gr[source].push_back(make_pair(dest,weight));
}

int 
graph::getMinimumDistanceNode()
{
    int min = int_max;
    int index = 0;
    for (int i=0;i<_numOfVertices;i++) {
        if (!visited[i] && dist[i] < min) {
            index = i;
            min = dist[i];
        }
    }
    return index;
}

void
graph::shortestPath(int source)
{
    cout<<"In shortest path\n";
    //add all the node in a priority queue and initialize their distances to infinity apart from the source node
    
    dist[source] = 0; //distance of source from source would be zero
    
    //get minimum distance node
    int u = getMinimumDistanceNode();
    
    visited[u] = true;
    cout<<u<<"\n";
    //update the distance of all the nodes in the adjacency list of u, only if the new distance is less than their current distance
    for (auto i=gr[u].begin(); i!=gr[u].end();i++) {
        cout<<(*i).first;    
    }
}

static graph g(2);

int main()
{
    cout<<"\nIn main\n";
    //graph has 9 node [0,8]
    //static graph g(3); //= new graph(2);
    
    //adding the neighbours of each node with their weights
    g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    
    g.addEdge(1,7,11);
    g.addEdge(1,2,8);
    g.addEdge(1,0,4);
    
   /* g.addEdge(2,1,8);
    g.addEdge(2,8,2);
    g.addEdge(2,3,7);
    g.addEdge(2,5,4);
    
    /*g->addEdge(3,2,7);
    g->addEdge(3,5,14);
    g->addEdge(3,4,9);
    
    g->addEdge(4,3,9);
    g->addEdge(4,5,10);
    
    g->addEdge(5,3,14);
    g->addEdge(5,4,10);
    g->addEdge(5,2,4);
    g->addEdge(5,6,2);
    
    g->addEdge(6,5,2);
    g->addEdge(6,7,1);
    g->addEdge(6,8,6);
    
    g->addEdge(7,0,8);
    g->addEdge(7,1,11);
    g->addEdge(7,8,7);
    g->addEdge(7,6,1);
    
    g->addEdge(8,7,7);
    g->addEdge(8,2,2);
    g->addEdge(8,6,6);*/
    
  //  g->shortestPath(0);
  return 0;
}


