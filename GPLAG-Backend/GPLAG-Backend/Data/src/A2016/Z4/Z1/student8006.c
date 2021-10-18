#include <stdio.h>

int slovo ( char c )
{
	if ( c >= 'a' && c <= 'z' )
	c -= 32;
	
	return ( c >= 'A' && c <= 'Z' );
}

/* S obzirom da je u zadatku trazeno da program ne razlikuje velika i mala slova
	tj da mu nije vazno da li je rijec napisana Rijec rijec ili RIJEC moramo definirati funkciju koja ce 
	provjeru raditi neovisno */
	
char Veliko_slovo ( char c )
{
	if ( c >= 'a' && c <= 'z' )
	{
		c -= 32; 
		return c;
	}
	
	else
	return c;
	
}

char* izbaci_najcescu ( char *s )
{
	char *operativni_pokazivac = s; /* Znamo da moramo vratiti pokazivac na pocetak,
	a posto je na pocetku mozemo njegovu vrijednost dodijeliti operativnom pokazivacu 
	i na kraju samo vratiti ulazni pokazivac s */ 
	
	int duzina_trenutne_rijeci, poredjena_duzina, i, broj_ponavljanja_rijeci, broj_ponavljanja_najcesce_rijeci = 0, najveca_duzina_rijeci;
	
	/*  */
	char *trenutna_adresa_rijeci = s;
	
	while ( *operativni_pokazivac != '\0' )
	{
		char *klizeci_pokazivac_kroz_rijec = operativni_pokazivac;
		char *kontrolni_klizac_koji_stoji_na_pocetku_stringa = operativni_pokazivac;
		/* Definirali smo jos dva lokalna pokazivaca koji ce nam sluziti da bi odredili duzine rijeci */
		
		duzina_trenutne_rijeci = 0;
		
		broj_ponavljanja_rijeci = 0; 
		
		/* Naredna petlja ce sluziti da bi mogli odrediti duzinu svake rijeci pojedinacno */
		
		while ( slovo ( *klizeci_pokazivac_kroz_rijec ) )
		{
			klizeci_pokazivac_kroz_rijec++;
			duzina_trenutne_rijeci++;
		}
		
		operativni_pokazivac = klizeci_pokazivac_kroz_rijec;
		
		/* Naredna petlja ce sluzi za pokazivanje na sljedecu rijecu odnosu na referentnu rijec */
		while ( !slovo ( *operativni_pokazivac ) && *operativni_pokazivac != '\0' )
		{
			*operativni_pokazivac++;
		}
		
		char *privremeni_pokazivac_napocetak_trenutne_rijeci; /* S obzirom da cemo se kretati kroz string trebace nam pokazivac 
		koji cemo korisiti da bi se oznacili pocetak za svaku sljedecu rijec u odnosu na trenutnu referentnu */
		
		while ( *privremeni_pokazivac_napocetak_trenutne_rijeci != '\0' )
		{
			char temp_klizeci_pokazivac_kroz_rijec = privremeni_pokazivac_napocetak_trenutne_rijeci;
			char temp_kontrolni_pokazivac_kroz_rijec = privremeni_pokazivac_napocetak_trenutne_rijeci;
			/* Bas kao sto smo definirali lokalne pokazivace pri odredjivadju duzina rijeci, tako i ovdje definiramo dva nova */
			
			poredjena_duzina = 0;
			
			/* Petljom ispod trazicemo duzinu rijeci koju poredim sa duzinom referentne rijeci */
			while ( slovo ( temp_klizeci_pokazivac_kroz_rijec ) )
			{
				temp_klizeci_pokazivac_kroz_rijec++;
				poredjena_duzina++;
			}
			
			/* Dalje uvodimo kontrolnu varijablu koja ce nam koristiti da utvrdimo da li je rijec koju poredimo sa referentnom rijec
			jednake duzine kao i referentna rijec, jer ako nije, nema smisla dalje provjeravati jer smo utvrdili da se referentna rijec
			i trenutno razlikuju i ako trenutna rijec nije iste duzine nema ih smisla porediti */
			
			if ( poredjena_duzina == duzina_trenutne_rijeci )
			{
				int kontrolna_varijabla = 1; 
				
				for ( i = 0; i < poredjena_duzina; i++ )
				{
					if ( Veliko_slovo ((*temp_kontrolni_pokazivac_kroz_rijec + i)) != Veliko_slovo ((kontrolni_klizac_koji_stoji_na_pocetku_stringa + i)))
					kontrolna_varijabla = 0;
				}
				
					if ( kontrolna_varijabla )
					broj_ponavljanja_rijeci++;
				
				 /* S obzirom na uvijete u if-ovima i jednakost duzina ako su ispunjeni svi uvijeti utvrdjeno je da su referentna i trenutna rijec
				 jednake pa mozemo povecati varijablu koja se odnosi na broj ponavljanja iste */
			}
			
			/* Dio ispod se odnosi na odredjivanje rijeci koja se najcesce ponavlja pa cemo to uraditi kako je naveceno u pelji ispod */
			
			if ( broj_ponavljanja_rijeci > broj_ponavljanja_najcesce_rijeci )
			
			{
				broj_ponavljanja_najcesce_rijeci = broj_ponavljanja_rijeci;
				trenutna_adresa_rijeci = temp_kontrolni_pokazivac_kroz_rijec;
				najveca_duzina_rijeci = duzina_trenutne_rijeci;
			}
			
			
			temp_klizeci_pokazivac_kroz_rijec = temp_kontrolni_pokazivac_kroz_rijec;
			/* Ostatak if-a iznad u stvari pamti kraj trenutne i referentne rijeci(najduze rijeci) */
			
			while ( !slovo ( *temp_klizeci_pokazivac_kroz_rijec ) && *temp_klizeci_pokazivac_kroz_rijec != '\0' )
			temp_klizeci_pokazivac_kroz_rijec++;
		}
		
	}
	
	
	return s;
}

int main() {
	
	char t[]=" Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";
	printf("'%s'", izbaci_najcescu(t));
	
	return 0;
}
