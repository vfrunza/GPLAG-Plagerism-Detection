#include <stdio.h>
#include <ctype.h>

/*Funkcija za prebrojavanje broja rijeci u stringu*/
int br_rijeci(char* s)
{
	int i=0;
	while(!isalpha(*s))  s++;  //krecemo se stringom do prvog slova
	while(*s!='\0')
	{
		if(i=0 || (!isalpha(*(s-1)) && isalpha(*s) ))
		{
			i++;
			s++;
			continue;
		}
		s++;
	}
	return i;
}

void unesi(char niz[], int velicina)
{
	char znak=getchar();
	if(znak == '\n')  znak=getchar();
	int i=0;
	while(i < velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

/*Funkcija za poredjenje rijeci u stringu*/
int poredi(char* s1,char* s2)
{
	int i=0;
	while(isalpha(*(s1+i)))
	{
		if(*(s1+i)==*(s2+i) || *(s1+i)+32 == *(s2+i) || *(s1+i) == *(s2+i)+32)
		{
			i++;
			continue;  //ako su slova ista, prelazimo na sljedece slovo u rijeci
		}
		else {    
			return 0;
		}
	}
	return 1;
}


char* izbaci_najcescu(char* s){
	char* pok=s;
	int max=-1;
	int broj_r;
	int dr[150]={1};  //pomocu dr[i] odredjujemo duzine rijeci
	int pomak_rijeci[150]={0};
	int k=-1,i,j;  //Pomocu k mjerimo na kojoj smo rijeci
	int brojac[150];  //Brojac istih rijeci u stringu
	
	if(*pok=='\0') return s;  //ako je prazan string funkcija ne treba nista raditi
	for(i=0;i<150;i++) brojac[i]=1;
	
	i=0;
	
	broj_r=br_rijeci(s);
	while(!isalpha(*s))   s++;   //krecemo se stringom do prvog slova
	while(*s!='\0')
	{
		if(k==-1 || (!isalpha(*(s-1)) && isalpha(*s)))
		{
			k++;
			dr[k]=1;
			pomak_rijeci[k]=s-pok;
			s++;
			continue;
		}
		while(isalpha(*s))
		{
			dr[k]++;
			s++;
		}
		s++;
	}
	
	s=pok; //vracamo string na pocetak
	for(i=0;i<broj_r;i++)
	{
		for(j=i+1;j<broj_r;j++)
		{
			if(dr[i]==dr[j])
			{
				if(poredi (s+pomak_rijeci[i], (s+pomak_rijeci[j])))
					brojac[i]++;
			}
		}
	}
	
	for(i=0;i<broj_r;i++) //trazimo rijec koja se najcesce ponavlja i najbliza je pocetku
	{
		if(brojac[i]>max)
		{
			max=brojac[i];
		}
	}
	
	for(i=0;i<broj_r;i++)
	{
		if(brojac[i]==max)
		{
			for(j=i+1;j<broj_r;j++){
				if(poredi (s+pomak_rijeci[i] , s+pomak_rijeci[j]))
				{
				//Brisemo rijec tako sto ostatak stringa pomijeramo
				do
				{
					*(s+pomak_rijeci[j])=*(s+pomak_rijeci[j]+dr[j]);
					s++;
				}while(*(s+pomak_rijeci[j]) != '\0');
				}
			}
		}
	}
	
	return pok;
}

int main() {
	char s[300];
	unesi(s,300);
	printf("%s",izbaci_najcescu(s));
	return 0;
}
