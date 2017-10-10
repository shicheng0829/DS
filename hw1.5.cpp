//我承诺诚实作业，没有抄袭他人
#include <cstdio>
struct node{
	int data;
	node* next;
};

//删除递增有序链表中值大于min(i)且小于max(k)的所有元素

int main()
{
	int n, min, max;
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
	scanf("%d %d", &min, &max);			//读入最小值和最大值
	p = root->next;
	while(p->next != NULL)				//删除链表中的要求结点
	{
		if(p->next->data > min && p->next->data < max)
			p->next = p->next->next;
		p = p->next;
	}

	p = root->next;						//输出链表
	while(p)
	{
		printf("%d ", p->data);
		p = p -> next;
	}
	return 0;
}