#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "graph.h"
#define ERROR_WRONG_VERTEX_NUM 1
#define ERROR_WRONG_EDGE_NUM 2
#define ERROR_WRONG_LINES_NUM 3

int checkInput(FILE * fout, int vert, int edge);

int main()
{
	int vert_num = -1, edge_num = -1;
    int i, ver1, ver2;
	FILE * fin = fopen("in.txt", "r");
	FILE * fout = fopen("out.txt", "w");
	if (!fscanf(fin, "%d" ,&vert_num)){
        printf("bad number of lines");
        return 0;
	}
	if (!fscanf(fin, "%d", &edge_num)){
        printf("bad number of lines");
        return 0;
	}
	if (checkInput(fout, vert_num, edge_num))
		return 0;

    Vertex ** vert_array = constructVertex(vert_num);

    for (i = 0; i < edge_num; i++)
    {
        if (fscanf(fin, "%d", &ver1) == -1 || fscanf(fin, "%d", &ver2) == -1) {
            fprintf(fout, "bad number of lines");
            return 0;
        }
        if (ver1 > vert_num || ver1 < 0 || ver2 < 0 || ver2 > vert_num) {
            fprintf(fout, "bad vertex");
            return 0;
        }
        vert_array[ver1-1]->list_to = push(vert_array[ver2-1], vert_array[ver1-1]->list_to);
    }
    writeSortedGraph(fout, vert_array, vert_num);
	return 0;
}

int checkInput(FILE * fout, int vert, int edge)
{
    if (vert == -1 || edge == -1){
        fprintf(fout, "bad number of lines");
		return ERROR_WRONG_LINES_NUM;
    }
	if (vert < 0 || vert > 1000){
        fprintf(fout, "bad number of vertices");
		return ERROR_WRONG_VERTEX_NUM;
	}
	if (edge < 0 || edge > vert*(vert + 1) / 2){
        fprintf(fout, "bad number of edges");
		return ERROR_WRONG_EDGE_NUM;
	}
	return 0;
}
