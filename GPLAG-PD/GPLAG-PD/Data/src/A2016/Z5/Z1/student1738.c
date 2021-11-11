#include <stdio.h>
#include <string.h>

struct Student
{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
int uporedi(char* s1, char* s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 < *s2) return -1;
		if (*s1 > *s2) return 1;
		s1++;
		s2++;
	}
	if (*s1 != '\0') return 1; 
	if (*s2 != '\0') return -1;
	return 0;                 
}
double pros (struct Student n)
{
	int zboc=0,i;
	double pr;

	if (n.br_ocjena==0)
	{
		return 5;
	}

	for (i=0;i<n.br_ocjena;i++)
	{
		if (n.ocjene[i]==5)
		{
			return 5;
		}

	}

	for (i=0;i<n.br_ocjena;i++)
	{
		zboc+=n.ocjene[i];
	}
	pr=(double)zboc/(double)n.br_ocjena;
	return pr;
}
void ispis (struct Student niz[],int v)
{
	int i;
	for (i=0;i<v;i++)
	{
		printf ("\nProsjek za %s %s je %f." , niz[i].ime,niz[i].prezime,pros(niz[i]));
	}
}

int genijalci (struct Student niz[],int v,double prosjek)
{
	struct Student nbt;
	struct Student nit[250];
	char t[35],ime[35];
	int pom=0,i,j,ret=0;
	double prosjeci[100],nb,temm;

	for (i=0;i<v;i++)
	{
		nit[i]=niz[i];
	}

	for (i=0;i<v;i++)
	{
		prosjeci[i]=pros(nit[i]);
	}
	for (i=0;i<v;i++)
	{
		if (prosjeci[i]<prosjek)
		{
			pom++;
			continue;
		}
	}
	if (pom==v)
	{
		return 0;
	}
	for (i=0;i<v;i++)
	{
		if (prosjeci[i]<prosjek)
		{
			for (j=i;j<v-1;j++)
			{
				prosjeci[j]=prosjeci[j+1];
				nit[j]=nit[j+1];
				niz[j]=niz[j+1];
			}
			v--;
			i--;
		}
	}

	for (i=0;i<v-1;++i)
	{
		for (j=0;j<v-1-i;++j)
		{
			if (prosjeci[j+1]>prosjeci[j])
			{
				nbt=nit[j+1];
				nb=prosjeci[j+1];

				prosjeci[j+1]=prosjeci[j];
				nit[j+1]=nit[j];

				prosjeci[j]=nb;
				nit[j]=nbt;
			}
		}
	}


	for (i=0;i<v;i++)
	{
		for (i = 1; i < v; i++)
			{
		      for (j = 1; j < v; j++)
		      {
		         if (strcmp(nit[j - 1].prezime, nit[j].prezime) > 0)
		         {
		            strcpy(t, nit[j - 1].prezime);
		            strcpy(ime, nit[j - 1].ime);
		            temm=prosjeci[j-1];

		            strcpy(nit[j - 1].prezime, nit[j].prezime);
		            strcpy(nit[j - 1].ime, nit[j].ime);
		            prosjeci[j-1]=prosjeci[j];

		            strcpy(nit[j].prezime, t);
		            strcpy(nit[j].ime, ime);
		         	prosjeci[j]=temm;
		      }
		   }}

		   	for (i = 1; i < v; i++)
			{
		      for (j = 1; j < v; j++)
		      {
		         if (strcmp(nit[j - 1].ime, nit[j].ime) > 0)
		         {
		            strcpy(t, nit[j - 1].ime);
		            strcpy(ime, nit[j - 1].prezime);
		            temm=prosjeci[j-1];

		            strcpy(nit[j - 1].ime, nit[j].ime);
		            strcpy(nit[j - 1].prezime, nit[j].prezime);
		            prosjeci[j-1]=prosjeci[j];

		            strcpy(nit[j].ime, t);
		            strcpy(nit[j].prezime, ime);
		         	prosjeci[j]=temm;
		      }
		   }

		}
	}
	for (i=0;i<v-1;++i)
	{
		for (j=0;j<v-1-i;++j)
		{
			if (prosjeci[j+1]>prosjeci[j])
			{
				nbt=nit[j+1];
				nb=prosjeci[j+1];

				prosjeci[j+1]=prosjeci[j];
				nit[j+1]=nit[j];

				prosjeci[j]=nb;
				nit[j]=nbt;
			}
		}
	}
	
	
	if (v>=3)
	{
		for (i=0;i<3;i++)
		{
		printf ("\n%s %s" , nit[i].prezime,nit[i].ime);

		}
	}
	else
	{
		for (i=0;i<v;i++)
		{
		printf ("\n%s %s" , nit[i].prezime,nit[i].ime);

		}
	}
	ret=0;
	for (i=0;i<v;i++)
	{
		ret++;
	}

	return ret;
}



int main ()
{
	 
    
	return 0;
}
