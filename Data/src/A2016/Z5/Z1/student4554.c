#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

/*float prosjek1(int ocjenee[], int vel){
	struct Student s;
	int i;
	float suma=0;
	float prosjek;
	for(i=0; i<s.br_ocjena; i++){
		suma+=i;
	}
	prosjek=suma/vel;
	return prosjek;
}*/
float prosjek(struct Student *p)
{
	float pr=5;
	int i;
	for(i=0;i<p->br_ocjena;i++)
	{
		pr+=p->ocjene[i]/p->br_ocjena;
		if(p->ocjene[i]==5){pr=5;break;}
	}
	return pr;
	
}
int  genijalci(struct Student *studenti, int vel, double prosjek2){
		int i, j;
		double suma,prosjek1;
		for(i=0;i<vel;i++)
		{
			prosjek1=0;
			suma=0;
			for(j=0;j<studenti[i].br_ocjena;j++)
			{
				suma+=studenti[i].ocjene[j];
				if(studenti[i].ocjene[j]==5){prosjek1=5;break;}
			}
			if(studenti[i].br_ocjena!=0 && prosjek!=5)prosjek1=suma/studenti[i].br_ocjena;
			else prosjek1=5;
			
			if(prosjek1<prosjek2)
			{
				for(j=i;j<vel-1;j++)
				studenti[j]=studenti[j+1];
				i--;
				vel--;
			}
		}
       int maxi1,maxi2,maxi3;
       maxi1=0;maxi2=0;maxi3=0;
       int max2, max3;
       max2=-999999;
       max3=-999999;
       for(i=0;i<vel;i++)
       {
       	  if(prosjek(&studenti[i])>prosjek(&studenti[maxi1]) || (prosjek(&studenti[i])==prosjek(&studenti[maxi1]) && strcmp(studenti[i].prezime,studenti[maxi1].prezime)))
       	  {
       	  	maxi1=i;
       	  }
       }
		for(i=0;i<vel;i++)
       {
       	  
       	  if(prosjek(&studenti[i])>max2 && i!=maxi1 || (prosjek(&studenti[i])==prosjek(&studenti[maxi2])&& max2!=-999999 && strcmp(studenti[i].prezime,studenti[maxi2].prezime)))
       	  {
       	  	max2=prosjek(&studenti[i]);
       	  	maxi2=i;
       	  }
       }
	  
		for(i=0;i<vel;i++)
       {
       	  if(prosjek(&studenti[i])>max3 && i!=maxi1  && i!=maxi2 && (prosjek(&studenti[i])==prosjek(&studenti[maxi3])&& max3!=-999999 && strcmp(studenti[i].prezime,studenti[maxi3].prezime)))
       	  {
       	  	max3=prosjek(&studenti[i]);
       	  	maxi3=i;
       	  }
       }	
	if(vel>=1)
	{
	printf("%s %s\n", studenti[maxi1].prezime, studenti[maxi1].ime);	
	}
	if(vel>=2)
	{
		printf("%s %s\n", studenti[maxi2].prezime, studenti[maxi2].ime);	
	}
	if(vel>=3)
	{
		printf("%s %s\n", studenti[maxi3].prezime, studenti[maxi3].ime);	
	}
		
	
	return vel;
	
}
		

int main() {
	
	
	
	return 0;
}
