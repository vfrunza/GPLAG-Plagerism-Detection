#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float prosjek(int ocjene[], int vel)
{
	int i=0;
	float suma=0;
	for(i=0; i<vel; i++)
		suma+=ocjene[i];
	return suma/vel;
}

int prosjek_5(int ocjene[], int vel)
{
	int i=0;
	if(vel==0)
		return 1;
	for(i=0; i<vel; i++)
		if(ocjene[i]==5)
			return 1;
	return 0;
}

int isti_string(char *p1, char *p2)
{
	int i=0, vel1=0, vel2=0;
	char *s1=p1, *s2=p2;
	
	vel1=strlen(s1); vel2=strlen(s2);
	 
	if(vel1<vel2)
	{
		for(i=0; i<vel1; i++)
		{
			if(s1[i] == s2[i])
				continue;
			else if(s1[i] > s2[i])
				return 2;
		}
		return 1;
	}
	else if(vel2<vel1)
	{
		for(i=0; i<vel2; i++)
		{
			if(s1[i] == s2[i])
				continue;
			else if(s1[i] < s2[i])
				return 2;
		}
		return 1;
	}
	else if(vel1 == vel2)
	{
		for(i=0; i<vel1; i++)
			if(s1[i] > s2[i])
				return 2;
		return 1;
	}
	return 1;
	
}

int genijalci(struct Student p[], int vel, float pr)
{
	struct Student s[200];
	struct Student temp;
	
	int i=0, j=0, pom=0;
	
	for(i=0; i<vel; i++)
		if(prosjek_5(p[i].ocjene, p[i].br_ocjena) || (prosjek(p[i].ocjene, p[i].br_ocjena)<pr))
		{
			for(j=i; j<vel-1; j++)
				p[j]=p[j+1];
			i--; vel--;
		}
		
	for(i=0; i<vel; i++)
		s[i]=p[i];
		
	for(i=0; i<vel-1; i++)
	{
		for(j=i+1; j<vel; j++)
		{
			if(prosjek(s[i].ocjene, s[i].br_ocjena) < prosjek(s[j].ocjene, s[j].br_ocjena))
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
	
	for(i=0; i<vel-1; i++)
	{
		for(j=i+1; j<vel; j++)
		{
			if(prosjek(s[i].ocjene, s[i].br_ocjena) == prosjek(s[j].ocjene, s[j].br_ocjena))
				if(isti_string(s[i].prezime, s[j].prezime) == 2)
				{
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
				}
		}
	}
	
	for(i=0; i<vel-1; i++)
	{
		for(j=i+1; j<vel; j++)
		{
			if(prosjek(s[i].ocjene, s[i].br_ocjena) == prosjek(s[j].ocjene, s[j].br_ocjena))
				if((isti_string(s[i].ime, s[j].ime) == 2) && (strcmp(s[i].prezime, s[j].prezime)==0 ))
				{
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
				}
		}
	}
	
	for(i=0; i<vel; i++)
		if(prosjek(s[i].ocjene, s[i].br_ocjena) >= pr && pom < 3)
		{
			pom++;
			printf("%s %s\n", s[i].prezime, s[i].ime);
		}
	
	return vel;
}

int main() {
	
	return 0;
}
