#include <stdio.h>
#include <math.h>

int provjeri(char* s)
{
	char* temp=s;
	
	while(*(temp)!='\0')
	{
		if(*temp!=' ')return 1;
		temp++;
	}
	return 0;
}

char* zadnji(const char* s)
{
	char* p=s;
	while(*p!='\0') p++;
	return p;
}

char* ubaci(char* s ,char n)
{
	char* pocetni=s;
	char* kraj=zadnji(s);
	
	
	while(kraj!=s+1)
	{
		*kraj=*(kraj-1);
		kraj--;
	}
	*kraj=n;
	s=pocetni;
	return (pocetni+1);
}

char* ubaci_broj (char* s, int broj)
{
	char* pocetni=s;
	int powbr,temp,brojac_cifri,cifra_broja,neg=0;
	
	if(broj<0){neg=1;broj=broj*-1;}

	while(*s!='\0')
	{
		if(*s!=' ' && *(s+1)==' ' && provjeri(s+1))
		{
			
			s++;
			if (neg) s=ubaci(s,'-');
			brojac_cifri=0;
			temp=broj;
			do
			{
				temp/=10; 
				brojac_cifri++;
			}while(temp>0);
			temp=broj;
			brojac_cifri--;
			do
			{
				powbr=pow(10,brojac_cifri--);
		    	cifra_broja=temp/powbr;
		    
		    	s=ubaci(s,'0'+cifra_broja);
		
				temp=temp-cifra_broja*powbr;
		
			}while(brojac_cifri>=0);
			
			if(*(s+1)!=' ') s=ubaci(s,' ');
		}
		s++;
	}
	return pocetni;
}


int main() {
	
	return 0;
}
