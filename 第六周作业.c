//3.10
void test(int &sum)
{
	int x;
	Stack S;
	InitStack(S);
	for( ; ;Push(S,x))
	{
		scanf("%d",&x);
		if(x==0) break;
		else continue;
	}
	if(IsEmpty(S)==0)
	{
		PoP(S,x);
		sum+=x;
		printf("%d",sum);
	}
}
//3.19
#include<stdio.h>
#define N 10
typedef struct SqList
{
	char elem[N];
	int top;
} *SqList;
int PushList(SqList S,int n)
{
	int i;
	SqList Sq;
	Sq->top=-1;
	for(i=0;i<n;i++)
	{
		if(S->elem[i]=='{'||S->elem[i]=='}'||S->elem[i]=='['||S->elem[i]==']'||S->elem[i]=='('||S->elem[i]==')')
		{
			if(top>=0&&Sq->elem[Sq->top]+2==S->elem[i]||Sq->elem[Sq->top]+1==S->elem[i])
			{
				PoP(Sq);
				top--;
			}
			else
			{
				top++;
				Sq->elem[Sq->top]=S->elem[i];
			}
		}
	}
	return (top);
}
//3.21
#include<stdio.h>
#define N MAXSIZE
typedef struct SqList
{
	char elem[N];
	int top;
}*SqList;
void RPN(SqList S,int n)
{
	int i;
	char x;
	SqList Sq1,Sq2;
	InitList(Sq1);
	InitList(Sq2);
	for(i=0;i<n;i++)
	{
		if('0'<S->elem[i]<'9')
		{
			Push(Sq1,S->elem[i]);
			Sq->top++;
		}
		else if(S->elem[i]=='+'||S->elem[i]=='-')
		{
			while(top>=0)
			{
				PoP(Sq2,x);
				Sq2->top--;
				Push(Sq1,x);
				Sq1->top++;
			}
			Push(Sq2,S->elem[i]);
			Sq2->top++;
		}
		else if(S->elem[i]=='*'||S->elem[i]=='/')
		{
			while(Sq2->elem[Sq2->top]=='*'||Sq2->elem[Sq2->top]=='/')
			{
				PoP(Sq2,x);
				Sq2->top--;
				Push(Sq1,x);
				Sq1->top++;
				Push(Sq2,S->elem[i]);
				Sq2->top++;
			}
		}
	}
	for(i=Sq2->top;i>=0;i--);
	{
		PoP(Sq2,x);
		Sq2->top--;
		Push(Sq1,x);
		Sq1->top++;
	}
	return ok;
}
//3.28
typedef struct LNode
{
	Elemtype elem;
	struct LNode *next;
} Node;
void InitList(struct LNode *rear)
{
	rear=(Node*)malloc(sizeof(Node));
	rear->next=rear;
}
void InQu(struct LNode *rear,Elemtype e)
{
	struct LNode *P;
	P=(Node*)malloc(sizeof(Node));
	P->next=rear->next;
	rear->next=P;
	rear=P;
	rear->elem=e;
}
viod OutQu(struct LNode *rear,Elemtype e)
{
	struct Node *Q;
	Q=rear->next;
	if(rear->next=rear) return NULL;
	else if(Q->next=rear)
	{
		Q->next=Q;
		e=rear->elem;
		free(rear);
		rear=Q;
	}
	else
	{
		e=Q->next->elem;
		Q->next=Q->next->next;

	}
}
