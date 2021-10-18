#include <stdio.h>
#include<string.h>
#include<stdlib.h>
FILE* ar;
FILE* prod;
struct Artikal {
char naziv[100];
double cijena;
int prodavnica;
};
struct Prodavnica {
char naziv[100];
int ID;
};
int ucitaj_artikle(struct Artikal *niz, int kapacitet)
{
int artikli;
ar=fopen("artikli.bin","rb");
//ukoliko dodje do greske pri otvaranju
if(ar==NULL) exit(1);
artikli=fread(niz,sizeof(struct Artikal),kapacitet,ar);
fclose(ar);
//vraca broj uspjesno ucitanih artikla
return artikli;
}
int ucitaj_prodavnice (struct Prodavnica *niz, int kap)
{
	int i=0,j=-1;
	prod=fopen("prodavnice.txt","r");
	
	if(prod==NULL) exit(1); //ukoliko dodje do greske pri otvaranju
	do{
		j=-1;
		do{
			
		if(j<99) j++;
		niz[i].naziv[j]=fgetc(prod);
		
	} while(niz[i].naziv[j]!=',' && niz[i].naziv[j]!=EOF);
	
	
	niz[i].naziv[j]='\0';
	if(fscanf(prod,"%d\n",&niz[i].ID)==0) break;
	i++;
	} while(feof(prod)!=1 && i<kap);
	fclose(prod);
	return i;
	}

int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke)
{
	ar=fopen(ime_datoteke,"wb");
	if(ar==NULL) return 0;
	fwrite(p,sizeof(struct Prodavnica),n,ar);
	if (ferror(ar)) return 0;
	fclose(ar);
	return 1;
	
}
int main() {

struct Artikal a[50];
int n = ucitaj_artikle(a, 50), i;
for (i = 0; i < n; ++i)
	printf ("%s (cijena: %g, prodavnica: %d)\n", a[i].naziv, a[i].cijena, a[i].prodavnica);


	return 0;
}
