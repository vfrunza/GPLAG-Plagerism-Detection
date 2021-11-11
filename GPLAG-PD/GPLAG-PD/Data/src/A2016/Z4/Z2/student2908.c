#include <stdio.h>

char *kodiraj(char *s,char *tablica){
	int maxi=0,i,j,brojaci[95]={0};
	char *x,*tab,*y;
	x=s;y=s;
	tab=tablica;
	while(*y!='\0'){
		for(i=0;i<95;i++)
			if(*y==i+32)brojaci[i]++;
		y++;
	}
	for(i=0;i<96;i++){
		for(j=0;j<95;j++)
			if(brojaci[j]>brojaci[maxi]) maxi=j;
		*tablica++=maxi+32;
		
		brojaci[maxi]=-1;
		maxi=0;
	}
	*tablica='\0';
	tablica=tab;
	while(*x!='\0'){
		while(*x!=*tab) tab++;
		*x=126-(tab-tablica);
		tab=tablica;
		x++;
	}
	return s;
}

char *dekodiraj(char *s,char *tablica){
	int i, j=-1;
	char *x=s, *tab=tablica;
	while(*x!='\0'){
		i=126-*x;
		for(j=0;j<i;j++) tab++;
		*x=*tab;
		tab=tablica;
		x++;
	}
	return s;
}

int main() {
	char tekst[] = "Ovo cemo sifrirati 2 puta";
    char sifrarnik[100] = "";
    char sifrarnik2[100] = "";
    int i;
    kodiraj(tekst, sifrarnik);
    printf("%s\n",tekst);
    for (i=0; i<10; i++) printf("%c",sifrarnik[i]);
    printf("\n");
    kodiraj(tekst, sifrarnik2);
    printf("%s\n",tekst);
    for (i=0; i<10; i++) printf("%c", sifrarnik2[i]);
    printf("\n");
    dekodiraj(tekst, sifrarnik2);
    printf("%s\n",tekst);
    dekodiraj(tekst, sifrarnik);
    printf("%s", tekst);
	return 0;
}
