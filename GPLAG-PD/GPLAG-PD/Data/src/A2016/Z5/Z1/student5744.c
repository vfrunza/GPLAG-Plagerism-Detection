#include <stdio.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};
//funkcija koja poredi leksikografski rijeci 
int poredi_rijeci(char *prva,char* druga)
{
	while(*prva!='\0'&&*druga!='\0')
	{
		if(*prva>*druga) return 0;
		if(*druga>*prva) return 1;
		druga++;
		prva++;
	}
	if(*prva!='\0'&&*druga=='\0') return 0;
	if(*prva=='\0'&&*druga!='\0') return 1;
	return -1;
}

int genijalci(struct Student* niz,int vel,double pro)
{
	int i,j;
	double tre,p=0,d=0,t=0;
	struct Student ps,ds,ts;
	//prolazi kroz niz studenata
	for(i=0;i<vel;i++)
	{
		tre=0;
		//racuna prosjek
		for(j=0;j<niz[i].br_ocjena;j++)
		{
			tre+=niz[i].ocjene[j];
			if(niz[i].ocjene[j]==5)
			{
				tre=5;	
				break;
			} 
		}
		if(niz[i].br_ocjena==0) tre=5;
		if(tre>5)
		{
			tre=tre/niz[i].br_ocjena;
		}
		//ako treba izbacuje studenta
		if(tre-pro<-0.00001)
		{
			for(j=i;j<vel-1;j++)
			{
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
			continue;
		}
		//ako je student po kriterijima ispred dosadasnjeg prvog ubacuje ga 
		if(tre>p || (tre==p&&poredi_rijeci(niz[i].prezime,ps.prezime)==1)||(tre==p&&poredi_rijeci(niz[i].prezime,ps.prezime)==-1&&poredi_rijeci(niz[i].ime,ps.ime)==1))
		{
			t=d;
			d=p;
			p=tre;
			ts=ds;
			ds=ps;
			ps=niz[i];
		}
		//isto i za drugog
		else if(tre>d||(tre==d&&poredi_rijeci(niz[i].prezime,ds.prezime)==1)||(tre==d&&poredi_rijeci(niz[i].prezime,ds.prezime)==-1&&poredi_rijeci(niz[i].ime,ds.ime)==1))
		{
			t=d;
			d=tre;
			ts=ds;
			ds=niz[i];
		}
		//i treceg
		else if(tre>t||(tre==t&&poredi_rijeci(niz[i].prezime,ts.prezime)==1)||(tre==t&&poredi_rijeci(niz[i].prezime,ts.prezime)==-1&&poredi_rijeci(niz[i].ime,ts.ime)==1))
		{
			t=tre;
			ts=niz[i];
		}
	}
	//ispisuju koliko ima od najbolja tri studenta
	if(p!=0)
	{
		printf("%s %s\n",ps.prezime,ps.ime);
	}
	if(d!=0)
	{
		printf("%s %s\n",ds.prezime,ds.ime);
	}
	if(t!=0)
	{
		printf("%s %s\n",ts.prezime,ts.ime);
	}
	return vel;
}

int main()
{
	/* AT5: Test leksikografskog sortiranja no. 2, jedna petica je prosjek 5.0 */
struct Student studenti[5] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Beba", "Bebic", { 10, 10, 10, 10, 5}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
genijalci(studenti, 5, 6.5);
if(poredi_rijeci(studenti[1].prezime,studenti[0].prezime)==-1&&poredi_rijeci(studenti[1].ime,studenti[0].ime))
printf("da");
printf("%d",poredi_rijeci(studenti[0].ime,studenti[1].ime));
	return 0;
}