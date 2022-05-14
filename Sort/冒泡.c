#include"inout.h"
int main()
//  平均time复杂度n(O²)
{	
	int size;
	scanf("%d",&size);
	int num[size];
	in(size,num);
	// bubbling sort
	for (int i = 0; i < size; i++)
	{
		for (int n = 0; n <size-1; n++)
		{
			if(num[n]>num[n+1])
			{
				int temp = num[n];
				num[n] = num[n + 1];
				num[n+1] = temp;
			}
		}
	}

	out(size,num);
}