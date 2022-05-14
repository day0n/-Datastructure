#include "inout.h"
int main(int argc, char const *argv[])
{
    int size = 5;
    int num[5];
    in(size,num);
    for (int i = 0; i < size-1; i++)
    {
        for (int n =  i+1; n < size; n++)
        {
            if (num[i] > num[n])
            {
            int temp = num[n];
            num[n] = num[i];
            num[i] = temp;
            }
        }
               
    }
    out(size,num);
    return 0;
}
