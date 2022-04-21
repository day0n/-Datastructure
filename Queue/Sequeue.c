#include <stdio.h>
#include <stdlib.h>

//该队列是顺序表循环队列

#define Type int
#define MaxSize 3
typedef int Position;
typedef struct QNode
{
    Type *Data;           /* 存储元素的数组 */
    Position Front, Rear; /* 队列的头、尾指针 */
    int Size;
} nod;

nod *Createnod(int Size);
int IsFull(nod *Q);
int IsEmpty(nod *Q);
int IsFull(nod *Q);
int AddQ(nod *Q, Type X);
Type DeleteQ(nod *Q);
int DestroyQueue(nod *Q);
int QueueTraverse(nod *Q);

int main(int argc, char const *argv[])
{
    nod *que = Createnod(MaxSize);
    printf("%d\n", IsEmpty(que));
    AddQ(que, 3);
    AddQ(que, 4);
    AddQ(que, 5);
    DeleteQ(que);
    printf("%d\n", IsEmpty(que));
    QueueTraverse(que);
    return 0;
}

nod *Createnod(int Size)
{
    nod *Q = (nod *)malloc(sizeof(struct QNode));
    Q->Data = (Type *)malloc(Size * sizeof(Type));
    Q->Front = Q->Rear = 0;
    Q->Size = Size;
    return Q;
}

int IsFull(nod *Q)
{
    return ((Q->Rear + 1) % Q->Size == Q->Front);
}

int AddQ(nod *Q, Type X)
{
    if (IsFull(Q))
    {
        printf("队列满,%d无法插入\n", X);
        return 0;
    }
    else
    {
        Q->Rear = (Q->Rear + 1) % Q->Size;
        Q->Data[Q->Rear] = X;
        return 0;
    }
}

int IsEmpty(nod *Q)
{
    return (Q->Front == Q->Rear);
}

Type DeleteQ(nod *Q)
{
    if (IsEmpty(Q))
    {
        printf("队列空");
        return 0;
    }
    else
    {
        Q->Front = (Q->Front + 1) % Q->Size;
        return Q->Data[Q->Front];
    }
}

int DestroyQueue(nod *Q)
{
    if (Q == NULL)
    {
        return 0;
    }

    if (Q->Data)
    {
        free(Q->Data);
    }

    Q->Data = NULL;
    Q->Front = Q->Rear = 0;

    return 0;
}

int QueueTraverse(nod *Q)
{
    int i;

    if (Q->Data == NULL)
    {
        return 0;
    }

    for (i = (Q->Front + 1) % Q->Size; i != (Q->Rear + 1) % Q->Size; i = (i + 1) % Q->Size)
    {
        printf("%d ", Q->Data[i]);
    }

    printf("\n");

    return 1;
}