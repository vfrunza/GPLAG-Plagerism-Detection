#include <stdio.h>
#include <math.h>
#define velicina_C 1000

int main()
{
	int i,j,k;
	int n,b,c,velicina_B=0;
	int A[101],A_Copy[101];
	int B[1000]= {0},C[velicina_C]= {0},Brojaci[101];
	int s[101]= {0};

	/* A - Niz
	A_Copy - Niz identican nizu A
	Brojaci - Niz brojaca
	B - Razlozen niz A
	C - Finalni niz */

	for(b=0; b<101; b++) {
		Brojaci[b]=1;
	}

	do {
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
	} while(n<=0 || n>101);

	printf("Unesite clanove niza: ");
	for(k=0,i=0; i<n; i++) {
		scanf("%d",&A[i]);
		A_Copy[i]=A[i];

		if(A[i]<0)
			i--;

		else if(A[i]>10) {
			while(A[i]!=0) {
				A[i]/=10;
				s[i]++;
			}

			while(s[i]!=0) {
				B[k]=(int)(A_Copy[i]/pow(10,s[i]-1)) % 10;
				k++;
				s[i]--;
				velicina_B++;
			}
		}

		else {
			B[k]=A_Copy[i];
			k++;
			velicina_B++;
		}
	}


	for(i=0,j=0,k=0; i<velicina_B; i++,j++,k+=2) {
		c=i;
		while(B[c]==B[j+1] && c<velicina_B && (j+1)<velicina_B) {
			Brojaci[B[c]]++;
			j++;
			i++;
		}

		C[k]=B[c];
		C[k+1]=Brojaci[B[c]];

		for(b=0; b<101; b++)
			Brojaci[b]=1;
	}

	printf("Finalni niz glasi:\n");
	for(i=0; i<velicina_B*2; i++)
		if(C[i]!=0 && (C[i+1]==0 && C[i+2]==0))
			printf("%d", C[i]);
		else if (C[i]==0 && C[i+1]==0)
			break;
		else printf("%d ", C[i]);
	return 0;
}
