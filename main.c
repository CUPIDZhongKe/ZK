#include<stdio.h>
#define MAXSIZE 20
typedef struct
{
	int Data[MAXSIZE];
	int Last;
}List;
List *MakeEmpty( )
{
     List *PtrL;
     PtrL = (List *)malloc( sizeof(List) );
     PtrL->Last = -1;
     return PtrL;
}
void Delete( int  i, List *PtrL )
{
    int  j;
    if( i < 1 || i > PtrL->Last+1 )
        {
            printf("不存在第%i个元素/n",i);
            return ;
        }
    for ( j = i; j <= PtrL->Last; j++ )
        PtrL->Data[j-1] = PtrL->Data[j];
    PtrL->Last--;
    return;
}
int main()
{
	List *MakeEmpty();
	PtrL->Data[MAXSIZE]={0,1,2,3,4,5,6,7,8,9};
	PtrL->Last=9;
	int i=8;
	Delete(i,PtrL);
	int j;
	for(j=0;j<10;j++)
	{
		printf("%d ",PtrL->Data[j]);
	}
}
