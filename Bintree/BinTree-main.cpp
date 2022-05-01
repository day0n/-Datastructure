#include"BinTree.h"
int main()
{
    nod *p = 0;
    printf("请输入第一个节点的值\t");
    CreateTree(&p);
    // preTraverse(p);
    // printf("\n");
    // inTraverse(p);
    // printf("\n");
    // posTraverse(p);
    // printf("\n");
    // TreeDeep(p);
    SeqTraverse(p);
    return 0;
}

