#include<stdio.h>
#include<math.h>

int power,x[10];
double epsilon;

double solver(double a) {
	double y=0;
	int i;
	for(i=power;i>=0;i--) {
		y+= x[i]*(pow(a,i));	
	}
	return y;	
}

double diffsolver(double b) {
	double y = 0;
	int i;
	for (i=power;i>=0;i++) {
		y+= i*x[i]*(pow(b,i-1));
	}
}

int errorcheck(double current,double previous) {
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
	do {
		guessold = guess;
		fx = solver(guess);
		fdx = diffsolver(guess);
		guessnew = guess - (fx/fdx);
	}while(errorcheck(guessnew,guessold)==0);
	printf("The solution is : %lf",guessnew);
}

void main() {
	int i;
	double guess1,guess2;

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
