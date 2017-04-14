#ifndef GRAPH_H
#define GRAPH_H

#include "stdio.h"
#include "malloc.h"

#define COLOR_WHITE 0
#define COLOR_GRAY 1
#define COLOR_BLACK 2

/**
*	Структура, определяющая вершины графа
*	Поля:	int num - номер вершины
*		char color - цвет вершины (статус)
*		ListNode list_to - список смежных вершин 
*/
typedef struct _Vertex {
	int num;
	char color;
	struct _ListNode * list_to;
} Vertex;

/**
*	Структура, определяющая список, содержащий вершины графа
*	Поля:	Vertex * value - указатель на хранимую вершину
		ListNode * next - указатель на следующий элемент списка
*/
typedef struct _ListNode {
    	struct _Vertex * value;
	struct _ListNode * next;
} ListNode;
Vertex * pop(ListNode ** head);
ListNode * push(Vertex * data, ListNode *head);

/**
*	Конструктор элемента списка с заданным значением
*	Аргументы:	Vertex * vertex - указатель на вершину-значение
*	Возвращает: указатель на сформированный элемент списка
*/
ListNode * ListNodeC(Vertex * value);

/**
*	Конструктор массива всех вершин графа
*	Аргументы: int vert_num - количество вершин в графе
*	Возвращает: указатель на массив вершин
*/
Vertex ** constructVertex(int vert_num);

/**
*	Выводит в поток номера вершин графа в топологически отсортированном порядке
*	Аргументы: FILE* fout - поток вывода
*		   Vertex ** v - массив вершин графа
*		   int v_num - количество вершин
*/
void writeSortedGraph(FILE * fout, Vertex ** v, int v_num);

/*private*/ void printStack(FILE * fout, ListNode *stack);

/*private*/ void processVertex(FILE * fout,Vertex * v, ListNode ** stack);

/**
*	Конструктор вершины
*	Аргументы: int num - номер вершины
*		   char color - цвет вершины
*		   ListNode * list_to - список смежных вершин
*	Возвращает: указатель на созданную вершину
*/
Vertex * VertexC(int num, char color, ListNode * list_to);

/* Деструктор вершины*/
void destructVertex(Vertex * v);
/* Деструктор списка*/
void destructList(ListNode * l);

#endif
