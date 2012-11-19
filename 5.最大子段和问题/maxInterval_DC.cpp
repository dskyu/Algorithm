#include <stdio.h>
#include <stdlib.h>

int maxInterval(int *a, int left, int right)
 {
    if(right==left)
      return a[left]>0?a[left]:0;
 
    int center = (left+right)/2;
    
    int leftMaxInterval = maxInterval(a,left,center);
    int rightMaxInterval= maxInterval(a,center+1,right);
 
    //center开始向左移动
    int sum = 0;
    int left_max = 0;
    for(int i = center; i >= left; --i)
    {
       sum += a[i];
       if(sum > left_max)
          left_max = sum;
    }
    //center+1开始向右移动
    sum = 0;
    int right_max = 0;
    for(int i = center+1; i <= right; ++i)
    {
       sum += a[i];
       if(sum > right_max)
         right_max = sum;
    }
    int ret = left_max+right_max;
    if(ret < leftMaxInterval)
        ret = leftMaxInterval;
    if(ret < rightMaxInterval)
        ret = rightMaxInterval;
    return ret;
 }

int main()
{
    int a[]={-2, 11, -4, 13, -5, -2};
    printf("%d",maxInterval(a,0,5));
    system("pause");
    return 0;
}
