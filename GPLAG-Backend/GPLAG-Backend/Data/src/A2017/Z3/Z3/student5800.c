#include <stdio.h>
int izbaci_cifre (int niz1[], int duzina1, int niz2[], int duzina2)
{
	int i, j, a=0, tmp=0, k=1, pomocna=0;
	for(i=0; i<duzina2; i++){
		if(niz2[i]<0 || niz2[i]>9)
			return 0; }
	for(i=0; i<duzina1; i++){	
		for(j=i+1; j<duzina2; j++){
				if(niz2[i]==niz2[j])
					return 0; 
		}
	}
	for(i=0; i<duzina1; i++){
		for(j=0; j<duzina2; j++){
			tmp=niz1[i];
			while(tmp>0){
				a=tmp%10;
				tmp=tmp/10;
				if(a!=niz2[j]){
					pomocna=pomocna+a*k;
					k=k*10;
					
				}
			}
			niz1[i]=pomocna;
		}
	}
	return 1;
}

int main() {
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
