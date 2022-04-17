#include"linklist.h"

int main(int argc, char const *argv[])
{

    list a = InitList(5);

    for (int i = 0; i < a.size; i++)
    {
        a.head[i] = i;
        a.length++;
    }
    print(a);
}
