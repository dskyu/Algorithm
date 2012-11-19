#include <stdio.h>
#include <stdlib.h>
int findNo_k(int a[],int low,int high,int k)
{
    int i=low;
    int j=high;
    int temp=a[low];
    
    while (i<j)
    {
        while (i<j && a[j] >= temp) j--;
        if (i<j) a[i++] = a[j];
        while (i<j && a[i] <= temp) i++;
        if (i<j)  a[j--] = a[i];
    }
    a[i] = temp;
    
    if (i==k-1) printf("%d ", a[i]);
    else if(i<k-1) findNo_k(a,i+1,high,k-i+1);
    else if(i>k-1) findNo_k(a,low,i-1,k);
    
    
    
  //  if (low<i) findNo_k(a,low,i-1,k);
  //  if (high>i) findNo_k(a,i+1,high,k);
}

int main()
{
    int a[] = {32,543,5,43,65,43,2,42,47,41};
    int i;
    printf("%d \n",findNo_k(a,0,9,1));
    for (i = 0;i<10;i++)
       printf("%d ",a[i]);
    
    system("pause");
    return 0;
}
