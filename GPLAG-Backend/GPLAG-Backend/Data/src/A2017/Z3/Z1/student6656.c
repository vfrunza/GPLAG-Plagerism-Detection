#include <stdio.h>
#include <math.h>
#define duzina 10000

int dva_od_tri(int A[], int duzina_a, int B[], int duzina_b, int C[], int duzina_c)
{
	int i,br_a[duzina]= {0},br_b[duzina]= {0},br_c[duzina]= {0},brojac=0,br_neg_a[duzina]= {0},br_neg_b[duzina]= {0},br_neg_c[duzina]= {0};

	for(i = 0; i < duzina_a; i++) {
		if(A[i] >= 0)
			br_a[A[i]]=1;
		else
			br_neg_a[(int)fabs(A[i])]=1;
	}
	for(i = 0; i < duzina_b; i++) {
		if(B[i] >= 0)
			br_b[B[i]]=1;
		else
			br_neg_b[(int)fabs(B[i])]=1;
	}

	for(i = 0; i < duzina_c; i++) {
		if(C[i] >= 0)
			br_c[C[i]]=1;
		else
			br_neg_c[(int)fabs(C[i])]=1;
	}
	

	for(i = 0; i < duzina; i++) {
		if((br_a[i]!=0 && br_b[i]!=0 && br_c[i]==0) || (br_b[i]!=0 && br_c[i]!=0 && br_a[i]==0) || (br_c[i]!=0 && br_a[i]!=0 && br_b[i]==0)) {
			if(br_a[i] == br_b[i] && (br_a[i] != br_c[i] || br_b[i] != br_c[i])) {
				brojac++;
			}
			if( br_a[i] == br_c[i] && (br_a[i]!=br_b[i]) && br_c[i]!=br_b[i]) {
				brojac++;
			}
			if( br_b[i] == br_c[i] && (br_b[i]!=br_a[i] && br_c[i]!=br_a[i])) {
				brojac++;
			}
		}
	}

	for(i = 0; i < duzina; i++) {
		if((br_neg_a[i]!=0 && br_neg_b[i]!=0 && br_neg_c[i]==0) || (br_neg_b[i]!=0 && br_neg_c[i]!=0 && br_neg_a[i]==0) || (br_neg_c[i]!=0 && br_neg_a[i]!=0 && br_neg_b[i]==0)) {
			if(br_neg_a[i] == br_neg_b[i] && (br_neg_a[i] != br_neg_c[i] || br_neg_b[i] != br_neg_c[i])) {
				brojac++;
			}
			if( br_neg_a[i] == br_neg_c[i] && (br_neg_a[i]!=br_neg_b[i]) && br_neg_c[i]!=br_neg_b[i]) {
				brojac++;
			}
			if( br_neg_b[i] == br_neg_c[i] && (br_neg_b[i]!=br_neg_a[i] && br_neg_c[i]!=br_neg_a[i])) {
				brojac++;
			}
		}
	}
	return brojac;
}

int main()
{
	int i,niz1[100],duzina_1,niz2[100],duzina_2,niz3[100],duzina_3;

	printf("Unesite duzinu za prvi niz: ");
	scanf("%d",&duzina_1);
	printf("Unesite prvi niz: ");
	for(i = 0; i < duzina_1; ++i) {
		scanf("%d",&niz1[i]);
	}

	printf("Unesite duzinu za drugi niz: ");
	scanf("%d",&duzina_2);
	printf("Unesite drugi niz: ");
	for(i = 0; i < duzina_2; ++i) {
		scanf("%d",&niz2[i]);
	}

	printf("Unesite duzinu za treci niz: ");
	scanf("%d",&duzina_3);
	printf("Unesite treci niz: ");
	for(i = 0; i < duzina_3; ++i) {
		scanf("%d",&niz3[i]);
	}

	printf("Broj brojeva koji se javljaju u dva od tri niza: %d",dva_od_tri(niz1,duzina_1,niz2,duzina_2,niz3,duzina_3));

	return 0;
}
