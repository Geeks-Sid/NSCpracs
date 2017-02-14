#include<stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node *next,*prev;
} *temp,*top=NULL;
int i;

int isEmpty() {
	if(top==NULL)
		return 1;
	else
		return 0;
}

void push(int j) {
	
	if (!isEmpty()) {	
		struct node *top = malloc(sizeof *node);
		temp->val = j;
		temp-> next = NULL;
		top = temp;	
	}
	else {
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->val = j;
                temp->next = NULL;
		top->next = temp;
		top = temp;
		printf("Insertion is Successful\n");	
	}
}

void pop() {
	if(!isEmpty()) {
		printf("Stack Underflow");
	}
	else {
		printf("Element popped %d",top->val);		
		top = top->next;
			// Top is now the next element to top
		//Free (temp)// We are deleting the temp now,okay? 
	}
}

void display() {
	if (top == NULL) {
		printf("Sorry the stack is Empty :");	
	}
	else {
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp = top;		
		while(temp->next!= NULL) {
			printf("%d---> ", temp->val);
			temp = temp->next;	
		}
	} 
}
void main()
 
{
 
  int choice,num1=0;
 
  int i;
 
  while(1)
 
  {
    printf("======================================");
    printf("\n\t\t MENU ");
    printf("\n======================================");
    printf("\n[1] Using Push Function");
    printf("\n[2] Using Pop Function");
    printf("\n[3] Elements present in Stack");
    printf("\n[4] Exit\n");
    printf("\n\tEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case (1):
      {
	printf("\n\tElement to be pushed:");
	scanf("%d",&num1);
	push(num1);
	break;
      }
      case (2):
      {
	pop();
	printf("\n\tElement to be popped:");
	break;
      }
      case (3):
      {
	printf("\n\tElements present in the stack are:\n\t");
	display();
	break;
      }
      case (4):
	exit(1);
	break;
      default:
	printf("\nYour choice is invalid.\n");
	break;
     }
}
}
