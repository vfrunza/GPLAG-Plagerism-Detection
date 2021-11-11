#include <stdio.h>

int slovo (char a) 
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return 1;
	return 0;
}

char* najcesca(char *string)
{
	char* prva_r = string;
	char* ispocetka = string;
	char* novi_poc = string;
	char* najcesca = string;
	int brojac = 0, max = 0;
	while (!slovo(*prva_r) && *prva_r != '\0')
		prva_r++;
	najcesca = prva_r;
	while (*prva_r != '\0') 
	{ 
		brojac = 0;
		while (!(slovo (*prva_r)) && *prva_r != '\0')
			prva_r++;
		if (prva_r == '\0') return najcesca;
		novi_poc = prva_r;	
		/* dva pokazivača na prvo slovo prve riječi */
		ispocetka = prva_r;
		
		while (slovo(*novi_poc) && *novi_poc != '\0')
			novi_poc++;
		while (!slovo(*novi_poc) && *novi_poc != '\0')
			novi_poc++;
		while (*novi_poc != '\0')
		{	
			prva_r = ispocetka;
			while (slovo(*prva_r) && (*prva_r == *novi_poc || *prva_r == *novi_poc + 32 || *prva_r == *novi_poc - 32))
			{
				prva_r++;
				novi_poc++;
			} 
			/* ako oba pokazivača pokazuju na znak povećaj brojač (riječi su jednake)*/
			if (!slovo(*prva_r) && !slovo(*novi_poc))	
				brojac++;
			/* ako prvi pokazivač pokazuje na znak, a drugi na slovo - drugi pokazivač izlazi iz te riječi*/
			else if (!slovo(*prva_r) && slovo(*novi_poc)) 
			{
				while (slovo(*novi_poc))
					novi_poc++;
			} 
			/* ako prvi pokazuje na slovo, a drugi na znak, resetiramo prvi pokazivač na početak riječi */
			else if (slovo(*prva_r) && !slovo(*novi_poc)) 
				prva_r = ispocetka;
			/* ako su oba na različitom slovu, prvi se resetira na početak riječi dok drugi prelazi na prvi znak nakon te riječi */
			else 
			{					
				prva_r = ispocetka;
				while (slovo(*novi_poc))
					novi_poc++;
			} 
			while (!slovo(*novi_poc) && *novi_poc != '\0') /* novi_poc nam je sad na znaku pa ga moramo pomjeriti na iduće slovo, tj početak riječi */
				novi_poc++;
		}
	    if (brojac > max)
	    {
	  		max = brojac;
	  		najcesca = ispocetka;
	  	} 
	    while (slovo(*prva_r))
	  		prva_r++;
	} if (max = 0)
		*najcesca = '\0';
	return najcesca; 
}

char* izbaci_najcescu (char* s)
{
	char* finish = s;
	char* nasa_rijec = najcesca(s);
	
	char* cuvar_nase = nasa_rijec;
	char* kraj = s;
	while (slovo (*nasa_rijec))
		nasa_rijec++;
	kraj = nasa_rijec;
	char* cuvar_kraja = nasa_rijec;
	char* za_izbacivanje;
	nasa_rijec = cuvar_nase;
	while (*kraj != '\0')
	{
		while (!slovo(*kraj) && *kraj != '\0')
			kraj++;
		cuvar_kraja = kraj;
		
		while (slovo(*nasa_rijec) && (*nasa_rijec == *kraj || *nasa_rijec == *kraj + 32 || *nasa_rijec == *kraj - 32) )
		{
			nasa_rijec++;
			kraj++;
		}
		if (!slovo(*nasa_rijec) && !slovo(*kraj))
		{
			za_izbacivanje = cuvar_kraja;
			while (*kraj != '\0')
				*za_izbacivanje++ = *kraj++;
			/* da ukloni sve ostale */
			while (*za_izbacivanje != '\0')
				*za_izbacivanje++ = '\0';
			kraj = cuvar_kraja;
			nasa_rijec = cuvar_nase;
		}
		else if ((slovo(*nasa_rijec) && slovo(*kraj)) || (!slovo(*nasa_rijec) && slovo(*kraj))) 
		{
			nasa_rijec = cuvar_nase;
			while (slovo(*kraj))
				kraj++;
		}
		else 
			nasa_rijec = cuvar_nase;
	}
	while (slovo(*nasa_rijec))
		nasa_rijec++;
	while (*nasa_rijec != '\0')
		*cuvar_nase++ = *nasa_rijec++;
	while (*cuvar_nase != '\0')
		*cuvar_nase++ = '\0';
	return finish;
}

int main() {
	char niz[] =" iiiii wat ";
	char* pok = izbaci_najcescu(niz);
	while (*pok != '\0')
		printf ("%c", *pok++);

	return 0;
}
