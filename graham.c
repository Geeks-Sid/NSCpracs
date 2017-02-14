#include<stdio.h>

int number,dimensions;
float a[10][10],k[10];
float v[10][10];

void scanning() {
	int i,j;
	for (i = 0; i < number; i++) {
		printf("\nEnter the co-ordinates of vector %d:",i+1);
		for (j = 0; j < dimensions ; j++) {
			scanf("%f",&a[i][j]);
		}
	}
}

void printing() {
	int i,j;
	printf("\nThe vector space looks like this\n");
	for (i = 0; i <number; ++i) {
		printf("Vector %d:",i+1);
		for(j=0;j<dimensions;j++) 
			printf("%f\t",a[i][j]);
		printf("\n");
	}
}

float norming(int row3) {
	float sum=0;
	int i;
	for(i=0;i<dimensions;i++) {
		sum+=v[row3][i]*v[row3][i];	
	}
	return sum;
}

float dotting(int row1,int row2) {
	float dot=0;
	int i;
	for (i=0;i<dimensions; i++) {
		dot+=a[row1][i]*v[row2][i];
	}
	return dot;
}

void worker() {
	int i,j,k;
	for(i=0;i<number;i++) {      // Here we have initialised vi = ui
		for (j=0;j<dimensions; j++) {
			v[i][j] = a[i][j];
		}
		for(j=0;j<i;j++) {
			float dotp=dotting(i,j);
			float norm=norming(j);
			float w=dotp/norm;
			for(k=0;k<dimensions;k++) {
				v[i][k] -= v[j][k] * w;
			}
		}
	}	
//Working from here
}

void main() {
	int i,j;
	printf("Enter the number of vectors:");
	scanf("%d",&number);
	printf("\nEnter the dimensions of vectors:");
	scanf("%d",&dimensions);
	printf("\nPlease start entering the vectors as their constants one by one as ordered:\n");
	scanning();
	printing();
	worker();
	printf("\nThe vector space looks like this\n");
	for (i = 0; i <number; ++i) {
		printf("Vector %d:",i+1);
		for(j=0;j<dimensions;j++) 
			printf("%f\t",v[i][j]);
		printf("\n");
	}
}