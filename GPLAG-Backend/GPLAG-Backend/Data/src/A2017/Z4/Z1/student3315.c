#include <stdio.h>
#include <stdlib.h>


/* funkcija za broj cifara */
int broj_cifara(int broj){
	int broj_cifara=0;
	while(broj!=0){
		broj/=10;
		broj_cifara++;
	}
	return broj_cifara;
}


UBACIVANJE BROJA IZMEDJU SVAKE DVIJE RIJECI

char *ubaci_broj(char *tekst,int broj){
	char *pocetak=tekst;
	while(*pocetak==' ') pocetak++;
	while(*pocetak!='\0'){
		if(*pocetak==' '){
			char *pomocni=pocetak;
			while(*pomocni!='\0'){
				
				if(*pomocni==' ')
					pomocni++;
				else break;
			}
			if(*pomocni=='\0') break;
			
			char *kraj=pocetak;
			while(*kraj!='\0') kraj++;
			int velicina=broj_cifara(broj),i,br=abs(broj);
			if(broj<0)velicina++;
			while(kraj>pocetak){
				*(kraj+velicina)=*kraj;
				kraj--;
			}
			for(i=velicina-1;i>=0;i--){
				if(broj<0 && i==0) {
					*(pocetak+1)='-';
					break;
				}
				*(pocetak+1+i)=br%10 + '0';
				br/=10;
			}
			
			
			if(*(pocetak+velicina+1)!=' '){
				while(*kraj!='\0') kraj++;
				while(kraj>pocetak+velicina){
					*(kraj+1)=*kraj;
					kraj--;
				}
				*(pocetak+velicina+1)=' ';
			}
			pocetak+=velicina+1;
			while(*pocetak==' ')pocetak++;
			continue;
			
		}
		pocetak++;
	}
	return tekst;
}


void unesi(char niz[],int velicina){
	int i;
	char znak=getchar();
	if(znak=='\n')
	znak=getchar();
	i=0;
    
	while(znak!='\n' && i<velicina-1){
		niz[i]=znak;
		i++;
		znak=getchar();
		}
		niz[i]='\0';
}



int main() {
	char niz[200];
	int broj;
	printf("Unesi: \n");
	unesi(niz,200);
	printf("Unesite broj: \n");
	scanf("%d",&broj);
	printf("String je: %s",ubaci_broj(niz,broj));
	return 0;
}
