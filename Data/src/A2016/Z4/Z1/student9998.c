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

char malo (char s){
	if (s>='A'&& s<='Z')
		return s+32;
	return s;
}

int uporedi (char *s1, char *s2){
	int broj=0;
	while(malo(*s1)==malo(*s2)) {
		if(*s1=='\0' && *s2=='\0'){ 
			broj=1;
			break;
		}
		s1++; s2++;
		
	}
	return broj;
}

int slovo (char s){
	if(s>='A' && s<='Z' || s>='a' && s<='z') return 1;
	return 0;
}

char *izbaci_najcescu (char *s){
	if(*s=='\0') return s;
	char *p=s, *zapamti=NULL;
	int brojac=0, max=0;
	char pomocni_niz[100],pomocni_niz2[100];
	while(*p!='\0'){
		while(!slovo(*p) && *p!='\0') p++;
		char *prva=p;
		char *q=pomocni_niz;
		while(slovo(*p)) *q++=*p++;
		*q='\0';
		char *drugi=s; // na drugu .... 
		brojac=0;
		while(*drugi!='\0'){
			while(!slovo(*drugi) && *drugi!='\0') drugi++;
			char *pok2=pomocni_niz2;
			while(slovo(*drugi)) *pok2++=*drugi++;
			*pok2='\0';
			if(pomocni_niz!='\0' && pomocni_niz2!='\0' && uporedi(pomocni_niz,pomocni_niz2)) brojac++;
			if(brojac>max){
			    zapamti=prva;
			    max=brojac;
			}
			
		}
		
	}
    p=s;
    char *q=pomocni_niz;
    if(zapamti==NULL) return s;
    while(slovo(*zapamti)) *q++=*zapamti++; 
    *q='\0';
    if(!slovo(*pomocni_niz)) return s;
    while (*p!='\0'){
    	while(!slovo(*p) && *p!='\0') p++;
    	char *pom1=p;
    	char *pok1=pomocni_niz2;
    	while (slovo(*p)) *pok1++=*p++; 
    	*pok1='\0';
    	if (pomocni_niz!='\0' && pomocni_niz2!='\0' && uporedi(pomocni_niz,pomocni_niz2)){
    		char *pom2=p;
    		while(*pom1++=*pom2++); 
    		p=s;
    	}
       
    }
    return s;
}







int main() {
     char s[100];
     unesi(s,100);
     printf("%s",izbaci_najcescu(s));

	return 0;
}
