#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
#define br 500

int main() {
	int n,i,j,k,l,m,B[br]={0},C[br]={0},D[br]={0};
	double A[br]={0},a,E[br]={0};
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for (i=0;i<n;i++){
		scanf("%lf", &E[i]);
	}
	for (i=0;i<n;i++){
		if(E[i]<0){
		A[i]=-1*E[i];
		}else{
		A[i]=E[i];
		}
	}
	//--------------------------------------------------------------------------
	for (j=0;j<n;j++){
		a=A[j]*(180/PI);
		B[j]=a;
		a=(a-B[j])*60;
		C[j]=a;
		a=(a-C[j])*60;
		a=a+0.5;
		D[j]=a;
	}
	//--------------------------------------------------------------------------
	for(j=0;j<n;j++){
	if (D[j]==60){
			C[j]++;
			D[j]=0;
	}
	//--------------------------------------------------------------------------
	if (C[j]==60){
		B[j]++;
		C[j]=0;
	}
	}
	//--------------------------------------------------------------------------
	for (k=0;k<n;k++){
		if (D[k]>30 || D[k]<-30){
			for (l=k;l<n-1;l++){
				B[l]=B[l+1];
				C[l]=C[l+1];
				D[l]=D[l+1];
			}
			n--;
			k--;
		}
	}
	//--------------------------------------------------------------------------
	printf("Uglovi su:\n");
	for (m=0;m<n;m++){
		if (E[m]<0){
		printf ("-%d stepeni %d minuta %d sekundi\n",B[m],C[m],D[m]);
		}else{
		printf ("%d stepeni %d minuta %d sekundi\n",B[m],C[m],D[m]);
		}
	}
	return 0;
}