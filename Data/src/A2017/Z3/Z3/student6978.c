#include <stdio.h>
#include<stdlib.h>
void izbaci_cifre (int* niz, int velicina1, int* cifra, int velicina2)
{
	int i,j,pom,desetka=1,temp;
	for (i=0; i<velicina1; i++) {
		for (j=0; j<velicina2; j++) {
		desetka=1;
			if (niz[i]>=0){
				pom=niz[i];
			if (pom%10==cifra[j]) {
				  niz[i]=pom/10;
				 desetka*=10;
				 
			}
			
			while(pom!=0){
				pom/=10;
				desetka*=10;
				if (pom<10){
					if (pom==cifra[j]) niz[i]=(pom/10)*desetka*10+niz[i]%(desetka);
					
				}
			else	if (pom%10==cifra[j]) {niz[i]=(pom/10)*desetka+niz[i]%(desetka);
					desetka/=10;
				}
			
			}}
			else {
			pom=abs(niz[i]);
			temp=abs(niz[i]);
			if (pom%10==cifra[j]) {
				
				  temp=pom/10;
				 
				 
			}
			
			while(pom!=0){
				pom/=10;
				desetka*=10;
				if (pom%10==cifra[j]) temp=(pom/10)*desetka+temp%(desetka);
			
			}	
			
			niz[i]=temp*(-1);
		}

	}

}
}
int main()
{
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
