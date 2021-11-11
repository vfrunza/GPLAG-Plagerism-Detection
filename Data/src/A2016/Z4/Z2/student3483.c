#include <stdio.h>

/* Unos teksta */
void unesi(char niz[], int dim){
	int i = 0;
	char znak = getchar();
	if(znak == '\n')
		znak = getchar();
	while(i<dim-1 && znak != '\n'){
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

char* kodiraj (char* a, char* b){
	int brojac, i, postoji, max, j, tempint;
	char znak[96], broj_znakova[96], temp;
	char *pokaz = a;
	/* Za prazan string */
	temp = ' ';
	if (a[0] == '\0'){
		for(i = 0; i < 95; i++){
			b[i] = temp;
			temp++;
		}
		return 0;
	}
	/* Za neprazan string */
	znak[0] = a[0];
	broj_znakova[0] = 1;
	brojac = 1;
	a++;
	/* Izdvajanje i brojanje razlicitih znakova iz stringa */
	while(*a != '\0'){
		postoji = 0;
		for (i = 0; i < brojac; i++){
			if(*a == znak[i]){
				broj_znakova[i]++;
				postoji = 1;
			}	
		}
		if (postoji == 0){
			znak[brojac] = *a;
			broj_znakova[brojac] = 1;
			brojac++;
		}
		a++;
	}
	/* Redanje znakova po ucestalosti ponavljanja */
	znak[brojac] = '\0';
	for(i = 0; i < brojac; i++){
		max = broj_znakova[i];
		for(j = i+1; j < brojac; j++){
			if(broj_znakova[j] > max){
				max = broj_znakova[j];
				temp = znak[i];
				znak[i] = znak[j];
				znak[j] = temp;
				tempint = broj_znakova[i];
				broj_znakova[i] = broj_znakova[j];
				broj_znakova[j] = tempint;
			}
		}
	}
	/* Redanje znakova koji se ponavljaju isti broj puta po ASCII vrijednosti */
	for(i = 0; i < brojac-1; i++)
		if(broj_znakova[i] == broj_znakova[i+1])
			if(znak[i+1] < znak[i]){
				temp = znak[i];
				znak[i] = znak[i+1];
				znak[i+1] = temp;
				i = 0;
			}
	/* Upisivanje znakova u sifrarnik */
	i = 0;
	while(i < brojac){
		b[i] = znak[i];
		i++;
	}
	i = brojac;
	temp = ' ';
	while(i < 95){
		postoji = 0;
		for(j = 0; j < brojac; j++){
			if(temp == znak[j]){
				temp++;
				postoji = 1;
			}
		}
		if(postoji == 0){
		b[i] = temp;
		temp++;
		i++;
		}
	}
	/* Kodiranje znakova u pocetnom stringu */
	a = pokaz;
	while(*a != '\0'){
		for(i = 0; i < 95; i++)
			if(*a == b[i]){
				*a = ('~' - i);
				a++;
				continue;
			}
	}
	return pokaz;
}

char* dekodiraj(char* a, char* b){
	int i;
	char temp;
	char* pokaz = a;
	while(*a != '\0'){
		temp = '~' - (*a);
		for (i = 0; i < 95; i++){
			if(temp == i){
				*a = b[i];
			}
		}
		a++;
	}
	return pokaz;
}

int main() {
	char tekst[1000], sifra[96], x;
	printf("Unesi tekst: ");
	unesi(tekst, 1000);
	kodiraj(tekst, sifra);
	dekodiraj(tekst, sifra);
	printf("%s", tekst);
	return 0;
}
