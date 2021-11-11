#include <stdio.h>
#include <math.h>
#define eps 0.0001
char* obuhvat(char* tekst,float x1,float y1,float x2,float y2)
{
int a,b,i,j=0,k=0;
char* poka;
char* poka1;
char* tmp1;
char* tmp2;
char abc[1];
float x[100]={{1}};
float y[100]={{1}};
abc[0]='\0';
char prosliznak;
int zarez=0;
int l_zagrada=0;
int tacka=0;
int d_zagrada=0;
int minus=0;
char* tmp=tekst;
float faktor=10;



if(*tmp=='\0')
return tekst;
if(*(tmp+1)=='(' && *tmp+2<=9 && *tmp+2>=0)
minus=0;
else
return NULL;
while(*tmp!='\0')
{
	/*Provjera da li je dobro formatiran string*/
	if(!(*tmp<=9 && *tmp>=0) && !(*tmp<=46 && *tmp>=44) && *(tmp)!=40 && *(tmp)!=41)
	return NULL;

	
	if(*tmp=='(')
	{
		l_zagrada++;
		if(tmp==tekst || (*(tmp-1)==',' && *(tmp-2)==')'))
		continue;
		else
		return NULL;
	}
	
	
	if(*tmp==')')
	{
		d_zagrada++;
		if((*(tmp-1)=='.' && *(tmp-2)<=9 && *(tmp-2)>=0) || (*(tmp-1)<=9 && *(tmp-1)>=0 && l_zagrada==d_zagrada))
		continue;
		else
		return NULL;
	}
	
	if(*tmp==',')
	{
		zarez++;
		tacka=0;
		if(*tmp==')' || (*(tmp-1)=='.' && *(tmp-2)<=9 && *(tmp-2)>=0) || (*(tmp-1)<=9 && *(tmp-1)>=0 && zarez%2==1))
		continue;
		else
		return NULL;
	}
	
	if(*tmp=='-')
	{
		minus++;
		if(*(tmp-1)=='(' || (*(tmp-1)==',' && *(tmp-2)<=9 && *(tmp-2)>=0))
		continue;
		else
		return NULL;
	}
	
	if(*tmp=='.')
	{
		tacka++;
		if(*(tmp-2)<=9 && *(tmp-2)>=0 && tacka==1)
		continue;
		else
		return NULL;
	}
	
	if(*tmp<=9 && *tmp>=0)
	{
		if(*(tmp-1)=='(' || *(tmp-1)=='-' || (*(tmp-1)==',' && *(tmp-2)!=')') || (*(tmp-1)<=9 && *(tmp-1)>=0) || *(tmp-1)=='.')    
		continue;
		else
		return NULL;
	}
tmp++;
}

if(*(tmp-1)!=')')
return NULL;
a=0;
b=0;
tmp=tekst;
tmp1=x;
tmp2=y;
faktor=10;
zarez=0;
l_zagrada=0;
d_zagrada=0;
/*Ocitavanje vrijednosti iz stringa*/
while(*tmp!='\0')
{
if(l_zagrada==d_zagrada+1 && zarez%2==0 && *tmp<=9 && *tmp>=0)	
{
	*tmp1=faktor*(*tmp1)+*tmp;
}	
if(*tmp=='.')
{
	faktor=0.1;
}
if(*tmp==',' && *(tmp+1)<=9 && *(tmp+1)>=0)
{
	faktor=10;
}
if(l_zagrada==d_zagrada+1 && zarez%2==1 && *tmp<=9 && *tmp>=0)	
{
	*tmp2=faktor*(*tmp2)+*tmp;
}
if(*tmp==')')
{
	tmp1++;
	tmp2++;
	a++;
	b++;
}
	


tmp++;	
}
/*Provjera da li pripada povrsi*/
poka=tekst;
for(i=0;i<a;i++)	
{
	if(x[i]<=x2 && x[i]>=x1 && y[i]<=y2 && y[i]>=y1)
	{
	while(poka!=')')
	{
		poka++;
	}
	poka=poka+2;
	}
	else
	{
		/*Izbacivanje iz stringa*/
		poka1=poka;
		while(*poka1!='(' && poka1!=poka)
		{
			poka1++;
		}
		j=poka1-poka;
		while(*(poka1)!='\0')
		{
			*(poka1-j)=*(poka1);
			
			poka1++;
		}
		*(poka1)='\0';
		
	}
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
return tekst;	
}










int main() {


printf("Zadaća 4, Zadatak 4");

	return 0;
}
