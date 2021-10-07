#include <bits/stdc++.h>
using namespace std;
#define V 30
int graph[30][30];
void traverse(int u, bool visited[]) {
   visited[u] = true; 
   for(int v = 0; v<V; v++) {
      if(graph[u][v]) {
         if(!visited[v])
            traverse(v, visited);
      }
   }
}
bool isConnected() {
   bool *vis = new bool[V];
   for(int u; u < V; u++) {
      for(int i = 0; i<V; i++)
         vis[i] = false; 
         traverse(u, vis);
      for(int i = 0; i<V; i++) {
         if(!vis[i]) 
            return true;
      }
   }
   return false;
}
int CD(int N, int M)
{
  
    int count = 0;
 
    
    int freq1[10] = { 0 };
 
    
    int freq2[10] = { 0 };
 
    
    while (N > 0) {
 
       
        freq1[N % 10]++;
 
       
        N = N / 10;
    }
   
    while (M > 0) {
 
        
        freq2[M % 10]++;
 
     
        M = M / 10;
    }
   
    for (int i = 0; i < 10; i++) {
 
        
        if (freq1[i] > 0 & freq2[i] > 0) {
 
           
            count++;
        }
    }
 
    
    return count;
}


int findMaxVertex(bool visited[], int weights[], int n)
{
 
   
    int index = -1;
 
   
    int maxW = INT_MIN;
 
   
    for (int i = 0; i < n; i++) {
 
        
        if (visited[i] == false
            && weights[i] > maxW) {
 
            maxW = weights[i];
 
            index = i;
        }
    }
    return index;
}
 

void printMaximumSpanningTree(int parent[],int n)
{
 
  
    int MST = 0;
 
    
    for (int i = 1; i < n; i++) {
 
        MST += graph[i][parent[i]];
    }
    cout<<MST;
}
 

void maximumSpanningTree(int n)
{
 
    
    bool visited[n];
 
    int weights[n];
 
   
    int parent[n];
 
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        weights[i] = INT_MIN;
    }
 
    weights[0] = INT_MAX;
    parent[0] = -1;
 
    for (int i = 0; i < n - 1; i++) {
 
  
        int maxVertexIndex
            = findMaxVertex(visited, weights,n);
 
        visited[maxVertexIndex] = true;
 
   
        for (int j = 0; j < n; j++) {
            if (graph[j][maxVertexIndex] != 0
                && visited[j] == false) {
                if (graph[j][maxVertexIndex] > weights[j]) {
                    weights[j] = graph[j][maxVertexIndex];
                    parent[j] = maxVertexIndex;
                }
            }
        }
    }
    printMaximumSpanningTree(parent,n);
}
 

int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    int roll[n];
     cout<<"enter n roll numbers: ";
    for(int i=0;i<n;i++){
       cin>>roll[i];
    }
   
     for (int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(CD(roll[i],roll[j])>=2){
              graph[i][j]=CD(roll[i],roll[j]);
              graph[j][i]=CD(roll[i],roll[j]);
            }
            else{
                graph[i][j]=0;
                graph[j][i]=0;
            }
        }
    }
 
  
    if(isConnected())
      cout << "Graph connection status: \"YES\" .\n";
   else
      cout << "Graph connection status: \"NO\" .\n";
   
   cout <<"Cost of maximum spanning tree: ";
    maximumSpanningTree(n);
 
    return 0;
} 
