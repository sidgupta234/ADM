/* BFS Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures. 
It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as 
a 'search key'[1]) and explores the neighbor nodes first, before moving to the next level neighbors.
*/

#include <bits/stdc++.h>
using namespace std;
#define size 5

bool visited[1001];
int parents [size]; // keeping track of the discoverer of i.

// Can only be used if start is some ancestor of end.
void findPath(int start, int end){
	if(start==end || start==-1){
		cout<<start<<endl;
	}

	else{
		findPath(start, parents[end]);
		cout<<end<<endl;
	}
}

void bfs(int G[][size], int v){
	queue <int> Q; // BFS is an example of level order traversal, uses QUEUE.
	Q.push(v);
	visited[v]=true;
	//parents[v] = -1;

	while(!Q.empty()){
		int val = Q.front();
		for(int i=0; i<size; i++){
					
			if(G[val][i] && !visited[i]){
				parents[i] = val;
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

0--1--2 4
\    /
 \  /
  \/
  3

*/
	for(int i=0; i<size; i++){
		visited[i]=false;
		parents[i]=-1;
	}

	for(int i=0 ; i<size; i++){
		if(visited[i]== false)
			bfs(G, i);
	}

	findPath(0, 2);

	return 0;

	
}

/*
Output :=

0
1
2

*/