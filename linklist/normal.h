#ifndef NORMAL_H
#define NORMAL_H
#include <stdio.h>
#include <stdlib.h>
#define Type int
typedef struct Node
{
    struct Node *next;
    Type elem;
} node;
node *temp = NULL; //全局变量，方便使用
node *L = NULL;
void init(node *L, int n);
void printI(node *L, int i);
void insert(node *L, int i, int e);
int delete (node *L, int i);
void printall(node *L);
void printlength(node *L);
#endif