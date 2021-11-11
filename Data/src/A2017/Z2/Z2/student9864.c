#include <stdio.h>

int main() {
	int vel,i,cifra,m,brojac;
	int polazni_niz[100];
	int cifre_broja[100], okrenute_cifre[100];
	int k=0;
	
	
	printf("Unesite velicinu niza: ");
	do{
		scanf("%d",&vel);
	}while(vel>100);
	
	printf("Unesite clanove niza: ");
	for(i=0;i<vel;i++){
		do{
		scanf("%d",&polazni_niz[i]);
		}while(polazni_niz[i]<=0);
	}
	
	for(i=0;i<vel;i++){
		/*u niz cifre_broja stavljam cifre*/
		do{
			cifra=polazni_niz[i]%10;
			polazni_niz[i]=polazni_niz[i]/10;
			cifre_broja[k]=cifra;
			k++; 
		}while(polazni_niz[i]!=0); 
		
		/*u niz okrenute_cifre okrenem niz cifre_broja*/
			brojac=k-1;
			for(m=0;m<brojac;m++){	
			okrenute_cifre[m]=cifre_broja[brojac];
			brojac--; printf("%d ", okrenute_cifre[m]);
					}
	}
	

	return 0;
}
