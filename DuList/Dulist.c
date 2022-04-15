#include"DuList.h"
/*
 * 初始化
 */
node *InitList()
{
    node *head = (node *)malloc(sizeof(node));
    if (!head)
    {
        exit(0);
    }
    head->next = head; //指向自身很重要，这样当链表是只有一个位置的时候能将链表串起来。
    head->prior = head;
    head->data = 9999999;
    return head;
}

/*
 * 销毁(结构)
 *
 * 释放双向循环链表所占内存，头结点也释放。
 */
void DestroyList(node *L)
{
    ClearList(L);
    free(L);
}

/*
 * 置空(内容)
 *
 * 这里需要释放双向循环链表中非头结点处的空间。
 */
// 该函数结束后头指针是一个野指针，应当指向NULL,可采用二级指针解决
void ClearList(node *L)
{
    node *p = L;
    p = p->next;
    while (p != L)
    {
        p = p->next;
        free(p->prior);
    }
}

/*
 * 判空
 *
 * 判断双向循环链表中是否包含有效数据。
 *
 * 返回值：
 * 1 : 双向循环链表为空
 * 0: 双向循环链表不为空
 */
int ListEmpty(node *L)
{
    if (L != NULL && L->next == L && L->prior == L)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
 * 计数
 *
 * 返回双向循环链表包含的有效元素的数量。
 */
int ListLength(node *L)
{
    node *p = L;
    int count = 0;
    p = p->next; // skip首元结点
    while (p != L)
    {
        count++;
        p = p->next;
    }
    return count;
}

/*
 * 取值
 *
 * 获取双向循环链表中第i个元素，将其存储到e中。
 * 如果可以找到，返回OK，否则，返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数，但这不符合编码的通用约定。
 * 通常，i的含义应该指索引，即从0开始计数。
 * 使用该函数时应当传入e结构体的地址。
 */
int GetElem(node *L, int i, ElemType e)
{
    e = (*GetElemP(L, i)).data;
    if (e)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
 * 前驱
 *
 * 获取元素cur_e的前驱，
 * 如果存在，将其存储到pre_e中，返回OK，
 * 如果不存在，则返回ERROR。
 */
int PriorElem(node *L, ElemType cur_e, ElemType *pre_e)
{
    node *p = L;
    if (L == NULL || L->next == L || L->prior == L)
    {
        return 0;
    }

    // 指向第1个元素
    p = L->next;

    // 第1个元素没有前驱
    if (p->data == cur_e)
    {
        return 0;
    }

    // 指向第2个元素
    p = p->next;

    // 从第2个元素开始，查找cur_e的位置
    while (p != L && p->data != cur_e)
    {
        p = p->next;
    }

    // 如果没找到元素cur_e，查找失败，返回ERROR
    if (p == L)
    {
        return 0;
    }

    *pre_e = p->prior->data;

    return 1;
}

/*
 * 后继
 *
 * 获取元素cur_e的后继，
 * 如果存在，将其存储到next_e中，返回OK，
 * 如果不存在，则返回ERROR。
 */
int NextElem(node *L, ElemType cur_e, ElemType *next_e)
{
    node *p = L;
    if (L == NULL || L->next == L || L->prior == L)
    {
        return 0;
    }

    // 指向第1个元素
    p = L->next;

    // 从第1个元素开始，查找cur_e的位置，且保证该结点的后继不为L
    while (p->next != L && p->data != cur_e)
    {
        p = p->next;
    }

    // 如果没找到cur_e，或者找到了，但它没有后继，均返回ERROR
    if (p->next == L)
    {
        return 0;
    }

    *next_e = p->next->data;

    return 1;
}

/*
 * ████████ 算法2.18 ████████
 *
 * 插入
 *
 * 向双向循环链表第i个位置上插入e，插入成功则返回OK，否则返回ERROR。
 *1  2  3  4  5
 *      |
 *      |
 *1  2  e  3  4  5
 * 教材中i的含义是元素位置，从1开始计数
 */
int ListInsert(node *L, int i, ElemType e)
{

    if (L == NULL)
    {
        return 0;
    }
    node *p = GetElemP(L, i);

    if (p == NULL)
    {
        printf("  error 256  ");
        return 0;
    }

    node *insert = (node *)malloc(sizeof(node));
    if (insert == NULL)
    {
        exit(0);
    }
    insert->data = e;
    insert->prior = p->prior;
    insert->next = p;
    p->prior->next = insert;
    p->prior = insert;
    return 0;
}

/*
 * ████████ 算法2.19 ████████
 *
 * 删除
 *
 * 删除双向循环链表第i个位置上的元素，并将被删除元素存储到e中。
 * 删除成功则返回OK，否则返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数
 */
int ListDelete(node *L, int i, ElemType *e)
{
    node *p = L;
    // 确保双向循环链表存在
    if (L == NULL || L->next == L || L->prior == L)
    {
        return 0;
    }

    // 查找第i个结点位置（引用）
    if ((p = GetElemP(L, i)) == NULL)
    {
        return 0;
    }

    // 如果p==L，说明待删除元素是第len+1个元素，不合规
    if (p == L)
    {
        return 0;
    }

    *e = p->data;

    // 移除p结点
    p->prior->next = p->next;
    p->next->prior = p->prior;

    free(p);

    return 1;
}

/*
 * 获取一个指针指向循环链表L上第i个元素
 *
 * 2.假设链表长度为len，且需要获取第len+1个元素的引用时，由于这里是循环链表，所以返回的是头结点
 * 此处不考虑数据有错的情况
 */
node *GetElemP(node *head, int i)
{

    node *p = head;
    if (head == NULL)
    {
        return NULL;
    }

    // 位置不合规
    if (i < 1)
    {
        return NULL;
    }

    if (i == 1)
    {
        return head;
    }
    int k = 1;

    while (p->next != head && k < i)
    {
        p = p->next;
        k++;
    }
    // 恰好找到第i个元素
    if (k == i)
    {
        return p;
    }

    // 至此，说明p->next==L，此时需要判断i是否过大
    if (k + 1 < i)
    {
        printf("  error 358");
        return NULL;
    }

    // 至此，说明需要在len+1的位置上插入元素
    return p;
}

void Listprint(node *head)
{
    node *p = head;
    if (head == NULL)
    {
        return;
    }
    p = p->next; // skip 头结点
    int i = 2;
    while (p != head)
    {
        printf("%d ", p->data);
        p = p->next;
        i++;
    }
}
