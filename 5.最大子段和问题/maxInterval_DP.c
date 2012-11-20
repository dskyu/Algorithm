#include <stdio.h>
#include <stdlib.h>

int maxInterval(int *arr, int left, int right)
{
	int i,sum = 0;
	int tmp = 0;
	for(i=left; i<right; ++i)
	{
		if(tmp > 0) {tmp += arr[i];}
		else        {tmp  = arr[i];}
		if(tmp >sum){sum  = tmp;}
	}
	return sum;
                    
}

int main()
{
    int a[]={-2, 11, -4, 13, -5, -2};
    printf("%d",maxInterval(a,0,5));
    system("pause");
    return 0;
}
