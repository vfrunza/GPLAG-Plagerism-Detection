#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
int *izbaci_cifre(int *niz_1, int velicina_1, int *niz_2, int velicina_2) {
	int j=0,i,z=0,e=0,l=0,brojac_cifara=0,novi_niz[MAX]={0},element=0,h=0,broj=0;
	int *rez=niz_1;
	int novi_niz2[MAX]={0};
	for(i=0;i<velicina_1;i++) {
		element=(*(niz_1+i));
		brojac_cifara=0;
		do{ 
			element=element/10;
			brojac_cifara++;
		} while(element!=0);
		element=(*(niz_1+i));
	do {
		for(j=brojac_cifara;j>0;j--) {
			novi_niz[e]=element/pow(10,j-1);
			element=element%((int)((pow(10,j-1))));
			e++;
		}	
		}while(e<brojac_cifara);
			
		
		for(e=0;e<brojac_cifara;e++) { 
		for(z=0;z<velicina_2;z++){
			if(novi_niz[e]==niz_2[z]) {
				for(l=e;l<brojac_cifara;l++){
					novi_niz[l]=novi_niz[l+1];
				}
				brojac_cifara--;
				l--;
			}
			
		} 
			
		}
		for(z=0;z<brojac_cifara;z++){
			broj += novi_niz[z]*pow(10,brojac_cifara-z-1);
		}
		novi_niz2[h] = broj;
		h++;
		

		
	}
	rez=novi_niz2;
	
	return rez;
}
int main() {
	int i=0,k=0,velicina_1=0,velicina_2=0;
	int niz_1[MAX]={0},niz_2[MAX]={0};
	int *rez;
	printf("Unesite velicinu niza brojeva: "); 
	scanf("%d",&velicina_1);


	printf("Unesite elemente niza brojeva: ");
	for(i=0;i<velicina_1;i++) {
		scanf("%d",&niz_1[i]);
		
	}
	printf("Unesite velicinu niza cifara: ");
	scanf("%d",&velicina_2); 
	printf("Unesite elemente niza cifara: ");
	for(k=0;k<velicina_2;k++) {
		scanf("%d",&niz_2[k]); 
		
	}
	rez=izbaci_cifre(niz_1,velicina_1,niz_2,velicina_2);
	printf("%d",*rez);
	return 0;
}