#include <stdio.h>
#define br_el 100

int dva_od_tri(int *p1,int x,int *p2,int y, int *p3, int z) {
	
	int i,j,k,l;
	int brojac=0;

	for(i=0;i<x;i++) {
		for(l=0;l<i;l++)
			if(p1[i]==p1[l]){
				l=-1;
				break;
			}
		if(l==-1)
			continue;
		for(j=0;j<y;j++) {
			if(p1[i]==p2[j]) {
				brojac++;
				for(k=0;k<z;k++) {
					if(p3[k]==p1[i]) {
						brojac--;
						break;
					}
				}
				break;
			}
		}
	}
	for (i=0;i<y;i++) {
		for(l=0;l<i;l++)
			if(p2[i]==p2[l]){
				l=-1;
				break;
			}
		if(l==-1)
			continue;
		for(j=0;j<z;j++) {
			if(p2[i]==p3[j]) {
				brojac++;
				for(k=0;k<x;k++) {
					if(p1[k]==p2[i]) {
						brojac--;
						break;
					}
				}
				break;
			}
		}
	}
	for (i=0;i<z;i++) {
		for(l=0;l<i;l++)
			if(p3[i]==p3[l]){
				l=-1;
				break;
			}
		if(l==-1)
			continue;
		for (j=0;j<x;j++) {
			if (p3[i]==p1[j]) {
				brojac++;
				for(k=0;k<y;k++) {
					if(p2[k]==p3[i]) {
						brojac--;
						break;
					}
				}
				break;
			}
		}
	}
	return brojac;
}
int main() {

	int i,j,k;
	int niz1[br_el],niz2[br_el],niz3[br_el],brojac1;
	
	do { 
	printf("Unesite elemente 1.niza: ");
	for (i=0;i<br_el;i++) {
		scanf("%d", &niz1[i]);
		if (niz1[i]==-1) break;
	}
	printf("Unesite elemente 2. niza: ");
	for (j=0;j<br_el;j++) {
		scanf("%d", &niz2[j]);
		if (niz2[j]==-1) break;
	}
	printf("Unesite elemente 3. niza: ");
	for (k=0;k<br_el;k++) {
		scanf("%d", &niz3[k]);
		if (niz3[k]==-1) break;
	}
	} while (i==j || j==k || k==i);

	brojac1 = dva_od_tri(niz1,i,niz2,j,niz3,k);
	printf("Broj clanova koji se javljaju u 2 od 3 niza: %d", brojac1);
	return 0;
}
