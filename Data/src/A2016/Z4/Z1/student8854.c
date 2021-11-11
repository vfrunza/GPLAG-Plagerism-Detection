#include <stdio.h>

char* izbaci_najcescu(char* s)
{int i;
char a,b;
int vel;
int znak=0;
int prosliznak=0;
int znak1=0;

int prosliznak1=0;
int duzinarijeci=0;
int duzina_max_rijeci=0;
int duzinarijeci1=0;
int brojrijeci=0;
int ponavljanja=0;
int maxpon=0;
int jednak=0;
char* helper;
char* pok_na_max=s;
char* tmp=s;
char* tmp1;
char* pok=s;
char* pok1=s;

	
	while(*tmp!='\0')
	{
	prosliznak=znak;
	/*Da li je znak slovo*/
	if((*tmp<='Z' && *tmp>='A') || (*tmp>='a' && *tmp<='z'))
	{
		znak=1;
	}
	else
	{
		znak=0;
	}
	if(znak==1 && prosliznak==1)
	{duzinarijeci++;
		if(*(tmp+1)=='\0' && brojrijeci==1)
		{
			pok_na_max=pok;
			duzina_max_rijeci=duzinarijeci;
			break;
		}
	}
	if(znak==1 && prosliznak==0)
	{duzinarijeci++;
	brojrijeci++;
		pok=tmp;
		if(*(tmp+1)=='\0' && brojrijeci==1)
		{
			pok_na_max=pok;
			duzina_max_rijeci=duzinarijeci;
			break;
		}
	}
	if(znak==0 && prosliznak==1)
	{
		znak1=1;
		
		ponavljanja++;
		tmp1=tmp;
		while(*tmp1!='\0')
		{
			prosliznak1=znak1;
			if((*tmp1<='Z' && *tmp1>='A') || (*tmp1>='a' && *tmp1<='z'))
			{
				znak1=1;
			}
			else
			{
				znak1=0;
			}
			
			if(znak1==1 && prosliznak1==1)
			{duzinarijeci1++;
			if(*(tmp1+1)=='\0')
			{/*Uporedjivanje rijeci*/
			if(duzinarijeci!=duzinarijeci1)
				jednak=0;
				else
				{
					for(i=1;i<=duzinarijeci;i++)
					{
						a=*(pok+i-1);
						b=*(pok1+i-1);
						/*Funkcija nije case sensitive*/
						if(a<='Z' && a>='A')
						a=a+32;
						if(b<='Z' && b>='A')
						b=b+32;
						
						if(a==b && ((a<='Z' && a>='A') || (a<='z' && a>='a')))
						jednak=1;
						else
						{jednak=0;
						break;}
					}
					
				}
			/*Broj ponavljanja rijeci*/	
			if(jednak==1)
			ponavljanja++;
			duzinarijeci1=0;
			
			}}
			
			
			
			if(znak1==1 && prosliznak1==0)
			{pok1=tmp1;
			duzinarijeci1++;
			if(*(tmp1+1)=='\0')
			{/*Uporedjivanje rijeci*/
			if(duzinarijeci!=duzinarijeci1)
				jednak=0;
				else
				{
					for(i=1;i<=duzinarijeci;i++)
					{
						a=*(pok+i-1);
						b=*(pok1+i-1);
						/*Funkcija nije case sensitive*/
						if(a<='Z' && a>='A')
						a=a+32;
						if(b<='Z' && b>='A')
						b=b+32;
						
						if(a==b && ((a<='Z' && a>='A') || (a<='z' && a>='a')))
						jednak=1;
						else
						{jednak=0;
						break;}
					}
					
				}
			/*Broj ponavljanja rijeci*/	
			if(jednak==1)
			ponavljanja++;
			duzinarijeci1=0;
			
			}
			
			}
			if(znak1==0 && prosliznak1==1 && tmp1!=tmp)
			{
				/*Uporedjivanje rijeci*/
				if(duzinarijeci!=duzinarijeci1)
				jednak=0;
				else
				{
					for(i=1;i<=duzinarijeci;i++)
					{
						a=*(pok+i-1);
						b=*(pok1+i-1);
						/*Funkcija nije case sensitive*/
						if(a<='Z' && a>='A')
						a=a+32;
						if(b<='Z' && b>='A')
						b=b+32;
						
						if(a==b && ((a<='Z' && a>='A') || (a<='z' && a>='a')))
						jednak=1;
						else
						{jednak=0;
						break;}
					}
					
				}
			/*Broj ponavljanja rijeci*/	
			if(jednak==1)
			ponavljanja++;
			duzinarijeci1=0;
			
			}
		tmp1++;	
		}
	if(ponavljanja>maxpon)
	{maxpon=ponavljanja;
	pok_na_max=pok;
		duzina_max_rijeci=duzinarijeci;
	}
	ponavljanja=0;
	duzinarijeci=0;}
	
	tmp++;
		
	}
	
	
	vel=tmp-s;
tmp=pok_na_max+duzina_max_rijeci;
znak1=0;

i=0;


/*Izbacivanje najcesce rijeci iz niza*/
while(*tmp!='\0')
{
	
	if(i==0)
	{
		if(tmp>pok_na_max+duzina_max_rijeci)
		{
			if(((*(tmp-1)<='Z' && *(tmp-1)>='A') || (*(tmp-1)<='z' && *(tmp-1)>='a')))
			znak1=1;
			else 
			znak1=0;
		}
	}

	
	a=*(tmp);
	b=*(pok_na_max+i);
	
	/*Funkcija nije case sensitive*/
	
	if(a<='Z' && a>='A')
	a=a+32;
	
	if(b<='Z' && b>='A')
	b=b+32;
	
	if(a==b && ((a<='Z' && a>='A') || (a<='z' && a>='a')))
	{
	if(i==0)
	helper=tmp;
	i++;}
	else
	i=0;
	
	if(i==duzina_max_rijeci && brojrijeci!=0)
	{
			if(((*(tmp+1)<='Z' && *(tmp+1)>='A') || (*(tmp+1)<='z' && *(tmp+1)>='a')))
			{
			i=0;}
			else 
			{
			if(znak1==0)
			{tmp1=helper;
				while(*(tmp1+duzina_max_rijeci-1))
				{*(tmp1)=*(tmp1+duzina_max_rijeci);
				tmp1++;}
				vel=vel-duzina_max_rijeci;
				i=0;
			
				
				
			tmp--;}}
		
	}	
	
	
tmp++;	
}
tmp=pok_na_max;	
while(*(tmp+duzina_max_rijeci-1)!='\0')
{
*(tmp)=*(tmp+duzina_max_rijeci)	;
tmp++;
}
	
	
	
	
	
	
	
	
	
	return s;
}














int main() {

char t[]="s h h";
printf("'%s'", izbaci_najcescu(t));
	return 0;
}


