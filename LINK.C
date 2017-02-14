#include<stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <stdbool.h>

struct node
{
int data;
struct node *next;
};

struct node *first,*temp;

int isEmpty()
{
	if(first==NULL)
		return 1;
	else 
		return 0;
}
/*----------------------------------*/
void insert()
{
	struct node *temp,*t;
	int d;

	printf("\n Enter the data");
	scanf("%d",&d);

	temp=malloc(sizeof(struct node));

	temp->data=d;
	temp->next=NULL;

  		if (isEmpty())
  		{
   			 first=temp;
  		}
 		else
 		{
		t=first;
    		while(t->next!=NULL)
    		{
     			 t=t->next;
    		}
 			t->next=temp;
 		}
}
/*----------------------------------*/
void delete()
{
	int d;
	struct node *temp,*t;
	int flag=0;

printf("Entaer data to delete");
scanf("%d",&d);

t= first;
	if(isEmpty())
	{
		printf("\n linked list is empty");
	}
	else
	{
		if(first->data==d)
		{
			t=first->next;
			free(first);
			first=t;
		}
		else
		{
			while(t!=NULL)
			{
				if(t->data!=d)
				{
					t=t->next;
				}
				else
				{
					temp=t;
					t=t->next;
					free(temp);
					flag=1;
				}
			}
		}
		if(flag==0)
		{
			printf("no nelement exist");
		}
    }
}
/*----------------------------------*/
void display()
{
	struct node *temp=first;
	if(isEmpty())
	{
		printf("linked list is empty");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("\n%d",temp->data);
			temp=temp->next;
		}
	}
}
/*----------------------------------*/
void main()
{
int ch;

do{
   printf("enter your choice -1:Insert,2:Delete,3:Display,4:exit\n");
     scanf("%d",&ch);
      switch(ch)
      {
		case 1:insert();
			break;
		case 2:delete();
			break;
		case 3:display();
			break;
	       default:
			break;
      }
}while(ch!=4);
}
























































