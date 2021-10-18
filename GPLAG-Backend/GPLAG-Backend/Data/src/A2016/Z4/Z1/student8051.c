#include <stdio.h>
//Funkcija duz mi daje duzinu stringa.
int duz(char* s){
	int l=0;
	while(*s++!=0)
		l++;
	return l;
}
/*Funkcija pitaj mi ispituje da li je dati char slovo ili ne.
Ako je slovo onda vraca 1, u suprotnom vraca 0.*/
int pitaj(char s){
	if(s>='A'&&s<='Z'||s>='a'&&s<='z')
		return 1;
	else 
	return 0;
}
//Ova funkcija salje mi najveci clan u datom nizu.
int najveci(int a[],int k){
	int p=a[0],i;
	for(i=0;i<k;i++)
		if(a[i]>p)
			p=a[i];
	return p;
}


int prazan(char *s){
	int i;
	for(i=0;i<duz(s);i++)
		if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
			break;
			
	if(i==duz(s))
		return 1;
	else 
		return 0;
}

/* A ova funkcija mi govori da li su 2 data stringa jednaka.
Ukoliko jesu, funkcija vraca 1, u suprotnom 0.*/
int ispitaj(char *s, char *k){
	if(duz(s)!=duz(k))
		return 0;
	int p1,p2,i;
	for(i=0;i<duz(s);i++){
		p1=0;
		p2=0;
		if(s[i]>='a'&&s[i]<='z')
			p1=32;
		if(k[i]>='a'&&k[i]<='z')
			p2=32;
		if((s[i]-p1)!=(k[i]-p2))
			return 0;
	}
	return 1;
}

char* izbaci_najcescu(char*s){
	if(prazan(s)==1)
		return s;
	char rijeci[100][100];
	char pom[1000], pom2[1000];
	int a[1000]={0},p=0;
	int i,j,k=0,z=0;
	for(i=0;i<duz(s);i++)
	{
		if(pitaj(s[i])==1)
		{
			p=0;
			for(j=i;j<duz(s);j++)
			{
				if(pitaj(s[j])==0)
					break;
				pom[p]=s[j];
				p++;
			}
			/*String pom mi sluzi da iz datog stringa "vadi" rijec po rijec.
			A varijabla p je tu koja dolazi kao pozicija u varijabli p. Odnosno, ona je brojac...*/
			i=j;
			pom[p]=0;
			z=0;
			for(j=0;j<k;j++){
				/*Ispituje da li je string pom jednak nekom clanu u nizu rijeci.
				Ukoliko jest, niz brojaca se povecava za 1.*/
				if(ispitaj(pom,rijeci[j])==1)
				{	
					a[j]++;
					break;
				}
			}
			/*Ukoliko je ta rijec "nova", u datom nizu strina rijeci se dodaje ta nova rijec.*/
			if(j==k)
			{
				for(j=0;j<duz(pom);j++)
					rijeci[k][j]=pom[j];
				rijeci[k][j]=0;
				k++;
			}
			//Pom se stavlja kao prazan string
			for(j=0;j<duz(pom);j++)
				pom[j]=0;
		}
	}
	int maxi=najveci(a,k);
	/*Nakon sto nadjemo koliko se neka rijec ponavlja najvise puta, prolazimo kroz for petlju.
	Pronalazi prvu rijec koja se ponavlja toliki broj puta.*/
	for(i=0;i<k;i++)
	{
		if(maxi==a[i])
			break;
	}
	// Onda se pomocna varijabla pretvara u tu najcescu rijec.
	for(j=0;j<duz(rijeci[i]);j++)
	{
		pom[j]=rijeci[i][j];
	}
	pom[j]=0;
	int temp=0;
	/*Temp varijabla je promjenjiva koja pamti poziciju i. 
	Ona mi sluzi da obiljezi odakle ce kasnije i petlja nastaviti.*/
	for(i=0;i<duz(s);i++)
	{
		if(pitaj(s[i])==1)
		{
			p=0;
			/* Pom2 "vadi" rijec iz datog stringa i poredi se kasnije sa najcescom rijeci.
			Ukoliko pom2==pom, onda se ta rijec izbacuje iz stringa*/
			for(j=i;j<duz(s);j++)
			{
				if(pitaj(s[j])==0)
					break;
				pom2[p]=s[j];
				p++;
			}
			pom2[p]=0;
			temp=j-1;

			j=0;
			if(ispitaj(pom2,pom)==1)
			{
				for(j=i;j<duz(s)-duz(pom);j++)
				{
					s[j]=s[j+duz(pom)];
				}
				s[j]=0;
				temp=i;
			}
				i=temp;
		}
	}
	
	
	return s;
	
}


int main() {
//Kraci program koji testira ispravnost funkcije...
char t[]="1PsT1 psT2 3Pst pstpst pst";
printf("'%s'", izbaci_najcescu(t));
	
	
	return 0;
}
