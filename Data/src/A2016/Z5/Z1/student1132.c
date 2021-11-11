#include <stdio.h>
#include <math.h>
#include<string.h>
#define PAO 5.00
#define EPS 1e-8
struct Student 
{
char ime[20], prezime[20];
int ocjene[50];
int br_ocjena;
};
/* Funkcija koja poredi da li je prvi student kasnije u poretku od drugog, takodjer p1 - prosjek prvog, p2 - prosjek drugog studenta*/
int manje(struct Student prva, struct Student druga,double p1,double p2)
{
	if((fabs(p1-p2)) > EPS)
	{
		if(p1 < p2) return 1;
		else return 0;
	}
	else
	{
		if(strcmp(prva.prezime,druga.prezime)<0) return 0;
		else if(strcmp(prva.prezime,druga.prezime)>0) return 1;
		else
		{
			if(strcmp(prva.ime,druga.ime) < 0) return 0;
			else return 1;
		}
	}
}
/* Funkcija pronalazi tri najbolja studenta u nizu studenta, i ispisuje one koji imaju prosjek veci od "prag"*/
int genijalci(struct Student* stud, int N, double prag)
{
	printf("\n");
	int i,j,vel = 0,k;
	double prosjek = 0;
	for(i=0;i<N;i++)
	{
		prosjek = 0;
		for(j=0; j < stud[i].br_ocjena;j++)
		{
			if(stud[i].ocjene[j] == 5) prosjek = -1000;
			else prosjek+=stud[i].ocjene[j];
		}
		if(stud[i].br_ocjena==0) prosjek = 5;
		else if(prosjek<0) prosjek = 5;
		else prosjek /= stud[i].br_ocjena;
		if(prosjek + EPS > prag) stud[vel++] = stud[i];
	}
	N = vel;

	struct Student top3[3]={{"a","a",{1},1},{"a","a",{1},1},{"a","a",{1},1}};
	double prosjeci[3] = {-1,-1,-1};
	for( i = 0;i < N; i++)
	{
		prosjek = 0;
		for(j=0; j < stud[i].br_ocjena;j++)
		{
			if(stud[i].ocjene[j] == 5) prosjek = -1000;
			else prosjek+=stud[i].ocjene[j];
		}
		
		if(stud[i].br_ocjena==0) prosjek = 5;
		else prosjek/=stud[i].br_ocjena;
		
		
		for(j = 0;j < 3;j++)
		{

			if(manje(top3[j],stud[i],prosjeci[j],prosjek))
			{
				for(k=1;k>=j;k--)
				{
					top3[k+1] = top3[k];
					prosjeci[k+1] = prosjeci[k];
				}
				prosjeci[j] = prosjek;
				top3[j] = stud[i];
				break;
			}
		}
	}
	for(j=0;j<3;j++)
	{
		if(prosjeci[j] + EPS > prag)
		{
			printf("%s %s\n",top3[j].prezime,top3[j].ime);
		}
	}
	return N;
}

int main()
{
	return 0;
}
