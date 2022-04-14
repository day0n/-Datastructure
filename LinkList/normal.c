#include"normal.h"
void init(node *L, int n)
{
    L->elem = n;
    for (int i = n - 1; i > 0; i--)
    {
        node *p = (node *)malloc(sizeof(node));
        p->elem = i;
        p->next = NULL;
        temp->next = p;
        temp = p;
    }
    temp = L; //中转指针重新指向表头，方便其他函数使用
}
void printI(node *L, int i)
{
    int k = 0;
    while (1)
    {
        if (k == i)
        {
            printf("第i个元素的值是%d \n", temp->elem);
            temp = L;
            break;
        }
        temp = temp->next;
        k++;
    }
    temp = L; //中转指针重新指向表头，方便其他函数使用
}

void insert(node *L, int i, int e)
{
    int k = 0;
    while (1)
    {
        if (k == i - 1) //将问题转换为向第i-1个元素后插入新的元素e，因为该我的结构没有设置前指针
        {
            node *insert = (node *)malloc(sizeof(node)); //插入的结构
            insert->elem = e;
            insert->next = temp->next;
            temp->next = insert;
            temp = insert; //可要可不要
            break;
        }
        temp = temp->next;
        k++;
    }
    temp = L; //中转指针重新指向表头，方便其他函数使用
}

int delete (node *L, int i)
{

    int k = 1, e;
    while (1)
    {
        if (k == i - 1) //将问题转换为向删除第i-1个元素的后一个元素也就是第i个元素
        {
            e = temp->next->elem;
            node *keep = temp->next; //用于释放内存
            temp->next = temp->next->next;
            free(keep);
            break;
        }
        temp = temp->next;
        k++;
    }
    temp = L; //中转指针重新指向表头，方便其他函数使用
    return e;
}

void printlength(node *L)
{

    int i = 1;
    while (temp->next != NULL)
    {
        i++;
        temp = temp->next;
    }
    printf("该链表的长度是%d\n", i);
    temp = L; //中转指针重新指向表头，方便其他函数使用
}

void printall(node *L)
{
    for (; temp->next; temp = temp->next)
    {
        printf("%d\t", temp->elem); //
    }
}
