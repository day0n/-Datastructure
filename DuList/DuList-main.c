#include"DuList.h"

int main(int argc, char const *argv[])
{
    //测试函数
    node *p = NULL;
    p = InitList();
    ListInsert(p, 1, 3);
    ListInsert(p, 2, 4);
    ListInsert(p, 3, 2);
    ListInsert(p, 4, 9);
    ListInsert(p, 5, 0);
    // ClearList(p);//此处会产生野指针问题，可将函数参数改变为二级指针解决
    ListEmpty(p);
    int *k;
    *k = 0;
    ListDelete(p, 2, k);
    printf("length is %d \n", ListLength(p));
    Listprint(p); //我们插入使用的是前置插入
    return 0;
}
