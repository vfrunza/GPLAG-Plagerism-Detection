#include <stdio.h>
#include <math.h>

int broj_rijeci(char *s)
{
	int broj=0;
	while(*s != '\0')
	{
		while(*s == ' ')
		{
			s++;
		}
		while(*s != ' ' && *s != '\0')
		{
			s++;
		}
		while(*s == ' ')
		{
			s++;
		}
		broj++;
		s++;
	}
	return broj;
}

int broj_r(char *s){
	int broj=0;
	while(*s != '\0'){
		if(*s != ' ' && *(s+1) == ' ' || *s != ' ' && *(s+1) == '\0') broj++;
		s++;
	}
	return broj;
}

int stepenovanje(int baza, int eksponent)
{
	int i,rezultat=1;
	for(i = 0; i < eksponent; i++)
	{
		rezultat *= baza;
	}
	return rezultat;
}

int konacan_broj(int broj)
{
	int x=1,i,broj_cifara=0,rezultat=0,temp;

	if(broj<0){
		x=-1;
		broj*=-1;
	}
	temp = broj;

	printf("%d\n\n",broj);
	while(temp > 0)
	{
		broj_cifara++;
		temp /= 10;
	}
	printf("broj cifara %d\n",broj_cifara);
	
	temp=broj;
	
	for(i=(broj_cifara-1);i>=0;i--){
		printf("rez: %d \n", temp/stepenovanje(10,i));
		
		temp-=((temp/(stepenovanje(10,i)))*stepenovanje(10,i));
		
		
	}
	
	return (x*broj);
}


char* kraj_stringa(char *tekst){
	char* pok;
	pok=tekst;
	while(*pok!='\0')pok++;
	return pok;
	
}


char* ubaci_broj (char *tekst, int broj)
{
	int br=0,broj_ponavljanja=0,temp,i,brojcifara=0;
	temp = broj;
	while(temp != 0)
	{
		brojcifara++;
		temp /= 10;
	}
	if(broj < 0) brojcifara++;
	
	broj_ponavljanja= broj_r(tekst)-1;
	char *s,*p, *q;
	int var;
	p=kraj_stringa(tekst);
	--p;
	s = tekst;
	while(*s == ' ') s++;

	while(broj_ponavljanja > 0)
	{
		while(*s != ' ' && *s!='\0')
		{	
			s++;
		}
		for(i=0;i<=brojcifara;i++){
			while(p >s)
				{
					*(p+1) = *p;
					p--;
				}
			
				p=kraj_stringa(tekst);
		}
		/*dio za ubacivanje broja*/
		br=0;
		temp=broj;
		//528
		s++;
		if(broj < 0){
			*s++ = '-';
			temp*=(-1);
			for(i=(brojcifara-2);i>=0;i--){
				var = '0';
				var+=(temp/stepenovanje(10,i));
				*(s++)=var;
				
				temp-=((temp/(stepenovanje(10,i)))*stepenovanje(10,i));
				
				br++;
				
			}
		}else {
			for(i=(brojcifara-1);i>=0;i--){
				var = '0';
				var+=(temp/stepenovanje(10,i));
				*(s++)=var;
						
				temp-=((temp/(stepenovanje(10,i)))*stepenovanje(10,i));
				
				br++;
			}	
		}
		*s++=' ';
		while(*s == ' '){
			//printf("aa\n");
			s++;
		}
		broj_ponavljanja--;
	}
	
	
	return tekst;
}

int main()
{
	/*
	char s[100]="Amra je lijepa KAO SUNCE";
	int broj=15;
	printf("%s",ubaci_broj(s,230));
	*/
	char s[66] = "a sada i primjer koji se zavrsava razmacima       ";
	printf("%d\n\n", broj_r(s));
	printf("\"%s\"", ubaci_broj(s, 1));
	return 0;
}
