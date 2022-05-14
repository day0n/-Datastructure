#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int low, int mid, int high)
{
    int i, k;
    int *tmp = (int *)malloc((high - low + 1) * sizeof(int));
    //申请空间，使其大小为两个
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;
    for (k = 0; left_low <= left_high && right_low <= right_high; k++)
    { // 比较两个指针所指向的元素
        if (arr[left_low] <= arr[right_low])
        {
            tmp[k] = arr[left_low++];
        }
        else
        {
            tmp[k] = arr[right_low++];
        }
    }
    if (left_low <= left_high)
    { //若第一个序列有剩余，直接复制出来粘到合并序列尾
        // memcpy(tmp+k, arr+left_low, (left_high-left_low+l)*sizeof(int));
        for (i = left_low; i <= left_high; i++)
            tmp[k++] = arr[i];
    }
    if (right_low <= right_high)
    {
        //若第二个序列有剩余，直接复制出来粘到合并序列尾
        // memcpy(tmp+k, arr+right_low, (right_high-right_low+1)*sizeof(int));
        for (i = right_low; i <= right_high; i++)
            tmp[k++] = arr[i];
    }
    for (i = 0; i < high - low + 1; i++)
        arr[low + i] = tmp[i];
    free(tmp);
    return;
}

void mergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);

        merge(A, low, mid, high);
    }

    return;
}
int main()
{
    int arraysize = 7;
    int array[7] = {9,12,4,0,10,98,23};
    int  low =0,high = arraysize - 1;

    mergeSort(array,low,high);

    for (int i = 0; i < arraysize; i++)
    {
        printf("%d  ",array[i]);
    }
    return 0;
}

