#include <stdio.h>

int okreni_broj(int broj){
	int novi=0;
	while(broj!=0){
		novi*=10;
		novi+=broj%10;
		broj/=10;
	}
	return novi;
}

int main() {
	int a[100], b[1000]={0};
	int dodatni[10000];
	int i, k, j_vel=0, vel, brojac=0, brojac_nula=0;
	int temp;
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d", &vel);
	}while(vel<1 || vel>100);
	printf("Unesite clanove niza: ");
	for(i=0; i<vel; i++){
		scanf("%d", &a[i]);
		if(a[i]<0) i--;
	}

	for(i=0; i<vel; i++){
		
		temp=a[i];		/*za slučaj da broj završava nulom*/
		while(temp%10==0 && temp) {
			temp/=10;
			brojac_nula++; 
		}
		
		a[i]=okreni_broj(a[i]);
		do{
			dodatni[j_vel++]=a[i]%10;  
			
			while(brojac_nula){	 /*zbog slučaja nula*/
				dodatni[j_vel++]=0; 
				brojac_nula--;
			}
		}while (a[i]/=10);			 
	}
	
	for(i=0, k=0; 		i<j_vel	&& k< 1000		; i++){
		brojac=1;
		while(i+1<j_vel && dodatni[i]==dodatni[i+1]) {
			brojac++;
			i++;
		}
		b[k++]=dodatni[i]; 			
		b[k++]=brojac;
	}
	
	printf("Finalni niz glasi:\n");
	for(i=0; i<k; i++){
		printf("%d ", b[i]);
	}
	
	return 0;
}
