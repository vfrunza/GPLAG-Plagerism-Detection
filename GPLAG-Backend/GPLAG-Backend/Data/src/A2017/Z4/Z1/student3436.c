#include <stdio.h>
#include <math.h>



char* novi_znak(char* s,char znak)
{
	char* prvi=s;
	char* zadnji=s;
	while(*zadnji!='\0')zadnji++;

	while(zadnji!=s+1)
	{
		*zadnji=*(zadnji-1);
		zadnji--;
	}
	*zadnji=znak;
	s=prvi;
	s++;
	return (s);
}


char* ubaci_broj (char* s,int broj){
	
	char* prvi=s;
	char* tempp=s;
	int razmak=0;
	int deset,broj_cifri,cifra,neg=0,temp;
	
	if(broj<0){
		neg=1;
		broj=-1*broj;
	}
	
	while(*s!='\0')
	{
		tempp=s+1;razmak=0;
		
		while(*tempp!='\0')
		{
			if(*tempp!=' ') razmak=1;
			tempp++;
		}
		
		if(*s!=' ' && *(s+1)==' '  && razmak==1 )
		{
				s++;
				if(neg) s=novi_znak(s,'-');
				broj_cifri=0;
				temp=broj;
				
				do{
					broj_cifri++;
					temp/=10;
				}while(temp>0);
				
				broj_cifri--;
				temp=broj;
				
				do{
					deset=pow(10,broj_cifri--);
					cifra=temp/deset;
					s=novi_znak(s,'0'+cifra);
					temp-=cifra*deset;
					
				}while(broj_cifri>=0);
				
				if(*(s+1)!= ' ') s=novi_znak(s,' ');
			}
			s++;
		}
	return prvi;
}

int main() {
	
	return 0;
	
}
