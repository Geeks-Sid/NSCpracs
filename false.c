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

int errorcheck(double current,double previous) {
	double checker;
	checker = (previous - current)/current;
	checker = fabs(checker);
	if(checker<epsilon) 
		return 1;
	else
		return 0;
}

void GuessChecker(double xl,double xh) {
	int i;	
	double fxh = 0 ,fxl = 0,fxr = 0,xr = 0,prev = 0,current = 0;
	fxh = solver(xh);
	printf("\n\nValue of Xh: %lf",fxh);	
	fxl = solver(xl);
	printf("\n\nValue of Xl: %lf",fxl);
	if(fxh*fxl < 0) {
		do {
			prev = fxr;
			//xr = (xl+xh)/2
			fxl = solver(xl);
			fxh = solver(xh);
			xr = ((fxl*xh)-(fxh*xl))/(fxl-fxu);
			fxr = solver(xr);
			if(fxr*fxl==0) {
				printf("Xr was found and the answer is %lf",xr);		
				return;			
			}
			else if(fxr*fxl<0) {
				xh = xr;		
			}
			else {
				xl = xr;	
			}
			current = fxr;
		}while(errorcheck(current,prev)==0);
		printf("Xr was found not precisely at %lf",xr);
	}
	else {
		printf("Sorry! Your initial guesses are wrong. Please Try again.");
		return;	
	}		
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

	printf("Enter the Initial Guess 2:");
	scanf("%lf",&guess2);

	GuessChecker(guess1,guess2);		
}
