#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

struct DLL {
	int value;
	struct DLL* prev;
	struct DLL* next;
};

typedef struct DLL DLL;

struct queue {
	int size;
	DLL * first;
	DLL * last;
};

typedef struct queue queue;

void enqueue(queue*, int);
int dequeue(queue*);
int isEmpty(queue*);

int main(void){
	queue Q;
	Q.first = NULL;
	Q.last = NULL;
	Q.size = 0;
	enqueue(&Q, 4);
	printf("Size: %d | First value: %d | Last value: %d\n", Q.size, Q.first->value, Q.last->value);
	enqueue(&Q, 2);
	printf("Size: %d | First value: %d | Last value: %d\n", Q.size, Q.first->value, Q.last->value);
	int contents[2];
	for(int i = 0; i < 2; i++) contents[i] = dequeue(&Q);
	printf("%d%d\nisEmpty? %d\n", contents[0], contents[1], isEmpty(&Q));
	return 0;
}

void enqueue(queue * Q, int val){
	DLL * enq = malloc(sizeof(DLL));
	enq->next = NULL;
	enq->value = val;
	enq->prev = Q->last;
	if(Q->size > 0){
		Q->last->next = enq;
		Q->last = enq;
	}
	else{
		Q->last = enq;
		Q->first = enq;
	}
	Q->size += 1;
	return;
}

int dequeue(queue * Q){
	if(Q->size <= 0) return -1;
	if(Q->size > 1){
		Q->first->next->prev = NULL;
	}
	int ret = Q->first->value;
	DLL * freer = Q->first;
	Q->first = Q->size > 1 ? Q->first->next : NULL;
	Q->size -= 1;
	free(freer);
	return ret;
}

int isEmpty(queue * Q){
	if(Q->size == 0) return 1;
	else return 0;
}


