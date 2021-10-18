#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void izbaciubaci(char*p, char*rij, char*zamj){
	char*z=p, *kraj=z;
	int duz=0;
	char*n=rij;
	while(*n++!='\0') duz++;
	char*r=p+duz;
	while(*r!='\0') 
	*p++=*r++;
	*p='\0';
	
	char*d=zamj;
	duz=0;
	while(*d++!='\0') duz++;
	while(*kraj!='\0') kraj++;
	
	while(kraj>=z){
		*(kraj+duz)=*kraj--;
	}
	while(*zamj!='\0') *z++=*zamj++;
}
char* trazi_rijec(char* s1, char*s2){
	char* poc=s1,*p,*q;
	while(*s1!='\0'){
		p=s1;q=s2;
		while(*p++==*q++)
		if(*q=='\0' && (s1==poc || *(s1-1)==' ') && (*p==' ' || *p=='\0')) return s1;
		s1++;
	}
	return NULL;
}
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	int i;
	for(i=0; i<broj_rijeci;i++){
		char*p=trazi_rijec(tekst, rijeci[i]);
		if(p!=NULL){
			izbaciubaci(p,rijeci[i], zamjene[i]);
			i--;
		}
	}
	return tekst;
}
int main() {
	char* rijeci[2]={"Ovo"};
	char* zamjene[2]={"AAA"};
	char tekst[100]="Ovo je ovo je OVO";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene,1));
	return 0;
}
