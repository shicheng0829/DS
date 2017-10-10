//我承诺诚实作业，没有抄袭他人
#include <cstdio>
struct node{
	int data;
	node* next;
};										//链表结点定义

void merge(node* A, node* B, node* &C)
{
	node* p = A->next;
	node* q = B->next;
	node* s;
	C = A;
	C->next = NULL;
	delete(B);
	while(p != NULL && q != NULL)
	{
		if(p->data <= q->data)
		{
			s = p;
			p = p->next;
			s->next = C->next;
			C->next = s;
			

		}
		else
		{

			s = q;
			q = q->next;
			s->next = C->next;
			C->next = s; 

		}

	}
	if(p != NULL)
	{
		while(p)
		{
			s = p;
			p = p->next;
			s->next = C->next;
			C->next = s;
		}
	}
	if(q != NULL)
	{
		while(q)
		{
			s = q;
			q = q->next;
			s->next = C->next;
			C->next = s; 
		}
	}
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