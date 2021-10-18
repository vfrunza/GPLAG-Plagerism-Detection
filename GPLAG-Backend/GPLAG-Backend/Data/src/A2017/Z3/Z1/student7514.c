#include <stdio.h>

int dva_od_tri(int*A, int duzina1, int*B, int duzina2, int* C, int duzina3){
	int i,j,brojaci1[100]={0},brojaci2[100]={0}, brojaci3[100]={0},povratni=0;
	for(i=0; i<duzina1; i++){
		for(j=0; j<duzina2; j++){
		if(A[i]==B[j]) {
			if(brojaci1[A[i]]>=1)
			continue;
		else brojaci1[A[i]]++;
	}
	}
	}
	for(i=0; i<duzina2; i++){
		for(j=0; j<duzina3; j++){
		if(B[i]==C[j]){
			if(brojaci2[B[i]]>=1)
				continue;
		else brojaci2[B[i]]++;
	}
	}
	}
	for(i=0; i<duzina3; i++){
		for(j=0; j<duzina1; j++){
		if(C[i]==A[j]) {
			if(brojaci3[C[i]]>=1)
				continue;
		else brojaci3[C[i]]++;
	}
	}
	}
	for(i=0; i<100; i++){
		if((brojaci1[i]==brojaci2[i]) && (brojaci1[i]==brojaci3[i]) && (brojaci2[i]==brojaci3[i]))
		continue;
		else if(((brojaci1[i]>0 || brojaci2[i]>0) && (brojaci3[i]==0)) || ((brojaci1[i]>0 || brojaci3[i]>0) && (brojaci2[i]==0)) || ((brojaci1[i]==0) && (brojaci2[i]>0 || brojaci3[i]>0)))
		povratni=povratni+brojaci1[i]+brojaci2[i]+brojaci3[i];
	}
	return povratni;
}
		
int main() {
	int A[100], B[100], C[100], i, duzina1=0,duzina2=0,duzina3=0;
	printf("Unesite clanove prvog niza: ");
	for(i=0; i<100; i++){
		scanf("%d", &A[i]);
		if(A[i]==-1) break;
		duzina1++;
	}
	printf("Unesite clanove drugog niza: ");
	for(i=0; i<100; i++){
		scanf("%d", &B[i]);
		if(B[i]==-1) break;
		duzina2++;
	}
	printf("Unesite clanove treceg niza: ");
	for(i=0; i<100; i++){
		scanf("%d", &C[i]);
		if(C[i]==-1) break;
		duzina3++;
	}
	printf("%d", dva_od_tri(A,duzina1,B,duzina2,C,duzina3));
	return 0;
}
