#include <stdio.h>
#include <math.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float dajProsjekStudenta(struct Student student)
{
	int i = 0, suma = 0;
	float prosjek = 10;
	if(student.br_ocjena == 0) return 5.0;
	for(i; i<student.br_ocjena; i++){
		suma += student.ocjene[i];
		if(student.ocjene[i] == 5) prosjek = 5.0;
	}
	if(prosjek <= 5.0) return 5.0;
	prosjek = suma/(student.br_ocjena*1.0);
	return prosjek;
}

void izbaciStudenta(struct Student studenti[100], int vel, int pozicija)
{
	int i = pozicija, j;
	for(i; i < vel-1; i++)
	{
		j = 0;
		while(studenti[i+1].ime[j] != '\0'){
			studenti[i].ime[j] = studenti[i+1].ime[j];
			j++;
		}
		studenti[i].ime[j] = '\0';
		j = 0;
		while(studenti[i+1].prezime[j] != '\0'){
			studenti[i].prezime[j] = studenti[i+1].prezime[j];
			j++;
		}
		studenti[i].prezime[j] = '\0';
		for(j = 0; j<studenti[i+1].br_ocjena; j++)
			studenti[i].ocjene[j] = studenti[i+1].ocjene[j];
		studenti[i].br_ocjena = studenti[i+1].br_ocjena;
	}
	return studenti;
}

int porediRijeci(char prvaRijec[20], char drugaRijec[20])
{
	int i = 0;
	while(prvaRijec[i] != '\0' && drugaRijec[i] != '\0')
	{
		if(prvaRijec[i] < drugaRijec[i]) return -1;
		else if(drugaRijec[i] < prvaRijec[i]) return 1;
		i++;
	}
	if(prvaRijec[i] != '\0') return 1;
	else if(drugaRijec[i] != '\0') return -1;
	else return 0;
}

int genijalci(struct Student studenti[100], int vel, float prosjek)
{
	int i = 0;
	for(i; i < vel; i++)
	{
		if(dajProsjekStudenta(studenti[i]) < prosjek)
		{
			izbaciStudenta(studenti, vel, i);
			vel--;
			i--;
		}
	}
	if(vel <= 0) return vel;
	else if(vel == 1)
	{
		printf("%s %s\n", studenti[0].prezime, studenti[0].ime);
		return vel;
	}
	else if(vel == 2)
	{
		if(fabs(dajProsjekStudenta(studenti[0]) - dajProsjekStudenta(studenti[1])) < 0.001)
		{
			int m = 0;
			if(porediRijeci(studenti[0].prezime, studenti[1].prezime) == -1)
				m = 0;
			else
				m = 1;
			printf("%s %s\n", studenti[m].prezime, studenti[m].ime);
			if(m == 1)
				m--;
			else m++;
			printf("%s %s\n", studenti[m].prezime, studenti[m].ime);	
		}
		else if(dajProsjekStudenta(studenti[0]) > dajProsjekStudenta(studenti[1]))
		{
			printf("%s %s\n", studenti[0].prezime, studenti[0].ime);
			printf("%s %s\n", studenti[1].prezime, studenti[1].ime);
		}else
		{
			printf("%s %s\n", studenti[1].prezime, studenti[1].ime);
			printf("%s %s\n", studenti[0].prezime, studenti[0].ime);
			
		}
		return vel;
	}
	
	int nizS[3] = {0};
	float nizP[3] = {0.0};
	/*
		nizP[0] -> prosjek
		nizS[0] -> indeks u studentima
	*/
	nizP[0] = dajProsjekStudenta(studenti[0]);
	for(i = 1; i<vel; i++)
	{
		float f = dajProsjekStudenta(studenti[i]);
		if(fabs(nizP[0] - f) < 0.0001)
		{
			int t = porediRijeci(studenti[nizS[0]].prezime, studenti[i].prezime);
			if(t == 0)
			{
				t = porediRijeci(studenti[nizS[0]].ime, studenti[i].ime);
				//printf("ULAZIM 1 %s %s\n");
				if(t == 1) nizS[0] = i;
			}
		}
		else if(f > nizP[0])
		{
			nizP[0] = f;
			nizS[0] = i;
		}
	}
	if(nizS[0] == 0)
	{ 
		nizS[1] = 1;
		nizP[1] = dajProsjekStudenta(studenti[nizS[1]]);
	}
	for(i = 0; i<vel; i++)
	{
		if(nizS[0] == i) continue;
		float f = dajProsjekStudenta(studenti[i]);
		if(fabs(nizP[1] - f) < 0.0001)
		{
			int t = porediRijeci(studenti[nizS[1]].prezime, studenti[i].prezime);
			if(t == 0)
			{
				t = porediRijeci(studenti[nizS[1]].ime, studenti[i].ime);
		//		printf("ULAZIM 2\n");
				if(t == 1) nizS[1] = i;
			}
		}
		else if(f > nizP[1])
		{
			nizP[1] = f;
			nizS[1] = i;
		}
	}
	if(nizS[0] == 0 || nizS[1] == 0)
	{
		for(i = 1; i<vel; i++)
		{
			if(nizS[0] != i && nizS[1] != i)
			{
				nizS[2] = i;
				nizP[2] = dajProsjekStudenta(studenti[i]);
				break;
			}
		}
	}
	for(i = 0; i<vel; i++)
	{
		if(nizS[0] == i || nizS[1] == i) continue;
		float f = dajProsjekStudenta(studenti[i]);
		if(fabs(nizP[2] - f) < 0.0001)
		{
			int t = porediRijeci(studenti[nizS[2]].prezime, studenti[i].prezime);
			if(t == 0)
			{
		//		printf("ULAZIM 3\n");
				t = porediRijeci(studenti[nizS[2]].ime, studenti[i].ime);
				if(t == 1) nizS[2] = i;
			}
		}
		else if(f > nizP[2])
		{
			nizP[2] = f;
			nizS[2] = i;
		}
	}
	
	for(i = 0; i<3; i++)
	{
		printf("%s %s\n", studenti[nizS[i]].prezime, studenti[nizS[i]].ime);
	}
	
	return vel;
}

int main() 
{
	char s1[] = "Fata";
	char s2[] = "Muj";
	printf("%i\n", porediRijeci(s2, s1));
	return 0;
}
