#include <stdio.h>




struct Datum {int dan,mjesec,godina};
struct Uposlenik{char ime_prezime[50];
		struct Datum datum_rodjenja;
	};
	
	int broj_razmaka(char *string){
		int razmaci=0;
		while (*string!='\0'){
			if(*string==' ')
			razmaci++;
			string++;
		}
		return razmaci;
	}
bool isto_prezime(char string1*,char string2*){
	int razmaci1,int razmaci2;
	char *p1,*p2,*p3,*p4;
	char prezime1[50],prezime2[50];
	
	razmaci1=broj_razmaka(string1);
	razmaci2=broj_razmaka(string2);
	while(razmaci1!=0){
		if(*string1==' '){
			razmaci1--;
		}
		string1++;
	}
	while(razmaci2!=0){
		if(*string2==' '){
			razmaci2--;
		}
		string2++;
	}
	p1=string1;
	p2=string2;
	p3=prezime1[0];
	while(*p1!='-' || *p1!='\0'){
		*p3++=*p1++;
	}
	*p3='\0';
	p3=prezime2[0];
	while(*p2!='-'  || *p2!='\0'){
		*p3++=*p2++;
	}
	*p3='\0';
	if(strcmp(prezime1[0],prezime2[0])==0)
		return true;
	if(*p1=='-' && *p2=='-'){
		
	} else if(*p1=='-'){
		p1++;
		p3=prezime1[0];
		while( *p1!='\0'){
		*p3++=*p1++;
	}
	*p3='\0';
	if(strcmp(prezime1[0],prezime2[0])==0)
		return true;
	}
	
}
unsigned long int datum_u_dane(struct Datum a){
	int i,b;
	unsigned long int s=0;
	for (i = 0; i < a.godina; i++) {
		s=s+365;
		if((i%4==0 && i%100!=0)||i%400==0)
		s++;
	/*	if(i%100==0 && i%400!=0)
		s--;	*/
	}
	b=a.godina;
	for (i = 1; i < a.mjesec; i++) {
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
		s+=31;
		else if(i==2)
		{s+=28;
		if(b%4==0&& b%100!=0)
		s++;
		else if(b%400==0)
		s++;
		}
		else
		s+=30;
	}
	s+=a.dan;
	
	
	return s;
}

int suzi_listu(struct Uposlenik kandidati [], int vel, struct Uposlenik direktor, int broj_dana){
	int i,dani1,dani2;
	for (int = 0; i < vel	; i++) {
		
	}
	
	
}


int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}




















	/*
	while(*p1==*p2){
		p1++;
		p2++;
		if(*p1=='-' || *p2=='-' || *p1=='\0' || *p2=='\0')
		break;
	}
	if(*p1=='-' &&(*p2=='-' || *p2=='\0'))
		return true;
	if(*p1=='\0' && (*p2=='-' || *p2=='\0'))
		return true;
	p1=string1;
	p2=string2;
	while(*p2==)
	while(*p1!='-' && *p1!='\0')
	p1++;
	while(*p2!='-' && *p2!='\0')
	p2++;
	if(*p1=='\0' && *p2=='\0')
		return false;
	if(*p1=='-'){
		p1++;
		p2=string2;
		while(*p1==*p2){
		p1++;
		p2++;
		if(*p2=='-' || *p1=='\0' || *p2=='\0')
		break;
		}
		if(*p1=='\0' &&(*p2=='-'  || *p2=='\0'))
			return true;
		
	}*/
	