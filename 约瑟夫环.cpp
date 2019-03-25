#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
    int data;
    int order;
    struct LNode*next;
}LNode;
int main()
{
    struct LNode *pa,*pb,*head;
    head=(struct LNode*)malloc(sizeof(LNode));
    pa=head;
    int i,m,n;
    printf("输入人数n和上限m\n");
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        pa->next=(struct LNode*)malloc(sizeof(LNode));
        pa=pa->next;
        pa->data=i;
        pa->order=i;
    }
    pa->next=head->next;
    pa=head->next;
    free(head);
    while(pa->next!=pa)
    {
        for(i=1;i<m;i++)
        {
            pb=pa;
            pa=pa->next;
        }
        printf("%d->",pa->order);
        pb->next=pa->next;
        free(pa);
        pa=pb->next;
    }
    printf("%d\n",pa->order);
}

