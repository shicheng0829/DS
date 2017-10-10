//我承诺诚实作业，没有抄袭他人
#include <cstdio>
struct node{
	int data;
	node* next;
};

//逆转链表

void reverse(node* root)				//头插法
{
	node* p = root->next, *q;
	root->next = NULL;
	while(p != NULL)
	{
		q = p->next;
		p->next = root->next;
		root->next = p;
		p = q;
	}
}

int main()
{
	int n;
	scanf("%d", &n);					//读入链表的长度
	node* root;
	root = new node;
	root->next = NULL;
	node* p = root;
	for(int i = 0; i < n; i++)			//写入链表
	{
		int temp;
		scanf("%d", &temp);
		node* q = new node;
		q -> data = temp;
		p -> next = q;
		p = q;

	}
	reverse(root);
	p = root->next;						//输出链表
	while(p)
	{
		printf("%d ", p->data);
		p = p -> next;
	}

	return 0;
}