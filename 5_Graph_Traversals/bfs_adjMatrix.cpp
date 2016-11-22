/* BFS Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures. 
It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as 
a 'search key'[1]) and explores the neighbor nodes first, before moving to the next level neighbors.
*/

#include <bits/stdc++.h>
using namespace std;
#define size 5

bool visited[1001];

void bfs(int G[][size], int v){
	queue <int> Q; // BFS is an example of level order traversal, uses QUEUE.
	Q.push(v);
	visited[v]=true;

	while(!Q.empty()){
		int val = Q.front();
		cout<<val<<endl;
		for(int i=0; i<size; i++){
			if(G[val][i] && !visited[i]){
				visited[i]=true;
				Q.push(i);
			}
		}
		Q.pop();
	}
}

int main(){
	int G[5][5] = {{0, 1, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 0, 0, 0, 0} };
/*

0--1--2 5
\    /
 \  /
  \/
  3
  
*/
	for(int i=0; i<size; i++){
		visited[i]=false;
	}

	for(int i=0 ; i<size; i++){
		if(visited[i]== false)
			bfs(G, i);
	}

	return 0;
}