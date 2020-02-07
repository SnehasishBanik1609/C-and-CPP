#include<stdio.h>
#include<stdlib.h> 
 
int trand(int a) 
{ 
  int rn;
  rn=random()%10;
  rn=rn%a;
  if(rn==0)
     rn=1;
   
   return(rn); 11.  
}

 int main() 
 { 
   int i,packet[5],psz,bsz,pszrn=0,clk,ptime,premain,orate,flag=0; 
   for(i=0;i<5;i++)
     packet[i]=trand(6)*10;
	  
   printf("\n enter the o/p rate"); 
   scanf("%d",&orate);
   printf("\n enter the bucket size");
   scanf("%d",&bsz);
   
    for(i=0;i<5;i++)
	{ 
	  if((packet[i]+pszrn)>bsz)
	     printf("\n incoming packet size %d is greater than bucket size_reject”, packet[i]); 
	  else
	  { 
	     for(;;)
		 { 
		   premain=4-i;
		   psz=packet[i];
		   pszrn+=psz;
		   printf("\nincoming packet size is %d",psz);
		   printf("\n no of packets waiting for transmission=%d",pszrn);
		   ptime=trand(4)*10;                           
		   printf("\n next packet will come at %d",ptime); 
		     for(clk=0;clk<=ptime;clk++)
			 { 
			   printf("\ntime left=%d",ptime-clk);
			   sleep(1); 
			   if(pszrn)
			   { 
			     if(pszrn==0)
				   printf("\n bucket is empty");
				 else 
				 { 
				   if(pszrn>=orate)
				     printf("%d bytes are transmitted",orate); 
				   else 
				     printf("\n %d bytes transmitted ",pszrn); 
			     } 
				 
				 if(pszrn<=orate) 
				   pszrn=0; 
				 else
				   pszrn-=orate;
				   printf("\n bytes remaining %d",pszrn); 
		       }   
			   else 
			      printf("\n bytes remaining %d",pszrn); 
			} 
			if(pszrn!=0) 
			   flag=1; 
			   break; 
			}
		} 
	}
	
	 printf("\n\n"); 
	
	 return 0; 
} 
  
