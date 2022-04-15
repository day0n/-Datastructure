#include <stdio.h>
#include <stdlib.h>

/* 双向循环链表元素类型定义 */
#define ElemType int

/*
 * 双向循环链表结构
 *
 * 注：这里的双向循环链表存在头结点
 */
// 该链表具有首元结点，需要将其跳过，该首元结点的值是9999999
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior; // 前驱
    struct DuLNode *next;  // 后继
} node;

node *InitList();
void DestroyList(node *L);
void ClearList(node *L);
int ListEmpty(node *L);
int ListLength(node *L);
int GetElem(node *L, int i, ElemType e);
int PriorElem(node *L, ElemType cur_e, ElemType *pre_e);
int NextElem(node *L, ElemType cur_e, ElemType *next_e);
int ListInsert(node *L, int i, ElemType e);
int ListDelete(node *L, int i, ElemType *e);
node *GetElemP(node *head, int i);
void Listprint(node *head);