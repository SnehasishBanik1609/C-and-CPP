#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

 #define max 50
 int q[max];
 int r=-1;
 int f=0;
 int i,item,x;
 
 void insertq(int x)
 {
 	if((f==0 && r==(max-1)) || (f>0 && r==(f-1)))
 	{
 		printf("\n Overflow of queue.. \n");
	}
	else
	{
		if(r==(max-1) && f>0)
		{
			r=0;
			q[r]=x;
		}
		else
		{
		   if((f==0 && r==-1) || (r!=(f-1)))
		   {
		   	  q[++r]=x;
		   }
		}
	}
 }
 
 int deleteq()
 {
 	int a;
 	if(f==0 && r==-1)
 	{
 		printf("\n Queue is empty \n");
	}
	if(f==r)
	{
		a=q[f];
		r=-1;
		f=0;
	}
	else
	{
		if(f==(max-1))
		{
			a=q[f];
			f=0;
		}
		else
		{
		    a=q[f++];
	    }
	}
	 return a;
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
 			case 2: x=deleteq();
 			        printf("The deleted value is %d",x);
 			        break;
 			case 3: display();
			        break;
			default: 
			         printf(" INVALID \n");
					 exit(0);        
		 }
 		
	 }
 }
