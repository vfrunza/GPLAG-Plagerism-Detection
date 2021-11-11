#include <stdio.h>
#include <stdlib.h>
	void ubaci (int* pok, int duzina ){
		int *temp1=pok; 
		int *temp2;
		int cifra=0, i=0, broj;
			
			while(temp1<pok+(2*duzina)){
				broj=abs(*temp1);
			
				while(broj){
					cifra=cifra+broj%10;
					broj/=10;
				}
				
				for(temp2=pok+(duzina+i); temp2>temp1; temp2--){
					*temp2=*(temp2-1);
				}
				i++;
				temp1++;
				*temp1=cifra;
				cifra=0;
				temp1++;				
			}
	}
	int fibonaci(int x){
		int niz[1000];
		niz[0]=1;
		niz[1]=1;
	
		if(x==1)
			return 1;
			
		int *temp1=niz;
		int *temp2=niz+1;
		int *temp3=niz+2;
			
			while(1){
				*temp3=*temp2+*temp1;
			
				if(*temp3==x)
					return 1;
				if(*temp3>x)
					return 0;
					
				temp1++;
				temp2++;
				temp3++;
			}
		
	}
	int izbaci (int* pok, int duzina){
		int *temp=pok;
		int *temp2;
		int broj;
		
		while(temp<pok+duzina){
			broj=*temp;
			broj=fibonaci(broj);
		
			if(broj==1){
				for(temp2=temp; temp2<pok+duzina-1; temp2++)
					*temp2=*(temp2+1);
		
			duzina--;
			temp--;
			}
			temp++;
		}
		return duzina;
	}
	
	
int main() {
	int niz[100],i,broj_izbaci;

	printf("Unesite niz od 10 brojeva: ");
		for(i=0; i<10; i++)
			scanf("%d",&niz[i]);
			
			ubaci(niz, 10);
			broj_izbaci=izbaci(niz, 20);
		
			
	printf("Modificirani niz glasi: ");
		for(i=0; i<broj_izbaci; i++){
		
		if(i==broj_izbaci-1)
			printf("%d.",niz[i]);
		
		else
			printf("%d, ",niz[i]);
	}
	return 0;
}
