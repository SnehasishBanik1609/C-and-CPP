#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

   #define max 50
     float stack[max];
     char postfix[max];
     int top=-1;
     
void push(float item)
{
	if(top == max-1)
	    printf("\n stack overflow.. \n");
	else
	    stack[++top]=item;
}

float pop()
{
	if(top == -1)
	   printf("\n stack is empty \n");
	else
	   return stack[top--];
}

void evalpostfix()
{
	char *e;
	float op1,op2,res,x;
	e = postfix;
	 while(*e != '\0')
	 {
	 	if(isdigit(*e))
	 	{
	 	     x = *e-48;
	 	     push(x);
	    }
	 	else
	 	{
	 		op1=pop();
	 		op2=pop();
	 		switch(*e)
	 		{
	 		   case '+':  res = op1+op2;
	 		              break;
	 		   case  '-': res = op1-op2;
	 		              break;
	 		   case '*':  res = op1*op2;
	 		              break;
	 		   case  '/': res = op1/op2;
	 		              break;
	 		   case '^':  res = (int)op1 ^ (int)op2;
	 		              break;
	 		}
	 		push(res);
		}
		e++;
	 }
}

int main()
{
	printf("\n Enter the postfix expression \n");
	gets(postfix);
	evalpostfix();
	printf("\n The resultant of expression %s = %f",postfix,pop());
	
	return 0;
}
