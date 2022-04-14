
#include"normal.h"
int main()
{
    temp = (node *)malloc(sizeof(node));
    L = temp;
    init(L, 5);
    printI(L, 0);
    insert(L, 2, 100);
    printf("删除元素的值是%d\n",delete(L,3));
    printlength(L);
}
