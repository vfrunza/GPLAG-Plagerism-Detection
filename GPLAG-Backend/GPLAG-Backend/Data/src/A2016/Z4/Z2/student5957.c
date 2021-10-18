#include <stdio.h>

void unesi(char niz[], int velicina)
 {
	char znak = getchar();
	int i=0;
	if (znak == '\n') znak=getchar();
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

char* kodiraj(char *s,char *sifra){
	char *a,tekst[100]="";
	int pomocna=0,i=0,max=-1,j=0,k=0;
	int niz[158]={0};
	a=s;
	while(*s!='\0'){
		tekst[k]=*s;
		pomocna=*s;
		niz[pomocna]++;
		s++;
		k++;
	}
	for(k=0;k<96;k++){
	for(i=32;i<127;i++){
		if(niz[i]>max){
			max=niz[i];
			j=i;
		}
	}
	if(max>-1)
	niz[j]=-1;
	sifra[k]=j;
	j=0;
	max=-1;
	}
	for(i=0;tekst[i]!='\0';i++){
		for(k=0;sifra[k]!='\0';k++){
			if(sifra[k]==tekst[i])
			a[i]=126-k;
		}
	}
	return a;
}

char* dekodiraj(char *s,char *sifra){
	char tekst[100]="",*a;
	int i=0,k=0;
	a=s;
	while(*s!='\0'){
		tekst[k]=*s;
		s++;
		k++;
	}
	for(i=0;tekst[i]!='\0';i++){
		for(k=0;sifra[k]!='\0';k++){
			if(sifra[126-tekst[i]]==sifra[k])
			a[i]=sifra[k];
		}
	}
	return a;
}

int main() {
	char tekst[100],sifrarnik[96]="";
	unesi(tekst,100);
	kodiraj(tekst,sifrarnik);
    dekodiraj(tekst,sifrarnik);
	return 0;
}
