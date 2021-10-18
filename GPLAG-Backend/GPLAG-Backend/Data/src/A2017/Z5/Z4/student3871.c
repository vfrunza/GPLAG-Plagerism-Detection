#include <stdio.h>
struct Prodavnica
{
 char naziv[100];
 int ID;
};
struct Prodavnica pr;
struct Artikal 
{
 char naziv[100];
 double cijena;
 int prodavnica;
};
struct Artikal ar;
int ucitaj_artikle(struct Artikal* ar,int kap)
{
 int ucitano;
 FILE* binarna=fopen("artikli.bin","wb");
 if(binarna==NULL)
 {
  printf("Otvaranje datoteke artikli.bin nije uspjelo");
  return 1;
 }
 while(kap<EOF)
 {
  ucitano=fwrite(ar,sizeof(struct Artikal),kap,binarna);
 }
 fclose(binarna);
 return ucitano;
}
int ucitaj_prodavnice(struct Prodavnica *pr);
int main() {
/*	FILE* tekstualna;
	FILE* binarna=fopen("artikli.bin","wb");
	
	if(tekstualna==NULL)
	{
	 printf("Otvaranje datoteke prodavnice.txt nije uspjelo");
	 return 1;
	}
	if(binarna==NULL)
	{
	 printf("Otvaranje datoteke artikli.bin nije uspjelo");
	 return 2;
	}
	*/

	return 0;
	
}
