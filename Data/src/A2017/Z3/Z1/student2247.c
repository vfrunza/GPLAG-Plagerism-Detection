#include <stdio.h>

int dva_od_tri (int niz1[100],int duzina1, int niz2[100],int duzina2, int niz3[100], int duzina3){
int ima=0, novi_niz[100]={0}, i, j, k,l, brojac=0;
/*provjeravamo da li se element pojavljuje u prvom i u drugom a ne pojavljuje u trecem nizu*/
for (i=0; i<duzina1; i++)
{
	for (j=0; j<duzina2; j++)
	{
		if (niz1[i]==niz2[j])
		{
			ima=0;
			for (k=0; k<duzina3; k++)
			{
				if (niz1[i]==niz3[k]) ima=1;
			}
			if (ima==0){
				for (l=0; l<brojac; l++)
				{
					if (niz1[i]==novi_niz[l]) ima=1;
				}
				if (ima==0)000
				{
					
				novi_niz[brojac]=niz1[i];
				brojac++;
				}
			}
		}
	}
}
/*provjeravmo da li se element nalazi u prvom i u trecem, a ne nalazi u drugom*/

for (i=0; i<duzina1; i++)
{
	for (k=0; k<duzina3; k++)
	{
		if (niz1[i]==niz3[k])
		{
			ima=0;
			for (j=0; j<duzina2; j++)
			{
				if (niz1[i]==niz2[j]) ima=1;
			}
			if (ima==0)
			{
				for (l=0; l<brojac; l++)
				{
					if (niz1[i]==novi_niz[l]) ima=1;
				}
				if (ima==0){
					novi_niz[brojac]=niz1[i];
					brojac++;
				}
				
			}
			
		}
	}
}

/*provjeravamo da li se element nalazi u drugom i u trecem, a ne nalazi u prvom*/

for (j=0; j<duzina2; j++)
{
	for (k=0; k<duzina3; k++)
	{
		if (niz2[j]==niz3[k])
		{
			ima=0;
			for (i=0; i<duzina1; i++)
			{
				if (niz2[j]==niz1[i])ima=1;
			}
			if (ima==0)
			{
				for (l=0; l<brojac; l++)
				{
					if (niz2[j]==novi_niz[l]) ima=1;
				}
				if (ima==0)
				{
					novi_niz[brojac]=niz2[j];
					brojac++;
				}
			}
		}
	}
}


return brojac;
	
	}
	
	
	int main (void){
		
     int niz1[100], niz2[100], niz3[100], i, j, k, duzina1, duzina2, duzina3;
	do {
		printf ("Unesite duzinu prvog niza: ");
		scanf ("%d", &duzina1);
		
	} while (duzina1<1 || duzina1>100);
	
	printf ("Unesite elemente prvog niza: ");
	for (i=0; i<duzina1; i++){
		scanf ("%d", &niz1[i]);
	}
	
	do {
		printf ("Unesite duzinu drugog niza: ");
		scanf ("%d", &duzina2);
		
	} while (duzina2<1 || duzina2>100);
	
	printf ("Unesite elemente drugog niza: ");
	for (j=0; j<duzina2; j++){
		scanf ("%d", &niz2[j]);
	}
	
	do { 
		printf ("Unesite duzinu treceg niza: ");
		scanf ("%d", &duzina3);
		
	} while (duzina3<1 || duzina3>100);
	
	printf ("Unesite elemente treceg niza: ");
	for (k=0; k<duzina3; k++){
		scanf ("%d", &niz3[k]);
	}
	printf("%d",dva_od_tri(niz1,duzina1,niz2,duzina2,niz3,duzina3));
	return 0;
}



