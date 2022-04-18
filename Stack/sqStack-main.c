#include"sqStack.h"


int main(int argc, char const *argv[])
{
    Stack *niu = (Stack *)malloc(sizeof(Stack));
    int *e;
    InitStack(niu);
    Push(niu, 3);
    Push(niu, 4);
    Push(niu, 5);
    Push(niu, 9);
    Push(niu, 9);
    Push(niu, 900);
    Pop(niu, e);
    printf("pop出的元素是%d", *e);
    ClearStack(niu);
    StackTraverse(niu);
    return 0;
}

