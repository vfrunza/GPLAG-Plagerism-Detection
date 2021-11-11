#include <stdio.h>

char duzina(char* string){
	int duzina=0;
	while(*string++!='\0')
		duzina++;
	return duzina;
}
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char *povratni=tekst,*p=tekst,*q;
	int i=0,duz;
	if(*tekst=='\0' || broj_rijeci==0)
	return tekst;
	while(i<broj_rijeci){
		int ima=0;
		p=povratni;
		q=rijeci[i];
		do{ 
			ima=0;
		while(*p!='\0'){
			char *pom1=p;
			char *pom2=q;
			while(*pom1++==*pom2++){
				if(*pom2=='\0' && (*pom1==' ' || *pom1=='\0')){
					if(p!=povratni){
						if(*(p-1)==' ' || p-1==povratni)
						ima=1;
						break;
					}
					else{
						ima=1;
						break;
					}
				}
			}
			if(ima) break;
			p++;
		}
		if(ima){
		char *k=p,*t=p;
		if(duzina(zamjene[i])!=duzina(rijeci[i])){
			while(*k!=' ' && *k!='\0')
			k++;
			while(*p++=*k++);
			k--;
			p=t;
			duz=duzina(zamjene[i]);
			while(k>=p){
				*(k+duz)=*k--;
			}
		}
		t=zamjene[i];
		while(*t!='\0')
			*p++=*t++;
		}
	}while (ima);
		i++;
	}
		return povratni;
}
int main() {
	char* rijeci[1]={"dobro"};
	char* zamjene[1]={"dobro"};
	char tekst[100]="dobro dobro";
	printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 1));
	return 0;
}
