//6.43
Status ExchangeBiTree(BiTree& T)
{
    BiTree p;
    if(T){
        p=T->lchild;
        T->lchild=T->rchild;
        T->rchild=p;
        ExchangeBiTree(T->lchild);
        ExchangeBiTree(T->rchild);
    }
    return OK;
}
//6.47
typedef BiTree QElemType;
Status LevelOrderTraverse(BiTree& T,Status(*Visit)(TElemType e))
{
    QElemType p;
    Queue q;
    InitQueue(q);
    if(T)EnQueue(q,T);
    while(!QueueEmpty(q)){
        DeQueue(q,p);
        Visit(p->data);
        if(p->lchild)EnQueue(q,p->lchild);
        if(p->rchild)EnQueue(q,p->rchild);
    }
    return OK;
}
//6.49
Status CompleteBiTree(BiTree& T)
{
	int d;
	if(T){
		d=BiTDepth(T->lchild)-BiTDepth(T->rchild);
		if(d<0||d>1)return ERROR;
		else{
			if(CompleteBiTree(T->lchild)&&CompleteBiTree(T->rchild)) return OK;
			else return ERROR;
		}
	}
	else return OK;
}
