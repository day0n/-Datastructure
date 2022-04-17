#include"BinTree.h"

int CreateTree(nod **p)
{
    int temp;
    scanf("%d", &temp);
    if (temp != 0)
    {
        *p = (nod *)(malloc(sizeof(nod)));
        (*p)->date = temp;
        printf("请输入%d节点的左儿子的date\t", temp);
        CreateTree(&((*p)->ltree));
        printf("请输入%d节点的右儿子的date\t", temp);
        CreateTree(&((*p)->rtree));
    }
    else
    {
        *p = 0;
    }
    return 0;
}

void preTraverse(nod *p)
{
    if (p)
    {
        printf("%d\t", p->date); //最后再来理解一下关于p空不空的问题
        preTraverse(p->ltree);       //似乎这个结构如果被分配了内存里面的指针就会指向null
        preTraverse(p->rtree);
    }
    else
    {
        return;
    }
}
void inTraverse(nod *p)
{
    if (p)
    {
        inTraverse(p->ltree);
        printf("%d\t", p->date);
        inTraverse(p->rtree);
    }
    else
    {
        return;
    }
}
void posTraverse(nod *p)
{
    if (p)
    {
        posTraverse(p->ltree);
        posTraverse(p->rtree);
        printf("%d\t", p->date);
    }
    else
    {
        return;
    }
}

//二叉树的深度
int TreeDeep(nod *T)
{
    int deep = 0;
    int ld = TreeDeep(T->ltree);
    int rd = TreeDeep(T->rtree);
    deep = ld >= rd ? ld + 1 : rd + 1;
    return deep; //函数递归的妙用
}
