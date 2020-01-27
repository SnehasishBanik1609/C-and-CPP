#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
}*temp,*cur;

typedef struct node NODE;

NODE *first;

void insert_front(int x)
{
	NODE *temp;
	temp = ((NODE *)malloc(sizeOf(NODE)));
	if(temp==NULL)
	{
		printf("NODE NOT CREATED \n");
	}
	else
	{
		temp->data=x;
		temp->link=NULL;
		  if(first==NULL)
		  {
		  	first=temp;
		  }
		  else
		  {
		  	temp->link=first;
		  	first=temp;
		  }
	}
}

void insert_end(int item)
{
	NODE *temp,*cur;
	temp=(NODE *)malloc(sizeOf(NODE));
	 if(temp==NULL)
	 {
	 	printf("NODE NOT CREATED...\n");
	 }
	 else
	 {
	 	cur=first;
	 	while(cur=link!=NULL)
	 	{
	 		cur=cur->link;
		}
		cur->link=temp;
	 }
}

void insert_anywhere(int item,int pos)
{
	int count;
	NODE *temp,*cur;
	temp=(NODE *)malloc(sizeOf(NODE));
	  if(temp==NULL)
	  {
	  	printf("NODE NOT CREATED..\n");
	  }
	  else
	  {
	  	temp->data=item;
	  	temp->link=NULL;
	  	  if(first==NULL)
	  	  {
	  	  	first=temp;
		  }
		  else
		  {
		  	cur=first;
		  	count=1;
		  	while(cur->link!=NULL)
		  	{
		  		if(count==pos)
		  		{
		  			break;
				}
				else
				{
					cur=cur->link;
					count++;
				}
			}
			if(count==pos)
			{
				temp->link=cur->link;
				cur->link=temp;
			}
			else
			{
				printf("\n Position not found..\n");
			}
		  }
	  }
}

void delete_front()
{
	NODE *temp;
	if(first==NULL)
	{
		printf("\n List is empty \n");
	}
	else
	{
		temp=first;
		first=first->link;
		free(temp);
	}
}

void delete_end()
{
	NODE *cur,*prev;
	if(first==NULL)
	{
		printf("LIST IS EMPTY...\n");
	}
	else
	{
		if(first->link==NULL)
		     free(first);
		else
		{
			prev=first;
			cur=first->link;
			while(cur->link!=NULL)
			{
				cur=cur->link;
				prev=prev->link;
			}
			prev->link=NULL;
			free(cur);
		}
	}
}

void delete_anywhere(int pos)
{
	int count;
	NODE *temp,*cur,*prev;
	if(first==NULL)
	{
		printf("List is empty..\n");
	}
	else
	{
		prev=first;
		cur=first->link;
		count=1;
		while(cur->link!=NULL)
		{
			if(count==pos-1)
			  break;
			else
			   prev=prev->link;
			   cur=cur->link;
			   count++;
		}
		if(count==pos-1)
		{
			temp=cur;
			prev->link=cur->link;
			free(temp);
		}
	}
}

void display()
{
	NODE *temp;
	if(first==NULL)
	{
		printf("LIST IS EMPTY..\n");
	}
	else
	{
		temp=first;
		do
		{
			printf("\n %d", temp->data);
			temp=temp->link;
		}while(temp->link!='\0');
		printf("%d",temp->data);
	}
}

int main()
{
	int ch,ch1,item,pos;
	printf("Enter your choice \n 1. INSERT \n 2. DELETE \n");
	scanf("%d",&ch);
	while(1)
	{
		switch(ch)
		{
			case 1: insert_front(item);
			        display();
			        break;
			case 2: printf("1. delete from front \n 2. delete freom end \n 3. delete anywhere \n");
			        scanf("%d",&ch1);
			        switch(ch1)
			        {
			        	case 1: delete_front();
			        	        display();
			        	        break;
			        	case 2: delete_end();
			        	        display();
			        	        break;
			        	case 3: printf("Enter the position to insert \n");
			                    scanf("%d",&pos);
			                    inset_anywhere(item,pos);
			                    display();
			                    break;
					}
			        break;
			default: 
			        printf("Invalid choice \n");
			        exit(0);
		}
	}
}
