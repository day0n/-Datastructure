#include "inout.h"
int main(int argc, char const *argv[])
{
    int size;
    scanf("%d", &size);
    int num[size];
    in(size, num);

    for (int i = 1; i < size; i++)
    {
        for (int n = i - 1; n >= 0; n--)
        {
            if (num[n + 1] < num[n])
            {
                int temp = num[n];
                num[n] = num[n + 1];
                num[n + 1] = temp;
            }
            else
            {
                break;
            }
        }
    }

    out(size, num);
    return 0;
}
