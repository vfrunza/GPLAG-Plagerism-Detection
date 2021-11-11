#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ImaCifra(int broj, int niz_cifara[], int vel){
	int i;
	for(i=0;i<vel;i++){
		if(broj==niz_cifara[i]) return 1;
	}
	return 0;
}

int izbaciBroj(int broj, int niz_cifara[], int vel){
	int povratni=0, multi=1, cif;
	broj=abs(broj);
	while(broj!=0){
		cif=broj%10;
		if(ImaCifra(cif,niz_cifara,vel)==0){
			povratni+=multi*cif;
			multi*=10;
		}
		broj/=10;
	}
	return povratni;
}


int izbaci_cifre(int niz_brojeva[], int vel_br, int niz_cifara[], int vel_cif){
	int i=0,j=0;
	/*Ako su nizovi prazni*/
	if(vel_br==0 || vel_cif==0) return 0;
	/*ako u nizu cifri se nalazi broj <0 ili >9*/
	for(i=0;i<vel_cif;i++){
		if(niz_cifara[i]<0 || niz_cifara[i]>9) return 0;
	}
	/*ako se neka cifra u nizu cifara ponavlja*/
	for(i=0;i<vel_cif-1;i++){
		for(j=i+1;j<vel_cif;j++){
			if(niz_cifara[i]==niz_cifara[j]) return 0;
		}
	}
	for(i=0;i<vel_br;i++){
		/*paziti na negativne!!*/
		if(niz_brojeva[i]<0)
		    niz_brojeva[i]=-1*izbaciBroj(niz_brojeva[i],niz_cifara,vel_cif);
		else 
		    niz_brojeva[i]=izbaciBroj(niz_brojeva[i],niz_cifara,vel_cif);
	}
	
	return 1;
}

int main() {
	int i;
	int niz1[]={0,0,2,232,5643};
	int niz2[]={3,2,0};
	printf("Poziv funkcije uspio(1), nije uspio(0): %d\n", izbaci_cifre(niz1,5,niz2,2));
	for(i=0;i<5;i++){
		printf("%d\n", niz1[i]);
	}
	return 0;
}
