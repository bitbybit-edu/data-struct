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
    graphArray->edge[0][5] = 1;

    graphArray->edge[1][2] = 1;
    graphArray->edge[1][8] = 1;
    graphArray->edge[1][6] = 1;

    graphArray->edge[2][3] = 1;
    graphArray->edge[2][8] = 1;

    graphArray->edge[3][4] = 1;
    graphArray->edge[3][7] = 1;
    graphArray->edge[3][6] = 1;
    graphArray->edge[3][8] = 1;

    graphArray->edge[4][5] = 1;
    graphArray->edge[4][7] = 1;

    graphArray->edge[5][6] = 1;

    graphArray->edge[6][7] = 1;
}

int hasTraversedVertex[MAX_VERTEX_NUM];

void depthFirstSearch(GraphArray graphArray, int start) 
{
    if (hasTraversedVertex[start] == 0)
    {
        hasTraversedVertex[start] = 1;
        printf("%c ",graphArray.vertex[start]);
        for (size_t i = 0; i < graphArray.edgeNum; i++)
        {
            if (graphArray.edge[start][i] == 1 && hasTraversedVertex[i] == 0)
            {
                depthFirstSearch(graphArray, i);
            }
            
        }
        
    }
}

/**
 * 深度优先遍历
 */
void depthPriorityTraverse(GraphArray graphArray)
{
    
    // 初始都未访问过
    for (size_t i = 0; i < graphArray.vertexNum; i++)
    {
        hasTraversedVertex[i] = 0;
    }

    int start = 8;
    depthFirstSearch(graphArray, start);
}



int main()
{
    GraphArray graphArray;

    // 初始化邻接矩阵
    initGraphArray(&graphArray);

    // 打印邻接矩阵
    printGraphArray(graphArray);

    // 深度优先遍历
    depthPriorityTraverse(graphArray);
}
