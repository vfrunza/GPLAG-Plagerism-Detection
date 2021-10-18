#include <stdio.h>
#include <stdlib.h>

int izbroj_neponavljana_slova(char* pocetak, int kraj_stringa){

	
	char* pom1 = pocetak;
	char* pom2;
	int brojac=0, ponavlja_se;
	char kraj=' ';
	if(kraj_stringa==1){
		kraj='\0';
	}
	while(*pom1!=kraj){
		pom2=pocetak;
		ponavlja_se=0;
		while(pom2!=pom1)
		{
			if(*pom2==*pom1 || *pom2 == (*pom1 + 32) || *pom2 == (*pom1 - 32) || (*pom2 + 32 == *pom1) || (*pom2 - 32 == *pom1) )
			{
				ponavlja_se=1;
				break; 
			}
			pom2++;
		}
		if(ponavlja_se==0)
		{
			brojac++;
		}
		pom1++;
	}
	return brojac;
}

int provjeri_ima_li_vec_u_stringu(char *s, char c)
{
	char *pom = s;
	while (*pom != '\0') {
		if(*pom == c)
		{
			return 1;
		}
			
		pom++;
	}
	
	return 0;
} 

void najduzi_bp(char* s1, char* s2)
{
	char* pocetak= s1, *pozicija;
	int najduzi=0, pom;
	while(*s1++!='\0')
	{
		if(*s1==' ' || *(s1+1)=='\0'){
			//ako ima jedno slovo ili dodje do kraja
			if(*(s1+1)=='\0')
			{
				pom=izbroj_neponavljana_slova(pocetak, 1);
			}
			//ako naidje na razmak
			else {
				pom=izbroj_neponavljana_slova(pocetak, 0);
			}
			if(pom>najduzi)
			{
				najduzi=pom;
				pozicija=pocetak;
			}
			
			pocetak=s1+1;
		}
	}
	
	*s2 = '\0';
	char *pocetakStringaDva = s2;
	
	while (1) {
		if(provjeri_ima_li_vec_u_stringu(pozicija+1, *pozicija) == 1)
		{
			pozicija++;
		}
		else
		{
			break;
		}
		
	}
	
	while(1)
	{
		
		if(provjeri_ima_li_vec_u_stringu(pocetakStringaDva,*pozicija) == 0 && ((*pozicija>='A' && *pozicija<='Z') || (*pozicija>='a' && *pozicija<='z')))
		{
			*s2=*pozicija;
			*(s2+1) = '\0';
			s2++;
		}
		pozicija++;
		if(*pozicija==' ' || *pozicija=='\0')
			break; 
		
	}
}




int main() {
	     char niz[10];
        najduzi_bp ("Ovo", niz);
        printf ("Niz: '%s'", niz);
}
