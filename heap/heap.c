#include<stdio.h>

#define ElementType int
/*数组实现最大堆*/
typedef struct HeapStruct *MaxHeap;  
struct HeapStruct{
    ElementType *Elements;   //存储堆元素的数组
    int Size;                //堆的当前元素个数
    int Capacity;            //堆的最大容量
};

MaxHeap Create(int MaxSize){
    MaxHeap H = malloc(sizeof(struct HeapStruct));
    H->Elements = malloc((MaxSize+1)*sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    //H->Elements[0]  = max;  //哨兵为数组最大值,考虑到函数不便写，我们选择在后面的判断加入对i的判断
    /*"哨兵" ，为堆中所有可能的元素的值，便于以后更快的操作 */
    return H;
}


void Insert(MaxHeap H,ElementType item){
    int i;    
    if(IsFull(H)){
        printf("最大堆已满");
        return ;
    }
    i = ++H->Size;  //将软塑插入到堆的最后一个位置，此时有序性未能得到满足
    //由于在Elements[0]处有个maxelement的哨兵，所以不需要添加i>1的条件判断
    for ( ; H->Elements[i/2]<item&&i>1; i/=2){
        //考虑完全二叉树特性，子节点在数组中的位置等于父节点位置/2
        H->Elements[i] = H->Elements[i/2]; //向下过滤节点
        H->Elements[i] = item;             //将item插入
    }
    
}

//删除策略：把最后一个元素放到根的位置，然后将根删除，最后去让节点的数和子节点进行比较

ElementType DeleteMax(MaxHeap H){
    /*从堆中取出键值为最大的元素，并删除*/
    int Parent ,Child;
    ElementType MaxItem,temp;

    if(H->Size==0){
        printf("max heap is empty");
    return;
    }
    temp = H->Elements[H->Size];  //last value
    H->Size--;

    for (Parent = 1; Parent*2<=H->Size; Parent = Child){
        Child = Parent*2;
        if((Child!=H->Size)&&(H->Elements[Child]<H->Elements[Child+1])){   //有右儿子并且右儿子大
            Child++;
        } // child指向左右结点较大者  

        if(temp >= H->Elements[Child]){
            break;
        }
        else{
            H->Elements[Parent] = H->Elements[Child];
        }
        
    }
    
}


int IsFull(MaxHeap H){
    if(H->Size>=H->Capacity)
    return 1 ;  //表示已经满了
    else
    {
        return 0;
    }
    
}
/*----------- 建造最大堆 -----------*/
void PercDown(MaxHeap H, int p)
{ /* 下滤：将H中以H->Elements[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;

    X = H->Elements[p]; /* 取出根结点存放的值 */
    for (Parent = p; Parent * 2 <= H->Size; Parent = Child)
    {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
            Child++; /* Child指向左右子结点的较大者 */
        if (X >= H->Elements[Child])
            break; /* 找到了合适位置 */
        else       /* 下滤X */
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = X;
}

void BuildHeap(MaxHeap H)
{   /* 调整H->Elements[]中的元素，使满足最大堆的有序性  */
    /* 这里假设所有H->Size个元素已经存在H->Elements[]中 */

    int i;

    /* 从最后一个结点的父节点开始，到根结点1 */
    for (i = H->Size / 2; i > 0; i--)
        PercDown(H, i);
}

//test
int main(int argc, char const *argv[])
{
    
    return 0;
}
