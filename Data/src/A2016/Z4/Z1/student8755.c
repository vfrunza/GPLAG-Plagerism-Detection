#include <stdio.h>

char* izbaci_najcescu(char* s)
{
	char *pok2, *pocetak, *niz[1000],*p, *q, *temp;
	int br=0, i, br2=0, max=0, br_temp=0, prvi_prolazi=1;
	pocetak=s;
	if(*s==NULL)
		return NULL;
	/*Trazi rijec koja se ponavlja najviše puta ~ pokazivac na tu rijec kod prvog pojavljivanja*/
	while(*s!='\0')
	{
		pok2=s+1;
		br=0;
		br2=0;
		temp=pok2;
		
		
		while(*temp!='\0')
		{
			p=s;
			q=temp;
			while(*p==*q || (*p>='A' && *p<='Z' && *q==*p+32) || (*p>='a' && *p<='z' && *q==*p-32))
			{
				p++;
				q++;
				if((s==pocetak || (*(s-1)<'A' || (*(s-1)>'Z' && *(s-1)<'a') || *(s-1)>'z')) && ((*p<'A' || (*p>'Z' && *p<'a') || *p>'z')) && ((*q<'A' || (*q>'Z' && *q<'a') || *q>'z')) && (*(temp-1)<'A' || (*(temp-1)>'Z' && *(temp-1)<'a') || *(temp-1)>'z'))
				{
					br2++;
					break;
				}
			}
			temp++;
		}
		
		
		if(br2>br_temp || prvi_prolazi)
		{
			br_temp=br2;
			while(*pok2!='\0')
			{
				p=s;
				q=pok2;
				
				while(*p==*q || (*p>='A' && *p<='Z' && *q==(*p)+32) || (*p>='a' && *p<='z' && *q==*p-32))
				{
					p++;
					q++;
					if((s==pocetak || (*(s-1)<'A' || (*(s-1)>'Z' && *(s-1)<'a') || *(s-1)>'z')) && ((*p<'A' || (*p>'Z' && *p<'a') || *p>'z')) && ((*q<'A' || (*q>'Z' && *q<'a') || *q>'z')) && (*(pok2-1)<'A' || (*(pok2-1)>'Z' && *(pok2-1)<'a') || *(pok2-1)>'z'))
					{
						br++;
						niz[br]=pok2;
						break;
					}
				}
				pok2++;
			}
			if(br>max || prvi_prolazi)
			{
				max=br;
				niz[0]=s;
			}
		}
		prvi_prolazi=0;
		s++;
	}
	/*izbacivanje rijeci koja se najvise puta ponavljaja od posljednje u recenici do prve*/ 
	for(i=max; i>=0; i--)
	{
		s=niz[i];
		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
			s++;
		if(*s!='\0')
		{
			while(*s!='\0')
				*niz[i]++=*s++;
			*niz[i]='\0';
		}
		else if(*s=='\0')
			*niz[i]='\0';
	/*	s=niz[i];
		while(*s!='\0')
		{
			if(*s!=' ')
				s++;
			else
			{
				s++;
				while(*s!='\0')
					*niz[i]++=*s++;
				*niz[i]='\0';
			}
		}*/
		
	}
	
		
	return pocetak;
}

int main() 
{	
	char niz[]="Test test abc test";
	printf("%s", izbaci_najcescu(niz));
	return 0;
}
