#include <stdio.h>

int main() {
	int n,niz[100],brojaci[101]={0},finalni[1000],i;
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
	} while(n<=0 || n>100);
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++){
		scanf("%d", &niz[i]);
		if(niz[i]<0) continue;
	}
	
	for(i=0;i<101;i++){
		brojaci[niz[i]]++;
	}
	
	
	return 0;
}
