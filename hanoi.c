/*Design, develop and implement a program in C for the following
  stack applications:

  a.  Evaluation  suffix / postfix expression with single digit 
      operands and operators:+, -, *, /, %, ^
  b.  Solving Tower of Hanoi problem with n disks
*/

#include <stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>

#define STACK_SIZE 30

double compute (char symbol, double op1, double op2)
{
  switch(symbol)
	{
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		case '%': return (int)op1 % (int)op2;
		case '^': return pow(op1,op2);
	}
	return(0);
}


void suffix( )
{

 double s[STACK_SIZE], res , op1,op2;
 
 int top, i;

 char postfix[30], sym;

 printf("Enter a valid postfix expression\n");
 scanf("%s",postfix);

 top=-1;

 for(i=0; i< strlen(postfix); i++)
 {

    sym = postfix[i];

    if( isdigit(sym))
    {
	top=top+1;
	s[top] = sym -'0';        //48-> '0'  49 to 57 for 1 to 9 res
    }
    else
    {
  	op2 = s[top--];
	op1 = s[top--];
	res = compute(sym,op1,op2);
	s[++top] = res;
    }

 }// end of for

 res = s[top];
 printf("The result of postfix expression is:%lf",res);
 
}

void tower(int n,char s, char t, char d)
{

 if(n==1)
  {
     printf("Move disc %d from %c to %c\n",n,s,d);
     return;
  }

  tower(n-1,s,d,t);

  printf("Move disc %d from %c to %c\n",n,s,d);

  tower(n-1,t,s,d);
  
}

void main()
{
  int n, choice;

  while(1)
  {
   clrscr();
   printf("\n\n--------STACK APPLICATIONS-----------\n\n");
   printf("\n 1.Suffix Evaluation\n");
   printf("\n 2.Tower of Hanoi Problem\n");
   printf("\n 3.Exit\n");
   printf("\n-------------------------------------\n");
   printf("\nEnter your choice:\t");
   scanf("%d",&choice);

   switch(choice)
   {

      case 1: suffix();
	      getch();
	      break;

      case 2: printf("Enter the number of discs:\n");
	      scanf("%d",&n);
	      tower(n,'A','B','C');
	      getch();
	      break;

      case 3: exit(0);
	      break;

      default: printf("\nInvalid choice:\n");
	       getch();
	       break;

   } //end of switch

 }// end of while

}//end of main
