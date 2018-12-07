#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <climits>

#define fl(i,n) for(int i=0;i<n;i++)
#define pl printf("\n")
#define ps printf(" ")

using namespace std;

typedef vector<vector<int>> graph;
typedef vector<int> vertex;

void printList(graph);
void printMatrix(graph);
void addVerM(graph &g, vertex v);
void addVerL(graph &g, vertex v);


graph adjMatrix;

graph adjList;

int main(void){
	
}

void printList(graph g){
	fl(i,g.size()){
		printf("%d -> ", i);
		fl(j,g[i].size()){
			printf("%d -> ", g[i][j]);
		}
		printf("%c[3D%c[K\n", 0x1B, 0x1B);
	}
}

void printMatrix(graph g){
	fl(i,g.size()){
		fl(j,g.size()){
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}

void addVerL(graph &g, vertex v){
	graph.push_back(v);
	int k = g.size() - 1;
	for(int i = 0; i < g[k].size(); i++){
		g[g[i]].push_back(k);
	}
}

void addVerM(graph &g, vertex v){
	while(v.size() != g.size() + 1){
		v.push_back(0);
	}
	fl(i, g.size())
		g[i].push_back(v[i]);
	g.push_back(v);
	//complete_matrix_to_1(g);
}
/*
*void complete_matrix_to_1(graph &g){
*	fl(i,g.size()){
*		for(int j = i; j < g.size(); j++){
*			if(g[i][j] != g[j][i]){
*				g[i][j] = 1;
*				g[j][i] = 1;
*			}
*		}
*	}
*}
*
*void complete_matrix_to_0(graph &g){
*	fl(i,g.size()){
*		for(int j = i; j < g.size(); j++){
*			if(g[i][j] != g[j][i]){
*				g[i][j] = 0;
*				g[j][i] = 0;
*			}
*		}
*	}
*}*/
