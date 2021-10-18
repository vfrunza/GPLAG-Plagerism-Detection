#include <stdio.h>

int main() {
	int niz[100], nizf[1000];
	int n;
	int duzina=0;
	int pom,i;
	printf("Unesite velicinu niza: ");
	do{
		scanf("%d",&n);
		
	} while(n<=0);
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++){
		scanf("%d", &niz[i]);
	}
	
	for(i=n-1;i>=0;i--){
		pom=niz[i];
		while(pom!=0){
			nizf[duzina++]=pom%10;
			pom/=10;
		}
	}
	
	for(i=0;i<duzina/2;i++){
		
		pom=nizf[i];
		nizf[i]=nizf[duzina-1-i];
		nizf[duzina-1-i]=pom;
	}
	printf("Finalni niz glasi: ");
		for(i=0;i<duzina;i++){
		printf("%d", nizf[i]);
		}
	
	return 0;
}
