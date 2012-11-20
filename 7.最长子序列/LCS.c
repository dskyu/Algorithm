#include <stdio.h>
#include <stdlib.h>

int LCS(char a[],char b[])
{
    int i,j;
    int f[100][100];
    int la=strlen(a),lb=strlen(b);
    
    for (i=0;i<=la;i++)
       for (j=0;j<=lb;j++)
       {
           if (i==0 || j==0) f[i][j]=0;
           else if (i>0 && j>0 && a[i]!=b[j])
                f[i][j]=f[i-1][j]>f[i][j-1]?f[i-1][j]:f[i][j-1];
           else if (i>0 && j>0 && a[i]==b[j])
                f[i][j]=f[i-1][j-1]+1;
       }   

    return f[la][lb];
}

int main()
{
    char a[]="1564137";
    char b[]="1168347";
    printf ("%d",LCS(a,b));
    system("pause");
    return 0;   
}
