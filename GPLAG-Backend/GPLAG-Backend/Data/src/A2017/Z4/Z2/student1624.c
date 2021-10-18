#include <stdio.h>

/*Napisati funkciju provjeri_duzine koja prima neki string koji predstavlja rečenicu i niz cijelih brojeva.
Funkcija treba provjeriti da li niz predstavlja niz dužina riječi u rečenici, te vraća 1 ako je uslov ispunjen a 0 ako nije.
Riječ se definiše kao neprekinut niz velikih i malih slova tako da se npr. string "Auto-Stop" smatra za dvije riječi.

Primjer: ako string glasi:
Ovo je neki primjer teksta

Onda bi niz brojeva morao glasiti: 3, 2, 4, 7, 6 jer su to dužine riječi u ovoj rečenici.
*/
void unesi (char niz[], int velicina) {
	char znak = getchar ();
	if (znak == '\n') getchar ();
	int i=0;
	while (i<velicina-1 && znak != '\n') {
		niz [i] = znak;
		i++;
		znak=getchar ();
	}
	niz[i]='\0';
	
}


int provjeri_duzine (char *s, int nizbrojeva[], int vel){
	char* p;
	p=s;
	int brojac=0;
	int i=0;
	
	while(*p!='\0'){
		if(
			(p==s && ((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))) || (p!=s && (((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && ((*(p-1)<'A' || *(p-1)>'Z') || 
		(*(p-1)<'a' || *(p-1)>'z'))))
		
		){
			brojac=0;
			while ((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')){
				brojac++;
				p++;
			}
			if(brojac!=nizbrojeva[i]) return 0;
			i++;
		}
		if(*p!='\0') p++;
	}
	
	
	
	if(i!=vel) return 0;
	else return 1;
}


int main(){
	
	char tekst[100];
	int niz[100];
	int n,i;
	
	printf("Unesite string: ");
	unesi(tekst,100);
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	printf("Unesite niz brojeva: ");
	for(i=0;i<n;i++){
		scanf("%d",&niz[i]);
	}
	printf("%d",provjeri_duzine(tekst,niz,n));
	return 0;
	
}