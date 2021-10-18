#include <stdio.h>

int da_li_je_prisutan(int cifra,int niz_za_provjeru[],int velicina_niza_provjera){
	int i;
	for(i=0;i<velicina_niza_provjera;i++){
		if(cifra==niz_za_provjeru[i]) return 1;
	}
	return 0;
}

int cifre(int niz[],int velicina,int prazan_niz[]){
	int i;
	int j;
	int broj;
	int cifra;
	int vel_praznog=0;
	int prisutan=0;
	int temp;
	int min=0;
	
	for(i=0;i<velicina;i++){
		
		
		
		broj=niz[i];
		if(broj == -1) continue;
do {
	

		if(broj<0) broj*=-1;
	
		cifra=broj%10;
	
		if(vel_praznog==0){
			prazan_niz[vel_praznog]=cifra;
			vel_praznog++;
		}

		else{
			prisutan=da_li_je_prisutan(cifra,prazan_niz,vel_praznog);
			if(prisutan==0) {
				prazan_niz[vel_praznog]=cifra;
				vel_praznog++;
			}
		}
		broj/=10;
	}while (broj!=0);
	}

	for(i=0;i<vel_praznog;i++){
		min=i;
		for(j=i+1;j<vel_praznog;j++){
			if(prazan_niz[j]<prazan_niz[min])
			min=j;
		}
		temp=prazan_niz[i];
		prazan_niz[i]=prazan_niz[min];
		prazan_niz[min]=temp;
	}
	
	
	return vel_praznog;
}

int main() {
	int niz[100];
	int prazni_niz[10];
	int i=0;
	int vel=0;
	int broj_upisanih=0;
	printf("Unesite brojeve: \n");
do{
	
	scanf("%d ",&niz[i]);
    if(++i==100) break;
}while(niz[i-1]!=-1 );

		vel=i;
		
broj_upisanih=cifre(niz,vel,prazni_niz);
printf("Cifre: ");
	for(i=0;i<broj_upisanih-1;i++){
		printf("%d,",prazni_niz[i]);
	}
	printf("%d.",prazni_niz[broj_upisanih-1]);
	return 0;
}
