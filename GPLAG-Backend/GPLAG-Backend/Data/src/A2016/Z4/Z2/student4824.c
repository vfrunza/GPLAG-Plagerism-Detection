#include <stdio.h>

char* kodiraj(char *s1, char *s2){
   int max, maxi, j, i, niz[96]={0};
   char *p=s1, *q=s2, *r=s2, *povratni=s1;
   while(*p!='\0'){
   	niz[*p-32]++;
   	p++;
   }
   for(j=0;j<95;j++){
   max=-1;
   for(i=0;i<95;i++){
    if(niz[i]>max){ max=niz[i];
    maxi=i;
    }
   }
   niz[maxi]=-1;
   *s2=maxi+32;
   s2++;
   }
   while(*s1!='\0'){
   	q=r;
   for(i=0;i<95;i++){
   	if(*s1==*q) { 
   		*s1=126-i;
   		break;
   	}
   	q++;
   	if(*q=='\0') break;
   }
   s1++;
   }
   return povratni;
}

char* dekodiraj(char *s1, char*s2){
	int i,broj=0;
	char *povratni=s1, *q=s2, *r=s2;
	while(*r!='\0'){
		broj++;
		r++;
	}
	while(*s1!='\0'){
		s2=q;
		for(i=0;i<broj;i++){
		if(*s1==126-i){
			*s1=*s2;
			break;
		}
		s2++;
		if(*s2=='\0') break;
		}
		s1++;
	}
	return povratni;
}

int main() {
 char tekst[] = "t~|n|x~{}w{o~s}x|~{}w{yuz{y~wzx|~v}q|vyuzpr}";
    char sifrarnik[100] = " eotaimsdrUcjknuv!";
    
    dekodiraj(tekst, sifrarnik);
    printf("%s\n", tekst);
    printf("%s", sifrarnik);
	return 0;
}
