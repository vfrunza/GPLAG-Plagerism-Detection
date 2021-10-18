#include <stdio.h>

void unesi(char niz[], int velicina){
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	
	niz[i]='\0';
}

char* ubaci_broj(char* tekst, int broj){
	char sbroj[12];
	char *sb=sbroj,*pocetak, *cuvar, *kraj, *razmak, *brisipocraz, *provjerikraj, *sljedeci;
	int tmp=broj,broj_znakova=0;
	
	if(broj<0){
		broj=-broj;
		broj_znakova++;
		*sb++='-';
	}
	
	do{
		sb++;
		tmp/=10;
	}while(tmp!=0);
	
	*sb--='\0';

	do{
		*sb--=broj%10+'0';
		broj/=10;
		broj_znakova++;
	}while(broj!=0);           /*Pretvara broj u string*/
	
	
	cuvar=tekst; /*Pokazivac koji cuva pocetak teksta*/
	
	brisipocraz=tekst;   /*Pokazivac koji preskace sve razmake na pocetku*/
	
	while(*tekst!='\0'){
		
		while(*brisipocraz==' '){ /*Ukoliko se u recenici na pocetku nalaze razmaci, njih preskace*/
			brisipocraz++;
			tekst=brisipocraz;
		}
		
		if(*tekst==' '){
			kraj=tekst;
			sljedeci=tekst;
			sljedeci++;
			
			if(*sljedeci!=' '){ /*Sljedeci je nesto poput fje peek u c++, provjerava koji znak je sljedeci, ako sljedeci nije razmak, onda mora ubaciti
			                                 razmak poslije broja*/
				while(*kraj!='\0') kraj++;
				
				while(kraj>tekst){                   /*Petlja koja pomjera sve znakove odgovarajuci broj mjesta udesno, da bi obezbijedila mjesto za brojeve*/
				    *(kraj+broj_znakova+1)=*kraj;   /*broj_znakova+1 obezbjedjuje dodatno mjesto za razmak*/
				    kraj--;
					
				}
				
				provjerikraj=tekst;       /*Pokazivac koji provjerava kad je kraj recenice i da li iza posljednjeg znaka/slova ima suvisnih razmaka*/
				tekst++;  /*Pomjera pokazivac teksta udesno, kako bi oslobodio prvobitni razmak i kako bi preko suvisnih znakova napisao odgovarajuci broj*/
				
				while(*provjerikraj==' ' && *provjerikraj!='\0')provjerikraj++; /*Dio koji provjerava kraj i vraca pokazivac na pocetak teksta ako jest */
				if(*provjerikraj=='\0'){
					  tekst=cuvar;
					  return tekst;
					
				}
				
				pocetak=sbroj;
				
				while(*pocetak!='\0') *tekst++=*pocetak++;
				*tekst=' ';
				
				razmak=tekst;
				while(*razmak==' ' && razmak!='\0') razmak++;  
				tekst=razmak;
				
			}
			
			if(*sljedeci==' '){ /* Ovdje provjerava da li je sljedeci znak razmak, ako jest, ne ubacuje nikakve dodatne razmake. Sve ostalo radi analogno*/
				while(*kraj!='\0') kraj++;
				while(kraj>tekst){                   
				    *(kraj+broj_znakova)=*kraj;
				    kraj--;
					
				}
				
				provjerikraj=tekst;       
				tekst++;  
				
				while(*provjerikraj==' ' && *provjerikraj!='\0')provjerikraj++; 
				if(*provjerikraj=='\0'){
					  tekst=cuvar;
					  return tekst;
					
				}
				
				pocetak=sbroj;
				
				while(*pocetak!='\0') *tekst++=*pocetak++;
				
				razmak=tekst;
				
				while(*razmak==' ' && razmak!='\0') razmak++;     
				
				tekst=razmak;
				
			}
			
		}
		
		tekst++;
	}
	
	tekst=cuvar;
	
	return tekst;
	
}


int main() {
	char tekst[100];
	int broj;
	
	printf("Unesi tekst:\n");
	unesi(tekst,100);
	printf("Unesi zeljeni broj:\n");
	scanf("%d", &broj);
	
	printf("%s",ubaci_broj(tekst, broj));

	return 0;
}



