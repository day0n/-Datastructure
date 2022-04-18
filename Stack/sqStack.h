#ifndef SQSTACK_H
#define SQSTACK_H

#include <stdio.h>
#include <stdlib.h>

#define Sizemax 10 // 顺序栈存储空间的初始分配量
#define Sizeadd 5  // 顺序栈存储空间的分配增量

/* 顺序栈元素类型定义 */
typedef int Type;

// 顺序栈元素结构
typedef struct
{
    Type *base;    // 栈底指针
    Type *top;     // 栈顶指针
    int stacksize; // 当前已分配的存储空间，以元素为单位
} Stack;

/*
 * 初始化
 *
 * 构造一个空栈。
 */
int InitStack(Stack *S);

/*
 * 销毁(结构)
 *
 * 释放顺序栈所占内存。
 */
int DestroyStack(Stack *S);

/*
 * 置空(内容)
 *
 * 只是清理顺序栈中存储的数据，不释放顺序栈所占内存。
 */
int ClearStack(Stack *S);

/*
 * 判空
 *
 * 判断顺序栈中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 顺序栈为空
 * FALSE: 顺序栈不为空
 */
int StackEmpty(Stack *S);

/*
 * 计数
 *
 * 返回顺序栈包含的有效元素的数量。
 */
int StackLength(Stack *S);

/*
 * 取值
 *
 * 返回栈顶元素，并用e接收。
 */
int GetTop(Stack *S, Type *e);

/*
 * 入栈
 *
 * 将元素e压入到栈顶。
 */
int Push(Stack *S, Type e);

/*
 * 出栈
 *
 * 将栈顶元素弹出，并用e接收。
 */
int Pop(Stack *S, Type *e);

/*
 * 遍历栈的值
 */
int StackTraverse(Stack *S);

#endif