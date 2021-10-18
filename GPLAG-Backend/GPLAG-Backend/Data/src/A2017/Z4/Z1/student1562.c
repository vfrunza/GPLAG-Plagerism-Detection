#include <stdio.h>


char* ubaci_broj (char* tekst, int broj)
{
	
	char *pocetak = tekst;
	//cpretvori  u pozitivne
    int duzina_broja = 1, temp_broj=broj, fixna_duzina;
    if(temp_broj < 0)
    {
        duzina_broja++;
        temp_broj=temp_broj*-1;
    }
    //izbroji cifre
    while(temp_broj != 0)
    {
        temp_broj = temp_broj/10;
        duzina_broja++;
    }
    char *pom1 = tekst;
    fixna_duzina = duzina_broja;
    
    // ako je pocetak teksta prazan pomjeri pokazivac na prvu rijec
    if(*tekst == ' ')
    {
    	while(*++tekst == ' ');
    }
    
    char *ispitivac_kraja;
    int kraj = 0;
    
    while(*tekst++ != '\0')
    {
		duzina_broja = fixna_duzina;
		
		//ispitaj jesu li sve razmaci do kraja stringa
		ispitivac_kraja = tekst;
		while (*ispitivac_kraja++ == ' ' ) {
			if(*(ispitivac_kraja+1) == '\0')
			{
				kraj = 1;
			}
			
		}
		
		//upisi broj
        if(*tekst == ' ' && kraj == 0)
        {
        	
            int i = 0;
        	if(*(tekst+1) == ' ')
        	{
        		duzina_broja--;
        		i--;
        	}
            int temp2 = broj;
            if(temp2<0)
            {
                temp2 = temp2 * -1;
            }
            char* pom = tekst;
            while(*pom++ != '\0');
            while(pom != tekst)
            {
                *(pom+duzina_broja) = *pom;
                  pom--;
            }
            
            
        	*(tekst + duzina_broja - i) = ' ';
            
            i++;
            while(temp2 != 0)
            {
                *(tekst + duzina_broja - i) = temp2%10 + 48;
                temp2=temp2/10;
                i++;
            }
            if(broj<0)
            {
                *(tekst + duzina_broja - i) = '-';
            }
            tekst += i;
            while(*++tekst == ' ');
        }
    }
    
    return pocetak;
}

int main()
{
char s[66] = "a sada i primjer koji se zavrsava razmacima       ";
printf("\"%s\"", ubaci_broj(s, 1));
}