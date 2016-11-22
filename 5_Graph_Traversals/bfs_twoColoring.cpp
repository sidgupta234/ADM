/* BFS Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures. 
It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as 
a 'search key'[1]) and explores the neighbor nodes first, before moving to the next level neighbors.
*/

#include <bits/stdc++.h>
using namespace std;
#define size 5
bool Bipartite = true;

int color[size]; // color would be used as a visited flag also :D

/* Color: -1 = Not Colored; 0 = White; 1 = Black */
void processEdge(int G[][size], queue<int> &Q, int v, int i){
	if(color[i]==-1){ // If uncolored, color with the opposite color of parent.
		color[i] = 1^color[v];
		Q.push(i);
	}

	else if(color[i]==color[v]){ // if colored and the color is same then parent, not Bipartite :'(
		Bipartite = false;
	}							
}

void bfs(int G[][size], int v){
	queue <int> Q; // BFS is an example of level order traversal, uses QUEUE.
	Q.push(v);
	color[v]=0; //color white

	while(!Q.empty()){
		v = Q.front();
		//cout<<v<<endl;
		for(int i=0; i<size; i++){
			if(G[v][i]){
				processEdge(G, Q, v, i); // opportunity to explore edge.
			}
		}
		Q.pop();
	}
}

int main(){
	int G[5][5] = {{0, 1, 0, 1, 0}, 
				   {1, 0, 1, 1, 0}, 
				   {0, 1, 0, 1, 0}, 
				   {1, 1, 1, 0, 0}, 
				   {0, 0, 0, 0, 0} 
				  };
/*

0--1--2 4
\  |  /
 \ | /
  \|/
   3

*/
	for(int i=0; i<size; i++){
		color[i]=-1; // leaving uncolored.
	}

	for(int i=0 ; i<size; i++){
		if(color[i]== -1) // If uncolored.
			bfs(G, i);
	}

	if(Bipartite){
		cout<<"Yay, Bipartite"<<endl;
	}

	else{
		cout<<"Not Bipartite"<<endl;
	}

	return 0;
}

/*
Output :=
Not Bipartite
*/