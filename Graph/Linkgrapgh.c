#include <bits/stdc++.h>
using namespace std;

//注意，我使用的下标是0开始，输入时候第一个节点的下标是0；且数据是字符

//输入示例
// 3 3 0 1 3 0 2 4 1 2 5 n i u

/* 图的邻接表表示法 */
//有向图
#define MaxVertexNum 100 /* 最大顶点数设为100 */
typedef int Vertex;      /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;  /* 边的权值设为整型 */
typedef char DataType;   /* 顶点存储的数据类型设为字符型 */

//这里边的作用是在insert边的时候作为一个参数传入insert函数中来方便取值，用完就抛弃
/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex V1, V2;     /* 有向边<V1, V2> */
    WeightType Weight; /* 权重 */
};
typedef PtrToENode Edge;

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;        /* 邻接点下标 */
    WeightType Weight;  /* 边权重 */
    PtrToAdjVNode Next; /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode
{
    PtrToAdjVNode FirstEdge; /* 边表头指针 */
    DataType Data;           /* 存顶点的数据 */
    /* 注意：很多情况下，顶点无数据，此时Data可以不用出现 */
} AdjList[MaxVertexNum]; /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;    /* 顶点数 */
    int Ne;    /* 边数   */
    AdjList G; /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

LGraph CreateGraph(int VertexNum);
void InsertEdge(LGraph Graph, Edge E);
LGraph BuildGraph();
void Visit(Vertex V);
void DFS(LGraph Graph, Vertex V, void (*Visit)(Vertex));
void BFS(LGraph Graph, Vertex valloc);

int *Visited;
int main(int argc, char const *argv[])
{
    LGraph a = BuildGraph();

    Visited = (int *)malloc(a->Nv * sizeof(int)); //创建一个数组。这样创建可以达到全局访问的目的
    for (int i = 0; i < a->Nv; i++)
    {
        Visited[i] = 0;
    }
    // DFS(a, 0, Visit);
    BFS(a, 0);
    return 0;
}

//初始化结构数组
LGraph CreateGraph(int VertexNum)
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
    Vertex V;
    LGraph Graph;

    Graph = (LGraph)malloc(sizeof(struct GNode)); /* 建立图 */
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* 初始化邻接表头指针 */
    /* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
    for (V = 0; V < Graph->Nv; V++)
        Graph->G[V].FirstEdge = NULL;

    return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;

    /* 插入边 <V1, V2> */
    /* 为V2建立新的邻接点 */
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;       //赋值下标
    NewNode->Weight = E->Weight; // 取值权重
    /* 将V2插入V1的表头 */
    NewNode->Next = Graph->G[E->V1].FirstEdge; //边表头指针在此时指向NULL，也就是让next等于NULL
    Graph->G[E->V1].FirstEdge = NewNode;       //该插入法是从表头的第一个边中间插，不是从尾部插

    /* 若是无向图，还要插入边 <V2, V1> */
    /* 为V1建立新的邻接点 */
    // NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    // NewNode->AdjV = E->V1;
    // NewNode->Weight = E->Weight;
    // /* 将V1插入V2的表头 */
    // NewNode->Next = Graph->G[E->V2].FirstEdge;
    // Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    printf("输入顶点个数\n");
    scanf("%d", &Nv);        /* 读入顶点个数 */
    Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */
    printf("输入边数\n");
    scanf("%d", &(Graph->Ne)); /* 读入边数 */
    if (Graph->Ne != 0)
    {                                           /* 如果有边 */
        E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
        /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
        for (i = 0; i < Graph->Ne; i++)
        {
            printf("分别输入起点 终点 权重\n");
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            /* 注意：如果权重不是整型，Weight的读入格式要改 */
            InsertEdge(Graph, E);
        }
    }

    /* 如果顶点有数据的话，读入数据 */

    for (V = 0; V < Graph->Nv; V++)
    {
        printf("输入第%d个顶点数据\n", V + 1);
        scanf(" %c", &(Graph->G[V].Data));
    }

    return Graph;
}

/* 邻接表存储的图 - DFS */

void Visit(Vertex V)
{
    printf("正在访问顶点%d\n", V);
}

/* Visited[]为全局变量，已经初始化为false */
void DFS(LGraph Graph, Vertex V, void (*Visit)(Vertex))
{ /* 以V为出发点对邻接表存储的图Graph进行DFS搜索 */
    PtrToAdjVNode W;

    Visit(V); /* 访问第V个顶点 */

    Visited[V] = 1; /* 标记V已访问 */

    //节点的存储是字符
    printf("该点数据(字符)是%c\n", (Graph->G[V]).Data);
    for (W = Graph->G[V].FirstEdge; W; W = W->Next)
    {
        // printf("niu");
        /* 对V的每个邻接点W->AdjV */

        if (Visited[W->AdjV] == 0) /* 若W->AdjV未被访问 */
        {
            // printf("niu");
            DFS(Graph, W->AdjV, Visit); /* 则递归访问之 */
        }
        // printf("niu");
    }
}
//从链式邻接表的组成方式去思考怎么写

void BFS(LGraph Graph, Vertex V)
{
    // LGraph是一个图的总的存储，是一个指针
    queue<int> que; //此处队列只需要下标即可所以使用int的队列
    que.push(V);
    // Visited[V] = 1;
    while (!que.empty()) // 0则是true，1是false
    {
        V = que.front();
        PtrToAdjVNode temp = (PtrToAdjVNode)malloc(sizeof(PtrToAdjVNode));
        //定义一个邻节点类型做中转指针，用来将firstEdge中转指向next节点，类似链表思想
        //注意我们的头结点类型和邻结点类型不是相同的
        temp = Graph->G[V].FirstEdge;
        while (temp)
        {
            if (Visited[temp->AdjV] == 0) //表示没有访问过
            {
                que.push(temp->AdjV);
            }
            temp = temp->Next;
        }
        que.pop();
        cout << V << "正在被访问---->"
             << "他的数据是" << Graph->G[V].Data << "\n";
        Visited[V] = 1; //表示访问过了
    }
}