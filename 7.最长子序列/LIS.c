#include <stdio.h>
#include <stdlib.h>

int LIS(int a[],int la)
{
    int max,i,j;
    int s[100]={0};
    
    s[0]=1;
    for (i=1;i<la;i++)
    {
        max=0;
        for (j=i;j<i;j++) 
        {    
           if (a[j]<a[i] && max<s[j]) max=s[j];
           s[i]=max+1;  
        }
    }   
    max=0;
    for (i=0;i<la;i++)
        if(max<s[i]) max=s[i];
    return max;
}

int main()
{
    int a[]={1,2,3,6,5,7,4,8,6};
    printf ("%d",LIS(a,9));
    system("pause");
    return 0;   
}
