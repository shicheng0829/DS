//我承诺诚实作业，没有抄袭他人
#include <cstdio>
struct node{
	int data;
	node* next;
};						//链表结点定义

//将两个非递减的有序链表合并为一个非递减的有序链表

void merge(node* A, node* B, node* &C)		//归并链表操作
{
	node* p = A->next;
	node* q = B->next;
	node* r;
	C = A;
	C->next = NULL;
	delete(B);
	r = C;
	while(p != NULL && q != NULL)
	{
		if(p->data <= q->data)
		{
			r->next = p;
			p = p->next;
			r = r->next;
		}
		else
		{
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}
	r->next = NULL;
	if(p != NULL)
		r->next = p;
	if(q != NULL)
		r->next = q;
}
int main()
{
	int n, m;							//保存两个链表的长度
	scanf("%d", &n);
	node* roota, *rootb, *rootc;
	roota = new node;
	roota -> next = NULL;
	rootb = new node;
	rootb -> next = NULL;
	rootc = new node;
	rootc -> next = NULL;
	node* p = roota;
	for(int i = 0; i < n; i++)			//写入链表
	{
		int temp;
		scanf("%d", &temp);
		node* q = new node;
		q -> data = temp;
		p -> next = q;
		p = q;

	}
	p->next = NULL;
	scanf("%d", &m);
	p = rootb;
	for(int i = 0; i < m; i++)
	{
		int temp;
		scanf("%d", &temp);
		node* q = new node;
		q -> data = temp;
		p->next = q;
		p = q;

	}
	p->next = NULL;

    merge(roota, rootb, rootc);
	
	p = rootc->next;					//输出链表
	while(p)
	{
		printf("%d ", p->data);
		p = p -> next;
	}
	return 0;
}