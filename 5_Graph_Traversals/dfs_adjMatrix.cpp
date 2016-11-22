/*
Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures. 
One starts at the root (selecting some arbitrary node as the root in the case of a graph) and explores 
as far as possible along each branch before backtracking.
*/

#include <bits/stdc++.h>
using namespace std;
#define size 5

bool visited[1001];

void dfs(int G[][size], int v){
	// BFS is an example of level order traversal, uses QUEUE.
	if(!visited[v]){
		visited[v]=true;
		for(int i=0; i<size; i++){
			if(G[v][i] && !visited[i]){
				dfs(G, i);
			}
		}
		cout<<v<<endl;
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
	}

	for(int i=0 ; i<size; i++){
		if(visited[i] == false)
			dfs(G, i);
	}

	return 0;
}

/*
Output :=

3
2
1
0
4

*/