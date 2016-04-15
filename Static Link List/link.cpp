// 一个简单的链表
/* Author: Lynn-Lau */


# include<stdio.h>
# define NULL 0

struct student  /* 定义学生结构体，来确定每个单元内的内容*/
{
	long name;
	float score;
	struct student *next;
	struct student *former;
	
};
// 主函数
void main()
{
	struct student a,b,c,*head,*p,*end,*q;
	
	/* 对每个节点的name和score进行赋值*/
	a.name = 123; a.score = 88;
	b.name = 456; b.score = 90;
	c.name = 789; c.score = 95;
	
	/* 从左向右循环，给每个成员以及地址进行赋值*/
	head = &a;     /* 将起始节点a的地址赋值给头指针head*/
	a.next = &b;   /* 将第二节点b的地址赋值给a节点的next成员*/
	b.next = &c;   /* 将第三节点c的地址赋值给c节点的next成员*/
	c.next = NULL; /* c节点next成员不存放其他节点的地址*/
	p = head;      /* p也指向a节点*/
	
    /* 从右往左循环，给每一个成员以及地址进行赋值*/
	end = &c;        /* 将起始节点c的地址赋值给头指针end*/
	c.former = &b;   /* 将倒数第二个节点b的地址赋值给c的former成员*/
	b.former = &a;   /* 将倒数第三个节点a的地址赋值给b的former成员*/
	a.former = NULL; /* 倒数第三的节点a的former成员不指向任何一个地址*/
	q = end;         /* q指向循环起始点*/
	do
	{
		/*输出p,q所指向的节点的数据*/
		printf("%1d %5.1f\n",p->name,p->score );
		printf("%1d %5.1f\n",q->name,q->score );
		/*将p,q指向下一个成员*/
		p = p->next;
		q = q->former;

	}
	/* 确定循环条件，p或者q指向空*/
	while ((p != NULL)||(q != NULL));
}