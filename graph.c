#include "graph.h"


Vertex * pop(ListNode ** head)
{
	ListNode * ln = *head;
	Vertex * res = ln->value;
	*head = ln->next;
	free(ln);
	return res;
}

ListNode * push(Vertex * data, ListNode *head)
{
	ListNode * newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->value = data;
	newNode->next = head;
	return newNode;
}

ListNode * ListNodeC(Vertex * value)
{
    ListNode * list = (ListNode*)malloc(sizeof(ListNode));
    list->value = value;
    list->next = NULL;
    return list;
}

Vertex * VertexC(int num, char color, ListNode * list_to) {
    Vertex * v = (Vertex *)malloc(sizeof(Vertex));
    v->color = color;
    v->list_to = NULL;
    v->num = num;
    return v;
}

Vertex ** constructVertex(int vert_num)
{
    Vertex ** v = (Vertex **)malloc(sizeof(Vertex *) * vert_num);
    for (int i = 0; i < vert_num; i++) {
        ListNode * l = NULL;
        v[i] = VertexC(i, COLOR_WHITE, l);
    }
    return v;
}

void writeSortedGraph(FILE * fout, Vertex ** v, int v_num)
{
    int i = 0;
    ListNode * stack = NULL;
    for (; i < v_num; i++){
        processVertex(fout, v[i], &stack);
    }
    printStack(fout, stack);
}

void printStack(FILE * fout, ListNode *stack)
{
    while (stack){
        Vertex *tmp = pop(&stack);
        fprintf(fout, "%d ", tmp->num+1);
        destructVertex(tmp);
    }
}

void processVertex(FILE * fout,Vertex * v, ListNode ** stack)
{
    if (v->color == COLOR_GRAY){
        fprintf(fout, "impossible to sort");
        exit(0);
    }
    if (v->color != COLOR_WHITE) {
        return;
    }

    if (v->list_to == NULL){
        v->color = COLOR_BLACK;
        *stack = push(v, *stack);
        return;
    }
    v->color = COLOR_GRAY;
    while (v->list_to != NULL) {
        processVertex(fout, v->list_to->value, stack);
        v->list_to = v->list_to->next;
    }
    v->color = COLOR_BLACK;
    *stack = push(v, *stack);
}

void destructVertex(Vertex * v)
{
    if (v->list_to != NULL)
        destructList(v->list_to);
    free(v);
}

void destructList(ListNode * l)
{
    if (l->next!=NULL)
        destructList(l->next);
    free(l);
}


