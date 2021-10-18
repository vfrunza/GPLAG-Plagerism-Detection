#include <stdio.h>
int Ima(char slovo,char niz1[]){
	char* p=niz1;
	while(*p!='\0'){
		if(slovo==*p) return 1;
		p++;
	}
	return 0;
}

void Sortiraj(int koliko[],char niz1[],int velicina){
	char* t=niz1;
	int* k=koliko;
	char* r=t;
	int* l=koliko;
	int broj;
	char slovo;
	int j,i,s;
	
	for(i=0;i<velicina;i++){
		l=k+1;
		r=t+1;

		for(j=i+1;j<velicina;j++){
			if((*k)<(*l)){
				broj=*k;
				*k=*l;
				*l=broj;
				
				slovo=*t;
				*t=*r;
				*r=slovo;
				
			}
			
		/*Isti broj ponavljanja, sortiranje po ascii*/
		if(*k==*l){
			if(*r<*t){
				broj=*k;
				*k=*l;
				*l=broj;
				
				slovo=*t;
				*t=*r;
				*r=slovo;
				
			}
		}
		
			l++;
			r++;}
		k++;
		t++;
		
	}
	          
	          }
	     
int pozicija(char znak,char tablica[]){
	char* gandalf=tablica;
	int brojac=0;
	while(*gandalf!='\0'){
		if(*gandalf==znak) break;
		brojac++;
		gandalf++;
	}
	return brojac;
}

void Raspored(char tekst_kodiraj[],char niz1[]){
	int brojac;
	char* z =niz1;
	int velicina=0;
	int koliko[100];
	char*p=tekst_kodiraj;
	char* q=niz1;
	char slovo;
	while(*p!='\0'){
		slovo=*p;
		if(Ima(slovo,niz1)==0){ *q=*p; q++;}
		niz1=z;
		p++;
	}
	*q='\0';
	
	/*broj razlicitih znakova*/
	 char* c=niz1;
	while(*c!='\0') {velicina++;c++;}
//	printf("%d",velicina);
	
	p=tekst_kodiraj;
	int j=0;
	q=niz1;
	
	while(*q!='\0'){
		brojac=0;
		p=tekst_kodiraj;
		while(*p!='\0'){
		if(*q==*p) brojac++;
		p++;
			}
			
			koliko[j]=brojac;
			j++;
			q++;
	}
	
	
	niz1=z;
	Sortiraj(koliko,niz1,velicina);
}

/*Funkcija kodiraj*/
char* kodiraj(char tekst_kodiraj[],char tablica[]){
	char niz1[100]="";
char* p=tablica;
char* q= niz1;
char dodaj_u_tablicu;
int i;
int pozicija_u_tablici;
pozicija_u_tablici=0;

	Raspored(tekst_kodiraj, niz1);
   
	while(*q!='\0'){
		*p=*q;
		p++;
		q++;
	}
	
  i=32;
	while(i<=126){
		dodaj_u_tablicu=i;
//printf("%c",i);
		if(Ima(dodaj_u_tablicu,niz1)==0){*p=dodaj_u_tablicu; p++;  }
		i++;
	}
	*p='\0';
	p=tablica;
/*	while(*p!='\0'){
		printf("%c",*p);
		p++;
	}*/
	q=tekst_kodiraj;
	while(*q!='\0'){
		dodaj_u_tablicu=*q;
		pozicija_u_tablici=pozicija(dodaj_u_tablicu,tablica);
		*q=126-pozicija_u_tablici;
	//	if(*q<32) {q--;q--;}
		q++;
	}
	return tekst_kodiraj;
}

char* dekodiraj(char tekst_dekodiraj[],char tablica[]){
	char* q=tekst_dekodiraj;
	char* p=tablica;
	int dodaj_u_tablicu;
	int pozicija_u_tablici;
		while(*q!='\0'){
			dodaj_u_tablicu=*q;
			pozicija_u_tablici=126-dodaj_u_tablicu;
			*q=*(p+pozicija_u_tablici);
			p=tablica;
		q++;
	}
	return tekst_dekodiraj;
}
int main() {
//char kodiraj[100]="SaritaMala";
char koodiraj[100]="LLMLNLNMONM";
char niz1[500]="";
char* t;
t=kodiraj (koodiraj,niz1);
printf(" %s",koodiraj);
t=dekodiraj(koodiraj,niz1);
printf("\n %s",koodiraj);
return 0;
}



