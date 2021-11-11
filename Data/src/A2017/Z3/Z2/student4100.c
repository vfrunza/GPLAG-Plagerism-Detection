#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void zaokruzi1 (float *niz, int vel){
	int i;
	
	//KLASICAN BLOK KODA ZA ZAOKRUZIVANJE NA JEDNU DECIMALU
	
	for(i=0;i<vel;i++){
		niz[i]*=10;
		niz[i]=round(niz[i]);
		niz[i]/=10;
	}
}


void preslozi (float *niz, int vel, int n){

	int i,suma=0;
	int j=0,k=0,s,pom;
	float pom_niz1[1000],pom_niz2[1000];
	
	zaokruzi1(niz,vel);
	
	//PROLAZAK KROZ NIZ I SABIRANJE CIFARA CLANOVA NIZA
	
	for(i=0;i<vel;i++){
		pom=abs(niz[i]*10);
		suma=0;
		
		while(pom!=0){
			suma+=pom%10;
			pom/=10;
		}
		
		//POREDJENJE SUMA SA PROIZVOLJNIM BRIJEM UNESENIM SA TASTATURE
		
		if(suma>=n){
			pom_niz1[k]=niz[i];
			k++;
		}
		else if(suma<n){
			pom_niz2[j]=niz[i];
			j++;
		}
	}
	
	//PRESLAGANJE NIZA 
	
	for(i=0;i<k;i++){
		niz[i]=pom_niz1[i];
	}
	for(i=k;i<vel;i++){
		niz[i]=pom_niz2[i-k];
	}

}



int main() {
	
	float niz[1000];
	int i,vel,k;
	
	printf("Dimenzija niza je : ");
	scanf("%d",&vel);
	
	for(i=0;i<vel;i++){
		scanf("%f",&niz[i]);
	}
	
	printf("Proizvoljan broj k: ");
	scanf("%d",&k);
	
	preslozi(niz,vel,k);
	
	return 0;
}
