#include <stdio.h>
#define n 100
#define m 300
int da_li_je_u_nizu(int A[], int a, int b){
	int i=0;
	for(i=0; i < a; i+=2){
		if(A[i]==b) {
			return i;}
	}
	return -999;
}
int dva_od_tri(int A[], int a, int B[], int b, int C[], int c){
	int B2[100], C2[100], k=0;
	int br=0, ind[100]={0}, i, j=0;
	for(i = 0; i < b; i++){
		B2[i]=B[i];
	}
	for(i = 0; i < c; i++){
		C2[i]=C[i];}
	for(i = 0; i < a; i++){
	if(da_li_je_u_nizu(ind, j, A[i]) != -999){
	}
	else{
		ind[j]=A[i];
		j++;
		ind[j]++;
		j++;
	}
	}
	for(i = 0; i < b; i++){
		if(B2[i] == -9999) continue;
	if(da_li_je_u_nizu(ind, j, B2[i]) != -999){
		ind[da_li_je_u_nizu(ind, j, B2[i])+1]++;
	}
	else{
		ind[j]=B2[i];
		j++;
		ind[j]++;
		j++;
	}
	for(k = 0; k < b; k++){
		if(B2[i]==B2[k] && i != k){
			B2[k]=-9999;
		}
	}	
	}
	for(i = 0; i < c; i++){
		if(C2[i]==-9999)continue;
	if(da_li_je_u_nizu(ind, j, C2[i]) != -999){
		ind[da_li_je_u_nizu(ind, j, C2[i])+1]++;
	}
	else{
		ind[j]=C2[i];
		j++;
		ind[j]++;
		j++;
	}
		for(k = 0; k < c; k++){
			if(C2[k]==C2[i] && i != k){
				C2[k]=-9999;
			}}
	}
	/*for(i = 0; i < j; i++){
		printf("%d ", ind[i]);
	}*/
	for(i = 1; i < 100; i+=2){
		if(ind[i]==2) br++;
	}
	return br;
}

int main() {
	int niz1[] = {1, 2, 3};
int niz2[] = {4, 5, 6};
int niz3[] = {7, 8, 9};
int rez = dva_od_tri(niz1, 3, niz2, 3, niz3, 3);
printf("%d ", rez);
rez = dva_od_tri(niz1, 3, niz2, 3, niz1, 3);
printf("%d ", rez);
rez = dva_od_tri(niz1, 3, niz1, 3, niz1, 3);
printf("%d ", rez);
rez = dva_od_tri(niz1, 3, niz3, 3, niz3, 3);
printf("%d ", rez);

	/*printf("Unesite dimenzije prvog niza: ");
	scanf("%d", &a);
	printf("Unesite dimenzije drugog niza: ");
	scanf("%d", &b);
	printf("Unesite dimenzije treceg niza: ");
	scanf("%d", &c);
	printf("Unesite prvi niz: ");
	for(i = 0; i < a; i++){
		scanf("%d", &A[i]);
	}
	printf("Unesite drugi niz: ");
	for(i = 0; i < b; i++){
		scanf("%d", &B[i]);
	}
	printf("Unesite treci niz: ");
	for(i = 0; i < c; i++){
		scanf("%d", &C[i]);
	}
	printf("Broj clanova koji su u dva od tri niza je %d", dva_od_tri(A, a, B, b, C, c));*/
	return 0;
}