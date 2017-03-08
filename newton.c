#include<stdio.h>
#include<math.h>

int power,x[10];
double epsilon;

double solver(double a) {
	printf("\nControl at solver");
	double y=0;
	int i;
	for(i=power;i>=0;i--) {
		y+= x[i]*(pow(a,i));	
	}
	printf("F(%lf) = %lf",a,y);
	return y;	
}

double diffsolver(double b) {
	printf("\nControl at diffsolver");	
	double y = 0;
	int i;
	for (i=power;i>0;i--) {
		y+= i*x[i]*(pow(b,i-1));
	}
	printf("F'(%lf) = %lf",b,y);
	return y;
}

int errorcheck(double current,double previous) {
	printf("\nControl at errorcheck");	
	double checker;
	checker = (current-previous)/current;
	checker = fabs(checker);
	printf("\nEpsilon current = %lf ",checker);
	printf("\nCurrent = %lf \n Previous = %lf",current,previous);
	if(checker<epsilon) 
		return 1;
	else
		return 0;
}

void newton(double guess) {
	double guessnew,guessold,fx=0,fdx=0;
	printf("\nControl at newton");
	guessnew = guess;
	do {
		guessold = guessnew;
		fx = solver(guessold);
		fdx = diffsolver(guessold);
		guessnew = guessold - (fx/fdx);
	}while(errorcheck(guessnew,guessold)==0);
	printf("The solution is : %lf",guessnew);
}

void main() {
	int i;
	double guess1;

	printf("\n\nEnter the maximum power:");
	scanf("%d",&power);
	printf("\n\nEnter the coefficients one by one from max to low:");
	for(i=power;i>=0;i--) 	
		scanf("%d",&x[i]);
	printf("\n\nThe Equation looks as follows:");
	
	for(i=power;i>=0;i--) {
		printf("%dx^%d +",x[i],i);
	}

	printf("Enter the value of Epsilon:");
	scanf("%lf",&epsilon);

	printf("Enter the Initial Guess 1:");
	scanf("%lf",&guess1);

	newton(guess1);		
}
