#include <stdio.h>
#include <math.h>
#define MAX 100

int main() {
	int niz[MAX]={0},i=0,j=0,e=0,k=0,novi_niz_cifara[1000]={0},novi_niz[1000]={0};
	int velicina_niza=0,brojac_cifara=0,element=0,z=0;
	do {
	printf("Unesite velicinu niza: ");
	scanf("%d",&velicina_niza);
	}while(velicina_niza<0 || velicina_niza>100);
	unos: printf("Unesite clanove niza: ");
	for(i=0;i<velicina_niza;i++){
		scanf("%d",&niz[i]);
		if (niz[i]<0) {
			goto unos;
		}
		
	}
	for(i=0;i<velicina_niza;i++) {
		element=niz[i];
		brojac_cifara=0;
		do{
			element=element/10;
			brojac_cifara++;
			
		}while(element!=0);
		for(j=brojac_cifara;j>0;j--) {
			novi_niz_cifara[e]=niz[i]/(pow(10,j-1));
			niz[i]=niz[i]%(int( ((pow(10,j-1));
			e++;	
			
		}
		
	}
	for(i=k=0;i<e;i++){
		brojac_cifara=0;
		novi_niz[k]=novi_niz_cifara[i];
		k++;
		while(novi_niz_cifara[i]==novi_niz_cifara[i+brojac_cifara] && i+brojac_cifara<e){
			brojac_cifara++;
			
		}
		novi_niz[k]=brojac_cifara;
		i=i+brojac_cifara-1;
		k++;
		
	}
	printf("Finalni niz glasi: \n");
	for(z=0;z<k;z++){
		printf("%d ",novi_niz[z]);
		
	}
	return 0;
}