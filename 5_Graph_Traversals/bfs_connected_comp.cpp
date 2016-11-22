/* In graph theory, a connected component (or just component) of an undirected graph is a subgraph in which any two 
vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.*/

#include <bits/stdc++.h>
using namespace std;
#define size 5

bool visited[1001];

// Can only be used if start is some ancestor of end.

void bfs(int G[][size], int v){
	queue <int> Q; // BFS is an example of level order traversal, uses QUEUE.
	Q.push(v);
	visited[v]=true;
	//parents[v] = -1;

	while(!Q.empty()){
		int val = Q.front();
		for(int i=0; i<size; i++){
			if(G[val][i] && !visited[i]){
				visited[i]=true;
				Q.push(i);
			}
		}
		cout<<val<<' '<<endl;
		Q.pop();
	}
}

int main(){
	int G[5][5] = {{0, 1, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 0, 0, 0, 0} };
/*

0--1--2 4
\    /
 \  /
  \/
  3

*/	int connectedComp=0;

	for(int i=0; i<size; i++){
		visited[i]=false;
	}

	for(int i=0 ; i<size; i++){
		if(visited[i]== false){
			cout<<"Component: "<<connectedComp<<endl;
			connectedComp++;
			bfs(G, i);
		}
	}

	cout<<"Number of Components: "<<connectedComp<<endl;
	
	return 0;
	
}

/*
Output:

Component: 0
0 
1 
3 
2 
Component: 1
4 
Number of Components: 2
*/