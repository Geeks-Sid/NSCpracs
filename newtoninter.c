#include<stdio.h>
#include<math.h>
double mat[10][10];
double x[10];
double fx[10];
int number;

void init() {
	int i,j;
	for (i = 1; i < number; i++) 
		for (j = 0; j < number; j++) 
			mat[i][j] = 0;
}

void matprinter() {/*                             //Please remove comments to print the DD matrix everytime
	printf("\n\n\n");
	int i,j;
	for (i = 0; i < number; i++) {
		for (j = 0; j < number; j++) {
			printf("\t %lf",mat[i][j
				]);
		}
		printf("\n");
	}*/
}

void ddcalc() {
	int i,j;
	for (i = 1; i < number; i++) {
		for (j = 0; j < number-i; j++) {
			mat[j][i] = mat[j+1][i-1] - mat[j][i-1 ];
		}
	}
//	printf("\nInside ddcalc");
	matprinter();
}


void matfirst() {
	int i;
	for (i = 0; i < number; i++)
	{
		mat[i][0] = fx[i];
	}
	//printf("\nInside Mat first");
	matprinter();
}

void polyprint() { //Polyprint
	int i,j;
	for (i = 0; i < number; i++) {
		printf("%lf*",mat[0][i]);
		for(j = 0;j<i;j++) {
			printf("(x-%lf)",x[j]);
		}
		printf(" + ");
	}
}

void solver(double val) {
	int i,j;
	double temp2 = 1,temp3 = 0;
	for (i = 0 ;i< number;i++) {
		temp = mat[0][i];
		temp2 = 1;
		for(j = 0;j<i;j++) {
			temp2 = temp2 * (val - x[j])
		}
		temp = temp*temp2;
		temp3 += temp;
	}
	printf("The value of Polynomial at %lf is:%lf",val,temp3);
}
void main() {
	
	int i;
	
	printf("\nPlease Enter the number of samples you are going to give(<10):");
	scanf("%d",&number);	
	
	printf("\nPlease Enter the values of X first :");
	for (i = 0; i < number; i++)
		scanf("%lf",&x[i]);
	
	printf("\nPlease Enter the values of F(X) now :");
	for (i = 0; i < number; i++) {
		printf("\nF(%lf) = ",x[i]);
		scanf("%lf",&fx[i]);
	}
	init();
	matprinter();
	matfirst();
	ddcalc();
	polyprint();
}

