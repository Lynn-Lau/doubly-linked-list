// һ���򵥵�����
/* Author: Lynn-Lau */


# include<stdio.h>
# define NULL 0

struct student  /* ����ѧ���ṹ�壬��ȷ��ÿ����Ԫ�ڵ�����*/
{
	long name;
	float score;
	struct student *next;
	struct student *former;
	
};
// ������
void main()
{
	struct student a,b,c,*head,*p,*end,*q;
	
	/* ��ÿ���ڵ��name��score���и�ֵ*/
	a.name = 123; a.score = 88;
	b.name = 456; b.score = 90;
	c.name = 789; c.score = 95;
	
	/* ��������ѭ������ÿ����Ա�Լ���ַ���и�ֵ*/
	head = &a;     /* ����ʼ�ڵ�a�ĵ�ַ��ֵ��ͷָ��head*/
	a.next = &b;   /* ���ڶ��ڵ�b�ĵ�ַ��ֵ��a�ڵ��next��Ա*/
	b.next = &c;   /* �������ڵ�c�ĵ�ַ��ֵ��c�ڵ��next��Ա*/
	c.next = NULL; /* c�ڵ�next��Ա����������ڵ�ĵ�ַ*/
	p = head;      /* pҲָ��a�ڵ�*/
	
    /* ��������ѭ������ÿһ����Ա�Լ���ַ���и�ֵ*/
	end = &c;        /* ����ʼ�ڵ�c�ĵ�ַ��ֵ��ͷָ��end*/
	c.former = &b;   /* �������ڶ����ڵ�b�ĵ�ַ��ֵ��c��former��Ա*/
	b.former = &a;   /* �������������ڵ�a�ĵ�ַ��ֵ��b��former��Ա*/
	a.former = NULL; /* ���������Ľڵ�a��former��Ա��ָ���κ�һ����ַ*/
	q = end;         /* qָ��ѭ����ʼ��*/
	do
	{
		/*���p,q��ָ��Ľڵ������*/
		printf("%1d %5.1f\n",p->name,p->score );
		printf("%1d %5.1f\n",q->name,q->score );
		/*��p,qָ����һ����Ա*/
		p = p->next;
		q = q->former;

	}
	/* ȷ��ѭ��������p����qָ���*/
	while ((p != NULL)||(q != NULL));
}