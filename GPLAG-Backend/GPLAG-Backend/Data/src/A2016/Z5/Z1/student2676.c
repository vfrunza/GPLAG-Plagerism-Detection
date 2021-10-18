#include <stdio.h>
#include <string.h>

struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student s[], int vel, float prosjek)
{
	int i, j, k, manji, maxindeks1=0, maxindeks2=0, maxindeks3=0, biomax=0;
	float suma, max;
	
	// Izbacianje studenata koji su ispod prosjeka
	
	for(i=0;i<vel;i++)
	{
		manji=0;
		suma=0;
		for(j=0;j<s[i].br_ocjena;j++)
		{
			suma+=s[i].ocjene[j];
			if(s[i].ocjene[j]==5) manji=1;
		}
		if(s[i].br_ocjena>0) suma=suma/s[i].br_ocjena; else suma=0;
		if(suma<prosjek) manji=1;
		if(manji==1)
		{
			for(j=i;j<vel-1;j++)
			{
				s[j]=s[j+1];
			}
			i--;
			vel--;
		}
	}
	
	// Trazenje prva 3 studenta po prosjeku
	
	while(biomax<vel && biomax<3)
	{
		
		// Varijabla biomax predstavlja broj nadjenih studenata sa max prosjekom. Kada nijedan dosad nije student
		// zabiljezen, samo trazimo onog sa najvecim prosjekom. Ali u ostalim slucajevima provjeravamo da li je
		// student do kojeg smo dosli vec ranije bio zabiljezen kao student sa max prosjekom.
		// Varijable maxindeks cuvaju poziciju u nizu studenta koji ima max prosjek.
		
		if(biomax==0)
		{
			max=0;
			for(k=0;k<s[0].br_ocjena;k++)
			{
				max+=s[0].ocjene[k];
			}
			max=max/s[0].br_ocjena;
			maxindeks1=0;
			for(i=0;i<vel;i++)
			{
				suma=0;
				for(k=0;k<s[i].br_ocjena;k++)
				{
					suma+=s[i].ocjene[k];
				}
				suma=suma/s[i].br_ocjena;
				if(suma>max)
				{
					max=suma;
					maxindeks1=i;
				}
				if(suma==max)
				{
					// Svaki put uzimamo u obzir i leksikografski poredak
					
					if(strcmp(s[i].prezime, s[maxindeks1].prezime)<0)
					{
						max=suma;
						maxindeks1=i;
					}
					if(strcmp(s[i].prezime, s[maxindeks1].prezime)==0)
					{
						if(strcmp(s[i].ime, s[maxindeks1].ime)<0)
						{
							max=suma;
							maxindeks1=i;
						}
					}
				}
			}
		}
		if(biomax==1)
		{
			i=0;
			max=0;
			while(i==maxindeks1) i++;
			for(k=0;k<s[i].br_ocjena;k++)
			{
				max+=s[i].ocjene[k];
			}
			max=max/s[i].br_ocjena;
			maxindeks2=i;
			for(i=0;i<vel;i++)
			{
				if(i!=maxindeks1)
				{
					suma=0;
					for(k=0;k<s[i].br_ocjena;k++)
					{
						suma+=s[i].ocjene[k];
					}
					suma=suma/s[i].br_ocjena;
					if(suma>max)
					{
						max=suma;
						maxindeks2=i;
					}
					if(suma==max)
					{
						if(strcmp(s[i].prezime, s[maxindeks2].prezime)<0)
						{
							max=suma;
							maxindeks2=i;
						}
						if(strcmp(s[i].prezime, s[maxindeks2].prezime)==0)
						{
							if(strcmp(s[i].ime, s[maxindeks2].ime)<0)
							{
								max=suma;
								maxindeks2=i;
							}
						}
					}
				}
			}
		}
		if(biomax==2)
		{
			i=0;
			max=0;
			while(i==maxindeks1 || i==maxindeks2) i++;
			for(k=0;k<s[i].br_ocjena;k++)
			{
				max+=s[i].ocjene[k];
			}
			max=max/s[i].br_ocjena;
			maxindeks3=i;
			for(i=0;i<vel;i++)
			{
				if(i!=maxindeks1 && i!=maxindeks2)
				{
					suma=0;
					for(k=0;k<s[i].br_ocjena;k++)
					{
						suma+=s[i].ocjene[k];
					}
					suma=suma/s[i].br_ocjena;
					if(suma>max)
					{
						max=suma;
						maxindeks3=i;
					}
					if(suma==max)
					{
						if(strcmp(s[i].prezime, s[maxindeks3].prezime)<0)
						{
							max=suma;
							maxindeks3=i;
						}
						if(strcmp(s[i].prezime, s[maxindeks3].prezime)==0)
						{
							if(strcmp(s[i].ime, s[maxindeks3].ime)<0)
							{
								max=suma;
								maxindeks3=i;
							}
						}
					}
				}
			}
		}
		biomax++;
	}
	if(biomax>=1) printf("%s %s\n", s[maxindeks1].prezime, s[maxindeks1].ime);
	if(biomax>=2) printf("%s %s\n", s[maxindeks2].prezime, s[maxindeks2].ime);
	if(biomax==3) printf("%s %s\n", s[maxindeks3].prezime, s[maxindeks3].ime);
	return vel;
}

int main() {
	int vel;
	struct Student studenti[6] =
	{
	    { "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	    { "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	    { "Beba", "Bebic", {}, 0},
	    { "Mujo", "Mujic", { 10,10,10,10,9}, 5}, 
	    { "Mujo", "Mujic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7}, 29}, 
	    { "Fata", "Fatic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6}, 29}, 
	};
    vel = genijalci(studenti, 6, 7);
	return 0;
}
