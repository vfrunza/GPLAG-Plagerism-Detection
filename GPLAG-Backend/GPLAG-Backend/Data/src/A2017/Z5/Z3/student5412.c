#include <stdio.h>

struct Oblik 
{
	char naziv[20];
	int br_stranica;
	double stranice[300];
};
void dodaj_oblik (struct Oblik o);

//izbaci_duple -> iz datoteke

struct Oblik daj_najveci ()
{
	struct Oblik o;
	double obim = 0, max = 0;
	int i;
	for (i = 0; i < o.br_stranica; i++)
	{
		if (o.stranice[i] != o.stranice[i+1] && o.stranice[i+1] != o.stranice[o.br_stranica-i-1]) obim += o.stranice[i]; 
		else if (o.stranice[i] == o.stranice[i+1] && o.stranice[i+1] == o.stranice[o.br_stranica-i-1]) obim = o.br_stranica * o.stranice[i]; 
		else if (o.stranice[i] != o.stranice[i+1] && o.stranice[i+1]== o.stranice[o.br_stranica-i-1]) obim += (o.br_stranica / 2) * o.stranice[i]; 
		
		if (max < o.stranice[i]) max = o.stranice[i];
		
	}
	
	return o;
}


int main() {
	//printf("Zadaća 5, Zadatak 3");
	return 0;
}
