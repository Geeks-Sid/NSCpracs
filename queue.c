#include<stdio.h>
void displayq();
int q[10],rear=-1,front=-1,i,MAX = 10;


int isEmpty() {
	if(front > rear || front < 0)
		return 1;
	else 
		return 0;
}


int isFull() {
	if(rear == MAX-1) 
		return 1;
	else
		return 0;
}


void enqueue(int item) {
	if (isFull()==1){
    		printf("Queue Overflow \n");
	}
	else {
			if(front==-1)
				front = 0;
			rear++;
			q[rear] = item;
	}
	displayq();
}


void dequeue() {
	if(isEmpty()==1) {
		printf("Sorry, we dont have any more elements to delete.");	
	}
	else {
		printf("Element has been deleted:");
		for(i=0;i<rear;i++) {
			q[i] = q[i+1];
		}
		rear--;
		displayq();
	}
}


void displayq() {
	printf("The Queue is as following :");
	for(i=front;i<=rear;i++) {
		printf("%d<-",q[i]);
	}
}


void main() {
	int choice,element;
	do {
		printf("\n\n=========================");
		printf("\n\n           MENU          ");
		printf("\n\n=========================");
		printf("\n\n1)Enqueue - Adding elements in the Queue:");
		printf("\n\n2)Dequeue - Deleting elements from the Queue:");
		printf("\n\n3)Display - Displaying the current state of the Queue :");
		printf("\n\n4)Exit - To Exit from the program :");
		printf("\n\nEnter your choice :");
		scanf("%d",&choice);
		switch(choice) {
			case(1): {
				printf("\nEnter the element to add into the Queue :");
				scanf("%d",&element);
				enqueue(element);
				break;
			}
			case(2): {
				printf("\nAn element is going to be deleted :");
				dequeue();
				break;
			}
			case(3): {
				displayq();
				break;
			}
			case(4): {
				printf("\nYou are exiting from the program. We will miss you.");
				break;
			}
		}
	} while(choice!=4);
}