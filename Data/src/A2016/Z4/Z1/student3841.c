#include <stdio.h>

/*POMOCNA FUNKCIJA ZA PROVJERU DA LI JE PROSLIJEDJENI ZNAK SLOVO*/
int je_li_slovo(char e)
{
	if((e >= 'A' && e <= 'Z') || (e >= 'a' && e <= 'z'))
		return 1;
		
	return 0;
}
/*POMOĆNA FUNKCIJA KOJA PRETVARA MALO SLOVO U VELIKO*/
char veliko_slovo(char a)
{
	if(a >= 'a' && a <= 'z')
		a -= 32;
		
	return a;
}

char *izbaci_najcescu(char *s)
{
	char *pocetak = s; /*pocetak stringa*/
	int nije_slovo = 1, nije_slovo2 = 1;
	char *kraj_rijeci, *kraj_rijeci2;
	char *pocetak_rijeci, *pocetak_rijeci2;
	char *pp, *dp, *tp; /*prvi pokazivac, drugi pokazivac, treci pokazivac*/
	char *fluks, *fluks4;
	char *najcesca_p = s; /*pocetak najcesce rijeci*/
	char *najcesca_k = s; /*kraj najcesce rijeci*/
	int iste = 1, brojac = 1;
	int max = 0;
	int duzina = 0, br_rijeci = 0;


	if(*s == 0)
		return s; //ako je prazan string ne radi ništa
		
	while (*s != 0)
	{
		if(je_li_slovo(*s) == 0)
			nije_slovo = 1;
			
		else if(nije_slovo == 1)
		{
			nije_slovo = 0;
			br_rijeci++;
			kraj_rijeci = s; /*s je pocetak rijeci, tj kraj pokazuje na prvo slovo svake rijeci*/
			
			while(*kraj_rijeci != 0 && je_li_slovo(*kraj_rijeci) == 1)
				kraj_rijeci++; /*provjerava svako slovo, tj dolazi do kraja rijeci*/
			
			pocetak_rijeci = s;
			/*za prvu rijec pretpostavlja da je najcesca*/
			if(br_rijeci == 1)
			{
				najcesca_k = kraj_rijeci;
				najcesca_p = pocetak_rijeci;
			}
			
			pp = kraj_rijeci;
			/*traze se ostalee rijeci za poredjenje*/
			nije_slovo2 = 1;
			brojac = 1;
			while(*pp != 0)
			{
				if(je_li_slovo(*pp) == 0)
					nije_slovo2 = 1;
					
				else if(nije_slovo2 == 1)
				{
					nije_slovo2 = 0;
					kraj_rijeci2 = pp;
					
					while(*kraj_rijeci2 != 0 && je_li_slovo(*kraj_rijeci2) == 1)
						kraj_rijeci2++;
						
					pocetak_rijeci2 = pp;
					
					iste = 1; //pretpostavka da su dvije rijeci iste
					
					dp = pocetak_rijeci;
					tp = kraj_rijeci;
					fluks = pocetak_rijeci2;
					fluks4 = kraj_rijeci2;
					
					/*Poredjenje jesu li iste*/
					while(dp != tp && pocetak_rijeci2 != kraj_rijeci2)
					{
						if(veliko_slovo(*dp++) != veliko_slovo(*pocetak_rijeci2++))
						{
							iste = 0; /*nisu iste, prekid*/
							break;
						}
					}
					
					if(tp != dp || kraj_rijeci2 != pocetak_rijeci2)
						iste = 0;
						
					if(iste)
						brojac++; 
						
					if(iste == 1 && brojac > max)
					{
						/*nadjena je rijec koja je cesca od prethodne najcesce*/
						max = brojac;
						najcesca_p = fluks;
						najcesca_k = fluks4;
						duzina = najcesca_k - najcesca_p;
						
					}
				}
				pp++;
			}
		}
		s++;
	}
	/*Izbacivanje najcesce rijeci*/
	s = pocetak;
	nije_slovo = 1;
	
	while(br_rijeci > 1 && s < najcesca_p)
	{
		if(je_li_slovo(*s) == 0)
			nije_slovo = 1;
			
		else if(nije_slovo == 1)
		{
			nije_slovo = 0;
			pocetak_rijeci = s;
			kraj_rijeci = s;
			
			while(*kraj_rijeci != 0 && kraj_rijeci < najcesca_p && je_li_slovo(*kraj_rijeci) == 1)
				kraj_rijeci++;
				
			iste = 1;
			dp = pocetak_rijeci;
			tp = kraj_rijeci;
			fluks = najcesca_p;
			fluks4 = najcesca_k;
			
			while(dp != tp && fluks != fluks4)
			{
				if(veliko_slovo(*dp++) != veliko_slovo(*fluks++))
				{
					iste = 0;
					break;
				}
			}
			
			if(tp != dp || fluks != fluks4)
				iste = 0;
				
			if(iste) /*izbacujemo rijec*/
			{
				najcesca_p -= duzina;
				najcesca_k -= duzina;
				s--;
				while(*pocetak_rijeci++ = *kraj_rijeci++);
			}
		}
		s++;
	}
	while(*najcesca_p++ = *najcesca_k++); /*izbacuje posljednju najcescu rijec*/
	
	return pocetak;
}
int main() 
{
	/*printf("Zadaća 4, Zadatak 1");*/
	char tekst[100] = "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS";
	
	printf("'%s'", izbaci_najcescu(tekst));
	return 0;
}
