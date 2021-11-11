#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001


struct Student {
    char ime[20], prezime [20];
    int ocjene[50];
    int br_ocjena;
};

/*funkcija za uporedjivanje stringova*/
int uporedi (char* s1, char* s2)
{
	while (s1!='\0' && s2!='\0')
	{
		if (*s1<*s2) return -1;
		if (*s1>*s2) return 1;
		s1++;
		s2++;
	}
	if (*s1!='\0') return 1;
	if (*s2!='\0') return -1;
	return 0;
}

/*Funkcija za racunanje prosjeka ocjena*/
double racunanje_prosjeka (struct Student student) {
	int j;
	double suma=0, prosjek_studenta=0;
	/*ako je broj ocjena jednak nuli*/
	if (student.br_ocjena==0)
	{
		prosjek_studenta=5.;
	}
		
	for (j=0; j<student.br_ocjena; j++)
	{
		/*ako postoji ocjena 5*/
		if (student.ocjene[j]==5)
		{	
			prosjek_studenta=5.0;
			break;
		}
		else
			suma+=student.ocjene[j];
	}
		if (prosjek_studenta!=5.)
			prosjek_studenta=suma/student.br_ocjena;
		
		return prosjek_studenta;
}

/*funkcija koja preslikava jednu strukturu u drugu*/
void izbacivanje (struct Student* novi, int vel)
{
	int i;
	for (i=0; i<vel; i++)
	{
		*(novi+i)=*(novi+i+1);
		/*printf("%s", novi[i].ime);*/
	}
}
/*odredjivanje najboljih studenata*/
void najbolji_studenti(struct Student* studenti, int vel, double prosjek)
{
	/*pronalazenje indeksa prva tri najbolja studenta (ako postoje)*/
	int i, index1=0, index2=0, index3=0;
	int n, k;
	int k1, k2, k3;
	/*Pronalazimo prvi sa najvecim prosjekom*/
	for (i=0; i<vel; i++)
	{
		if (racunanje_prosjeka(studenti[index1])<racunanje_prosjeka(studenti[i]))
			index1=i;
	}
	/*ako je broj studenata veci od 1 trazimo sljedeci najveci prosjek*/
	if (vel>1)
	{
		if (index1==index2)
			index2=index1+1;
		
		for(i=0; i<vel; i++)
		{
			if (i!=index1 && racunanje_prosjeka(studenti[index2])<racunanje_prosjeka(studenti[i]))
				index2=i;
		}
		
		/*ako je broj studenata tacno jednak 2, uporedjujemo prosjeke, te prezime i ime po potrebi i vrsimo ispis*/
		if (vel==2)
		{
			if(fabs(racunanje_prosjeka(studenti[index1])-racunanje_prosjeka(studenti[index2]))<EPSILON)
			{
				n=uporedi(studenti[index1].prezime, studenti[index2].prezime);
				if (n==-1)
				{
					printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
					printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
					return;
				}
				else if (n==1)
				{
					printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
					printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
					return;
				}
				else if (n==0)
				{
					k=uporedi(studenti[index1].ime, studenti[index2].ime);
				
					if(k==-1)
					{
						printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
						printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
						return;
					}
					else if (k==1)
					{
						printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
						printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
						return;
					}
					else 
					{
						printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
						printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
						return;
					}
				}
			}
			else 
			{
				printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
				printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
				return;
			}
		}
		/*...u protivnom trazimo i treci najveci prosjek*/
		else  
		{
			if (index1==index3 || index3==index2)
				index3=index2+1;
			
			for (i=0; i<vel; i++)
			{
				if (i!=index1 && i!=index2 && racunanje_prosjeka(studenti[index3])<racunanje_prosjeka(studenti[i]))
					index3=i;
			}
			
			/*ukoliko su svi prosjeci razliciti*/
			if(racunanje_prosjeka(studenti[index1])!=racunanje_prosjeka(studenti[index2]) && racunanje_prosjeka(studenti[index2])!=racunanje_prosjeka(studenti[index3]) && racunanje_prosjeka(studenti[index1])!=racunanje_prosjeka(studenti[index3]))
			{
				printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
				printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
				printf("%s %s\n", studenti[index3].prezime, studenti[index3].ime);
				return;
			}
			/*ukoliko su prvi i drugi prosjek jednaki, dok treci je manji od prva dva*/
			else if (racunanje_prosjeka(studenti[index1])==racunanje_prosjeka(studenti[index2]) && racunanje_prosjeka(studenti[index1])!=racunanje_prosjeka(studenti[index3]))
			{
				n=uporedi(studenti[index1].prezime, studenti[index2].prezime);
				if (n==-1)
				{
					printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
					printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
					printf("%s %s\n", studenti[index3].prezime, studenti[index3].ime);
					return;
				}
				else if (n==1)
				{
					printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
					printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
					printf("%s %s\n", studenti[index3].prezime, studenti[index3].ime);
					return;
				}
				else if (n==0)
				{
					k=uporedi(studenti[index1].ime, studenti[index2].ime);
				
					if(k==-1)
					{
						printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
						printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
						printf("%s %s\n", studenti[index3].prezime, studenti[index3].ime);
						return;
					}
					else if (k==1)
					{
						printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
						printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
						printf("%s %s\n", studenti[index3].prezime, studenti[index3].ime);
						return;
					}
					else 
					{
						printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
						printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
						printf("%s %s\n", studenti[index3].prezime, studenti[index3].ime);
						return;
					}
				}
			}
			/*ukoliko su svi prosjeci ocjena jednaki*/
			else
			{
				/*u zavisnosti od povratne vrijednosti za k1,k2,k3 vrsiti ce se razliciti ispisi*/
				k1=uporedi(studenti[index1].prezime, studenti[index2].prezime);
				k2=uporedi(studenti[index1].prezime, studenti[index3].prezime);
				k3=uporedi(studenti[index2].prezime, studenti[index3].prezime);
				
				if (k1!=0 && k2!=0 && k3!=0)
				{
					if (k1==-1 && k2==-1 && k3==-1)
					{
						printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
						printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
						printf("%s %s\n", studenti[index3].prezime, studenti[index3].ime);
						return;
					}
					else if (k1==-1 && k2==-1)
					{
						printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
						printf("%s %s\n", studenti[index3].prezime, studenti[index3].ime);
						printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
						return;
					}
					else if (k1==1 && k2==-1 && k3==-1)
					{
						printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
						printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
						printf("%s %s\n", studenti[index3].prezime, studenti[index3].ime);
						return;
					}
					else if (k1==-1 && k2==1 && k3==1)
					{
						printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
						printf("%s %s\n", studenti[index3].prezime, studenti[index3].ime);
						printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
						return;
					}
					else if (k1==1 && k2==1 && k3==-1)
					{
						printf("%s %s\n", studenti[index3].prezime, studenti[index3].ime);
						printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
						printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
						return;
					}
					else 
					{
						printf("%s %s\n", studenti[index3].prezime, studenti[index3].ime);
						printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
						printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
						return;
					}
				}
			}
		}
	}
	else if (vel==1)
	{
		printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
		return;
	}
	
}

int genijalci (struct Student* studenti, int vel, double prosjek)
{
	int i, j;
	for (i=0; i<vel; i++)
	{
		if (racunanje_prosjeka(studenti[i])<prosjek)
		{
			izbacivanje(studenti+i, vel-i-1);
			vel--;
			i--;
		}
	}
	
	najbolji_studenti(studenti, vel, prosjek);
	
	return vel;
}

int main()
{
	struct Student s = { "aaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaa", {}, 50 };
	int i;
	for (i=0; i<50; i++) s.ocjene[i]=10;
	printf("Vel: %llu", sizeof s);
	/* = 244 = 20*1 (char) + 20*1 (char) + 50*4 (int) + 4 (int) */

	struct Student niz[1];
	niz[0]=s;	
	genijalci(niz, 1, 9.9);
    return 0;
}
