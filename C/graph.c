#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

#define fl(i,n) for(int i=0;i<n;i++)
#define ps printf(" ")
#define pl printf("\n")

struct LinkedList {
	int value;
	struct LinkedList * prev;
};

typedef struct LinkedList LinkedList;

void printVertexEdges(int u, int E[][2], int LE[]);
void insertEdge(int u, int v, int E[][2], int LE[], int id);
void DFS(int v, int E[][2], int LE[], LinkedList ** stack, int visited[]);
void push(LinkedList ** stackP, int val);
int pop(LinkedList ** stackP);
void printStack(LinkedList * stack);

int main(void){
	int n, m;
	LinkedList * stack = NULL;
	printf("Enter node number: ");
	scanf("%d", &n);
	printf("Enter edge count: ");
	scanf("%d", &m);

	int E[m][2];
	int LE[n];
	int visited[n];
	fl(i,n){
		LE[i] = -1;
		visited[i] = 0;
	}

	int u,v;
	fl(i,m){
		do{
			printf("Enter start and end points: ");
			scanf("%d %d", &u, &v);
		} while( u >= n || u < 0 || v >= n || v < 0);
		insertEdge(u, v, E, LE, i);
	}
	int i;
	printf("Enter a vertex: ");
	scanf("%d", &i);
	printVertexEdges(i, E, LE);
	DFS(i, E, LE, &stack, visited);
	free(stack);
	return 0;
}

void printVertexEdges(int u, int E[][2], int LE[]){
	for(int i = LE[u]; i != -1; i = E[i][1]){
		printf("%d -> %d\n", u, E[i][0]);
	}
}

void insertEdge(int u, int v, int E[][2], int LE[], int id){
	E[id][0] = v;
	E[id][1] = LE[u];
	LE[u] = id;
}

void DFS(int v, int E[][2], int LE[], LinkedList ** stackP, int visited[]){
	printf("Executing on: %d\n", v);
	visited[v] = 1;
	for(int i = LE[v]; i != -1; i = E[i][1]){
		push(stackP, E[i][0]);
//		printf("Pushing %d\n", E[i][0]);
	}
	printStack(*stackP);
	if((*stackP) != NULL){
		int aux = pop(stackP);
//		printf("aux: %d\n", aux);
		while(aux != -1){
			if(visited[aux] == 0){
				DFS(aux, E, LE, stackP, visited);
			}
			if((*stackP) == NULL){
//				printf("Hit stack bottom.\n");
				return;
			}
//			printf("Printing stack before popping...\n");
//			printStack(*stackP);
			aux = pop(stackP);
//			printf("Aux: %d\n",aux);
//			printf("Post-pop...\n");
		}
	}
}

void push(LinkedList ** stackP, int val){
	LinkedList * new = malloc(sizeof(LinkedList));
	new->value = val;
	if(*stackP != NULL){
		new->prev = *stackP;
//		printf("Previous value: %d\n", new->prev->value);
	}
	else{
		new->prev = NULL;
//		printf("First value!\n");
	}
	(*stackP) = new;
}

int pop(LinkedList ** stackP){
	if((*stackP) == NULL) return -1;
	LinkedList * aux = (*stackP);
	if(aux->prev != NULL)
		(*stackP) = aux->prev;
	else{
		(*stackP) = NULL;
	//	printf("Last value!\n");
	}
	int temp = aux->value;
	free(aux);
//	printf("Popping: %d\n", temp);
	return temp;
}

void printStack(LinkedList * stack){
	LinkedList * aux = stack;
	if(aux == NULL){
		printf("Empty stack.\n");
		return;
	}
	pl;
	printf("Stack: %d\n", aux->value);
	aux = aux->prev;
	while(aux != NULL){
		printf("%d\n", aux->value);
		aux = aux->prev;
	}
	printf("\n");
}
