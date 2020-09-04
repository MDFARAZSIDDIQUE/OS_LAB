#include<stdio.h>
#include<stdlib.h>
int main(){
	int num,j,sum,i,sumwt,sumtt;
	float avgwt,avgtt;
	printf("Enter number of processes	: ");
	scanf("%d",&num);
	int *a,*b;
	a=(int*)malloc(num*sizeof(int));
	for( i=0;i<num;i++){
		printf("\nEnter burst time for process %d	:",i);
		scanf("%d",&a[i]);
	}
	b=(int*)malloc(num*sizeof(int));
	for( i=0;i<num;i++){
		if(i==0){
			b[i]=0;
		}
		else{
			sum=0;
			for (j=0;j<i;j++){
				sum=sum+a[j];
			}
			b[i]=sum;
		}
	}
	sumwt=0,sumtt=0;
	printf("PROCESS		BURST TIME		WAITING TIME	TURNAROUND TIME");
	for (i=0;i<num;i++){
		
		printf("\n	P%d			%d				%d						%d",i,a[i],b[i],b[i]+a[i]);
		sumwt=sumwt+b[i];
		sumtt=sumtt+b[i]+a[i];
	}
	avgwt=sumwt/num;
	avgtt=sumtt/num;
	printf("\nAverage waiting time= %6.6f",avgwt);
	printf("\nAverage turnaround time=%6.6f",avgtt);
}
