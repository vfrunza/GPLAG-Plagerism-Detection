#include <stdio.h>
#include <math.h>

void zaokruzi1 (float niz[], int velicina){
	int i;
	
	for (i=0; i<velicina; i++){
		niz[i]=round (niz[i]*10)/10;
		
	}
	return ;
	
}

void preslozi (float niz[], int velicina,  int k)
{
  int suma=0, pomm;
  int brojac1=0, brojac2=0,brojac3=0, i;
  float nizVecihOdK[100]={0}, nizManjihOdK[100]={0}, konacanNiz[100]={0};
  
	zaokruzi1(niz, velicina);
	
	for(i=0;i<velicina;i++)
	{
		suma=0;
		pomm=(int)fabs((niz[i]*10));
		
		while(pomm!=0)
		{
			suma += pomm%10;
			pomm/=10;
		}
		
		if(suma>=k)
		{
			nizVecihOdK[brojac1]=niz[i];
			brojac1++;
		}
		
		if(suma<k)
		{
			nizManjihOdK[brojac2]=niz[i];
			brojac2++;
		}
	}
	/* Stavljanje iz nizova u niz */
	for(i=0;i<brojac1;i++){
		konacanNiz[brojac3]=nizVecihOdK[i];
		brojac3++;
	}
	for(i=0;i<brojac2;i++){
		konacanNiz[brojac3] = nizManjihOdK[i];
		brojac3++;
	}
	for(i=0;i<brojac3;i++){
		niz[i]=konacanNiz[i];
	}
	
}
int main(void) {
	int velicina, i;
	float niz[100];
	int k;
	
	do {
		printf("Unesite velicinu niza: ");
		scanf ("%d", &velicina);
	} while (velicina<1 || velicina >100);
	
	printf ("Unesite clanove niza: ");
	for (i=0; i<velicina; i++)
		scanf ("%f", &niz[i]);
	
	
	zaokruzi1(niz, velicina);
	
	printf ("Nakon zaokruzivanja niz glasi: \n");
	for (i=0; i<velicina; i++)
		printf ("%g ", niz[i]);
	
	
	printf ("Unesite parametar k: ");
	scanf ("%d", &k);
	
	preslozi(niz, velicina, k);
	
	printf ("Nakon poziva funkcije preslozi niz glasi: \n");
	for (i=0; i<velicina; i++){
		printf ("%g ", niz[i]);
	}
	return 0;
}
