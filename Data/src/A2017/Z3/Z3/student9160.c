#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int izbaci_cifre ( int *niz, int vel, int *cifre, int cvel){
	int k,i,j,pom,p,q,neg=0;
	int pom_niz[10];
	
	//PROVJERA ISPRAVNOSTI NIZA CIFARA
	
	for(i=0;i<cvel;i++){
		if(cifre[i]>9 || cifre[i]<0) return 0;
	}
	
	for(i=0; i<cvel;i++){
		for(j=i+1;j<cvel;j++){
			if(cifre[i]==cifre[j]) return 0;
		}
	}
	
	//BLOK ZA IZBACIVANJE CIFRI
 	//POLAZIMO KROZ NIZ BROJEVA
 	for(i=0;i<vel;i++){
 		neg=0;
 		if(niz[i]<0) neg=1;
 		pom=abs(niz[i]);
 		k=0;
 		
 		//PRETVARANJE INT-A U NIZ CIFARA
 		
 		while(pom!=0){
 			pom_niz[k]=pom%10;
 			pom/=10;
 			k++;
 		}
 		
 		//KLASICNO IZBACIVANJE IZ NIZA
 		
 		for(j=0;j<cvel;j++){
 			for(p=0;p<k;p++){
 				if(cifre[j]==pom_niz[p]){
 					for(q=p;q<k-1;q++){
 						pom_niz[q]=pom_niz[q+1];
 					}
 					p--;
 					k--;
 				}
 			}
 			
 			//PRETVARANJE NIZA CIFARA NAZAD U BROJ
 			
 			pom=0;
 			for(p=0;p<k;p++){
 				pom+=pom_niz[p]*pow(10,p);
 			}
 			if(neg==1) niz[i]=pom*(-1);
 			else niz[i]=pom;
 		}
 		
 	}
 	
 	return 1;
}


int main() {

	int niz[1000],cifre[10];
	int vel,cvel;
	int i,u;

	printf("Unesite dimenzije nizova: ");
	scanf("%d %d", &vel,&cvel);
	
	for(i=0;i<vel;i++) scanf("%d",&niz[i]);
	
	for(i=0;i<cvel;i++) scanf("%d",&cifre[i]);
	
	izbaci_cifre(niz,vel,cifre,cvel);
	
	for(i=0;i<vel;i++){
	printf("%d ",niz[i]);
	}
	
	return 0;
}
