#include<stdio.h>
#include<stdlib.h>
int i,j,item,max=5,y,top=-1;
int stack[5];
void push()
	{
	if(top==max-1) {
	printf("\nstack overflow.");
	}
	else {
		top++;
		printf("\n enter the element to push:");
		scanf("%d",&item);
		stack[top]=item;
		}
	}
void pop()
	{
	if(top==-1) {
	printf("\n stack underflow.cant perform pop");
	}
	else {
	y=stack[top];
	printf("\n %d",y);	
	top--;
	
	}	
}

void display()
	{
		for(i=0;i<=top;i++)
		{
		printf("\n %d",stack[i]);
		}
	}
		
	
void main()
{
	
	printf("1.push\n2.pop\n3.display\n4.exit");
	
	do
	{
		printf("\n enter choice:");
	        scanf("%d",&i);
		switch(i)
		{
		case 1:
		{		
		push();break;
		}
		case 2:
		{		
		pop();break;
		}
		case 3:
		{		
		display();break;
		}
		
		case 4:
		{		
		exit(0);break;
		}
		
		}
		i++;
	}while(i!=4);
}	
