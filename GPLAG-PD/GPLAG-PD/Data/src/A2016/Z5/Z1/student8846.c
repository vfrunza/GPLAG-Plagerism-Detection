#include <stdio.h>
#include <math.h>
#define eps 0.000001

struct Student
{
char ime[20], prezime[20];
int ocjene[50];
int br_ocjena;
};

double daj_prosjek(int *niz,int velicina)
{
	double suma=0;
	int nova_vel=velicina;
	if(velicina==0)
	{

		return 5.0;
	}

	while(velicina!=0)
	{
		if(*niz<5.00001)
		{
			return 5.0;
		}
		else 
		{
			suma+=*niz;
			niz++;
			velicina--;
		}
	}
	return suma/nova_vel;
}
struct Student daj_najgoreg(struct Student *studenti,int velicina)
{
	struct Student vjecni_student;
	double prosjek =10;
	while(velicina!=0)
	{
		if(daj_prosjek((*studenti).ocjene,(*studenti).br_ocjena)<prosjek)
		{
			prosjek=daj_prosjek((*studenti).ocjene,(*studenti).br_ocjena);
			vjecni_student=*studenti;
		}
		velicina--;
		studenti++;
	}
	return vjecni_student;
}

int leksikografkso_poredjenje(char* s1, char* s2) {
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
void daj_najbolja_tri(struct Student *studenti, int velicina, struct Student *najbolji)
{
	int nova_vel=velicina;
	struct Student *pok=studenti;
	double prosjek1,prosjek2,prosjek3,prosjek4;
	*najbolji=daj_najgoreg(studenti,velicina);
	*(najbolji+1)=*najbolji;
	*(najbolji+2)=*najbolji;
	while(velicina!=0)
	{
	prosjek1=daj_prosjek((*najbolji).ocjene,(*najbolji).br_ocjena); 
	prosjek2=daj_prosjek((*(najbolji+1)).ocjene,(*(najbolji+1)).br_ocjena); 
	prosjek3=daj_prosjek((*(najbolji+2)).ocjene,(*(najbolji+2)).br_ocjena);
	prosjek4=daj_prosjek((*studenti).ocjene,(*studenti).br_ocjena);
		if(prosjek4>prosjek1 || fabs(prosjek4-prosjek1)<eps )
		{
			if(fabs(prosjek4-prosjek1)<eps)
			{
				if(leksikografkso_poredjenje((*najbolji).prezime,(*studenti).prezime)==-1)
				{
					*(najbolji+2)=*(najbolji+1);
					*(najbolji+1)=*studenti;
				}
				else if(leksikografkso_poredjenje((*najbolji).prezime,(*studenti).prezime)==1)
				{
					*(najbolji+2)=*(najbolji+1);
					*(najbolji+1)=*najbolji;
					*najbolji=*studenti;
				}
				else if(leksikografkso_poredjenje((*najbolji).prezime,(*studenti).prezime)==0)
				{
					if(leksikografkso_poredjenje((*najbolji).ime,(*studenti).ime)==-1)
					{
						*(najbolji+2)=*(najbolji+1);
						*(najbolji+1)=*studenti;
					}
					else if(leksikografkso_poredjenje((*najbolji).ime,(*studenti).ime)==1)
					{
						*(najbolji+2)=*(najbolji+1);
					*(najbolji+1)=*najbolji;
					*najbolji=*studenti;
					}
				}
			}
			else
			{
			*(najbolji+2)=*(najbolji+1);
			*(najbolji+1)=*najbolji;
			*najbolji=*studenti;
			}
		}
		else if(prosjek4>prosjek2 || fabs(prosjek4-prosjek2)<eps)
		{
			if(fabs(prosjek4-prosjek2)<eps)
			{
				if(leksikografkso_poredjenje((*(najbolji+1)).prezime,(*studenti).prezime)==-1)
				{
					*(najbolji+2)=*studenti;

				}
				else if(leksikografkso_poredjenje((*(najbolji+1)).prezime,(*studenti).prezime)==1)
				{
					*(najbolji+2)=*(najbolji+1);
					*(najbolji+1)=*studenti;
				}
				else if(leksikografkso_poredjenje((*(najbolji+1)).prezime,(*studenti).prezime)==0)
				{
					if(leksikografkso_poredjenje((*(najbolji+1)).ime,(*studenti).ime)==-1)
					{
						*(najbolji+2)=*studenti;
					}
					else if(leksikografkso_poredjenje((*najbolji).ime,(*studenti).ime)==1)
					{
						*(najbolji+2)=*(najbolji+1);
						*(najbolji+1)=*studenti;
					}
				}
			}
			else
			{
			*(najbolji+2)=*(najbolji+1);
			*(najbolji+1)=*studenti;
			}
		}
		else if(prosjek4>prosjek3 || fabs(prosjek4-prosjek3)<eps)
		{
			if(fabs(prosjek4-prosjek3)<eps)
			{
				if(leksikografkso_poredjenje((*(najbolji+1)).prezime,(*studenti).prezime)==1)
				{
					*(najbolji+2)=*studenti;
				}
				else if(leksikografkso_poredjenje((*(najbolji+1)).prezime,(*studenti).prezime)==0)
				{
				 if(leksikografkso_poredjenje((*najbolji).ime,(*studenti).ime)==1)
					{
						*(najbolji+2)=*studenti;
					}
				}
			}
			else
			*(najbolji+2)=*studenti;
		}
		velicina--;
		studenti++;
	}

	
}
int je_li_broj_u_nizu(int broj,int *niz, int duzina)
{
	while(duzina!=0)
	{
		if(*niz==broj) return 1;
		niz++;
		duzina--;
	}
	return 0;
}

int genijalci(struct Student *studenti,int velicina,double prosjek)
{
	struct	Student novi_niz[200],*pokazivac=studenti,najbolji[3];
	int *pomocni_pok;
	int i=0,j=0, nova_duzina=velicina, niz_indeksa[200],indeks_prosjeka[3];
	for(i=0;i<velicina;i++)
	{
		novi_niz[i]=*studenti;
		studenti++;
	}
	for(i=0;i<velicina;i++)
	{
		if(daj_prosjek(novi_niz[i].ocjene,novi_niz[i].br_ocjena)<prosjek)
		{
			nova_duzina--;
			niz_indeksa[j]=i;
			j++;
		}
	}
	studenti=pokazivac;
	for(i=0;i<velicina;i++)
	{
		if(je_li_broj_u_nizu(i,niz_indeksa,j)==1)
		{
			continue;
		}
		else
		{
			*studenti=novi_niz[i];
			studenti++;
		}
	}
	studenti=pokazivac;
	if(nova_duzina>=3)
	{
		daj_najbolja_tri(studenti,nova_duzina,najbolji);
		for(i=0;i<3;i++)
		{
			printf ("%s %s\n", najbolji[i].prezime, najbolji[i].ime);
		}
	}
	else if(nova_duzina==2)
	{
		if(daj_prosjek(studenti[0].ocjene,studenti[0].br_ocjena)>=daj_prosjek(studenti[1].ocjene,studenti[1].br_ocjena))
		{
			printf("%s %s\n%s %s\n",studenti[0].prezime, studenti[0].ime,studenti[1].prezime, studenti[1].ime);
		}
		else 
			printf("%s %s\n%s %s\n",studenti[1].prezime, studenti[1].ime,studenti[0].prezime, studenti[0].ime);
	}
	else if(nova_duzina==1)
	{
			printf("%s %s\n",studenti[0].prezime, studenti[0].ime);
	}
	
	return nova_duzina;
	
	
}
int main()
{
     struct Student studenti[6] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
       genijalci(studenti, 6, 6.5);
}
