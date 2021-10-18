#include <stdio.h>
int izbaci_duple(int *niz,int duzina)
{
	int i,k,j,t;
	int novi[100];
	k=0;
	for(i=0; i<duzina; i++) {
		novi[i]=niz[i];
	}
	for(i=0; i<duzina; i++) {
		t=1;
		for(j=0; j<i; j++) {
			if(novi[j]==novi[i]) {
				t=0;
				break;
			}
		}
		if(t==1) {
			niz[k]=novi[i];
			k++;
		}
	}
	return k;
}
int dva_od_tri(int *niz1,int v1,int *niz2,int v2,int *niz3,int v3)
{
	int i,j,k,v11,v22,v33,brojac=0,t=0;
	v11=izbaci_duple(niz1,v1);
	v22=izbaci_duple(niz2,v2);
	v33=izbaci_duple(niz3,v3);
	for(i=0; i<v11; i++) {
		for(j=0; j<v22; j++) {
			if(niz1[i]==niz2[j]) {
				t=1;
				for(k=0; k<v33; k++) {
					if(niz1[i]==niz3[k]) {
						t=0;
					}
				}
				if(t) {
					brojac++;
				}
			}
		}
	}
	for(i=0; i<v11; i++) {
		for(j=0; j<v33; j++) {
			if(niz1[i]==niz3[j]) {
				t=1;
				for(k=0; k<v22; k++) {
					if(niz1[i]==niz2[k]) {
						t=0;
					}
				}
				if(t) {
					brojac++;
				}
			}
		}
	}
	for(i=0; i<v22; i++) {
		for(j=0; j<v33; j++) {
			if(niz2[i]==niz3[j]) {
				t=1;
				for(k=0; k<v11; k++) {
					if(niz2[i]==niz1[k]) {
						t=0;
					}
				}
				if(t) {
					brojac++;
				}
			}
		}
	}
	return brojac;
}
int main()
{
	int niz1[100],niz2[100],i,niz3[100],v1,v2,v3;
	printf("Unesite velicinu niza1: ");
	scanf("%d",&v1);
	printf("Unesite niz1: ");
	for(i=0; i<v1; i++) {
		scanf("%d",&niz1[i]);
	}
	printf("Unesite velicinu niza2: ");
	scanf("%d",&v2);
	printf("Unesite niz2: ");
	for(i=0; i<v2; i++) {
		scanf("%d",&niz2[i]);
	}
	printf("Unesite velicinu niza3: ");
	scanf("%d",&v3);
	printf("Unesite niz3: ");
	for(i=0; i<v3; i++) {
		scanf("%d",&niz3[i]);
	}
	printf("\n K1 = %d",dva_od_tri(niz1,v1,niz2,v2,niz3,v3));
	return 0;
}
