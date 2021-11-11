#include <stdio.h>

int main() {
	
	int niz[110], niz_cifri[1000], novi_niz[1010];
	int vel_niz,i,broj,n=0,k=0,br_cif,p=0,brojac;
	int j=0,l=0,cifra,brojac_cifri=0;
	
	printf("Unesite velicinu niza: ");
	do{
	    
	    scanf("%d", &vel_niz);
	    if(vel_niz<=0 || vel_niz>100){
	        printf("Neispravna velicina!\n");
	    }
	} while(vel_niz<=0 || vel_niz>100);
	
	printf("Unesite clanove niza: ");
	
		do{
		
	    scanf("%d", &broj);
	    if(broj<0){
	        printf("Neispravan clan!\n");
	    }
	    if(broj>=0) {
	        niz[n]=broj;
	        n++;
	    }
	} while(n<vel_niz);
	
	
	for(i=0;i<vel_niz;i++){
													
		cifra=niz[i];
		
		while(cifra/10!=0){
			brojac_cifri++;
			cifra=cifra/10;
		}

	
	br_cif=brojac_cifri+1;
	
	niz_cifri[p]=niz[i];
	
	while(niz[i]/10!=0){
		niz_cifri[p+brojac_cifri]=niz[i]%10;
		niz[i]/=10;
		brojac_cifri--;
	}
	niz_cifri[p+brojac_cifri]=niz[i];
	p+=br_cif;
	}
	

	for(i=0;i<p;i++){
		
		brojac=1;
		
	    novi_niz[k]=niz_cifri[i];
	    
	    for(j=i+1;j<p;j++){
	    	
	        if(niz_cifri[j]==niz_cifri[j-1])
	        {brojac++;}
	 		else break;
	    }
	    novi_niz[k+1]=brojac;
	    k=k+2;
	    i+=brojac-1;
}
	
	    printf("Finalni niz glasi:\n");
	    for(l=0;l<k;l=l+2){
	    printf("%d %d ", novi_niz[l], novi_niz[l+1]);
	}
	
	return 0;
}
