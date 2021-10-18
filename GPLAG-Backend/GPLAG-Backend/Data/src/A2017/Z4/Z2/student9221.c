#include <stdio.h>
#include<stdbool.h>
int brojclanova(char*s)
{
	int broj=0;
	bool tacno=false;
	while(*s!='\0')
	{
		
		if((*s>='a'&&*s<='z')||(*s>='A'&&*s<='Z'))
			{
				if(!tacno)
					{
				//	printf(" slovo je %c \n", *s);
				tacno=true;
				broj++;}
			}
			else
			tacno=0;
			
		
		s++;
		
	}
	return broj;
}


int duzina(char* s)
{
	int duzina=0;
	while(*s!='\0'&&((*s>='a'&&*s<='z')||(*s>='A'&&*s<='Z')))
	{
		duzina++;
		s++;
	}
	return duzina;
}
int prva_sljedeca(char*s)
{
	int duzina=0;
    	while(*s!='\0'&&((*s>='a'&&*s<='z')||(*s>='A'&&*s<='Z')))
	{
		duzina++;
		s++;
	}
	while(!((*s>='a'&&*s<='z')||(*s>='A'&&*s<='Z')))
	{
		if(*s=='\0')break;
		duzina++;
		s++;
	}
	
	if(*s=='\0')return -1;
	else return duzina;
	
}
bool provjeri_duzine(char* tekst , int* niz,int k )
{
	//printf("brck: %d \n",brojclanova(tekst));
	if(brojclanova(tekst)!=k)
	return 0;
	
	while(*tekst!='\0')
	{
		//printf("%d = %d . %c   %d \n", duzina(tekst),*niz ,*tekst ,prva_sljedeca(tekst));
		
		if(duzina(tekst)!=*niz)return 0;
		
		
		if(prva_sljedeca(tekst)==-1)break;
		
		niz++;	
		tekst+=prva_sljedeca(tekst);
		//	printf("  %d = %d . %c   %d \n", duzina(tekst),*niz ,*tekst ,prva_sljedeca(tekst));
	}
	
	return 1;
	
}

int main() {


char tekst[] = "Napravicemo jos jedan primjer";
int niz[] = {11, 3, 5, 7};

printf("%d ", provjeri_duzine(tekst, niz, 0));
printf("%d ", provjeri_duzine(tekst, niz, 3));
printf("%d ", provjeri_duzine(tekst, niz, 4));
	
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
}
