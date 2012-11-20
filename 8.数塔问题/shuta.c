#include <stdio.h>
#include <stdlib.h>

int shuta(int val[5][5])
{
    int i,j;
    int f[100][100];
    int N = 5;
    
    for (i=0;i<N;i++)
       f[N-1][i] = val[N-1][i];
    for (i=N-2;i>=0;i--)
       for (j=0;j<=i;j++)
           f[i][j]=(f[i+1][j]>f[i+1][j+1]?f[i+1][j]:f[i+1][j+1]) + val[i][j];
           
    for (i=0;i<N;i++)
    {for (j=0;j<N;j++) printf ("%d ",f[i][j]);       
     printf ("\n");}      
           
    return f[0][0];
    
}

int main()
{
    int a[5][5]={{7,0,0,0,0},
               {3,8,0,0,0},
               {8,1,0,0,0},
               {2,7,4,4,0},
               {4,5,2,6,5}};
    printf ("%d",shuta(a));
    system("pause");
    return 0;
}
