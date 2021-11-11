#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#define PI 3.1415926
#define MAX 500
int main() {
	double ugao,A[MAX];
	int i,step,min,sec,n;
	printf("Unesite broj uglova: ");
	scanf("%d",  &n);
	printf("Uglovi su:\n");
	for(i=0;i<n;i++){
		scanf("%lf", &A[i]);
		if (A[i]>=0) {
	
	ugao=A[i]*(180./PI);
	step=(int)ugao;
	
	min=(int)(((ugao-step)*3600+0.5)/60);
	
	sec=((int)((ugao-step)*3600+0.5)%60);
	
	
	if(min==60) {
		step++;
		min=0;
	}
	if(sec<=30) printf("%d stepeni %d minuta %d sekundi\n", step,min,sec);
	
		}
		else {
			A[i]=-A[i];
			ugao=A[i]*(180./PI);
	step=(int)ugao;
	
	min=(int)(((ugao-step)*3600+0.5)/60);
	
	sec=((int)((ugao-step)*3600+0.5)%60);
	
	
	if(min==60) {
		step++;
		min=0;
	}
	if(sec<=30)
	printf("-%d stepeni %d minuta %d sekundi\n" , step,min,sec);
		} }
		
	return 0;
}
