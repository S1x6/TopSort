#ifndef GRAPH_H
#define GRAPH_H

#include "stdio.h"

#define COLOR_WHITE 0;
#define COLOR_GRAY 1;
#define COLOR_BLACK 2;

typedef struct _Vertex Vertex;
typedef struct _Edge Edge;
typedef struct _ListNode ListNode;

Vertex pop(ListNode ** head);
ListNode * push(Vertex data, ListNode *head);
void clearList(ListNode ** head);



#endif

