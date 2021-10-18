#include <stdio.h>

#define broj_el 100

int main() {
	int i,n,niz[broj_el],brojac[broj_el+broj_el]={0};

	do{
		printf("Unesite velicinu niza: ");
		scanf("%d",&n);
	}while(n<0 || n>100);
	
	do{
		printf("Unesite clanove niza: ");
		for(i=0;i<n;i++){
		scanf("%d",&niz[broj_el]);}
	}while(niz[broj_el]<0);
	
	n=i;
	for(i=0; i<n; i++){
		brojac[niz[i]]++;
	printf("%d ",niz[i]);
			
	}
	
	return 0;
}
	

	
	
	
	

