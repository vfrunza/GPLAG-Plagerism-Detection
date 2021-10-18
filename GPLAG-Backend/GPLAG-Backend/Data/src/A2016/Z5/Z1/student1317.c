#include <stdio.h>
#include <math.h>
#include <string.h>

struct Student
{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
/* Funkcija izbaci_osobu izbacuje sve osobe ciji je prosjek manji od
zadatog prosjeka */
void izbaci_osobu(struct Student* s, int poc_izb, int vel)
{
	int j=0;
	
	for(j=poc_izb+1; j<vel; j++)
	{
		s[j-1]=s[j];
	}
	return;
}

int genijalci(struct Student* s, int vel, float pros)
{
	int i=0, j=0, suma=0, max_ind=0;
	float prosjeci[1000]={0.0};
	char prez_isp[3][20]={{""}};
	char ime_isp[3][20]={{""}};
	float max_oc=0.0;
	
	for(i=0; i<vel; i++)
	{
		suma=0;
		if(s[i].br_ocjena==0) prosjeci[i]=5.0;
		else
		{
			for(j=0; j<s[i].br_ocjena; j++)
			{
				if(s[i].ocjene[j]==5) 
				{
					prosjeci[i]=5.0;
					break;
				}
				suma=suma+s[i].ocjene[j];
			}
			if(j==s[i].br_ocjena) prosjeci[i]=(float)suma/(float)s[i].br_ocjena;
		}
		if(prosjeci[i]<pros) 
		{
			izbaci_osobu(s, i, vel);
			i--;
			vel--;
		}
	}
	
	if(vel==0) return 0;
	
	if(vel==1) printf("%s %s", s[0].prezime, s[0].ime);
	
	if(vel==2)
	{
		if(prosjeci[0]>prosjeci[1])
		{
			printf("%s %s\n", s[0].prezime, s[0].ime);
			printf("%s %s\n", s[1].prezime, s[1].ime);
		}
		else if(prosjeci[0]<prosjeci[1])
		{
			printf("%s %s\n", s[1].prezime, s[1].ime);
			printf("%s %s\n", s[0].prezime, s[0].ime);
		}
		else
		{
			if(strcmp(s[0].prezime, s[1].prezime)<0)
			{
				printf("%s %s\n", s[0].prezime, s[0].ime);
				printf("%s %s\n", s[1].prezime, s[1].ime);
			}
			else if(strcmp(s[0].prezime, s[1].prezime)>0)
			{
				printf("%s %s\n", s[1].prezime, s[1].ime);
				printf("%s %s\n", s[0].prezime, s[0].ime);
			}
			else if(strcmp(s[0].prezime, s[1].prezime)==0)
			{
				if(strcmp(s[0].ime, s[1].ime)<0)
				{
					printf("%s %s\n", s[0].prezime, s[0].ime);
					printf("%s %s\n", s[1].prezime, s[1].ime);
				}
				else if(strcmp(s[0].ime, s[1].ime)>0)
				{
					printf("%s %s\n", s[1].prezime, s[1].ime);
					printf("%s %s\n", s[0].prezime, s[0].ime);
				}
				else if(strcmp(s[0].ime, s[1].ime)==0)
				{
					printf("%s %s\n", s[0].prezime, s[0].ime);
					printf("%s %s\n", s[1].prezime, s[1].ime);
				}
			}
		}
	}
	if(vel>=3)
	{
		for(i=0; i<3; i++)
		{
			max_oc=prosjeci[0];
			strncpy(prez_isp[i], s[0].prezime, 20);
			strncpy(ime_isp[i], s[0].ime, 20);
			max_ind=0;
			/* Odredjivanje studenata sa najvecim prosjekom */
			for(j=1; j<vel; j++)
			{
				if(prosjeci[j]>max_oc)
				{
					max_oc=prosjeci[j];
					strncpy(prez_isp[i], s[j].prezime, 20);
					strncpy(ime_isp[i], s[j].ime, 20);
					max_ind=j;
				}
			}
			/* Odredjivanje redoslijeda studenata po leksikografskom redoslijedu */
			for(j=0; j<vel; j++)
			{
				if(prosjeci[j]==max_oc && j!=max_ind)
				{
					if(strcmp(s[j].prezime, prez_isp[i])<0 || (strcmp(s[j].prezime, prez_isp[i])==0 && strcmp(s[j].ime, ime_isp[i])<0))
					{
						strncpy(prez_isp[i], s[j].prezime, 20);
						strncpy(ime_isp[i], s[j].ime, 20);
						max_ind=j;
					}
				}
			}
			prosjeci[max_ind]=0.0;
			printf("%s %s\n", s[max_ind].prezime, s[max_ind].ime);
		}
	}
	
	return vel;
}

int main() 
{
	struct Student studenti[] = {
   	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
    };
	int vel=sizeof studenti/sizeof studenti[0];
	float prosjek=6.5;
	
	genijalci(studenti, vel, prosjek);
	
	return 0;
}
