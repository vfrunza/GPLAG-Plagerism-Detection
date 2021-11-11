#include <stdio.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int daLiImaPet(struct Student s)
{
	int i; 
	
	for(i=0;i<s.br_ocjena;i++)
	{
		if(s.ocjene[i] == 5)
		return 1;
	}
	
	
	return 0;

}

int imaOcjenu(struct Student s)
{
	if(s.br_ocjena == 0)
		return 0;
		
	return 1; 	
}

float ukProsjek(struct Student s)
{
	int i;
	float suma = 0;
	float br_ocjena;
	
	if(s.br_ocjena==0)
		return 5;
	
	for(i=0;i<s.br_ocjena;i++)
	{
		suma+=s.ocjene[i];
		
	}
	br_ocjena=s.br_ocjena;
	suma=suma/br_ocjena;
	return suma;
}

void kopirajRijec(char* ulaz,char* izlaz)
{
	while(*ulaz != '\0' && *ulaz !='\n')
	*izlaz++=*ulaz++;
	*izlaz='\0';
	
}

int jednakeRijeci(char* prva, char* druga)
{
	int jednake = 1;
	while((*prva != '\n' && *prva != '\0')&&(*druga != '\n' && *druga != '\0'))
	{
		if(*prva != *druga) jednake = 0;
		prva++;
		druga++;
	}
	
	if(*prva != *druga) jednake = 0;
	
	return jednake;
	
}

int vecaRijec(char* r1,char* r2)
{
	char prva[100];
	char druga[100];
	kopirajRijec(r1,prva);
	kopirajRijec(r2,druga);
	int clan = 0;
	
	while((prva[clan] != '\n' && prva[clan] != '\0')&&(druga[clan] != '\n' && druga[clan] != '\0'))
	{
		if(prva[clan] > druga[clan]) return 1;
		else if(prva[clan] < druga[clan]) return 0;
		clan++;
	}
	if(prva[clan] == '\n' || prva[clan] == '\0') return 1;
	
	else return 0;
}

int daLiJeVeci(struct Student s1, struct Student s2)
{
	if(ukProsjek(s1)>ukProsjek(s2))
	{
		return 1;
	}
	else if(ukProsjek(s1)<ukProsjek(s2))
		{
			return 0;
		}
	else
	{
		if(!jednakeRijeci(s1.prezime,s2.prezime) && vecaRijec(s1.prezime,s2.prezime))
			return 1;
		
		else if(!jednakeRijeci(s1.prezime,s2.prezime) && vecaRijec(s1.prezime,s2.prezime))
			return 0;
		
		else
		 	{
		 		if(!jednakeRijeci(s1.ime,s2.ime) && vecaRijec(s1.ime,s2.ime))
		 			return 0;
		 		
		 		else if(!jednakeRijeci(s1.ime,s2.ime) && vecaRijec(s1.ime,s2.ime))
		 			return 1;
		 			
		 		else return 1;
		 	}
	}
	
}

void ispisStudent(struct Student s)
	{
		printf("%s %s\n",s.prezime,s.ime);
		
	}



int genijalci(struct Student *niz, int vel,float prosjek )
{
	int i,j;
    int  nizN[100];
	
	int temp;
	
	for(i=0;i<vel;i++)
	{
		if(imaOcjenu(niz[i]) == 0 || daLiImaPet(niz[i]) == 1 || ukProsjek(niz[i]) < prosjek)
		{
			for(j=i;j<vel-1;j++)
			{
				niz[j]=niz[j+1];
				
			}
			vel--;
			i--;
		}
	}
	
	
	
	for(i=0;i<vel;i++)
	{
		nizN[i] = i;
	}
	
	for(i=0;i<vel;i++)
	{
		for(j=i;j<vel;j++)
		{
			if(daLiJeVeci(niz[nizN[j]],niz[nizN[i]]))
			{
				temp = nizN[j];
				nizN[j] = nizN[i];
				nizN[i] = temp;
				
			}
			
		}
		

	}
	
	for(i=0;i<3 && i<vel;i++)
	{
	 	ispisStudent(niz[nizN[i]]);
	}
	
	return vel;
}




int main() {
		return 0;
}
