#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

 #define max 50
 int q[max];
 int r=-1;
 int f=-1;
 int i,item;
 
 void insertq(int item)
 {
 	if(r>max-1)
 	{
 		printf("\n Queue is full.. \n");
	}
	else
	{
		if(r<=max-1)
		{
			q[++r]=item;
		}
	}
 }
 
 void deleteq()
 {
 	if(r==f)
 	{
 		printf("\n Queue is empty \n");
	}
	else
	{
		q[++f];
	}
 }
 
 void display()
 {
 	if(f==r)
 	{
 	 	printf("\n Queue is empty..\n");
	}
	else
	{
		for(i=f+1;i<=r;i++)
		{
			printf("%d \t",q[i]);
		}
	}
 }
 
 int main()
 {
 	int ch;
 	while(1)
 	{
 		printf("\n press 1: INSERT \n");
 		printf("\n press 2: DELETE \n");
 		printf("\n press 3: DISPLAY QUEUE \n");
 		printf("\n press anything to exit \n");
 		scanf("%d",&ch);
 		switch(ch)
 		{
 			case 1: printf("\n Enter item \n");
 			        scanf("%d", &item);
 			        insertq(item);
 			        break;
 			case 2: deleteq();
 			        break;
 			case 3: display();
			        break;
			default: 
			         printf(" INVALID \n");
					 exit(0);        
		 }
 		
	 }
 }
