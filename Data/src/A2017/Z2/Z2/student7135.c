#include <stdio.h>

int main() {
	int a,indeks,i,help,lol,brojac,j;
	int niz[100],drugi[1000];
	do {
	printf("Unesite velicinu niza: ");

	scanf("%d",&a);
	}while(a<=0);
	
	
	printf("Unesite clanove niza: ");
	for(i=0;i<a;i++) {
		do {
		scanf("%d",&niz[i]);
		}while(niz[i]<0);
	}
	i=0;
	indeks=0;
	while(i<a) {
		brojac=0;
		if(niz[i]==0){
			drugi[indeks]=niz[i];
			indeks++;
			i++;
			continue;
		}
		help=niz[i];
		while(help>0) {
			help=help/10;
			brojac++;
		}
		lol=brojac;
		help=niz[i];
		while(help>0) {
			drugi[indeks+brojac-1]=help%10;
			help=help/10;
			brojac--;
		}
		indeks=indeks+lol;
		i++;
		
	}
		
		i=0;
		while(i<indeks) {
				brojac=0;
				lol=i;
			if(drugi[lol]==drugi[i]){
				
			while(lol<indeks) {
			if(drugi[lol] != drugi[i] || lol>=indeks || i>=indeks ) break;

				brojac++;
				lol++;
			}
			}
			if(brojac==1) {
				for(j=indeks; j>i;j--) drugi[j]=drugi[j-1];
				j++;
				drugi[j]=1;
				i=j;
				i++;
				indeks++;
				continue;
			}
			else if(brojac==2) {
				i++;
				drugi[i]=2;
				i++;
				continue;
			}
			else {
				i++;
				drugi[i]=brojac;
				i++;
				for(j=i;j<indeks+brojac-2;j++) {
					drugi[j]=drugi[j+brojac-2];
				}
				indeks=indeks-(brojac-2);
				continue;
			}
			
		}
			
			
			
			
		
		
			printf("Finalni niz glasi:\n");
	for(i=0;i<indeks;i++){
		printf("%d ",drugi[i]);
	}
	
	return 0;
}
