#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next,*prev;
}

typedef struct node NODE;

NODE *start=NNULL;

void createlist()
{
	int n,i,data;
	printf("Enter the no. of nodes to be inserted \n");
	scanf("%d",&n);
	printf("Enter the elements to be inserted \n");
	scanf("%d",&data);
	insert_front();
	for(i=2;i<=n;i++)
	{
		printf("\n Enter the elements to be inserted \n");
	    scanf("%d",&data);
	    insert_end();
	}
}

void insert_front()
{
	NODE temp;
	int data;
	temp=(NODE *)malloc(sizeof(NODE));
	printf("Enter the elements to be inserted \n");
	scanf("%d",&data);
	temp->info=data;
	 if(start==NULL)
	      temp->prev=NULL;
	      temp->next=NULL;
	      start=temp;
	else
	      temp->prev=NULL;
	      temp->next=start;
	      start->prev=temp;
	      start=temp;
}

void insert_after()
{
	NODE *temp,*p;
	int data,val;
	temp=(NODE *)malloc(sizeof(NODE));
	printf("Enter the elements to be inserted \n");
	scanf("%d",&data);
	printf("Enter the nodes after which you want to insert \n");
	scanf("%d",&val);
	 temp->info=data;
	 p=start;
	 while(p!=NULL)
	 {
	 	if(p->info==val)
	 	{
	 		temp->prev=p;
	 		temp->next=p->next;
	 		if(p->next!=NULL)
	 		     p->next->prev=temp;
	 		p->next=temp;
		 }
		prev=p->next;
	 }
}

void insert_end()
{
	NODE *temp,*p;
	int data;
	printf("Enter the element to be inserted \n");
	scanf("%d",&data);
	temp=(NODE *)malloc(sizeof(NODE));
	temp->info=data;
	 p=start;
	 while(p->next!=NULL)
	 {
	 		p=p->next;
     }
     temp->next=NULL;
     temp->prev=p;
     p->next=temp;
}

void insert_before()
{
	NODE *temp,*p;
	int data,val;
	temp=(NODE *)malloc(sizeof(NODE));
	printf("Enter the element to be inserted \n");
	scanf("%d",&data);
	printf("Enter the nodes before which you want to insert \n");
	scanf("%d",&val);
	 temp->info=data;
	  if(start->info==val)
	       temp->next=start;
	       temp->prev=NULL;
	       start->prev=temp;
	       start=temp;
	  else
	  {
	  	p=start;
	  	 while(p!=NULL)
	  	 {
	  	 	if(p->info==val)
	  	 	{
	  	 		temp->next=p;
	  	 		temp->prev=p->prev;
	  	 		p->prev->next=temp;
	  	 		p->prev=temp;
			}
			p=p->next;
		}
	  }
}

void search()
{
	NODE *p=start;
	int pos=1;
	int data;
	printf("Enter the data to be searched \n");
	scanf("%d",&data);
	while(p!=NULL)
	{
		if(p->info==data)
		    printf("\n Element is found in position %d",pos);
		
		p=p->next;
		pos++;
	}
	if(p==NULL)
	     printf("\n Elements not found..\n");
}

void delete()
{
	NODE *temp,*p;
	int val;
	printf("\n Enter the values of node \n");
	scanf("%d",&val);
	if(start->info==val && start->next==NULL)
	   temp=start;
	   start=NULL;
	else if(start->info==val)
	    temp=start;
	    start=start->next;
	    start->prev=NULL;
	else
	{
		p=start;
		while(p->next!=NULL)
		{
			if(p->info==val)
			{
				temp=p;
				p->prev->next=p->next;
				p->next->prev=p->prev;
			}
		  p=p->next;
		}
		if(p->info==val)
		     temp=p;
		     p->prev->next=NULL;
		     
		free(temp);
	}
}

void display()
{
	NODE *p;
	if(start==NULL)
	    printf("\n List is Empty \n");
	else
	{
		p=start;
		printf("\n List is Empty \n");
		while(p!=NULL)
		{
			printf("%d",p->info);
			p=p->next;
		}
	}
}

int main()
{
	int ch;
	while(1)
	{
		printf("Enter your choice \n 1. Create a list \n 2. Add at the beginning \n 3. Add at the end \n 4. Add after a node \n 5. Add before a node \n 6. Delete a node \n 7. Search a node \n 8.Display \n");
		switch(ch)
		{
			case 1: createlist();
			        break;
			case 2: insert_front();
			        break;
			case 3: insert_end();
			        break;
			case 4: insert_after();
			        break;
			case 5: insert_before();
			        break;
			case 6: delete();
			        break;
			case 7: search();
			        break;
			case 8: display();
			        break;
			        
			default: 
			        printf("Invalid choice \n");
			        exit(0);
	    }
   }
}
