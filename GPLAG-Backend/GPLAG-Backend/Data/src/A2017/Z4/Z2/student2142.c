#include <stdio.h>
#include <ctype.h>

int JelSlovo(char s)
{ 
	int slovo=0;
	if(s>='A' && s<='Z' || s>='a' && s<='z')
		slovo=1;
	
	return slovo;
}

int provjeri_duzine(char *str,int *niz,int vel)
{
	int i;
	int br;
	int b=vel;
	char *p;
	if(vel<=0) return 0;
	
	for(p=str,i=0;*p!='\0';p++,i++)
	{
	    br=0;
	    while(!JelSlovo(*p))p++;
		while(JelSlovo(*p))
		{
			p++;
			br++;
		}
	
		b--;
		if(niz[i]!=br || b<0 || (*p=='\0' && i<vel-1))
			return 0;
			
		if(*p=='\0') break;
	}
	
	return 1;
}

int main() {
/* AT5: Ne-slova na pocetku stringa */
/* AT6: Ne-slova na kraju stringa */
char tekst[] = "Kakav je ovo test!?!?";
int niz[] = {5,2,3,4};
int niz2[] = {5,2,3,8};
int niz3[] = {5,2,3,4,0};

printf("%d ", provjeri_duzine(tekst, niz3, 5));
printf("%d ", provjeri_duzine(tekst, niz2, 4));
printf("%d ", provjeri_duzine(tekst, niz, 4));
	return 0;
}
