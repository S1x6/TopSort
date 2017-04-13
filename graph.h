#ifndef GRAPH_H
#define GRAPH_H

#include "stdio.h"
#include "malloc.h"

#define COLOR_WHITE 0
#define COLOR_GRAY 1
#define COLOR_BLACK 2

typedef struct _Vertex {
	int num;
	char color;
	struct _ListNode * list_to;
} Vertex;

typedef struct _ListNode {
    struct _Vertex * value;
	struct _ListNode * next;
} ListNode;

Vertex * pop(ListNode ** head);
ListNode * push(Vertex * data, ListNode *head);
void clearList(ListNode ** head);
ListNode * ListNodeC(Vertex * value);
Vertex ** constructVertex(int vert_num);
void writeSortedGraph(FILE * fout, Vertex ** v, int v_num);
void printStack(FILE * fout, ListNode *stack);
void processVertex(FILE * fout,Vertex * v, ListNode ** stack);
Vertex * VertexC(int num, char color, ListNode * list_to);
void destructVertex(Vertex * v);
void destructList(ListNode * l);

#endif
