#include <stdio.h>
#include <stdlib.h>


void ubaci(int *niz,int kraj){
	int duzina=kraj*2,suma=0;
	int i,j,rem,broj;
	
	for (i=0;i<duzina;i+=2){   //glavnja petlja za racunanje sume na niz[i]
	suma=0;
	
	broj=abs(niz[i]);	//racunanje same sume cifara
	while(broj!=0){
		rem=broj%10;
		suma=suma+rem;
		broj/=10;
	}
	//pravljenje razmaka na odabranoj lokaciji
		for(j=duzina-1;j>=i+1;j--){
		niz[j]=niz[j-1];
	}
	
	niz[i+1]=suma; 	
	}
}


int izbaci(int *niz,int kraj){
	int broj1=1,broj2=1,rez=1,i=0,j=0,krajzareturn=kraj,fibonacci=0;
	for(i=0;i<krajzareturn;i++){			//ovdje je *greska :)
		while(niz[i]>=rez){
		if(niz[i]==rez){
			fibonacci=1;
		}
		rez=broj1+broj2;
		broj2=broj1;
		broj1=rez;
		}
		
		
		if (fibonacci==1){
		for(j=i;j<kraj-1;j++){			
				niz[j]=niz[j+1];
			}
			krajzareturn--;
			i--;
		}
			if (krajzareturn==0){
			break;
		}
fibonacci=0;
rez=1;
broj1=1;
broj2=1;



	}
	return krajzareturn;
}
	
	

int main() {
	int niz[20]={0},i,duzina=10;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<duzina;i++){
		scanf("%d",&niz[i]);
	}
	
ubaci(&niz[0],duzina);
duzina=izbaci(&niz[0],duzina*2);

printf("Modificirani niz glasi: ");
	for(i=0;i<duzina;i++){
		if (duzina==1){
				printf("%d.",niz[duzina-1]);
		}else if (i==duzina-1){
		printf(" %d.",niz[duzina-1]);
		}else if (i==0){
		printf("%d,",niz[i]);
		}else {
		printf(" %d,",niz[i]);
	}

}
	return 0;
}

//Vazno: Ako netko ovo rucno pregledava iz bilo kojeg razloga. Copy paste na pocetku dokumenta se desio jer sam 13/12/2016 izbrisao folder za Z2 iz Z3 te pasteovo svoj kod natrag.