#include <stdio.h>

int main() {
	int niz[100], niz1[1000], niz2[1000];
	int i, j=0, m, vel, vel1=0, bc, t=0;
    int pom, pom1, cifra, temp, brojac;
    
	printf("Unesite velicinu niza: ");
	scanf("%d", &vel);
	printf("Unesite clanove niza: ");
	for(i=0; i<vel; i++){
	    scanf("%d", &niz[i]);
	}
	
	/* Prebrojavanje cifara u unesenom nizu */
	for(i=0; i<vel; i++){
		bc=1; pom=niz[i];
		cifra=pom%10;
		pom/=10;
		while(pom!=0){
			cifra=pom%10;
			bc++; 
			pom/=10;
		}  
		vel1+=bc;
	}
	
	/* Formiranje niza1 pomocu cifara unesenog niza */
	for(i=vel-1; i>=0; i--){
		pom1=niz[i];
		cifra=pom1%10;
		pom1/=10;
		niz1[j]=cifra;
		while(pom1!=0){
			j++;
			cifra=pom1%10;
			niz1[j]=cifra;
			pom1/=10;
		}
		j++;
		if(j==vel1) break;
	}
	
	/* Okretanje niza */
	j=vel1-1;
	for(i=0; i<vel1/2; i++){
		if(i!=j){
			temp=niz1[i];
			niz1[i]=niz1[j];
			niz1[j]=temp;
		}
		j--;
	}
	
	/* Formiranje finalnog niza */
	for(i=0; i<vel1; i++){
		brojac=1;
		for(j=i+1; j<vel1; j++){
			if(niz1[i]==niz1[j]){
				brojac++;
				for(m=i; m<vel1-1; m++){
					niz1[m+1]=niz1[m+2];
				}
				vel1--;
				j--;
			}
			else if(niz1[i]!=niz1[j]){
				break;
			}
		}
		 niz2[t]=niz1[i];
		 niz2[t+1]=brojac;
		 t+=2;
	}
	
	/* Ispis finalnog niza*/
	printf("Finalni niz glasi:\n");
	for(j=0; j<t; j++){
	    printf("%d ", niz2[j]);
	}
	
	return 0;
}
