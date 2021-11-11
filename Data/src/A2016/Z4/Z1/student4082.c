
#include <stdio.h>
#include <stdlib.h>

int strcmpa(const char*prvi,const char*drugi,int velikamala)
{
	char *p1=prvi;
	char *p2=drugi;
	if(velikamala==0)
	{
		while(*p1!='\0' || *p2!='\0')
		{
			if(*(p1)==*(p2))
			{
				p1++;
				p2++;
				continue;
			}
			else if(*(p1)<*(p2) || *(p1)=='\0')
				return -1;
			else
				return 1;
		}
		return 0;
	}
	else
	{
			
		while(*p1!='\0' || *p2!='\0')
		{
			if(*p1>=65 && *p1<=90 && *p2>=97 && *p2<=122)
			*p1=*p1+32;
			else if(*p1>=97 && *p1<=122 && *p2>=65 && *p2<=90)
			*p2=*p2+32;
			p1++;
			p2++;
		}
		
		p1=prvi;
		p2=drugi;
		
		while(*p1!='\0' || *p2!='\0')
		{
			if(*(p1)==*(p2))
			{
				p1++;
				p2++;
				continue;
			}
			else if(*(p1)<*(p2) || *(p1)=='\0')
				return -1;
			else 
				return 1;
		}
		
		return 0;
	}
}


char* nadjiNajcescu(char *str)
{
	char* p=str,*q=str,*najveca=str,*temp=str;
	char rijec1[50],rijec2[50];
	int i=0,j=0,maxRijec=1,trenutnaRijec=1;
	
	while(*p != '\0'){
		temp = p;
		
		while(*p>='A'&& *p<='z' && *p !='\0'){
			rijec1[i] = *p;
			i++;
			p++;
		}
		
		rijec1[i] = '\0';
		
		if(*p!='\0') p++; // p sada pokazuje na pocetak sljedeće rijeci
		
		q=p;
		
		if(*q!='\0'){
			while(*q!='\0'){
				rijec2[j] = *q;
				j++;
				q++;
				
				if(*q<'A'||*q>'z'||*q=='\0')
				{
					rijec2[j]='\0';
					j=0;
					if(strcmpa(rijec1,rijec2,1)==0)
						trenutnaRijec++;
					if(*q<'A' || *q>'z')
					q++;
				}
			}
			if(trenutnaRijec>maxRijec)
				{
					maxRijec=trenutnaRijec;
					najveca=temp;
				}
				i=0;
				trenutnaRijec=1;
		}
			
		
	}
	return najveca;
	
}

char* izbaci_rijec(char str[]){
	char*p=str,*q=str;
	
	while(*p>='A' && *p<='z' && *p!='\0')
	{
		p++;
	}
	
	while(*p!='\0'){
		*q= *p;
		q++;
		p++;
	}
	
	*q='\0';
	
	return str;
	
}

char* izbaci_najcescu(char *s)
{
	
	char* najcesca=nadjiNajcescu(s);
	
	char *p=najcesca;
	char trazenaRijec[50];
	char trenutnaRijec[50];
	int i=0;
	
	while(*p>='A' && *p<='z' && *p!='\0')
	{
		trazenaRijec[i]=*p;
		i++;
		p++;
	}
	trazenaRijec[i]='\0';
	i=0;
	
	p=najcesca;
	while(*p!='\0')
	{
		
		while(*p>='A' && *p<='z' && p!='\0')
		{
			trenutnaRijec[i]=*p;
			i++;
			p++;
		}
		trenutnaRijec[i]='\0';
		i=0;
		
		if(strcmpa(trenutnaRijec,trazenaRijec,1)==0)
		{
			najcesca=izbaci_rijec(najcesca);
			while((*najcesca<'A' || *najcesca>'z') && *najcesca!='\0')
			najcesca++;
			p=najcesca;
		}
		else
		{
			if(*p=='\0') break;
			while((*p<'A' || *p>'z') && *p!='\0')
			p++;
			najcesca=p;
		}
	}
	
	return s;
	
	
}

int main()
{
	
}