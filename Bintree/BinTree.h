#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int date;
    struct Node *ltree;
    struct Node *rtree;
} nod;
int CreateTree(nod **p);
void preTraverse(nod *p);
void inTraverse(nod *p);
void posTraverse(nod *p);
int TreeDeep(nod *p);
void SeqTraverse(nod *p);