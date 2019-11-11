#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int numVertices;
    list *adjLists;
    bool* visited;
public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
    Graph Map_create(int mapa[n][n]);
};

Graph::Graph(int mapa[n][n])
{
    int k=0
    for(int i= 0 ; i<n; i++){
      for (int j = 0; j < n; j++) {
         if(mapa[i][j]== 1){
           adjLists = new list[(i*n)+j];
           k++;
         }
      }
    }
    numVertices= k;

}

void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void Graph::BFS(int startVertex)
{
    visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++)
        visited[i] = false;

    list queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    list::iterator i;

    while(!queue.empty())
    {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " ";
        queue.pop_front();

        for(i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
        {
            int adjVertex = *i;
            if(!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

Graph Graph::Map_create(int mapa[n][n]){
  Graph grafo;
  for(int i=0 ; i<n ;  i++){
    for(int j=0 ; j<n ;j++){
      if (i==0){
        if (j==0) {
            if(mapa[i][j]==1){
              if (mapa[i+1][j]==1) {
                grafo.addEdge((i*n)+j,((i+1)*n)+j);
              }
              if (mapa[i][j+1]==1) {
                grafo.addEdge((i*n)+j,(i*n)+j+1);
              }
            }
        }
        if(j==n-1){
          if(mapa[i][j]==1){
            if (mapa[i+1][j]==1) {
              grafo.addEdge((i*n)+j,((i+1)*n)+j);
            }
            if (mapa[i][j-1]==1) {
              grafo.addEdge((i*n)+j,(i*n)+j-1);
            }
          }
        }
        else{
          if(mapa[i][j]==1){
            if (mapa[i+1][j]==1) {
              grafo.addEdge((i*n)+j,((i+1)*n)+j);
            }
            if (mapa[i][j-1]==1) {
              grafo.addEdge((i*n)+j,(i*n)+j-1);
            }
            if (mapa[i][j+1]==1) {
              grafo.addEdge((i*n)+j,(i*n)+j+1);
            }
          }
        }
      }
      if(i==n-1){
        if (j==0) {
          if(mapa[i][j]==1){
            if (mapa[i-1][j]==1) {
              grafo.addEdge((i*n)+j,((i-1)*n)+j);
            }
            if (mapa[i][j+1]==1) {
              grafo.addEdge((i*n)+j,(i*n)+j+1);
            }
          }
        }
        if(j==n-1){
          if(mapa[i][j]==1){
            if (mapa[i-1][j]==1) {
              grafo.addEdge((i*n)+j,((i-1)*n)+j);
            }
            if (mapa[i][j-1]==1) {
              grafo.addEdge((i*n)+j,(i*n)+j-1);
            }
          }
        }
        else{
          if(mapa[i][j]==1){
            if (mapa[i+1][j]==1) {
              grafo.addEdge((i*n)+j,((i+1)*n)+j);
            }
            if (mapa[i][j+1]==1) {
              grafo.addEdge((i*n)+j,(i*n)+j+1);
            }
            if (mapa[i][j-1]==1) {
              grafo.addEdge((i*n)+j,(i*n)+j-1);
            }
          }
        }
      }
      else{
        if (j==0) {
          if(mapa[i][j]==1){
            if (mapa[i-1][j]==1) {
              grafo.addEdge((i*n)+j,((i-1)*n)+j);
            }
            if (mapa[i+1][j]==1) {
              grafo.addEdge((i*n)+j,((i+1)*n)+j);
            }
            if (mapa[i][j+1]==1) {
              grafo.addEdge((i*n)+j,(i*n)+j+1);
            }
          }
        }
        if(j==n-1){
          if(mapa[i][j]==1){
            if (mapa[i-1][j]==1) {
              grafo.addEdge((i*n)+j,((i-1)*n)+j);
            }
            if (mapa[i+1][j]==1) {
              grafo.addEdge((i*n)+j,((i+1)*n)+j);
            }
            if (mapa[i][j-1]==1) {
              grafo.addEdge((i*n)+j,(i*n)+j-1);
            }
          }
        }
        else{
          if(mapa[i][j]==1){
            if (mapa[i-1][j]==1) {
              grafo.addEdge((i*n)+j,((i-1)*n)+j);
            }
            if (mapa[i+1][j]==1) {
              grafo.addEdge((i*n)+j,((i+1)*n)+j);
            }
            if (mapa[i][j-1]==1) {
              grafo.addEdge((i*n)+j,(i*n)+j-1);
            }
            if (mapa[i][j+1]==1) {
              grafo.addEdge((i*n)+j,(i*n)+j+1);
            }
          }
        }
      }
    }
  }
  return grafo;
}
