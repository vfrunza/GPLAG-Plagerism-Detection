#include <stdio.h>

int main() {
	int finalni[1000],i,j=0,n=3,brojac=0,pom,suma,poredi;
	int br = 0;
	int niz[100];
   printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	printf("Unesite clanove niza: ");
	 	for(i = 0; i < n; i++)scanf("%d",&niz[i]);

	printf("Finalni niz glasi: \n");
	for(i = 0; i < n; i++){
		suma = 0;
		pom = niz[i];
		while(pom != 0){
			br++;
			suma =suma*10 + pom%10;
			pom/=10;
		}
		if(suma== 0)br++;
	pom = suma;
	if(brojac == 0)	poredi = pom%10;
		while (pom!=0 || br != 0) {
			 if(poredi == pom%10 ){brojac++; pom/=10;br--;}
			else{
				finalni[j] = poredi;
				finalni[++j]=brojac; brojac=0; j++; poredi = pom%10;
			}
		}
		
		if(i == n-1 && pom == 0){
			finalni[j]=poredi; finalni[++j] = brojac;j++; 
		}
	}
	for(i = 0; i <j; i++ )
	printf("%d ",finalni[i]);
	return 0;
}
