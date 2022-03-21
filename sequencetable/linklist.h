#ifndef LINKLIST_H 
#define LINKLIST_H 

#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 10 /* 线性表存储空间的初始分配量 */
#define LIST_INCREMENT 2  /* 线性表存储空间的分配增量 */
#define ElemType int
#define TRUE 1
#define FALSE 0 

typedef struct
{
    ElemType *elem; /* 存储空间基址 */
    int length;     /* 当前长度 */
    int listsize;   /* 当前分配的存储容量(以sizeof(ElemType)为单位) */
} SqList;

void InitList(SqList *L);
void DestroyList(SqList *L);
void ClearList(SqList *L);
int ListEmpty(SqList L);
int ListLength(SqList L);
int GetElem(SqList L, int i, ElemType *e);
int LocateElem(SqList L, ElemType e, int (*compare)(ElemType, ElemType));
int PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);
int NextElem(SqList L, ElemType cur_e, ElemType *next_e);
int ListInsert(SqList *L, int i, ElemType e) ;
int ListDelete(SqList *L, int i, ElemType *e);
void ListTraverse(SqList L, void (*vi)(ElemType *));

#endif