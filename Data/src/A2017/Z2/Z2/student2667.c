#include <stdio.h>

int main()
{
	int i,n,niz[100],niz2[100],br=0,brojac=1,j=0,k=0,duzina=0,niz3[100],cifra,broj=0,cifra1;

	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	printf("Unesite clanove niza:");
	for(i=0; i<n; i++) {
		scanf("%d",&niz[i]);
	}
	
	for(i=0; i<n; i++) {
		do {
			cifra1=niz[i]%10;
			if(cifra1==0){
			broj=10*broj;
			}
			else{
			broj=broj*10+cifra1;
				}
			
		niz[i]=niz[i]/10;
		}while(niz[i]!=0);
		do {
			cifra=broj%10;
			broj=broj/10;
			niz2[k]=cifra;
			k++;
			duzina++;
		} while(broj!=0);
}
	
   if(niz2[duzina-1]==niz2[duzina-2]){

	for(i=0; i<duzina; i++) {
	if(i==duzina-1)break;
		else if(niz2[i]==niz2[i+1]) {
			brojac++;
				if(i==duzina-2) {
			niz3[j]=niz2[i];
			niz3[j+1]=brojac;
			br=br+2;
		}
			continue;
		} else {

			niz3[j]=niz2[i];
			niz3[j+1]=brojac;
			brojac=1;
			j=j+2;
			br=br+2;
		}
	} }
	else {	for(i=0; i<duzina; i++) {
		if(i==duzina-1) {
			niz3[j]=niz2[i];
			niz3[j+1]=1;
			br=br+2;
		}
		else if(niz2[i]==niz2[i+1]) {
			brojac++;
			continue;
		} else {

			niz3[j]=niz2[i];
			niz3[j+1]=brojac;
			brojac=1;
			j=j+2;
			br=br+2;
		}
	}

}
	printf(" Finalni niz glasi:\n");
	for(i=0; i<br; i++) {
		printf("%d ",niz3[i]);
	}
	return 0;
}
