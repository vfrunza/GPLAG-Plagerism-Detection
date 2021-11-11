#include <stdio.h>
#define EL1 100
#define EL2 1000

int main() {
	
	int velicina,i=0,niz[EL1],x,broj,j=0,niz2[EL2],brojac=1,vec,niz3[EL2],z=0;
	
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d",&velicina);
		}while(velicina<=0 || velicina>100 );
		
	printf("Unesite clanove niza: ");
	for(i = 0; i < velicina; i++){
	     scanf("%d",&niz[i]);
	    if(niz[i]<0){
	    	i--;
	    }
	}
	
	for(i = velicina-1; i >= 0; i--){
		x=1;
		
		while(x==1 || niz[i]!=0){ 
			broj=niz[i]%10;
		    niz[i]/=10;
		    if(niz[i]/10==0)
		    x=0;
		    niz2[j]=broj;
		    j++;
		    
		}
	}
	
	
	for( i = j-1; i >= 0; i--){
		if (i==0){
		niz3[z]=niz2[i];
		z++;;
		niz3[z]=brojac;
			break;
		}
		
		else if(niz2[i]==niz2[i-1]){
		brojac++;
			
		}
		else if(niz2[i]!=niz2[i-1]){
		niz3[z]=niz2[i];
		z+=1;
		niz3[z]=brojac;
		z++;
		brojac=1;
		}
	}
	vec=z;
	
	printf("Finalni niz glasi: \n");
	for(i = 0; i <= vec; i++){
		printf("%d ",niz3[i]);
	}
	return 0;
}
