#include <stdio.h>

char *kodiraj (char *s1, char *s2){
	char *pocetak=s1,*p=s1,*q=s2;
	int slova[127]={0},i,max=0,l;
	while (*p!='\0')
		slova[(int)*p++]++;
	do {
		max=0;
		for (i=32; i<=126; i++)
			if(slova[i]>max){
				l=i;
				max=slova[i];
			}
		if (max==0) break;
		*s2++=(char) l;
		slova[l]=-1;
	} while (max!=0);
	for(i=32; i<=126; i++)
		if(slova[i]!=-1)
			*s2++=(char) i;
	*s2='\0';
	while(*s1!='\0'){
		char *pom=q;
		while(*s1!=*pom)
			pom++;
		*s1=(char)126-(pom-q);
		s1++;
	}
	return pocetak;
}

char *dekodiraj(char *s1, char *s2){
	char *pocetak=s1,*p=s1,sifra[96],*q;
	int slova[127]={0},i,max,l;
	if(*s2=='\0' || *s1=='\0') return pocetak;
	while(*p!='\0')
		slova[(int)*p++]++;
	q=sifra;
	do {
		max=0;
		for (i=126; i>=0; i--)
			if(slova[i]>max){
				max=slova[i];
				l=i;
			}
		slova[l]=-1;
		if(max==0) break;
		*q++=(char) l;
	} while (max!=0);
	for(i=32; i<127;i++)
		if(slova[i]!=-1)
			*q++=(char) i;
	*q='\0';
	q=sifra;
	s1=pocetak;
	while(*s1!='\0'){
		i=0;
		char *pom=q;
		while(*s1!=*pom++)
			i++;
		*s1++=*(s2+i);
	}
	return pocetak;
}
int main(){
	char tekst[] = "Ovo je neki testni tekst";
char sifrarnik[100] = "";
int i;
kodiraj(tekst, sifrarnik);
printf("%s\n", tekst);
for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
dekodiraj(tekst, sifrarnik);
printf("\n%s", tekst);
	return 0;
}
