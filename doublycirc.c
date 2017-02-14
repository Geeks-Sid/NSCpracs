#include<stdio.h>
#include<stdlib.h>

int i,choice,element;

struct node {
	int data;
	struct node *next;
	struct node *prev;
}*front=NULL,*rear=NULL,*temp;

int isEmpty() {
	if(front==NULL&&rear==NULL)
		return 1;
	else
		return 0;
}

void enqueue(int j) {
	if(isEmpty()==1) {
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data=j;
		temp->next=NULL;
		temp->prev=NULL;
		front=temp;
		rear=temp;
		printf("Insertion is Successfull.");
	}
	else {
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data=j;
		temp->next=front;
		temp->prev=rear;
		rear->next = temp;
		rear = temp;
		front->prev = rear; 
		printf("Insertion is Successfull.\n");
	}
}

void dequeue() {
	if(isEmpty()==1) {
		printf("Sorry, There are no elements to return.");
	}
	else {
		front = front->next;
		front->prev = rear;
		rear->next = front;
		printf("Deletion is Successfull.");
	}
}

void display() {
	if(isEmpty()==1) {
		printf("Sorry, There are no elements to Print.");
	}
	else {
		printf("The list is as follows:");
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp=front;
		do {
			printf("%d -> ",temp->data);
			temp=temp->next;
		}while(temp!=front);
	}
}

void displayrev() {
	if(isEmpty()==1) {
		printf("Sorry, There are no elements to Print.");
	}
	else {
		printf("The list is rev as follows:");
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp=rear;
		do {
			printf("%d -> ",temp->data);
			temp=temp->prev;
		}while(temp!=rear);
	}
}

void main() {
	do {
		printf("================================");
		printf("              MENU              ");
		printf("================================\n\n");
		printf("1.Enter an element in Circular Queue\n\n");
		printf("2.Delete an element from Circular Queue\n\n");
		printf("3.Display the Circular Queue\n\n");
		printf("4.Display the Circular Queue in rev.\n\n");
		printf("5.Exit\n\n");
		printf("Enter Your choice:");;
		scanf("%d",&choice);
		switch(choice) {
			case(1) : {
				printf("\nEnter the element you want to add:");
				scanf("%d",&element);
				enqueue(element);
				break;
			}
			case(2) : {
				printf("\nThe Element in front will be deleted.");
				dequeue();
				break;
			}
			case(3) : {
				display();
				break;
			}
			case(4) : {
				displayrev();
				break;
			}
			case(5) : {
				printf("\nWe will miss you!");
				break;
			}
			default : {
				printf("\nWrong choice! Please Try again.");
				break;
			}
		}
	} while(choice!=5);
}
