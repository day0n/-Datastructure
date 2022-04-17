#include"linklist.h"
//创建一个空的线性表
list InitList(int size1)
{
    list t;
    t.head = (int *)malloc(size1 * sizeof(int));
    if (!t.head) //如果malloc申请失败会返回null
    {
        printf("初始化失败");
        exit(0);
    }
    t.size = size1;
    t.length = 0; // 重要，若果不赋值，length就会以一个不确定的值开始
    return t;
}

//如果线性表以已存在，则销毁线性表
void DestroyList(list L)
{
    free(L.head);
    L.head = NULL; //此时应当将head指向null，不然此时的head就是一个野指针
    // free释放了内存，此时只是将内存还给了系统，但是head仍指向该内存，且内存内容仍然存在
}

//如果线性表已存在，将该表重置为空表，我的理解是把表中的数组所有值重置为0；
void ClearEmpty(list L)
{
    //从第一个开始向最后一个重置
    for (int i = 0; i < L.length; i++)
    {
        L.head[i] = 0;
    }

    L.length = 0;
}

//在表存在下，如果表为空表则返回1，否则返回0
//判断是否为空我采用判断length是否为0即可
int ListEmpty(list L)
{
    if (L.length)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//若线性表存在，返回L中的数据元素个数
int ListLength(list L)
{
    return L.length;
}

//线性表已存在，用e返回L中第i个数据元素的值
int *GetElem(list L, int i, int *e)
{
    *e = L.head[i - 1];
    return e;
}

//线性表已存在，使用compare判定数据元素，返回L中第一个与e的满足关系compare的数据元素的位序。若该元素不存在，则返回0
//该处应该要使用函数指针，首先需要明确的是，在C语言中，函数名就是函数的首地址，所以将函数作为函数参数的思路是将函数地址传入，形参是一个指针类型的变量，形参的基类型为函数原型。
int LocateElem(list L, int e, int (*compare)(int a, int b))
{
    for (int i = 0; i < L.length; i++)
    {
        if (compare(e, L.head[i]))
        {
            return i;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

//我把compare函数定义为判定两数是否相等
int compare(int a, int b)
{
    if (a == b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//
void PriorElem()
{
}

void print(list L)
{
    printf("list内容：");
    for (int i = 0; i < L.length; i++)
    {
        printf(" %d", L.head[i]);
    }
}

list listcombine(list a, list b)
{
    list t;
    //内存不够，扩容
    if (a.size < a.length + b.length)
    {
        a.head = (int *)realloc(t.head, (a.length + b.length - a.size) * sizeof(int));
        a.size = a.length + b.length;
    }
    for (int i = a.length; i < a.size; i++)
    {
        a.head[i] = b.head[i - a.length];
        a.length++;
    }
    t = b;
    return t;
}
