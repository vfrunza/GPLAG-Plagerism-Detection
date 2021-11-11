#include <stdio.h>

int dva_od_tri(int* niz1, int n1, int* niz2, int n2, int* niz3, int n3)
{
	int i,j,k;
	int brojac=0, brojac1=0;;

	for(i=0; i<n1; i++) {
		for(j=i+1; j<n1; j++) {
			if(niz1[i]==niz1[j]) {
				niz1[i]=niz1[n1-1];
				n1--;
				j--;
			}
		}
	}


	for(i=0; i<n2; i++) {
		for(j=i+1; j<n2; j++) {
			if(niz2[i]==niz2[j]) {
				niz2[i]=niz2[n2-1];
				n2--;
				j--;
			}
		}
	}

	for(i=0; i<n3; i++) {
		for(j=i+1; j<n3; j++) {
			if(niz3[i]==niz3[j]) {
				n3--;
				j--;
			}
		}
	}


	for(i=0; i<n1; i++) {
		for(j=0; j<n2; j++) {
			if(niz1[i]==niz2[j]) {
				brojac=0;
				for(k=0; k<n3; k++) {
					if(niz2[j]!=niz3[k]) brojac++;
				}
				if(brojac==n3) brojac1++;
			}
		}
	}

	for(i=0; i<n2; i++) {
		for(j=0; j<n3; j++) {
			if(niz2[i]==niz3[j]) {
				brojac=0;
				for(k=0; k<n1; k++) {
					if(niz3[j]!=niz1[k]) brojac++;
				}
				if(brojac==n1) brojac1++;
			}
		}
	}


	for(i=0; i<n1; i++) {
		for(j=0; j<n3; j++) {
			if(niz1[i]==niz3[j]) {
				brojac=0;
				for(k=0; k<n2; k++) {
					if(niz3[j]!=niz2[k]) brojac++;
				}
				if(brojac==n2) brojac1++;
			}
		}
	}
	return brojac1;
}

int main()
{
	int niz1[10] = {0,3,4,4,5,6,7,8,9,0};
	int niz2[10] = {1,1,2,4,5,6,7,8,9,0};
	int niz3[10] = {1,1,1,4,5,6,7,8,9,0};

	printf("%d",dva_od_tri(niz1,1,niz2,1,niz3,1));


	return 0;
}
