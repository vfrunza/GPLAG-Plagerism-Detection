#include <stdio.h>

int main() {
	int niz[100]={0},niz1[1000]={0},n,k=0,i=0,brojac=0,broj,brojac2=0,broj_mijesta=0,niz2[1000]={0},br_clanova=0,cifra;
	
    printf("Unesite velicinu niza: ");
    scanf("%d",&n);
    printf("Unesite clanove niza: ");
    for(i=0;i<n;i++){
    	scanf("%d",&niz[i]);
    }
    
    for(i=0;i<n;i++){
    	broj=niz[i];
    	while(broj!=0){
    	    brojac++;
    	    broj/=10;
    	}
    	if(niz[i]==0) {niz1[brojac+1]=0; brojac++;}
    	while(niz[i]!=0){
    	    cifra=niz[i]%10;
    	    niz1[brojac-k-1]=cifra;
    	    k++;
    	    niz[i]/=10;
    	}
    	k=0;
    }
    k=0;
    for(i=0;i<brojac;i++){
        niz2[k]=niz1[i];
        while(i<brojac-1 && niz1[i]==niz1[i+1]){
            brojac2++;
            i++;
        }
        niz2[k+1]=brojac2+1;
        brojac2=0;
        k+=2;
        
    }
    
    printf("Finalni niz glasi: \n");
    for(i=0;i<k;i++){
        printf("%d ",niz2[i]);
    }
	return 0;
}
