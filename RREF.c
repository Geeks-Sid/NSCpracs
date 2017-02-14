#include<stdio.h>
float a[10][10];
int r,c,count=0,cnt=0,arr[10][2];
int temp1;
void swap(int i1,int i2);
void fun(int x,int y);
void REF(int x,int y)
{
    int i,j;
    for(j=y;j<c;j++)
    {
     	for(i=x;i<r-count;i++)
 	    {
 		    if(a[i][j]!=0)
 		    {
 			    if(i!=x)
 			    swap(i,x);
 			    fun(x,j);
 			    arr[cnt][0]=x;
 		    	arr[cnt][1]=j;
 			    cnt++;
 			    REF(x+1,j+1);
 			    return;
 		    }
 	    }
    }
}
void swap(int i1,int i2)
{
	int temp;
	int j;
	for(j=0;j<c;j++)
	{
		temp=a[i1][j];
		a[i1][j]=a[i2][j];
		a[i2][j]=temp;
	}
}
void fun(int x,int y)
{
	float temp;
	int i,j;
	temp=a[x][y];
	if(temp!=1)
	for(j=0;j<c;j++)
	a[x][j]=a[x][j]/temp;
	for(i=x+1;i<r-count;i++)
	{
		temp=a[i][y];
		if(temp!=0)
		for(j=0;j<c;j++)
		a[i][j]=a[i][j]-a[x][j]*temp;
	}
}
swap1(int i)
{
	int j;
	float temp;
	for(j=0;j<c;j++)
	{
		temp=a[i][j];
		a[i][j]=a[r-count-1][j];
		a[r-count-1][j]=temp;
	}
	count++;
}
void RREF(int z)
{
	float temp;
	int i,j,x,y;
	x=arr[z][0];
	y=arr[z][1];
	for(i=x-1;i>=0;i--)
	{
		if(a[i][y]!=0)
		{
			temp=a[i][y];
			for(j=0;j<c;j++)
			a[i][j]-=a[x][j]*temp;}
			if(z>0)
			RREF(z-1);
			
		}
}
int main()
{
    int i,j;	
	printf("enter the size of r and c");
	scanf("%d%d",&r,&c);
	printf("Enter matrix:");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			{
				scanf("%f",&a[i][j]);
			}
			printf("\n");
		}
    printf("enterd matrix is :\n");
	for(i=0;i<r;i++)
		{
		for(j=0;j<c;j++)
		{
			printf("%f ",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<r-count;i++)
	{
		temp1=0;
		for(j=0;j<c;j++)
		{
			if (a[i][j]!=0)
			{
				temp1=1;
				break;
			}
		}
		if(temp1==0)
		{
			swap1(i);
			i--;
    	}
	}
	REF(0,0);
	RREF(cnt-1);
	printf("Reduced matrix is :\n");
		for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		printf("%f ",a[i][j]);
		}
		printf("\n");
	}
	return 1;
}