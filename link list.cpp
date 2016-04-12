/*
  Creat a dynamic link table,which has some functions
  Creating,Printing,Deleting,Inserting nodes.
  Author: Lynn-Lau Liu Silin
  Student Number: S150101093
  Language: C
  All Rights Reserved
*/

# include<stdio.h>
# include<malloc.h>
# define NULL 0
# define LEN sizeof(struct student)

/* Define a struct which includes num,score*/
struct student
{
	long num;
	float score;
	struct student *next;
};
int n;

/* Define a function which can creat a link list*/
/* Has a pointer point the head of the link list */
struct student *creat(void)     
{
	struct student *head;
	struct student *p1,*p2;
	n = 0;

	/* Creat a new unit whose length is LEN and put it in the RAM*/
	p1 = p2 = (struct student *) malloc (LEN); 
	scanf("%ld,%f",&p1->num,&p2->score);
	head = NULL;
	while (p1->num != 0)
	{
		n = n+1;
		if(n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct student*)malloc(LEN);
		scanf("%ld,%f",&p1->num,&p1->score);
	}
	p2->next = NULL;

	/* 
	return the head which point the struct student,so the function 
	returns the value of head ,the first node's address of link list
	*/
	return(head);
}

/* 
  Define a function which can print the link list
*/
void print(struct student *head)
{
	struct student *p;
	printf("\nNow, These %d records are:\n",n);
	p = head;
	if(head != NULL)
		do
		{
			printf("%ld %5.1f\n",p->num,p->score);
			p = p->next;
		}
		while(p != NULL);
}


/*
  Define a function which can delete a node of the link list
*/
struct student *del(student *head,long num)
{
	struct student *p1,*p2;
	if(head == NULL)
	{
		printf("\nlist null!\n");
		return head;
	}
	p1 = head;
	/*
	  p1 points the wrong node,besides there is another node
	*/
	while((num!=p1->num) && (p1->next!=NULL))
	/*
	  p1 moves to the next node
	*/
	{
		p2 = p1;
		p1 = p1->next;
	}

	if(num == p1->num) /* Found it */
	{
		/*
		  If p1 points to the first node,so give the 
		  address value of second node to the head.
		*/
		if(p1 = head)
			head = p1->next;
		/*
		  Give the address of next node to 
		  the former node's address
		*/
		else
			p2->next = p1->next;
		printf("delete:%ld\n",num);
		n = n-1;
	}
	else /* Not found it*/
		printf("%ld not been found!\n",num);
	return(head);
}


/*
  Define a function which can insert a node to
  the created link list.
*/
struct student *insert(struct student *head,struct student *stud)
{
	struct student *p0,*p1,*p2;
	p1 = head;                              /* Make p1 point to the first node*/
	p0 = stud;                              /* p0 points to the node which want to be inserted */
	if(head == NULL)                        /* Created link list is empty list */
	{
		/*
		  Make the point which p0 pointed be the head node
		*/
		head = p0;
		p0->next=NULL;
	}
	else
	{
		while((p0->num>p1->num) && (p1->next!=NULL))
		{
			/*
			Make p2 point to p1
			p1 moves to the next point
			*/
			p2 = p1;
			p1 = p1->next;
		}
		if(p0->num <= p1->num)
		{

			if(head == p1)
				head = p0;
			else
				p2->next=p0;
			p0->next=p1;
		}
		else
		{
			p1->next=p0;
			p0->next=NULL;
		}
	}
	n = n+1;/* The number of nodes adds 1*/
	return(head);
}

/*
  main function
*/
void main()
{
	struct student *head,stu;
	long del_num;
	printf("Please input records:\n");
	head = creat();                                 /* Creat a link list and return the head pointer*/
	print(head);                                    /* Print the whole link list */

	printf("\nPliease input the deleted number:");  /* Input the number you want delete*/  
	scanf("%ld",&del_num);
	head = del(head,del_num);                       /* Delete the address of link list*/
	print(head);                                    /* Print the left link list*/

	printf("\nPlease input the inserted record:");  /* Input the number you want to insert */
	scanf("%ld,%f",&stu.num,&stu.score);    
	head = insert(head,&stu);                       /* Insert a node and return the address of head */
	print(head);                                    /* Print the new link list*/
}