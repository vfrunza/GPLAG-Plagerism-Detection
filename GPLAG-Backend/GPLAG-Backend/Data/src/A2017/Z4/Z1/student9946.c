/*char* ubaci_broj (char* tekst, int broj)

koja prima string i neki cijeli broj tipa int, te u primljenom stringu ubacuje broj između svake dvije riječi.
Radi lakšeg lančanog pozivanja, funkcija vraća pokazivač na početak primljenog stringa. 
Pretpostaviti da je primljeni string dovoljno velik da primi sve dodatne karaktere. Obratite pažnju da broj može biti i negativan. 

Riječ se definiše kao niz karaktera omeđenih znakom razmaka, početkom i krajem stringa, 
tako da se npr. string "auto-stop" smatra za jednu riječ. Prilikom ubacivanja broja razmak se treba nalaziti prije i poslije broja.
Ako se između dvije riječi nalazi dva ili više razmaka, broj treba ubaciti nakon prvog razmaka a ostale razmake ostaviti između broja i sljedeće riječi

Primjer: Ako je primljen string:
Ovo   je neki     primjer   teksta
i broj -123, nakon poziva funkcije string treba da glasi:
Ovo -123  je -123 neki -123    primjer -123   teksta

U programu je zabranjeno koristiti funkcije iz biblioteka string.h i stdlib.h, te funkcije sprintf i sscanf iz biblioteke stdio.h. Također je strogo zabranjeno kreirati pomoćni niz/string u funkciji!
*/


	#include <stdio.h>

void unesi (char niz[], int velicina) {
	char znak = getchar ();
	if (znak == '\n') getchar ();
	int i=0;
	while (i<velicina-1 && znak != '\n') {
		niz [i] = znak;
		i++;
		znak=getchar ();
	}
	niz[i]='\0';
	
}

char* ubaci_broj (char* tekst, int  broj){
	char* p;
	char* p1;
	char* p2;
	p=tekst;
	p1=tekst;
	p2=tekst;
	int brojac=0;
	int temp;
	temp=broj;
	
	while(temp!=0){
		temp/=10;
		brojac++;
	}
	
	while(*p!='\0'){
		
        if(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && (p!=tekst && *(p-1)==' ')){
        p1=p;
		p2=p;
		
        	  while(*p2!='\0') { p2++;
        	  	
        	  }
        	 
        	  
        	  while(p2!=p-1){
        	  	*(p2+brojac)=*p2;
        	  	p2--;
               }
               
               temp=broj;
        	  p1+=brojac-1;
        	  
        	  while(temp!=0){
        	  	
        	  	 *p1=temp%10+'0';
        	  	temp/=10;
        	  p1--;	
        	  }
        }
        
        
        if(*p!='\0') p++;
	}

		return tekst;
}
	
	int main(){
		char tekst [100];
		int n;
		
	
		
		
		printf("Unesite neki tekst: ");
		unesi(tekst,100);
		printf("Unesite neki broj: ");
		scanf("%d",&n);
		printf("%s",ubaci_broj(tekst,n));
	
	

		return 0;
		
		
	}
	
	
	
	
	
	
	
	