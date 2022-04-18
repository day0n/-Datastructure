#include"sqStack.h"

int InitStack(Stack *S)
{
    S->base = (Type *)malloc(sizeof(Type) * Sizemax); //创建一个大小为Sizemax的数组
    if (S->base == NULL)
    {
        exit(0);
    }
    S->top = S->base;
    S->stacksize = Sizemax;
    printf("该栈的大小为%d\n", S->stacksize);
}

int DestroyStack(Stack *S)
{
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->stacksize = 0;
}

int ClearStack(Stack *S)
{
    S->top = S->base; //该栈仍然可以取到第一个元素的值
}
int StackEmpty(Stack *S)
{
    if (S->top == S->base)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int StackLength(Stack *S)
{
    return (int)(S->top - S->base);
}
int GetTop(Stack *S, Type *e)
{
    e = (--S->top);
}

int Push(Stack *S, Type e)
{
    //栈内存大小不够，扩容操作
    if (S->top - S->base >= S->stacksize) //数组指针相减为数组下标相减，应当对标初始化扩容操作的top=base，且base有值，top无值
    {
        //给base扩容
        S->base = (Type *)realloc(S->base, (Sizemax + Sizeadd) * sizeof(Type));
        S->stacksize = S->stacksize + Sizeadd;
    }

    *(S->top) = e;
    S->top++; //也就是说base指针指向底部，底部不赋值。
}

int Pop(Stack *S, Type *e)
{
    *e = *(--S->top);
}

int StackTraverse(Stack *S)
{
    printf("该栈的大小为%d\n", S->stacksize);
    int i = 0; //求数组下标
    Type *p = S->base;
    while (p < S->top)
    {
        printf("栈的第%d个元素是%d\n", i, *p);
        p++;
        i++;
    }
}
