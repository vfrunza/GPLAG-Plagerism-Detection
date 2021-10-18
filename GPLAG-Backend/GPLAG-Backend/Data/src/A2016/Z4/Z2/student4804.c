#include <stdio.h>

void unesi(char s[], int n)
{
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(i<n-1 && znak!='\n') {
		s[i]=znak;
		i++;
		znak=getchar();
	}
	s[i]='\0';
}

char *kopiraj(char *s,const char *r)
{
	char *pocs=s;
	while(*r) {
		*s++=*r++;
	}
	*s='\0';
	return pocs;
}

int broj_ponavljanja(char *s, char c)
{
	int br=0;
	while(*s!='\0') {
		if(*s==c)
			br++;
		s++;
	}
	return br;
}

char *dodaj(char *s, const char *r, int n)
{
	char *pocs=s;
	while(*s!='\0') {
		s++;
	}
	while(n--) {
		if(!(*s++ = *r++))
			return pocs;
	}
	*s='\0';
	return pocs;
}

int duzina(char *s)
{
	int br=0;
	while(*s!='\0') {
		br++;
		s++;
	}
	return br;
}

char *kodiraj(char *s,char *t)
{

	char *pocs=s,*poct,temp,str2[100]="",*r,*pocr;
	int n,i,j,duzr,duztab,ubaci;
	r=&str2[0];
	poct=t;

	/*Upisivanje znakova iz unesenog stringa u tablicu*/
	if(*t=='\0')
	*t=*s;
	while(*s!='\0') {
		ubaci=1;
		t=poct;
		while(*t!='\0') {
			if(*s==*t)
				ubaci=0;
			t++;
		}

		if(ubaci==1) {
			*t=*s;
		}
		s++;
	}
	t++;
	*t='\0';
	t=poct;
	s=pocs;
	n=duzina(t);
	
	/*Sortiranje po broju ponavljanja/ASCII vrijednosti ako je jednak broj ponavljanja*/
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			
			if(broj_ponavljanja(s,t[i])>broj_ponavljanja(s,t[j])) {
				temp=t[i];
				t[i]=t[j];
				t[j]=temp;
				
			} else if(broj_ponavljanja(s,t[i])==broj_ponavljanja(s,t[j])) {
				
				if(t[i]<t[j]) {
					temp=t[i];
					t[i]=t[j];
					t[j]=temp;
					
				}
			}

		}
	}
	/*Upisivanje ostatka tablice*/
	pocr=r;
	*r=' ';
	while(*r!='~') {
		r++;
		*r=*(r-1)+1;
	}
	r++;
	*r='\0';
	r=pocr;

	for(i=0; i<n; i++) {
		while(*r!='\0') {
			if(*r==t[i]) {
				kopiraj(r,r+1);
			} else
				r++;
		}
		r=pocr;
	}
	/*Kodiranje*/
	duzr=duzina(r);
	dodaj(t,r,duzr);
	duztab=duzina(t);
	while(*s!='\0') {
		for(i=0; i<duztab; i++) {
			if(*s==t[i]) {
				*s=126-i;
				break;
			}
		}
		s++;
	}
	return pocs;
}

char *dekodiraj(char *s,char *t)
{
	char *pocs=s;
	int i;
	while(*s!='\0') {

		i=126-*s;
		*s=t[i];
		s++;
	}
	return pocs;
}

int main()
{

	char tekst[] = "Ovo cemo kodirati i dekodirati u istoj liniji";
	char sifrarnik[100] = "";
	int i;
	kodiraj(tekst,sifrarnik);
	dekodiraj(tekst,sifrarnik);
	kodiraj(tekst,sifrarnik);
	dekodiraj(tekst,sifrarnik);
	printf("%s\n", tekst);
	for(i = 0; i < 20; i++) printf("%c", sifrarnik[i]);

	return 0;
}
