 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<fcntl.h>
 #include<sys/types.h>
 #include<sys/stat.h>
 #include<unistd.h>
     
	 #define FIFO1 "fifo1"
     #define FIFO2 "fifo2"
 
 int main()                         
 {
   char p[100],c[5000]; 
   int num,fd,fd2,f1;
   mknod(FIFO1,S_IFIFO|0666,0);
   mknod(FIFO2,S_IFIFO|0666,0);
   printf("\n Client online...\n");   
    fd=open(FIFO1,O_WRONLY);
      fd2=open(FIFO2,O_RDONLY);
	  printf("Client : Enter the filename . \n\n");
	  scanf("%s",p);
	  num=write(fd,p,strlen(p));
	  if(num==-1)
	  { 
	    perror("\nWrite Error.\n");
		return 1;
	  }
	  else
	  { 
	   printf("\n Waiting for reply\n");
	   if((num=read(fd2,c,5000))==-1) 
            perror("\nError while reading from fifo \n");
	   else
	   {
	    c[num]=0;
	     printf("%s",c);
	   }
	  }
	  
	  return 1;
  }   
