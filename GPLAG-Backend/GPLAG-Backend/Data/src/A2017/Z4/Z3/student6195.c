#include <stdio.h>




int zadovoljava(char *p, char *k)
{
	char *klizni = p;
	char *klizni2;
	int da = 1;
	while(klizni <= k)
	{
		//uzme zadnje slovo kao referentno
		// a poredit ce sa svim ostalim slovima pocevsi od predzadnjeg ka prvom
		klizni2 = klizni - 1;
		while(klizni2 >= p)
		{
			if(*klizni2-*klizni==0||(*klizni2-*klizni=='a'-'A'&&*klizni2>='a'&&*klizni2<='z')||*klizni2-*klizni=='A'-'a')da=0;
			//provjerava da li su dva slova ista 
			// ako jesu imamo da=0
			// ako je da = 0 onda funkcija na kraju vraa to 0 i to znaci da rijec nije sastavljena od slova bez ponavljanja 
			klizni2--;
			// idemo ka prvom slovu kao sto sam rekao
		}
		klizni++;
	}
	return da;
}

int slovo(char c)
{
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	return 1;
	return 0;
}
void najduzi_bp(char *s1, char *s2)
{
	char *poc = s2, *kraj = s2;
	char *p1, *k, *k1, *klizni;
	int duzina = 0;
	int neslovo = 1;
	
	klizni = s1;
	//idemo od pocetka stringa
	while(*klizni != '\0') 
	{
		if(!slovo(*klizni))
		{
			//ako nije slovo stavi varijablu na 1
			neslovo = 1;
		}
		else if(neslovo)
		{ 	//ako je slovo, krecemo u akciju
			p1 = klizni;
			k = klizni;
			while(slovo(*k)) k++;
			//idemo na kraj rijeci, tj. pomjeramo pokazivac sve dok je slovo
			// sad ovaj pokazivac k pokazuje na prvo neslovo poslije rijeci
			//p1 je prvo slovo rijeci 
			//k je prvo slovo neslovo poslije rijeci
			while(p1 < k-1)
			{
				k1 = p1;
				while(k1 < k)
				//sve dok ova dva pokazivaca zatvaraju "rijec"-podrijec
				{
					if(zadovoljava(p1,k1)) //saljemo funkciji ovu podrijec da je ona ispita
					{
						//ako uđe u ovu granu, znaci da je rijec prosla provjeru 
					
						if(k1 - p1 > duzina) //ako je razlika pokazivaca kraja rijeci i pocetka veca od max duzine koju trenutno imamo onda je to nova max rijec
						{
							poc = p1; //samo pomocna varijabla pocetak rijeci(zapamcen sve dok ne dodje veca)
							kraj = k1; //samo pomocna varijabla kraj rijeci
							duzina = kraj - poc; // smjestimo novu duzinu
						}
					}
					//svaki sljedeci put saljem podrijec koja nema slovo s pocetka prethodne 
					k1++;
				}
				//dvostruka provjera
				p1++;
			}
			// kad se ova petlja zavrsi vec smo na zadnjem slovu
			neslovo = 0; // napisemo sad da je upravo bilo slovo
		}
		// pomjerimo pokazivac dalje
		klizni++;
	}
	p1 = s2; //pohranjujemo rijec
	
	while(poc <= kraj)
	{
		//pohranjujemo karaktere u nas string s2 jedan po jedan
		*p1 = *poc;
		p1++;
		poc++;
	}
	// zatvaramo nas string sa \0 
	*p1 = '\0';
	
	
}
int main() {
	
	return 0;
}
