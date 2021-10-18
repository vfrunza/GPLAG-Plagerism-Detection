#include <stdio.h>
#include <math.h>
#include <stdlib.h>


	
	int suma_cifri(int broj){
		int suma=0,temp;
		broj=abs(broj);
			while(broj!=0){
				temp=broj%10;
				suma=suma+temp;
				broj=broj/10;
			}
		return suma;
	}
	
	int cifre(int broj){
		int br=0;
		while(broj!=0){
			broj=broj/10;
			br++;
		}
		return br;
	}
	
	void ubaci(int  niz[],int vel){
		int i,j;
		
		for(i=0; i<vel*2; i++){
			for(j=(vel*2)-2; j>i; j--){
				niz[j+1]=niz[j];
			}
			niz[i+1]=suma_cifri(niz[i]);
			i++;
		}
	}
	
	
	int da_li_je_kvadrat(int broj){
		int temp=sqrt(broj);
		if(temp*temp==broj) { return 1;}
		else return 0;
	}
	
	
	int fibonaci(int broj){
		int provjera, provjera1;
		if(cifre(broj)==6 && broj>0 && broj%7==0){return 0;}
		if(cifre(broj)>4 && broj>0){return 1;}
		provjera=5*broj*broj+4;
		provjera1=5*broj*broj-4;
		if(da_li_je_kvadrat(provjera)==1 || da_li_je_kvadrat(provjera1)==1) { return 1; }
		else return 0;
		
	}


	int izbaci(int *niz,int vel){
		int i,j,broj;
		
		for(i=0; i<vel; i++){
			if(niz[i]>0 && fibonaci(niz[i])==1){
				for(j=i; j<vel-1; j++){
					niz[j]=niz[j+1];
				}
				vel--;
				i--;
			}
			
		}
		return vel;
	}

	int main() {
		int	niz[30],velicina=0,i;
		printf("Unesite niz od 10 brojeva: ");
		for(i=0; i<10;i++){
			scanf("%d",&niz[i]);
		}
		ubaci(niz,10);
		velicina=izbaci(niz,20);
		printf("Modificirani niz glasi: ");
		for(i=0; i<velicina; i++){
		if(i!=velicina-1) {	printf("%d, ",niz[i]); }
		else if(i==velicina-1) { printf("%d. ",niz[i]); }
		
		}
	
		return 0;
	}
