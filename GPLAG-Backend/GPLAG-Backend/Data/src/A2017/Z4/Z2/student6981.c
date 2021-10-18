#include <stdio.h>

void unesi(char niz[], int velicina)
{
	int i;
	char znak=getchar();
	if(znak == '\n') znak=getchar();
	i=0;
	
	while(i<velicina-1 && znak!= '\n')
	{
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	
	niz[i]='\0';
}

int provjeri_duzine(char *string, int *niz, int duz1)
{
	int rijec=0, duzina=0;
	int i=0;
	
	while(*(string+i)!='\0')
	{
		if((*(string+i)<='Z' && *(string+i)>='A')|| (*(string+i)<='z' && *(string+i)>='a'))
		{
			duzina++;
			if(*(string+i+1)=='\0') rijec++;
		}
		else if(duzina>0)
		{
			if(rijec+1>duz1){return 0;}
			if(niz[rijec]!=duzina) return 0;
			rijec++;
			duzina=0;
		}
		i++;
	}
	if(rijec>duz1 || rijec<duz1) {return 0;}
	return 1;
}

int main(){
	
	char tekst[]="Napravicemo jos jedan primjer";
	int niz[]={11, 3, 5, 7};
	
	printf("%d ", provjeri_duzine(tekst, niz, 0));
	printf("%d ", provjeri_duzine(tekst, niz, 3));
	printf("%d ", provjeri_duzine(tekst, niz, 4));
	return 0;
	
	
}



