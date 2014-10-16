/*************************************************************************
	> File Name: Tuple.c
	> Author: 
	> Mail: 
	> Created Time: 2014年10月16日 星期四 19时52分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
#define FALSE 0
#define TRUE 1

typedef struct
{
    int row,col,value;
}Triple;

typedef struct
{
    Triple data[Maxsize];
    int rows,cols,nums;
}TSMatrix;

void InitTuple(TSMatrix * A)
{
    A->rows = 0;
    A->cols = 0;
    A->nums = 0;
}

int CreatTuple(TSMatrix * N)
{
    int k = 0 ;
    printf("请输入矩阵的行，列，以及非0元素个数\n");
    scanf("%d%d%d",&N->rows,&N->cols,&N->nums);
    if( N->rows <= 0 || N->cols <= 0 || N->nums <= 0 || N->nums > N->rows*N->cols )
        return FALSE ;
    else  {
        printf("请输入三元组矩阵\n");
        for(;k<N->nums;k++)  {
            scanf("%d",&N->data[k].row);
            scanf("%d",&N->data[k].col);
            scanf("%d",&N->data[k].value);
        }
    }
    return TRUE;
}

void PrintTuple(TSMatrix * A)
{
    int i,j,k = 0;
    for( i = 0 ; i < A->rows ; i++ )  {
        for( j = 0 ; j < A->cols ; j++ )  {
                if( i == A->data[k].row-1 && j == A->data[k].col-1 )  {
                    printf("%d   ",A->data[k].value);
                    k++;
                }
                else
                    printf("0   ");
        }
        j = 0;
        printf("\n");
    }   
}

int AddTuple(TSMatrix * A , TSMatrix * B , TSMatrix * C)
{
    int i = 0 ,j = 0, k = 0;

    C->rows = A->rows;
    C->cols = A->cols;
    if(A->rows != B->rows && A->cols != B->cols )
        return FALSE;
    
    while( i < A->nums && j < B->nums )  {
        if( A->data[i].row != B->data[j].row )  {
            if(A->data[i].row < B->data[j].row)  {
                C->data[k].row = A->data[i].row;
                C->data[k].col = A->data[i].col;
                C->data[k].value = A->data[i].value;
                C->nums++;
                i++;
            }
            if( A->data[i].row > B->data[j].row ) {
                C->data[k].row = B->data[j].row;
                C->data[k].col = B->data[j].col;
                C->data[k].value = B->data[j].value;
                C->nums++;
                j++;
            }  
        }
        else  {
            if( A->data[i].col == B->data[j].col )  {
                C->data[k].row = B->data[j].row;
                C->data[k].col = B->data[j].col;
                C->data[k].value =A->data[i].value + B->data[j].value;
                C->nums++;
                i++;j++;
            }
            else if( A->data[i].col < B->data[j].col )  {
                C->data[k].row = A->data[i].row;
                C->data[k].col = A->data[i].col;
                C->data[k].value = A->data[i].value;
                C->nums++;
                i++;
            }
            else {
                C->data[k].row = B->data[j].row;
                C->data[k].col = B->data[j].col;
                C->data[k].value = B->data[j].value;
                C->nums++;
                j++;
            }
        }
        k++;
    }
	    if( i == A->nums )  {
    		for(;j < B->nums ; j++ )  {
    	   	         C->data[k].row = B->data[j].row;
       		         C->data[k].col = B->data[j].col;
       		         C->data[k].value = B->data[j].value;
       		         C->nums++;
			k++;
		}
	    }
	if( j == B->nums )  {
   	 	for(;i < A->nums ; i++ )  {
        	        C->data[k].row = A->data[i].row;
               		C->data[k].col = A->data[i].col;
              	 	C->data[k].value = A->data[i].value;
                	C->nums++;
			k++;
		}
    	}

    PrintTuple(C);
}

void ReduceTuple(TSMatrix * A,TSMatrix * B,TSMatrix *C)
{
	int i;
	for( i = 0 ; i < B->nums ; i++ )  {
		B->data[i].value = -1*B->data[i].value;
	}
	AddTuple(A,B,C);
}

void Inversion(TSMatrix * A , TSMatrix * C)
{
	int i = 0 , j = 1 , k;

	C->rows = A->rows;
	C->cols = A->cols;
	C->nums = A->nums;
	while( i < A->nums  )  {
		k = 0;
		for( ; k < A->nums ; k++ )  {
			if( A->data[k].col == j )  {
				C->data[i].row = A->data[k].col;
				C->data[i].col = A->data[k].row;
				C->data[i].value = A->data[k].value;
				i++;
			}

		}
		j++;
	}
	PrintTuple(C);
}

int main()
{
    TSMatrix a,b,c,d;
    InitTuple(&a);
    InitTuple(&b);
    InitTuple(&c);
    CreatTuple(&a);
    CreatTuple(&b);
    PrintTuple(&a);
    printf("\n");
    PrintTuple(&b);
    printf("\n两矩阵相加结果:\n");
    AddTuple(&a,&b,&c);
    printf("\n两矩阵相减结果:\n");
    ReduceTuple(&a,&b,&c);
    printf("\n");
    Inversion(&a,&d);
    return 0;
}


