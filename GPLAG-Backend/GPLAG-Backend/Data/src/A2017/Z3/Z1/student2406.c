#include <stdio.h>

int provjeri_duplikate(int p,int n[],int vel){
	int i,brojac=0;
	for(i=0;i<vel;++i){
			if(p==n[i])
				brojac++;
			if(brojac>1)
				return 1;
				}
	return 0;
} /*ovdje to provjerava da li se u nizu elementi ponove, i ako kopija postoji vraca log. vrijednost kojom se u nastavku runtime-a resetuje brojac*/

int petljica(int niz1[],int v1,int niz2[],int v2,int niz3[],int v3){
	int i,j,k,brojac=0;
	for(i=0;i<v1;++i)
		for(j=0;j<v2;++j){
			if(niz1[i]==niz2[j]){
				brojac++;
				if(provjeri_duplikate(niz1[i],niz1,v1))
					brojac=1;
			for(k=0;k<v3;++k){
			if(niz1[i]==niz3[k]&&brojac>=1)
				brojac--;
			else if(niz1[i]==niz3[k]&&brojac==0)
				brojac=0;
				}
			}
		}
	return brojac;
}

int dva_od_tri(int a[],int vel1,int b[],int vel2,int c[],int vel3){
return petljica(a,vel1,b,vel2,c,vel3)+petljica(a,vel1,c,vel3,b,vel2)+petljica(b,vel2,c,vel3,a,vel1);
}

int main(void) {		
	int niz1[] = {1, 2, 3, 5};
int niz2[] = {1, 2, 4, 6, 7};
int niz3[] = {1, 3, 4, 8, 9, 10};
int rez = dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
printf("%d", rez);
	return 0;
}
