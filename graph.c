#include "graph.h"

struct _Vertex {
	int num;
	int parent;
	char color;
};

struct _Edge {
	Vertex from;
	Vertex to;
};

struct _ListNode {
	Vertex value;
	struct ListNode * next;
};

Vertex pop(ListNode ** head)
{
	ListNode * ln = *head;
	Vertex res = ln->value;
	*head = ln->next;
	free(ln);
	return res;
}

ListNode * push(Vertex data, ListNode *head)
{
	ListNode * newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->value = data;
	newNode->next = head;
	return newNode;
}

void clearList(ListNode ** head)
{
	if (*head != NULL) {
		pop(head);
		clearList(head);
	}
}
