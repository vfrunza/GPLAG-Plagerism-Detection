#include <stdio.h>

int dva_od_tri(int niz1[50],int n1, int niz2[50], int n2, int niz3[50], int n3) {
	int brojac=0,i,j,k;
	for(i=0; i<n1; i++){
		for(j=0; j<n2; j++){
			if(niz1[i]==niz2[j])
			brojac++;
		}
	}
	for(i=0; i<n1; i++){
		for(k=0; k<n3; k++){
			if(niz1[i]==niz2[k])
			brojac++;
		}
	}
	for(j=0; j<n2; j++){
		for(k=0; k<n3; k++){
			if(niz1[i]==niz2[j])
			brojac++;
		}
	}
	for(i=0; i<n1; i++){
		for(j=0; j<n2; j++){
			for(k=0; k<n3; k++){
				
				if(niz1[i]==niz2[j]==niz3[k])
				brojac--;
			}
		}
	}
return brojac;	
	
}

int main() {
	int niz1[50], niz2[50], niz3[50],i,j,k,x,y,z;
	printf("Unesite broj elemenata prvog niza: ");
	scanf("%d",&x);
    printf("Unesite elemente prvog niza: ");
	for(i=0; i<x; i++){
		scanf("%d", &niz1[i]);
		if(niz1[i]==-1) break;
	}
	
	printf("Unesite broj elemenata drugog niza: ");
	scanf("%d",&y);
	printf("Unesite elemente drugog niza: ");
	for(j=0; j<y; j++){
		scanf("%d", &niz2[i]);
		if(niz2[i]==-1) break;
	}
	
	printf("Unesite broj elemenata treceg niza: ");
	scanf("%d",&z);
	printf("Unesite elemente treceg niza: ");
	for(k=0; k<z; k++){
		scanf("%d", &niz3[i]);
		if(niz3[i]==-1) break;
	}
	
	
	dva_od_tri(niz1[x],x, niz2[y],y, niz3[z],z);
	
	return 0;
}