#include <stdio.h>
void unesi(char*s,int velicina){
	int i=0;
	char znak=getchar();
	if(znak=='\n')
	znak=getchar();
	while(i<velicina-1 && znak!='\n'){
		*s++=znak;
		znak=getchar();
		i++;
	}
	s[i]='\0';
}
int podstring(char* tekst, char* rijec){
	char*p=tekst;
	char*s=rijec;
	char*a;
	char*b;
	while(*p!='\0'){
		a=p;
		b=s;
		while(*a++==*b++){
			if(*b=='\0' && (p==tekst || *(p-1)==' ') && (*a==' ' || *a=='\0'))
			return 1;
		}
		p++;
	}
	return 0;
}
int duzina(char*s){
	int vel=0;
	while(*s!='\0'){
	vel++;
	s++;
	}
	return vel;
}
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	int i=0,x;
	char*p=tekst;
	char**s=rijeci;
	char*q;
	char*t;
	char*v;
	char*poc=tekst;
	char*k;
	while(i<broj_rijeci){
		x=podstring(p,*s);
		if(x==1){
			while(*p!='\0'){
				q=p;
				while(*q!=' '){
				if(*q==*(*(s+i))){
					(*(s+i))++;
				}
				q++;
				}
					if(*(s+i)=='\0'){
						t=p;
						while(*t!='\0')
						t++;
						while(t>p){
						*(t+duzina(*(zamjene+i)))=*t;
						t--;
						}
						v=*(zamjene+i);
						k=p;
						while(*v!='\0'){
							*k++=*v++;
						}
					}
				p++;
			}
		}
		i++;
	}
	return poc;
}
int main() {
	char tekst[100];
	char*rijeci[2]={"beli","sneg"};
	char*zamjene[2]={"bijeli","snijeg"};
	unesi(tekst,30);
	zamjena_rijeci(tekst,rijeci,zamjene,2);
	printf("%s",tekst);
	return 0;
}
