#include <stdio.h>

int main() {
	int vel, niz[100], cifra=0; finalni[10000]={0}, b=0, i;
	printf("Unesite velicinu niza: ");
	do{
		scanf("%d", &vel);
	}while (vel<=0 || vel>100);
	printf("Unesite clanove niza: ");
	for(i=0;i<vel;i++){
		scanf("%d", &niz[i]);
		b=niz[i];
		while (niz[i]!=0) {
			cifra=niz[i]%10;
			niz[i]/=10;
			
			
		}
	}
	
	printf("Finalni niz glasi:  ");
	for(i=0;i<vel;i++){
		if (i%2==0) {
			for(j=vel-1;j>i;j--){
				niz[j]==niz[j-1];
			}
			if (niz[i]!=niz[j]) {
				niz[i+1]=brojac;
				vel++;
			}
		}
	}
	for(i=0;i<n;i++) printf("%d ", niz[i]);
	
	return 0;
} 