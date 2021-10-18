#include <stdio.h>
//const double epsilon 1e-10;

struct Student 
{
	char ime[20]; 
	char prezime[20];
	int ocjene[50];
	int br_ocjena;
};

void unesi (char niz[], int velicina)
{
	char znak=getchar();
	if(znak=='\n')
	znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

struct Student unos_osobe()
{
	struct Student s;
	int i;
	unesi(s.ime, 20);
	unesi(s.prezime, 20);
	for(i=0; i<50; i++)
		scanf("%d", &s.ocjene[i]);
	scanf("%d", &s.br_ocjena);
	return s;
}

void ispis_osobe (struct Student niz[], int vel)
{
	int i;
	for(i=0; i<vel; i++)
	{
		printf("\n%s %s", niz[i].ime, niz[i].prezime);
	}
}

int genijalci (struct Student niz[], int vel, double prosjek)
{
	struct Student pomocni[3];
	const double epsilon = 1e-10;
	char pomocni_ime[20];
	char pomocni_prezime[20];
	int i, j, k, pomocna, m=0, n, a, b;
	double pom_prosjek, suma, l, niz_prosjek[50], max1=-9999, max2=-9999, max3=-9999;
	for(i=0; i<vel; i++)
	{
		pom_prosjek=0;
		suma=0;
		pomocna=0;
		for(j=0; j<niz[i].br_ocjena;j++)
		{
			if(niz[i].ocjene[j]==5)
			{
				pom_prosjek=5.0;
				pomocna=1;
				break;
			}
			else if(niz[i].br_ocjena==0)
			{
				pom_prosjek=5.0;
				pomocna=1;
				break;
			}
			else 
			{
				suma+=niz[i].ocjene[j];
				pomocna=0;
			}
		}
		if(pomocna==0)
		{
			pom_prosjek=suma/niz[i].br_ocjena;
		}
		
		//printf("%.1f %f ", pom_prosjek, prosjek);
		//l=pom_prosjek-prosjek;
		//printf("%.2f ", l);
		if(pom_prosjek<prosjek)
			{
			for(k=i; k<vel-1; k++)
			{
				niz[k]=niz[k+1];
			}
			vel--;
			i--;
			}
		
		if(pom_prosjek>=prosjek)
		{
			while(m<vel)
			{
				niz_prosjek[m]=pom_prosjek;
				m++;
				break;
			}
		}
	}
		
		
		for(a=0; a<m; a++)
		{
			if(niz_prosjek[a]>max1)
			{
				max1=niz_prosjek[a];
			}
		}
		
		b=0;
		for(a=0; a<m; a++)
		{
			if(niz_prosjek[a]<max1)
			{
				while(b<m-1)
				{
					niz_prosjek[b]=niz_prosjek[a];
					b++;
					break;
				}
			}
		}
		
		for(a=0; a<m-1; a++)
		{
			if(niz_prosjek[a]>max2)
			{
				max2=niz_prosjek[a];
			}
		}
		
		b=0;
		for(a=0; a<m-1; a++)
		{
			if(niz_prosjek[a]<max2)
			{
				while(b<m-2)
				{
					niz_prosjek[b]=niz_prosjek[a];
					b++;
					break;
				}
			}
		}
		
		for(a=0; a<m-2; a++)
		{
			if(niz_prosjek[a]>max3)
			{
				max3=niz_prosjek[a];
			}
		}
		
		//printf("%.2f %.2f %.2f", max1, max2, max3);
		/*for(n=0; n<m; n++)
		printf("%.2f ", niz_prosjek[n]);*/
		
		for(i=0; i<vel; i++)
		{
			double suma1=0, prosjek1=0;
			int p;
			for(p=0; p<niz[i].br_ocjena; p++)
			{
				suma1+=niz[i].ocjene[p];
			}
			prosjek1=suma1/niz[i].br_ocjena;
			//printf("%.2f ", prosjek1);
			if(prosjek1==max1)
			{
				printf("%s %s\n", niz[i].prezime, niz[i].ime);
				pomocni[0]=niz[i];
				
			}
			
		}
		
		for(i=0; i<vel; i++)
		{
			double suma1=0, prosjek1=0;
			int p;
			for(p=0; p<niz[i].br_ocjena; p++)
			{
				suma1+=niz[i].ocjene[p];
			}
			prosjek1=suma1/niz[i].br_ocjena;
			if(prosjek1==max2)
			{
				printf("%s %s\n", niz[i].prezime, niz[i].ime);
				pomocni[1]=niz[i];
			}
		}
		
		for(i=0; i<vel; i++)
		{
			double suma1=0, prosjek1=0;
			int p;
			for(p=0; p<niz[i].br_ocjena; p++)
			{
				suma1+=niz[i].ocjene[p];
			}
			prosjek1=suma1/niz[i].br_ocjena;
			if(prosjek1==max3)
			{
				printf("%s %s", niz[i].prezime, niz[i].ime);
				pomocni[2]=niz[i];
			}
		}
		
	
		//printf("%d ", vel);
		
	return vel;
}

int main() 
{
	int i;

	/*struct Student studenti[2];
	for(i=0; i<2; i++)
	{
		studenti[i]=unos_osobe();
	}
	
	ispis_osobe(studenti, 2);*/
	return 0;
}












