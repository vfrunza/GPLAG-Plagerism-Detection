#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kompresuj(char *ime_ulaz, char *ime_izlaz) {
	char rijeci[1005][10], trenutna[10], najcesce[10][10], c;
	int histogram[1000]={0}, broj_razlicitih=0, i, j, k, max;
	FILE *ulaz=fopen(ime_ulaz, "r");
	if(!ulaz) exit(1);
	FILE *izlaz=fopen(ime_izlaz, "w");
	if(!izlaz) exit(1);
	/*Storat cemo rijeci u matricu 'rijeci'; idemo kroz dat. 'ulaz' dok ne naidjemo na slovo, onda storamo vrijednost te rijeci u 'trenutna', 
		pod uslovom da mora imati izmedju 2 i 9 slova. U histogramu cemo imati podatke za svaku rijec koliko se puta ponavlja*/
	c=fgetc(ulaz);
	while(!feof(ulaz)) {
		while(!feof(ulaz) && !((c>='A' && c<='Z') || (c>='a' && c<='z'))) {
			if(ferror(ulaz)) exit(1);
			c=fgetc(ulaz);
		}
		if(ferror(ulaz)) exit(1);
		
		for(i=0; i<9 && !feof(ulaz) && ((c>='A' && c<='Z') || (c>='a' && c<='z')); i++) {
			trenutna[i]=c;
			c=fgetc(ulaz);
			if(ferror(ulaz)) exit(1);
		}
		if(i>1 && !((c>='A' && c<='Z') || (c>='a' && c<='z'))) {
			trenutna[i]='\0';
			for(j=0; j<broj_razlicitih; j++) {
				if(strcmp(*(rijeci+j), trenutna)==0) {
					histogram[j]++;
					break;
				}
			}
			if(j==broj_razlicitih) {
				for(k=0; trenutna[k]!='\0'; k++) {
					rijeci[broj_razlicitih][k]=trenutna[k];
				}
				rijeci[broj_razlicitih][k]=trenutna[k];
				histogram[broj_razlicitih]++;
				broj_razlicitih++;
			}
		}
		
		else while(!feof(ulaz) && ((c>='A' && c<='Z') || (c>='a' && c<='z'))) {
			c=fgetc(ulaz);
			if(ferror(ulaz)) exit(1);
		}
	}
	/*Trazimo najcescu rijec i storamo njenu vrijednost u red 'najcesce', stavljamo njen histogram na -1 da je ne bismo ponovo nasli
		i trazimo sljedecu, tako max 10 puta ili ako je broj rijeci manji od 10 onda to tog broja*/
	for(i=0; i<10 && i<broj_razlicitih; i++) {
		max=0;
		for(j=0; j<broj_razlicitih; j++) {
			if(histogram[j]>histogram[max] || (histogram[j]==histogram[max] && strcmp(*(rijeci+j), *(rijeci+max))<0)) max=j;
		}
		for(j=0; rijeci[max][j]; j++) {
			najcesce[i][j]=rijeci[max][j];
		}
		najcesce[i][j]=rijeci[max][j];
		histogram[max]=-1;
	}
	/*Ispisujemo najcesce rijeci u izlaznu, ako ih je manje od 10 ide dodatni \n na kraju*/
	for(i=0; i<broj_razlicitih && i<10; i++) {
		fprintf(izlaz, "%s\n", najcesce[i]);
		if(ferror(izlaz)) exit(1);
	}
	if(broj_razlicitih<10) fprintf(izlaz, "\n");
	if(ferror(izlaz)) exit(1);
	/*Vracamo kursor na pocetak i idemo redom kroz dat. Prepisujemo u izlaznu sve dok ne naidjemo na rijec, nadjemo tu rijac,
		onda ako ta rijec ima izmedju 2 i 9 slova uporedjujemo je sa najcescim, ako je jednaka ispisujemo odgovarajuci ascii znak*/
	rewind(ulaz);
	c=fgetc(ulaz);
	while(!feof(ulaz)) {
		while(!((c>='A' && c<='Z') || (c>='a' && c<='z'))) {
			if(ferror(ulaz)) exit(1);
			if(feof(ulaz)) break;
			fprintf(izlaz, "%c", c);
			if(ferror(izlaz)) exit(1);
			c=fgetc(ulaz);
		}
		for(i=0; !feof(ulaz) && i<9 &&  ((c>='A' && c<='Z') || (c>='a' && c<='z')); i++) {
			trenutna[i]=c;
			if(ferror(ulaz)) exit(1);
			c=fgetc(ulaz);
		}
		trenutna[i]='\0';
		if((i>1 && i<9) || (i==9 && !((c>='A' && c<='Z') || (c>='a' && c<='z')))) {
			for(j=0; j<broj_razlicitih && j<10; j++) {
				if(strcmp(trenutna, najcesce[j])==0) {
					fprintf(izlaz, "%c", 20+j);
					if(ferror(izlaz)) exit(1);
					break;
				}
			}
			if(j==broj_razlicitih || j==10) {
				fprintf(izlaz, "%s", trenutna);
				if(ferror(izlaz)) exit(1);
			}
		}
		else if(i==1) {
			fprintf(izlaz, "%s", trenutna);
			if(ferror(izlaz)) exit(1);
		}
		else {
			fprintf(izlaz, "%s", trenutna);
			if(ferror(izlaz)) exit(1);
			while((c>='A' && c<='Z') || (c>='a' && c<='z')) {
				if(feof(ulaz)) break;
				fprintf(izlaz, "%c", c);
				if(ferror(izlaz)) exit(1);
				c=fgetc(ulaz);
				if(ferror(ulaz)) exit(1);
			}
		}
	}
	fclose(ulaz); fclose(izlaz);
	printf("Datoteka kompresovana.\n");
}

void dekompresuj(char *ime_ulaz, char *ime_izlaz) {
	char najcesce[12][12], c;
	int i, j;
	FILE *ulaz=fopen(ime_ulaz, "r");
	if(!ulaz) exit(1);
	FILE *izlaz=fopen(ime_izlaz, "w");
	if(!izlaz) exit(1);
	/*Ucitamo najcesce rijeci u matricu 'najcesce'*/
	c=fgetc(ulaz);
	if(ferror(ulaz)) exit(1);
	for(i=0; i<10; i++) {
		if(c=='\n') {
			c=fgetc(ulaz);
			if(ferror(ulaz)) exit(1);
			break;
		}
		for(j=0; c!='\n'; j++) {
			najcesce[i][j]=c;
			c=fgetc(ulaz);
			if(ferror(ulaz)) exit(1);
		}
		najcesce[i][j]='\0';
		c=fgetc(ulaz);
		if(ferror(ulaz)) exit(1);
	}
	/*Idemo redom kroz "kompresovanu" dat. i prepisujemo u izlaznu, ako nadjemo na odg. ascii znak umjesto njega ispisemo 
		jednu od najcescih rijeci*/
	while(!feof(ulaz)) {
		if(c>=20 && c<=29) {
			fprintf(izlaz, "%s", najcesce[c-20]);
			if(ferror(izlaz)) exit(1);
		}
		else {
			fprintf(izlaz, "%c", c);
			if(ferror(izlaz)) exit(1);
		}
		c=fgetc(ulaz);
		if(ferror(ulaz)) exit(1);
	}
	fclose(ulaz); fclose(izlaz);
	printf("Datoteka dekompresovana.\n");
}

void unesi(char *s) {
	/*Funkcija za unos stringa*/
	int i=0; char z=getchar(); 
	if(z=='\n') z=getchar();
	while(z!='\n' && i<1000) {
		*s=z;
		s++;
		z=getchar();
	}
	*s='\0';
}

int main() {
	int unos;
	char ulaz[1005], izlaz[1005];
	do {
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &unos);
		if(unos==1) {
			printf("Unesite ime ulazne datoteke: ");
			unesi(ulaz);
			printf("Unesite ime izlazne datoteke: ");
			unesi(izlaz);
			kompresuj(ulaz, izlaz);
		}
		else if(unos==2) {
			printf("Unesite ime ulazne datoteke: ");
			unesi(ulaz);
			printf("Unesite ime izlazne datoteke: ");
			unesi(izlaz);
			dekompresuj(ulaz, izlaz);
		}
	} while(unos);
	return 0;
}
