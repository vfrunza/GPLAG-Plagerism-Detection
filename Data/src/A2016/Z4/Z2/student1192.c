#include <stdio.h>
#include <string.h>

char* kodiraj(char * text, char* prazan)
{
	int i, max=0, br, pozicija=0;
	int nizbr[95]={0};
	char * reset=text, *p, *reset2=prazan;
	
	/*Trazenje maksimalnog broja ponavljanja nekog slova*/
	while(*text!='\0')
	{ br=0;
		p=text;
		while(*p!='\0')
		{
			if(*text==*p)
			br++;
			
			p++;
		}
		if(br>max)
		max=br;
		text++;
	}
	/*u niz nizbr upisujemo brojace slova iz teksta po asci codu i oduzimamo 32 jer znakovi su u intervalu od 32 do 126*/
	
	text=reset;
	while(*text!='\0')
	{
		nizbr[*text-32]++;
		text++;
	}
	
	/*u niz prazan upisujemo sifrarnik i dodajemo 32 ako bi dobili asci vrijednosti*/
	text=reset;
	while (max>=0){
		for(i=0;i<95; i++)
		{
			if(nizbr[i]==max)
			{
				*prazan= i+32;
				prazan++;
				
			}
		}
		max--;
	}
	
	/*Šifriramo tekst*/
	
	text=reset;
	while(*text!='\0'){
		pozicija=0;
		prazan=reset2;
		while(*prazan!='\0'){
			pozicija++;
			if(*text==*prazan)
			{
				*text= 126- pozicija+1;
				break;
			}
		prazan++;
			
		}
		text++;
	}
	
text=reset;
return text;	
}


char* dekodiraj(char*text, char*pomocni)
{ 
	int i;
	char* reset= text;
	for(i=0; i<strlen(text); i++)
	{
		*(text+i)=*(pomocni +126 - *(text+i));
	}
    
	text=reset;
	return text;
}

int main() {
	
	return 0;
}
