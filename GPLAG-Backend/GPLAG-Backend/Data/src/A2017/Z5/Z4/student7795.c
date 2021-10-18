#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARTIKLI		"artikli.bin"
#define PRODAVNICE		"prodavnice.txt"
#define SIZE			100

/* structures */
struct Prodavnica {
	char naziv[SIZE];
	int ID;				
};

struct Artikal {
	char naziv[SIZE];
	double cijena;
	int prodavnica;		
};

/* functions to implement */
int ucitaj_artikle (struct Artikal *niz, int kap) {
	int i = 0;
	FILE* file = fopen(ARTIKLI, "rb");
	if(!file) return 0;
	i = fread(niz, sizeof(struct Artikal), kap, file);
	fclose(file);
	return i;
}

int ucitaj_prodavnice (struct Prodavnica *niz, int kap) {
	struct Prodavnica heap;
	char c;
	int i = 0, _pos = 0;
	
	FILE* file = fopen(PRODAVNICE, "rb");
	if(!file) return 0;
	
	while(i < kap) {
		/* start reading */
		_pos = 0;
		while((_pos < SIZE-1) && ((c = fgetc(file)) != ','))
			heap.naziv[_pos++] = c;
		heap.naziv[_pos] = '\0';
		
		/* in case of overflow */
		if(_pos+1 == SIZE) {
			c = getc(file);
			while((c != ',') && (c != EOF) && (c != '\n'))
				c = getc(file);
		} 
		
		if(fscanf(file, "%d\n", &heap.ID) == 1)
			niz[i++] = heap; 
		else break;
	}

	fclose(file);
	return i;
}


int izbaci_skupe (struct Prodavnica *p, int np, struct Artikal *a, int na) {
	double _midProd = 0.0, _average = 0.0;
	int _numProd = 0, _artNum = 0;
	int i = 0, j = 0;
	/* find average price of all products */
	for(i = 0; i < na; i++) {
		_midProd += a[i].cijena;
		_numProd++;
	}
	if(_numProd > 0)
		_midProd /= _numProd;
	
	/* find average product price in shop */
	for(i = 0; i < np; i++) {
		_artNum = 0;
		_average = 0.0;
		for(j = 0; j < na; j++) {
			if(p[i].ID == a[j].prodavnica) {
				_average += a[j].cijena;
				_artNum++;
			}
		}
		if(_artNum > 0)
			_average /= _artNum;
		if(_average > _midProd) {
			/* remove this one from stack */
			for(j = i; j < np-1; j++) 
				p[j] = p[j+1];
			np--;
			i--;
		}
	}
	
	return np;
}

int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke) {
	/* initial */
	FILE *file;
	int i, check = 0;
	
	/* can't read file */
	file = fopen(ime_datoteke, "wb");
	if(file == NULL)
		return 0;
		
	/* start writing in file, byte by byte */
	for(i = 0; i < n; i++) {
		check = fwrite(p[i].naziv, SIZE, 1, file);
		check += fwrite(&p[i].ID, sizeof(int), 1, file);
		if(check != 2) {
			fclose(file);
			return 0;
		}
	}
	fclose(file);
	return 1;
}

int main() {
	return 0;
}
