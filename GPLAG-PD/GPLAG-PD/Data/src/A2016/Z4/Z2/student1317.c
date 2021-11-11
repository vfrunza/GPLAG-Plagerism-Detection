#include <stdio.h>
/* Funkcija kodiraj kodira string na koji pokazuje prvi parametar
   sa tablicom sifrovanja na koju pokazuje drugi parametar */
char* kodiraj(char* org_tekst, char* tabl_s)
{
	char* poc_tekst=org_tekst;
	char temp_2=' ';
	int i=0, j=0, temp_1=0, br_pon_znak[95]={0};

	for(i=32; i<127; i++)
		tabl_s[i-32]=(char) i;
	
	/* Prebrojavanje znakova */	
	while(*org_tekst!='\0')
	{
		for(i=0; i<95; i++)
		{
			if(tabl_s[i]==*org_tekst) 
			{
				br_pon_znak[i]++;
				break;
			}
		}
		org_tekst++;
	}
	/* Sortiranje tablice sifrovanja po broju ponavljanja znakova */
	for(i=0; i<95; i++)
	{
		for(j=i+1; j<95; j++)
		{
			if(br_pon_znak[j]>br_pon_znak[i]) 
			{
				temp_1=br_pon_znak[j];
				br_pon_znak[j]=br_pon_znak[i];
				br_pon_znak[i]=temp_1;
				
				temp_2=tabl_s[i];
				tabl_s[i]=tabl_s[j];
				tabl_s[j]=temp_2;
			}
			else if(br_pon_znak[j]==br_pon_znak[i] && (int)tabl_s[i]>(int)tabl_s[j])
			{
				temp_2=tabl_s[i];
				tabl_s[i]=tabl_s[j];
				tabl_s[j]=temp_2;
			}
		}
	}

	org_tekst=poc_tekst;
	while(*org_tekst!='\0')
	{
		for(i=0; i<95; i++)
		{
			if(*org_tekst==tabl_s[i]) 
			{
				*org_tekst=(char)(126-i);
				break;
			}
		}
		org_tekst++;
	}
	return poc_tekst;
}
/* Funkcija dekodiraj dekodira string na koji pokazuje prvi parametar
   sa tablicom sifrovanja na koju pokazuje drugi parametar */
char* dekodiraj(char* kod_tekst, char* tabl_s)
{
	char* poc_tekst=kod_tekst;
	int indeks=0;
	
	while(*kod_tekst!='\0')
	{
		indeks=126-(int)(*kod_tekst);
		*kod_tekst=tabl_s[indeks];
		kod_tekst++;
	}
	return poc_tekst;
}

int main() 
{
	char tekst[]="";
	char tab_sif[96]="";
	char* pok_tekst=tekst;
	
	pok_tekst=kodiraj(tekst, tab_sif);
	printf("%s", pok_tekst);
	
	pok_tekst=dekodiraj(tekst, tab_sif);
	printf("%s", pok_tekst);
	return 0;
}
