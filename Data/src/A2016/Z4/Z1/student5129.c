#include <stdio.h>

/* Ideas:
String array 100:30, Uporediti svako slovo dva clana arraya sa +-32 da vidimo ako su rijeci iste ali im je kapitalizacija slova razlicita.
Array [100] za svaku rijec u stringu, pregledamo od pocetka svaku rijec i provjeravamo ako je ista kao prosle, ako jeste, 
inkrementuje se vrijednost koja je na mjestu gdje se ta rijec prvi put spominje u stringu.
Npr: Ako se rijec javlja na trecem mjestu unesenog stringa, pa onda ponovo na petom, array[2] ce biti 2, a array[4] ce biti nula, jer se prije vec javlja. 

Ovo cemo kasnije koristiti u slucaju da se dvije rijeci isti broj puta ponavljaju.
Na kraju vidimo koja je vrijednost ovog drugog niza najveca, i onda rijec na tom mjestu izbacimo, kao i svaku njenu verziju u originalnom stringu.

AUTOTEST TRAZI SAMO JEDNU VARIJABLU KAO UNOS, SAN JE MRTAV
*/

char* izbaci_najcescu(char* s){
	char* pPrviClan = s;
	if(*s=='\0'){
		return 0;
	}
	/*
	while((*s>=65 && *s<=90) || (*s>=97 && *s<=122)){
		if(*s)
	}
	
	U ovom trenutku sam saznao da imamo test iz LAG-a sljedece sedmice
	*/
	return pPrviClan;
}


int main() {
	char unos[100];
	char rijeci[20][20];
	
	
	printf(" ");
	return 0;
}
