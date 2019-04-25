#include<stdio.h>
#include<string.h>
#define N 27
typedef struct{
    unsigned int weight;
    unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char ** HuffmanCode;
void Select(HuffmanTree HT,int n,int *s1,int *s2)
{
    HTNode *search[n];
    int m[n]={0};
    int k=-1;
    int p=0;
    for(int i=1;i<=n;i++)
    {
        if(HT[i].parent==0)
        {
            search[p]=HT+i;
            m[++k]=i;
        }
        else i++;
    }
    for(int i=1;i<=n;i++)
    {
        if(HT[i].parent==0)
        {
            if(HT[i].weight<=search[p].weight)
            {
                search[++p].weight=HT[i].weight;
                m[++k]=i;
            }
            else continue;
        }
        else continue;
    }
    *s1=m[k];
    *s2=m[k-1];
}
viod HuffmanCoding(HuffmanTree HT,HumanCOde HC,int *w,int n)
{
    if(n<=1) return;
    m=2*n-1;
    HTNode *p;
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
    for(p=HT+1,i=1;i<=n;++i,++p,++w)
    {
        p->weight=*w;
        p->lchild=0;
        p->parent=0;
        p->rchild=0;
    }
    for(i=n+1;i<=m;i++)
    {
        p->lchild=0;
        p->parent=0;
        p->rchild=0;
        p->weight=0;
    }
    for(i=n+1;i<=m;++i)
    {
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
    char ** HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
    char * cd=(char *)malloc(n*sizeof(char));
    cd[n-1]="\0";
    for(i=1;i<=n;++i)
    {
        start=n-1;
        for(int c=i,int f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
        {
            if(HT[f].lchild==c) cd[--start]="0";
            else cd[--start]="1";
        }
        HC[i]=(char*)malloc((n-start)*sizeof(char));
        strcpy(HC[i],&cd[start]);
    }
    free(cd);
}
int main()
{
    int *w=(int *)malloc(N*sizeof(int));
    w[0]=186;
    w[1]=64;
    w[2]=13;
    w[3]=22;
    w[4]=32;
    w[5]=103;
    w[6]=21;
    w[7]=15;
    w[8]=47;
    w[9]=57;
    w[10]=1;
    w[11]=5;
    w[12]=32;
    w[13]=20;
    w[14]=57;
    w[15]=63;
    w[16]=15;
    w[17]=1;
    w[18]=48;
    w[19]=51;
    w[20]=80;
    w[21]=23;
    w[22]=8;
    w[23]=18;
    w[24]=1;
    w[25]=16;
    w[26]=1;
    HuffmanTree HT;
    HuffmanCode HC;
    HuffmanCoding(HT,HC,w,N);
    for(int i=0;i<=N;i++)
    {
        printf("%c->",*HC[i]);
    }
}
