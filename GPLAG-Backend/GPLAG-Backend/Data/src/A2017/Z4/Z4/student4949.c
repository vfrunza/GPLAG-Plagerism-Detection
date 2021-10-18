#include <stdio.h>
#include <string.h>

/*int provjeri(char*s){
	char *a, *pocetak, *kraj;
	int brojac1=0, brojac2=0;
	a=s;
	while(*a!='\0'){
		//if(*a=='<' && *a && *(a+1)=='.') return 0;
		if(*a=='<') brojac1++;
		if(*a=='>') brojac2++;
		a++;
	}
	if(brojac1!=brojac2) return 0;
	a=s;
	
	while(*a!='/0'){
		while(*a!='<' && *a) a++;
		if(*a=='<'){
			pocetak=a;
			while(*a!='>' && *a) a++;
			kraj=++a;
			a=pocetak;
			while(*kraj) *pocetak++=*kraj++;
			*pocetak='\0';
		}
	}
	return 1;
}*/

/*int provjeri(char *s)
{
	char *p = s;
	char *naziv[100];
	while (*p != '\0')
	{
		if (*(p+1) != '\0' && *p == '<' && *(p+1) != '\')
		{
			char *poc = p + 1;
			int i = 0;
			while (*poc != ' ') 
			{
				naziv[i] = *poc;
				poc++; i++;
			}
		}
	}
} */



int main() {
	// AT1: Primjeri iz zadatka
char tekst1[] = "<div id=\"tekst\"><h2>Naslov</h2><p>Ovo je <b>cetvrti</b> i <i>posljednji</i> zadatak iz <a href=\"zadaca4\">zadace 4</a></p></div>";
char tekst2[] = "<b><a>proba</b></a>";
printf("%d ", provjeri(tekst1));
//printf("%d ", provjeri(tekst2));
	return 0;
}
