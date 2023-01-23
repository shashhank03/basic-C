	/*Design, Develop and Implement a menu driven Program in C for the
 following operations on Singly Linked List (SLL) of
 Student Data with the fields: USN, Name, Branch, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of SLL
d. Perform Insertion and Deletion at Front of SLL
e. Demonstrate how this SLL can be used as STACK and QUEUE
f. Exit
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 3

int count=0;
struct node
{
   int sem;
   char phno[10];
   char name[20],branch[10],usn[20];
   struct node *link;
};
typedef struct node * NODE;

NODE getnode()
{
  NODE new=NULL;
  int sm;
  char nm[20],br[10],us[20],ph[10];
  new=(NODE)malloc(sizeof(struct node));
  //read from the Keyboard
  printf("\nEnter Student Details:\n");
  printf("USN:");
  scanf("%s",us);
  fflush(stdin);

  printf("NAME:");
  scanf("%s",nm);
  fflush(stdin);

  printf("BRANCH:");
  scanf("%s",br);
  fflush(stdin);

  printf("SEMESTER:");
  scanf("%d",&sm);
  fflush(stdin);

  printf("PHONE NO:");
  scanf("%s",ph);
  fflush(stdin);

  //copy to structure members
  strcpy(new->usn,us);
  strcpy(new->name,nm);
  strcpy(new->branch,br);
  new->sem = sm;
  strcpy(new->phno,ph);

  new->link=NULL;
  count++;
  return new;
}

NODE insert_front(NODE first)
{  NODE temp;
   temp=getnode();
   temp->link = first;
   return temp;
}

NODE insert_rear(NODE first )
{
   NODE cur,temp;
   temp=getnode();
   if(first==NULL)
      return temp;

   cur=first;
   while(cur->link!=NULL)
   {
     cur=cur->link;
   }
   cur->link=temp;
   return first;
}

NODE delete_front(NODE first )
{
	NODE cur;
	if(first==NULL)
	{
	  printf("List is Empty!!\n");
	  return first;
	}

	cur = first;
	first = first->link;

	printf(" The deleted Item is: \n\n" );
	printf("\n-------------------------------------\n");
	printf("\nUSN\tNAME\tBRANCH\tSEM\tPHNO\n");
	printf("\n-------------------------------------\n");
	printf("\n%s\t%s\t%s\t%d\t%s\n", cur->usn, cur->name,cur->branch,cur->sem, cur->phno );

	free(cur);

	count = count - 1;
	return first;
}

NODE delete_rear(NODE first )
{
   NODE cur,prev;
   if(first==NULL)
   {
     printf("List is Empty!!\n");
     return first;
   }

   if( first->link == NULL)
   {
   printf(" The deleted Item is: \n\n" );
   printf("\n-------------------------------------\n");
   printf("\nUSN\tNAME\tBRANCH\tSEM\tPHNO\n");
   printf("\n-------------------------------------\n");
   printf("\n%s\t%s\t%s\t%d\t%s\n", first->usn, first->name,first->branch,first->sem, first->phno );
   free(first);
   return NULL;
   }

   prev = NULL;
   cur = first;

   while(cur->link != NULL)
   {
      prev = cur;
      cur = cur->link;
   }

   printf(" The deleted Item is: \n\n" );
   printf("\n-------------------------------------\n");
   printf("\nUSN\tNAME\tBRANCH\tSEM\tPHNO\n");
   printf("\n-------------------------------------\n");
   printf("\n%s\t%s\t%s\t%d\t%s\n", cur->usn, cur->name,cur->branch,cur->sem, cur->phno );

   free( cur );

   prev->link = NULL;
   count = count -1;

   return first;
}


void display(NODE first )
{
	NODE temp;
	if(first==NULL)
	{
		printf("List is Empty!!\n");
		return;
	}

	temp = first;
	printf("\n-------------------------------------\n");
	printf("\nUSN\tNAME\tBRANCH\tSEM\tPHNO\n");
	printf("\n-------------------------------------\n");
	while( temp!=NULL )
	{
	  printf("\n%s\t%s\t%s\t%d\t%s\n", temp->usn, temp->name,temp->branch,temp->sem, temp->phno );
	  temp = temp->link;
	}
	printf("\nThe number of nodes in the list : %d\n", count);
}


void main( )
{
  int ch,n,i;
  NODE first=NULL;
  clrscr();
  for(;;)
  {
  printf("-----------STUDENT DATA-----------------\n");
  printf("\n 1 - CREAT A SLL OF 'N' STUDENTS");
  printf("\n 2 - DISPLAY");
  printf("\n 3 - INSERT_FRONT");
  printf("\n 4 - INSERT_REAR");
  printf("\n 5 - DELETE_FRONT");
  printf("\n 6 - DELETE_REAR");
  printf("\n 7 - STACK PUSH OPEARATION");
  printf("\n 8 - STACK POP OPEARATION");
  printf("\n 9 - ENQUEUE OPERATION");
  printf("\n10 - DEQUEUE OPERATION");
  printf("\n11 - EXIT\n");
  printf("----------------------------------------\n");

     printf("\nEnter your choice : ");
     scanf("%d", &ch);
     switch (ch)
     {
	case 1: printf("\nEnter number of students : ");
		scanf("%d", &n);
		for(i=0;i<n;i++)
		{
		   first=insert_front(first);
		}
		break;

	case 2: display(first);
		break;

	case 3: first=insert_front(first);
		break;

	case 4: first=insert_rear(first);
		break;

	case 5: first=delete_front(first);
		break;

	case 6: first=delete_rear(first);
		break;

	case 7: printf("\nSTACK PUSH OPERATION\n");
		if(count<SIZE)
		    first = insert_front(first);

		else if(count==SIZE)
		    printf("Stack Overflow");
		break;

	case 8: printf("\nSTACK POP OPERATION\n");
		first=delete_front(first);
		break;

	case 9:	printf("\nENQUEUE OPERATION\n");
		if(count<SIZE)
		    first = insert_rear(first);

		else if(count==SIZE)
		    printf("Queue Overflow");
		break;

	case 10:printf("\nDEQUEUE OPERATION\n");
		first=delete_front(first);
		break;

	default: exit(0);

     }//end of switch

   } //end of for

} //end of main


