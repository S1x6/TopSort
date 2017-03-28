#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h";

#define ERROR_WRONG_VERTEX_NUM 1;
#define ERROR_WRONG_EDGE_NUM 2;

int main()
{
	int vert_num, edge_num;

	FILE * fin = fopen("in.txt", "w");
	fscanf(fin, "%d" ,&vert_num);
	fscanf(fin, "%d", &edge_num);
	if (checkInput(vert_num, edge_num))
		return 0;

	return 0;
}

int checkInput(int vert, int edge)
{
	if (vert < 0 || vert > 1000)
		return ERROR_WRONG_VERTEX_NUM;
	if (edge < 0 || edge > vert*(vert + 1) / 2)
		return ERROR_WRONG_EDGE_NUM;
	return 0;
}