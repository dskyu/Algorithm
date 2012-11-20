#include <iostream>
using namespace std;

#define MAXNUM 100
#define MAX 65536
//p中为有序关键字k1到k5的搜索概率，k1<k2<k3<k4<k5
double p[MAXNUM] = {0.00,0.15,0.10,0.05,0.10,0.20};
double q[MAXNUM] = {0.05,0.10,0.05,0.05,0.05,0.10};
void optimal_bst(double e[][MAXNUM],int root[][MAXNUM],double w[][MAXNUM],int n)
{
         int i =0,j=0;
         //针对左或右孩子为空树情况初始化
         for(i = 1;i<=n+1;i++)
         {
                 e[i][i-1] = q[i-1];
                 w[i][i-1] = q[i-1];
         }
         int l = 0;
         //计算顺序如下：根据计算式：e[i,j] = e[i,r-1]+e[r+1,j
         //     首先计算节点个数为1的最优二叉树的代价e[1,1],e[2,2]……
         //     接着计算节点个数为1的最优二叉树的代价e[1,2],e[2,3]……
         //     ……
         //     最后计算结点个数为n的最优二叉树的代价e[1,n]，利用之前保存的较少结点最优二叉树的结果。
         for(l = 1;l<=n;l++)
         {
                 for(i = 1;i<=n-l+1;i++)
                 {
                         j = i+l-1;
                         e[i][j] = MAX;
                         w[i][j] = w[i][j-1] + p[j]+q[j];
                         for(int r = i;r<=j;r++)
                         {
                                 double t = 0;
                                 t = e[i][r-1]+e[r+1][j] + w[i][j];
                                 if(t<e[i][j])
                                 {
                                         e[i][j]= t;
                                         root[i][j] = t;
                                 }
                         }
 
                 }
         }
 
 }
int main()
{
         double e[MAXNUM][MAXNUM];
         int root[MAXNUM][MAXNUM];
         double w[MAXNUM][MAXNUM];
 
         optimal_bst(e,root,w,5);
 
         for(int i =1;i<=6;i++)
         {
                 for(int j = 0;j<=5;j++)
                 {
                         cout << e[i][j] << "  ";
                 }
                cout << endl;
         }
}
