#include <stdio.h>
#define true 1
#define false 0
#define bool int


void kopiraj(char *m, char* poc,char* kraj){  
	while(poc!=kraj){  //sve sto je izmedju poc i kraja prebacuje se u string m
		*m++=*poc++;
		}
*m='\0';
}


void izbaci_rijec(char *s, char *p){
	char *s1=s;
	while(*p!='\0'){
		*s1=*p;
		 s1++;
		 p++;
	}
*s1='\0';
}


bool uporedi (char *s1, char *s2, char *p){ //uporedjujemo dvije rijeci, ako su iste vratimo true, a ako nisu onda false
	while(s1!=s2 && *p!='\0'){ //dok je prva rijec razlicita od kraja prve rijeci i dok je druga rijec razlicita od kraja stringa
		if(*s1!=*p && *s1!=(*p+32) && *s1!=(*p-32))  return false;  /*ako nadjemo da nase slovo nije isto kao veliko ili malo slovo drugog stringa, 
																	 odmah vratimo false, ako nije idemo kroz oba stringa */
				s1++;
				p++;
			}
	
	if(*p=='\0' && s1==s2) return true; /* ako smo dosli do kraja sa drugim stringom, a sa prvim ako smo dosli na kraj rijeci, onda smo dosli do kraja
										i sva slova su ista pa vratimo true */
	return false;
}


void prebroji(char *poc, char *kraj, int* broj){
	if(*kraj=='\0') return;
	char rijec[100];
	
	kopiraj(rijec,poc,kraj); //u niz charova spasimo sve izmedju poc i kraja rijeci, tj nas niz bude rijec
	
	char*ostatak=kraj+1; //provjeravamo sve od te rijeci pa dalje kolilko ima ponavljanja u stringu 
	bool neslovo=true;

	while(*ostatak!='\0'){
		if(!((*ostatak>='A' && *ostatak<='Z') || (*ostatak>='a' && *ostatak<='z'))) 
			neslovo=true;
		
		else if(neslovo==true){
			neslovo=false;
			
			char *p1=ostatak;
			
			while((*p1>='A' && *p1<='Z') || (*p1>='a' && *p1<='z'))	 	
				p1++;
			
			if(uporedi(ostatak,p1,rijec))  (*broj)++; //uporedjujemo svaku rijec sa zadanom, ako je ista, onda se broj ponavljanja nase rijeci poveca za 1
			}
		ostatak++;
	}
}


char *izbaci_najcescu(char *str){
	char *p=str, *pocetak_najcesce=0, *kraj_najcesce, *pocetak_trenutne=0, *kraj_trenutne, *p1;
	int max=0, rel_max; //max je broj rijeci koja se najvise puta ponavlja, a rel_max je ponavljanje trenutne rijeci
	int *brojac= &rel_max;
	bool neslovo=true;
	
	while(*p!='\0'){ //idemo kroz string, obican kod iz predavanja za broj rijeci, ali smo to iskoristili da znamo kad smo na pocetku i na kraju rijeci
		if(!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))) 
			neslovo=true;
		
		else if(neslovo==true){ 
			rel_max=1; //ovdje smo sigurno na pocetku rijeci i ta se rijec ponavlja vec jednom
			
				if(neslovo==true) 
					neslovo=false;
		
			pocetak_trenutne=p1=p; //upamtimo gdje pocinje rijec i sa while petljom prodjemo kroz nju 
			
			while((*p1>='A' && *p1<='Z') || (*p1>='a' && *p1<='z')) 
				p1++;
			
			kraj_trenutne=p1; //upamtimo joj kraj
			
			prebroji(pocetak_trenutne, kraj_trenutne, brojac); //u funkciju saljemo nasu rijec i brojac, brojac je rel_max, to je broj ponavljanja trenutne
			
			if(rel_max>0){ /*ako smo nasli da se nasa rijec ponavlja vise od 0 puta, onda ispitujemo da li se ponavlja vise od maxa i spasimo poc i kraj rijeci 
							koja se najvise puta ponavlja*/
				if(rel_max>max){
					max=rel_max;
					pocetak_najcesce=pocetak_trenutne;
					kraj_najcesce=kraj_trenutne;
				}
			}
		else continue;
		}
	p++;
}
	
	if(max==0) return str;
	
	char *s=str;
	char rijec[100];
	
	kopiraj(rijec,pocetak_najcesce,kraj_najcesce); //od dva pokazivaca napravimo rijec, ono sve sto je izmedju pokazivaca
	
	neslovo=true;
	
	while (*s!='\0'){ //prodjemo kroz string i gdje god se nasa rijec pronadje treba je izbaciti
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) 
			neslovo=true;
		
		else if(neslovo==true){
			if(neslovo==true) 	
				neslovo=false;
			
				p1=s;
		
		while((*p1>='A' && *p1<='Z') || (*p1>='a' && *p1<='z'))	
			p1++;
		
		if(uporedi(s,p1,rijec)==true){ //saljemo svaku rijec i ako smo nasli istu, funkcija vrati true i izbacimo je
			izbaci_rijec(s,p1);
			neslovo=true;
		}
			
	}
		s++;
	}
return str;

}


int main() {

char t[]="a-a-a-a-a";
printf("%s", izbaci_najcescu(t));

	return 0;
}
