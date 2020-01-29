#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *llink,*rlink;
};

typedef struct node directory;

directory *insertbinsearchtree( directory *ptr,int val)
{
	if(ptr == NULL)
	{
		ptr = (directory *)malloc(sizeof(directory));
		ptr->info=val;
		ptr->llink=NULL;
		ptr->rlink=NULL;
	}
	else if(val < ptr->info)
	{
		ptr->llink = insertbinsearchtree(ptr->llink,val);
	}
	else if(val > ptr->info)
	{
		ptr->rlink = insertbinsearchtree(ptr->rlink,val);
	}
	else
	{
		printf(" \n Duplicate entry!! \n");
	}
	
	return ptr;
}

void inorder(directory *ptr)
{
	if(ptr == NULL)
	     return;
	
	inorder(ptr->llink);
	printf("\t %d \t",ptr->info);
	inorder(ptr->rlink);
}

void preorder(directory *ptr)
{
	if(ptr == NULL)
	     return;
	
	printf("\t %d \t",ptr->info);
	preorder(ptr->llink);
	preorder(ptr->rlink);
}

void postorder(directory *ptr)
{
	if(ptr == NULL)
	     return;
	
	postorder(ptr->llink);
	postorder(ptr->rlink);
	printf("\t %d \t",ptr->info);
}

directory *iterative_search(int item, directory *root)
{
	if(root == NULL)
	      return root;
	else
	{
		while(root != NULL)
		{
			if(item == root->info)
			      break;
			else if(item < root->info)
			      root = root->llink;
			else
			      root = root->rlink;
		}
		if( root == NULL)
		       printf(" key not found \n");
		else
		       printf(" key found \n");
		    
	    return root;
	}
}

int main()
{
	int ch,key;
	directory *root=NULL;
	while(1)
	{
		printf(" Enter user choice \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf(" enter the key \n");
			        scanf("%d",&key);
			        root = *insertbinsearchtree(root,key);
			        break;
			case 2: inorder(root);
			         break;
			case 3: preorder(root);
			         break;
			case 4: postorder(root);
			         break;
			         
			case 5: printf("\n Enter the key to search \n");
			        scanf("%d",&key);
			        root = iterative_search(key,root);
			        break;
			
			default: exit(0);
		}
	}
}




