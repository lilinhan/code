/************************************************* 
    File Name:  optimal_decomposition.cpp 
    Functions:    最优分解问题求解
                将正整数n分解为若干个自然数的和，
                使这些自然数的乘积最大。
    Author:        Jeccey     
    Created:     Jeccey
    Last Change: 2013-07-03 
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 51;     
int a[MAX - 1];        //记录所分解的自然数        

int PIntdecomp(int n);

int main()
{
    int n;
    char ch;


    FILE *fp1, *fp2;
    if( (fp1=fopen("input.txt","r")) == NULL){
        printf("cannot open file!\n");
        exit(0);    
    }
    fscanf(fp1,"%d",&n);

    memset(a, 0, MAX*sizeof(int));

    if( (fp2=fopen("output.txt","w")) == NULL){
        printf("cannot open file!\n");
        exit(0);    
    }
    fprintf(fp2,"%d\n",PIntdecomp(n));

    return 0;    
}

/**************************************************** 
    Function name:    PIntedecomp 
    Description: 将正整数n分解为若干个自然数的和，
                保证所分解自然数的乘积最大并返回。 
    Arguments:    n (int类型，且n<=437)

    Returns:    mresult, int 类型
                n所分解的自然数的乘积，返回0表示错误 
*****************************************************/
int PIntdecomp(int n)
{
    int k,j,mresult;
    
    if (n < 1 )        //非正整数返回0 
        return 0;    
    if (n < 5)        //若n<5，结果是其本身 
        return n;
    else{            //若 n>= 5 
        k = 0;
        a[k] = 2;
        n -= 2;
        /* 贪心策略：先从2开始分成连续自然数的和 */
        for (; n > a[k]; ){
            a[++k] = a[k-1] + 1;
            n -= a[k];
        }
        /* 如果剩下一个数，将其按后项优先的方式
        均匀分给前面各项 */ 
        if (n == a[k]){
            a[k]++;
            n--;
        }
        for (j = 0; j < n; j++){
            a[k-j]++;
        }
        /* 计算连乘积 */ 
        for(mresult = 1, j = 0; j <= k; j++){
            mresult *= a[j];
        }
        
        return mresult;
    }        
}
