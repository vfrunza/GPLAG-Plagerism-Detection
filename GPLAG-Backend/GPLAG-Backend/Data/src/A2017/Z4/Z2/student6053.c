#include <stdio.h>
void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}
int broj_rijeci(char *s){
	int neslovo=1, broj=0;
	while(*s!='\0'){
		if(!((*s>='A'&&*s<'Z') || (*s>='a' && *s<='z'))) neslovo=1;
		else if(neslovo==1){
			neslovo=0;
			broj++;
		}
		s++;
	}
	return broj;
}
int provjeri_duzine(char *s, int niz[],int velicina){
	int logicka=1;
	int i=0;
	int broj_slova=0;
	int br_rj;
	br_rj=broj_rijeci(s);
	if(br_rj!=velicina) return 0;
	while(*s!='\0'){
		broj_slova=0;
		while(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')))s++;
		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')){
			if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) broj_slova++;
			s++;
		}
		if(broj_slova!=niz[i]) return 0;
		if(*s=='\0') continue;
		s++;
		i++;
	}
	return 1 ;
}
int main() {
	char s[100];
	int i;
	unesi(s,100);
	char *p=s;
	int niz[100], vel;
	do{
		scanf("%d",&vel);
	}while(vel<0);
	for(i=0;i<vel;i++)
	scanf("%d",&niz[i]);
	/*while(*p!='\0'){
		printf("%c",*p);
		p++;
	}
	printf("%d",broj_rijeci(s));*/
/*	for(i=0;i<vel;i++)
	printf("%d",niz[i]);*/
	printf("%d",provjeri_duzine(s,niz,vel));
	return 0;
}
