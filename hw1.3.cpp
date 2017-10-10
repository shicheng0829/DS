//我承诺诚实作业，没有抄袭他人
#include <cstdio>
struct node{
	int data;
	node* next;
};

//通过一趟遍历确定单链表中值最大的结点

int main()
{
	int n, max;
	scanf("%d", &n);
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
	p = root->next;						//遍历链表，寻找最大结点
	max = root->next->data;
	int count = 1;
	int maxnum = 1;						//count保存结点序号，maxnum保存最大结点的值
	while(p)
	{
		if(max < p->data)
		{
			max = p->data;
			maxnum = count;
		}
		p = p->next;
		count++;
	}
	printf("maxnode is no.%d node whose value is %d.",maxnum, max);
	return 0;
}