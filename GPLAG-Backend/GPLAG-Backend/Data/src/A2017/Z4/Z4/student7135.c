#include <stdio.h>
int provjeri(char* s)
{
	int i=0,j=0;
	int k=0;
	int matrica[100][100]= {{0,0}};
	int aktivni[100]= {0};
	int aktivan=0;
	while(*s!='\0') {
		if(*s=='<') {
			s++;
			if(*s!='/' && *s!='\0') {
				j=0;
				while(*s!=' ' && *s!='>' && *s!='\0') {
					matrica[i][j]=*s;
					j++;
					s++;
				}
				if(j==0) return 0;
				aktivni[i]=1;
				i++;
			}
			if(*s=='/' && *s!='\0') {
				s++;
				for(k=i; k>=0; k--)
					if(aktivni[k]==1) {
						aktivan=k;
						break;
					}
				k=0;
				while(*s!='>' && *s!='\0') {
					if(matrica[aktivan][k]!=*s  && (*s!=matrica[aktivan][k]+('a'-'A')) && (*s!=matrica[aktivan][k]-('a'-'A')) && *s!=' ') return 0;
					s++;
					k++;
				}
				aktivni[aktivan]=0;
			}
		}
		s++;
	}
	for(k=0; k<i; k++)
		if(aktivni[k]!=0) return 0;
	return 1;
}
int main()
{
	char tekst1[] = "<div id=\"tekst\"><h2>Naslov</h2><p>Ovo je <b>cetvrti</b> i <i>posljednji</i> zadatak iz <a href=\"zadaca4\">zadace 4</a></p></div>";
	char tekst2[] = "<b><a>proba</b></a>";
	printf("%d ", provjeri(tekst1));
	printf("%d ", provjeri(tekst2));
	return 0;
}
