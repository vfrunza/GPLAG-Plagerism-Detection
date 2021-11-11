#include <stdio.h>
#include <math.h>
#define EPS 0.0001

/*Funkcija prima niz tacaka u formi stringa i "pravougaonik"*/
/*Vraca NULL - pokazivac ako string nije ispravno formatiran*/
/*Ako jeste onda vraca taj string iz kojeg su izbacene tacke izvan tog pravougaonika*/

char* obuhvat(char *s,float x1,float y1,float x2,float y2)
{
	int i,j,N=0,pocetak=0,kraj,zarez,tacka,aux,kalac;
	for(i=0;s[i]!='\0';)
	{
	
		if(i!=0 && s[i]!=',')  return NULL;
		if(s[pocetak]!='(') return NULL;  
		if(s[i]==0) return NULL;
		zarez = -1;
		for(j=i+1;;j++)
		{
			if(s[j]==',')
			{
				if(zarez!=-1) return NULL;
				zarez=j;
			}
			if(s[j]==')'||s[j]=='\0') 
			{
				kraj=j;
				break;
			}
		}
			if(s[kraj]!=')')  return NULL;
			if(pocetak+1==kraj) return NULL;
			if(zarez==-1) return NULL;
			if(zarez+1==kraj || pocetak+1==zarez) return NULL;
			if(s[kraj+1]!='\0' && s[kraj+1]!=',') return NULL;
			if(s[pocetak+1]=='-'&&s[pocetak+2]=='.') return NULL;
			if(s[zarez+1]=='-'&&s[zarez+2]=='.') return NULL;
		float x=0,y=0,cener=10,iza=1;
		int predznak = 0;
		tacka=0;
		kalac = 0;
		if(s[pocetak+1]=='.'||s[zarez+1]=='.') return NULL;
		for(j=pocetak+1;j<zarez;j++)
		{
			if(s[j]=='-')
			{
				predznak = -1;
				if(j!=pocetak+1) return NULL;
			}
			else if(s[j]=='.')
			{
				if(tacka==1)  return NULL;
				tacka=1;
			}
			else if(s[j]<'0'||s[j]>'9')
			{
				return NULL;
			}
			else
			{
				x = x*cener + (s[j]-'0')*iza;
				kalac = 1;
			}
			if(tacka) 
			{
				cener=1;
				iza/=10;
			}
			else
			{
			    cener=10;
				iza=1;
			}
		}
		if(kalac==0) return NULL;
		if(predznak==-1&&fabs(x)<EPS) return NULL;
		if(predznak==-1) x=-x;
		predznak=1;
		cener = 10;
		iza = 1;
		tacka = 0;
		kalac = 0;
	for(j=zarez+1;j<kraj;j++)
		{
			if(s[j]=='-')
			{
				predznak = -1;
				if(j!=zarez+1)  return NULL;
			}
			else if(s[j]=='.')
			{
				if(tacka==1)  return NULL;
				tacka=1;
			}
			else if(s[j]<'0'||s[j]>'9')
			{
				return NULL;
			}
			else
			{
				y = y*cener + (s[j]-'0')*iza;
				kalac = 1;
			}
			if(tacka) 
			{
				cener=1;
				iza/=10;
			}
			else
			{
				cener=10;
				iza=1;
			}
		}
		if(kalac==0) return NULL;
		if(predznak==-1&&fabs(y)<EPS) return NULL;
		if(predznak==-1) y=-y;
		if(x+EPS<x1||x-EPS>x2||y+EPS<y1||y-EPS>y2)
		{
			aux=kraj-pocetak+2;
			while(aux--)
			{
			for(j=i;s[j]!='\0';j++)
			{
				s[j] = s[j+1];
			}
			}
		}
		else
		{
		i=kraj+1;
		pocetak = kraj+2;
		}
	}
	return s;
}


int main() 
{

	return 0;
}
