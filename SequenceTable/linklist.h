#include <stdio.h>
#include <stdlib.h> //malloc()、exit()
typedef struct List
{
    int *head;  //”动态数组“
    int length; //记录当前顺序表长度
    int size;   //记录顺序表分配的存储容量

} list;

list InitList(int size1);
void DestroyList(list L);
void ClearEmpty(list L);
int ListEmpty(list L);
int ListLength(list L);
int *GetElem(list L, int i, int *e);
int LocateElem(list L, int e, int (*compare)(int a, int b));
int compare(int a, int b);
void PriorElem();
list listcombine(list a, list b);1
