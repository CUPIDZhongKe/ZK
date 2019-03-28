//2.19
Status ListDelete_L(LinkList &L,int mink,int maxk)
{
    LinkList Pa,Pb,Q;
    if(mink>maxk)
        return ERROR;
    Pb=L;
    Pa=L->Next;
    while(Pa&&Pa->data<maxk)
    {
        if(Pa->data<=mink)
        {
            Pb=Pa;
            Pa=Pa->Next;
        }
        else
        {
            Q=Pa;
            Pb->Next=Pa->Next;
            Pa=Pa->Next;
            free(Q);
        }
    }
}//时间复杂度O(n)
//2.21
Status ListOppose_Sq(SqList &L)
{
    int i;
    int x;
    for(i=0;i<L.length/2;i++)
    {
        x=L.elem[i];
        L.elem[i]=L.elem[length-1-i];
        L.elem[length-1-i]=x;
    }
    return ok;
}
//2.24
Status ListMergeOppose_L(LinkList &A,LinkList &B,LinkList &C)
{
    LinkList pa,pb,qa,qb;
    pa=A->next;
    pb=B->next;
    A->next=NULL;
    C=A;
    while(pa&&pb)
    {
        if(pa->data<pb->data)
        {
            qa=pa;
            pa=pa->next;
            qa->next=A->next;
            A->next=qa;
        }
        else
        {
            qb=pb;
            pb=pb->next;
            qb=A->next;
            A->next=qb;
        }
    }
    while(pa)
    {
        qa=pa;
        pa=pa->next;
        qa=A->next;
        A->next=qa;
    }
    while(pb)
    {
        qb=pb;
        pb=pb->next;
        qb=A->next;
        A->next=qb;
    }
    pb=B;
    free(pb);
    return ok;
}
//2.29&2.30
Status ListDelete(LinkList &A,LinkList &B,LinkList &C,LinkList &D)
{
    LinkList pa,pb,pa,pd,qa;
    pa=A->next;
    pb=B->next;
    pc=C->next;
    D->next=NULL;
    while(pb&&pc)
    {
        if(pb->data<pc->data)
            pa=pa->next;
        if(pb->==pc->data)
        {
            qb=pb;
            pb=pb->next;
            qb=NULL;
            D->next=qb;
            pc=pc->next;
        }
        if(pb->data>pc->data)
            pc=pc->next;
    }
    pd=D->next;
    while(pa&&pd)
    {
        if(pa->data<pd->data)
            pa=pa->next;
        if(pa->data==pd->data)
            {
                qa=pa;
                pa=A;
                while(pa->next!=qa)
                    pa=pa->next;
                pa->next=pa->next->next;
                free(qa);//释放A表中无用空间结点
                pd=pd->next;
            }
        if(pa->data>pd->data)
            pd=pd->next;
    }
    pd=D;
    free(pd);
    return ok;
}//时间复杂度O(n^2)
//5.18
viod RRMove(ElemType A[],int k,int n)
{
    int temp;
    int j,i=1;
    int p=n/k;//k个元素分p组
    int q=n%k;//剩余q个元素
    while(i<p)
    {
        for(j=0;j<k;j++)
        {
           temp=A[j];
           A[j]=A[k*i+j];
           A[k*i+j]=temp;
        }
        i++;
    }
    for(j=0;j<q;j++)
    {
        temp=A[j];
        A[j]=A[p*k+j];
        A[p*k+j]=temp;
    }
}
