#include <stdio.h>

int dva_od_tri( int nizA[], int vel_nizA, int nizB[], int vel_nizB, int nizC[] , int vel_nizC )
{
	int D[10000], A[1000], B[1000], C[1000];
	int i, j, brojac=0, br=0, temp,	min;
	int velA=0, velB=0, velC=0;
	for (i=0; i<vel_nizA; i++) {
		for(j=0; j<velA; j++) {
			if (nizA[i]== A[j]){
				break;
			}
		}
		if (j==velA) {
			A[velA]=nizA[i];
			velA++;
		}
	}
	for (i=0; i<vel_nizB; i++) {
		for(j=0; j<velB; j++) {
			if (nizB[i]==B[j]){
				break;
			}
		}
	
		if (j==velB) {
			B[velB]=nizB[i];
			velB++;
		}
	}
	for (i=0; i<vel_nizC; i++) {
		for(j=0; j<velC; j++) {
			if (nizC[i]== C[j]){
				break;
			}
		}
		if (j==velC) {
			C[velC]=nizC[i];
			velC++;
		}
	}
	
	for ( i=0; i<velA; i++) {
		D[brojac]=A[i];
		brojac++;
	}
	for (i=0; i<velB; i++) {
		D[brojac]=B[i];
		brojac++;
	}
	for (i=0; i<velC; i++) {
		D[brojac]=C[i];
		brojac++;
	}
	for (i=0; i<brojac; i++) {
		min=i;
		for (j=i+1; j<brojac; j++) {
			if( D[j]< D[min] )
				min=j;
		}
		temp=D[i];
		D[i]=D[min];
		D[min]=temp;
	}
	for (i=0; i<brojac-2; i++) {
		if( i==0 ) {
			if (D[i]==D[i+1] && D[i]!=D[i+2]) br++;
		} 
		else if (i==brojac-3) {
			if(D[i]!=D[i+1] && D[i+1]==D[i+2]) br++;
			else if(D[i]==D[i+1] && D[i+1]!=D[i+2]) br++;
		} 
		else {
			if(D[i]!=D[i+1] && D[i+1]==D[i+2] && D[i+2]!=D[i+3]) br++;
		}
	}
	return br;
}

int main()
{
	/*	printf("Zadaća 3, Zadatak 1");*/
	return 0;
}
