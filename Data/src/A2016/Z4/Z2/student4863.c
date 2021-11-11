#include <stdio.h>
char* kodiraj(char* tekst, char* tablica)
{
	char* reset=tekst;
	char* tablica2=tablica;
	char* i=tablica, *k;
	char* treset=tablica;
	int br=-31, x=0;
	int brojac[128]= { 0 }, j=0, t, ubaci;
	int ponavljanje=0;
	for(i=tablica; i<tablica+96; i++)
		*i=0;
	*i='\0';
	i=treset;
	//formiranje tablice i broj ponavljanja svakog karaktera iz teksta
	while(*tekst != '\0') {
		ponavljanje=0;
		for(i=treset; i<treset+96; i++) {
			if(*tekst == *i && *i != '\0' && *tekst != '\0')
				ponavljanje++;
		}
		if(ponavljanje==0) {
			*tablica=*tekst;
			tablica++;
		}
		brojac[*tekst]++;
		tekst++;
	}
	tablica=treset;

	//sortira tablicu po broju ponavljanja
	for(i=treset; i<treset+96; i++) {
		for(k=i; k<treset+96; k++) {
			if(brojac[*i]<brojac[*k]) {
				t=*i;
				*i=*k;
				*k=t;
			} else if(brojac[*i]==brojac[*k] && *k <*i) {
				t=*i;
				*i=*k;
				*k=t;
			}
		}
	}
	//prebrojava koliko ima znakova da se ne pojavljuju u tekstu
	for(j=0; j<127; j++)
		if(brojac[j]==0)
			br++;
	//ubacuje u tablicu karaktere koji se nikako ne pojavljuju
	j=32;
	tablica=treset+96-br;
	while(tablica<treset+96) {
		ubaci=1;
		tablica2=treset;
		while(tablica2<treset+96-br) {
			if(j==*tablica2)
				ubaci=0;
			tablica2++;
		}
		if(ubaci==1) {
			*tablica=j;
			tablica++;
		}
		j++;
	}
	*(tablica-1)='\0';
	
	//kodira
	tablica=treset;
	tekst=reset;
	while(*tekst != '\0') {
		while(*tablica != '\0') {
			if(*tekst == *tablica) {
				*tekst=126-(tablica-treset);
				break;
			}
			tablica++;
		}
		tablica=treset;
		tekst++;
	}
	tablica=treset;
	tekst=reset;

	return reset;
}

char* dekodiraj(char* tekst, char* tablica)
{
	char* reset=tekst;
	char* treset=tablica;

	while(*tekst != '\0') {
		while(*tekst != 126-(tablica-treset))
			tablica++;
		*tekst=*tablica;
		tablica=treset;
		tekst++;
	}
	return reset;

}
int main()
{
	char tekst[] = "wo{~vus{~q}tz}z|y}~x~rpy|";
	char sifrarnik[100] = "";
	char sifrarnik2[100] = "";
	int i;
	kodiraj(tekst, sifrarnik);
	printf("\n%s\n", tekst);
	for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
	/* dekodiraj(tekst, sifrarnik2);
	 printf("\n%s\n", tekst);
	 dekodiraj(tekst, sifrarnik);
	 printf("\n%s", tekst);*/
	return 0;
}
