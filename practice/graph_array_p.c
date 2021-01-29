#include <stdio.h>

// 顶点数量
#define MAX_VERTEX_NUM 9

typedef struct
{
    // 顶点表
    char vertex[MAX_VERTEX_NUM];

    // 邻接矩阵边表
    int edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

    // 顶点数
    int vertexNum;

    // 边数
    int edgeNum;

} GraphArray;

/**
 * 打印邻接矩阵 
 */
void printGraphArray(GraphArray graphArray)
{
    for (int i = 0; i < graphArray.vertexNum; i++)
    {
        for (int j = 0; j < graphArray.vertexNum; j++)
        {
            printf("%d ", graphArray.edge[i][j]);
        }
        printf("    %d\n", i);
    }
}

/**
 * 初始化邻接矩阵
 */
void initGraphArray(GraphArray *graphArray)
{
    graphArray->vertexNum = 9;
    graphArray->edgeNum = 15;

    graphArray->vertex[0] = 'A';
    graphArray->vertex[1] = 'B';
    graphArray->vertex[2] = 'C';
    graphArray->vertex[3] = 'D';
    graphArray->vertex[4] = 'E';
    graphArray->vertex[5] = 'F';
    graphArray->vertex[6] = 'G';
    graphArray->vertex[7] = 'H';
    graphArray->vertex[8] = 'I';

    for (int i = 0; i < graphArray->vertexNum; i++)
    {
        for (int j = 0; j < graphArray->vertexNum; j++)
        {
            graphArray->edge[i][j] = 0;
        }
    }

    graphArray->edge[0][1] = 1;
}

int main()
{
    GraphArray graphArray;

    // 初始化邻接矩阵
    initGraphArray(&graphArray);

    // 打印邻接矩阵
    printGraphArray(graphArray);
}
