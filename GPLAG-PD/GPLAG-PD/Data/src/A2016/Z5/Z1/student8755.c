#include <stdio.h>
#include <string.h>

struct Student 
{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
struct Student s;

double avg(int niz[], int broj_ocjena)
{
	int suma=0;
	int i;
	
	if(broj_ocjena>0)
		for(i=0; i<broj_ocjena; i++)
		{
			if(niz[i]==5) return 5;
			suma+=niz[i];
		}
	else return 5;
	return(double)suma/broj_ocjena;
}

int genijalci(struct Student s[], int br_studenata, double prosjek)
{
	int i, j, max[3]={0,0,0}, k, vrati, n, temp;
	double temp_avg;
	for(i=0; i<br_studenata; i++)
	{
		if(avg(s[i].ocjene, s[i].br_ocjena)<prosjek)
		{
			if(i!=br_studenata-1)
			{
				for(j=i; j<br_studenata-1; j++)
					s[j]=s[j+1];
				br_studenata--;
			}
			else
				br_studenata--;
			i--;
		}
	}
	vrati=br_studenata;
	if(br_studenata<3)
		temp=br_studenata;
	else
		temp=3;
	for(k=0; k<temp; k++)
		if(br_studenata>0)
		{
			temp_avg=0;
			for(i=0; i<br_studenata; i++)
			{
				if(k==0 || (k==1 && max[0]!=i) || (k==2 && max[0]!=i && max[1]!=i))
				{
					
					if(avg(s[i].ocjene, s[i].br_ocjena)>temp_avg)
					{
						max[k]=i;
						temp_avg=avg(s[i].ocjene, s[i].br_ocjena);
					}
					else if(avg(s[i].ocjene, s[i].br_ocjena)==temp_avg)
					{
						n=max[k];
						if(strcmp(s[i].prezime,s[n].prezime)<0)
							max[k]=i;
						else if(strcmp(s[i].prezime,s[n].prezime)==0)
							{
								if(strcmp(s[i].ime,s[n].ime)<0)
									max[k]=i;
							}
					}
					
				}
			}
			n=max[k];
			printf("%s %s\n", s[n].prezime, s[n].ime);
		}
	return vrati;
}
int main()
{
	struct Student studenti[3] = {
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}, 29}, 
	{ "Fata", "Fatic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7}, 29}, 
};
genijalci(studenti, 3, 7.0);

	return 0;
}