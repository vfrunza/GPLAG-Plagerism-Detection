#include <stdio.h>
void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}
struct Student {
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};
float prosjek_ocjena(int x[],int vel)
	{
		int i;
		float prosjek=0;
		float suma=0;
		for(i=0;i<vel;i++)
		{
			if(x[i]==5. || x[i]==0 || x[i]==' ') return 5.;
			suma+=x[i];
		}
		prosjek=suma/vel;
		return prosjek;
	}

struct Student unos_studenta() {
	struct Student s;
	int i;
	printf("Unesite ime studenta: ");
	unesi(s.ime,20);
	printf("Unesite prezime studenta: ");
	unesi(s.prezime,20);
	printf("Unesite broj ocjena studenta: ");
	scanf("%d",&s.br_ocjena);
	printf("Unesi ocjene studenta: ");
	for(i=0;i<s.br_ocjena;i++)
	{
		scanf("%d",&s.ocjene[i]);
	}
	return s;
}
int genijalci(struct Student studenti[],int velicina,float prosjek)
{
	int i,j;
	for(i=0;i<velicina;i++)
	{
		if(prosjek_ocjena(studenti[i].ocjene,studenti[i].br_ocjena)<prosjek) {
			for(j=i;j<velicina-1;j++)
			{
				studenti[j]=studenti[j+1];
			}
			velicina--;
			i--;
		}
	}
		
	return velicina;
	
}

int main() {
	struct Student studenti[3];
	int i;
	for(i=0;i<3;i++) {
	studenti[i]=unos_studenta();
	}
	int vel=0,j;
        vel = genijalci(studenti, 3, 7.);
        printf("Vel: %d",vel);
        printf("\n");
     for(i=0;i<vel-1;i++)
     {
     
     	
     	printf("%s %s\n",studenti[i].prezime,studenti[i].ime);
     }
	
	return 0;
}
