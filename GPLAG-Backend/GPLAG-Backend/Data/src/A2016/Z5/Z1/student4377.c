#include <stdio.h>

struct Student
{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
	
};

double rac_prosjek(struct Student *student)
{
	int i;
	int br = (*student).br_ocjena;
	double suma = 0;
	
	if((*student).br_ocjena == 0)
	{
		return 5.0;
	}
		
	for(i = 0; i<br; i++)
	{
		if((*student).ocjene[i] == 5)
		{
			return 5.0;
		}
		suma += (*student).ocjene[i];
	}

	return suma/br;
}

void zamjeni_ime(struct Student *ime1, struct Student *ime2)
{
	int i=0;
	while(i != 20)
	{
		(*ime1).ime[i] = (*ime2).ime[i];  
		i++;
	}
}

void ispisi_najbolje(struct Student *studenti, int vel)
{
	int i, j, k = 0;
	int index, nadjen = 0;
	float prosjek, max = 0;
	
	for(j=0; j<3; j++)	
	{
		max = 0;
		index = -1;
		
		for(i=0; i<vel; i++)
		{
			prosjek = rac_prosjek(studenti + i);
			
			if(prosjek > max)
			{
				max = prosjek;
				index = i;
			}
			else if(prosjek == max)
			{
				k=0;
				nadjen=0;
				while((*(studenti+i)).prezime[k] != '\0' && (*(studenti+index)).prezime[k] != '\0')
				{
					if((*(studenti+i)).prezime[k] - (*(studenti+index)).prezime[k] < 0)
					{
						index = i;
						nadjen = 1;
						break;
					}
					else if((*(studenti+i)).prezime[k] - (*(studenti+index)).prezime[k] == 0)
					{
						k++;
					}
					else
					{
						nadjen = 1;
						break;
					}
				}
				
				if(nadjen == 0)
				{
					k=0;
					while((*(studenti+i)).ime[k] != '\0' && (*(studenti+index)).ime[k] != '\0')
					{	
						if((*(studenti+i)).ime[k] - (*(studenti+index)).ime[k] < 0)
						{
							index = i;
							break;
						}
						else if((*(studenti+i)).ime[k] - (*(studenti+index)).ime[k] == 0)
						{
							k++;
						}
						else
						{
							break;
						}
					}
				}
			}
		}
		
		if(index != -1)
		{
			printf("%s %s\n", (*(studenti+index)).prezime, (*(studenti+index)).ime);
			(*(studenti+index)).ocjene[0] -= 1000;
		}
	}
}

void zamjeni_prezime(struct Student *ime1, struct Student *ime2)
{
	int i=0;
	while(i != 20)
	{
		(*ime1).prezime[i] = (*ime2).prezime[i];  
		i++;
	}
}

int genijalci(struct Student *studenti, int vel, double prosjek)
{
	int i, j, z;
	double prosjek_studenta;
	
	for(i=0; i<vel ; i++)
	{
		prosjek_studenta = rac_prosjek(studenti + i);
		
		if(prosjek_studenta < prosjek)
		{
			for(j=i; j < vel-1 ; j++)
			{
				zamjeni_ime(studenti + j, studenti+j+1);
				zamjeni_prezime(studenti+j, studenti+j+1);
				(*(studenti+j)).br_ocjena = (*(studenti+j+1)).br_ocjena;
				for(z=0; z < (*(studenti+j+1)).br_ocjena; z++)
					(*(studenti+j)).ocjene[z] = (*(studenti+j+1)).ocjene[z];
			}
			i--;
			vel--;
		}
	}
	
	ispisi_najbolje(studenti, vel);
	
	for(i=0; i<vel; i++)
	{
		if((*(studenti+i)).ocjene[0] < -800)
		{
			(*(studenti+i)).ocjene[0] += 1000; 
		}
	}
	
	return vel;
}

int main() 
{

struct Student studenti[6] ={
	{ "Mujo", "Mujic", { 10,10,10,10,9}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", {}, 0},
	{ "Mujo", "Mujic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7}, 29}, 
	{ "Fata", "Fatic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6}, 29}, 
};
int vel = genijalci(studenti, 6, 10);
printf("Vel: %d\n", vel);
      	

	return 0;
}
