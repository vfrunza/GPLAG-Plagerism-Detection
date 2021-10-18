#include <stdio.h>

char* izbaci_najcescu(char* s)
{
	char *p=s, *pt, *kt, *ptp, *ktr, *ptr, *r, *pp, *ktp;
	char pom[100]={""};
	int br=0, max=0, pretp=0, br2=0;
	pp=pom;
	while(*s!='\0')
	{
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
			br++;
		if(*(s)<'A' || (*(s)>'Z' && *(s)<'a') || *(s)>'z') br2++;
		s++;
	}
	if(br==0)
		return p;
	if(br2==0)
	{
		s=p;
		*s='\0';
		return s;
	}
	br=1; s=p;
	while(*s!='\0')
	{
		while(*(s)<'A' || (*(s)>'Z' && *(s)<'a') || *(s)>'z') s++;
		if(((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && ((s==p) || *(s-1)<'A' || (*(s-1)>'Z' && *(s-1)<'a') || *(s-1)>'z'))
		{
			pt=s; ptp=s;
		}
		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
			s++;
		if(*(s)<'A' || (*(s)>'Z' && *(s)<'a') || *(s)>'z')
			kt=s;
		r=s; br=1;
		while(*r!='\0')
		{
			while(*r<'A' || (*r>'Z' && *r<'a') || *r>'z') r++;
			if(((*r>='A' && *r<='Z') || (*r>='a' && *r<='z')) && (*(r-1)<'A' || (*(r-1)>'Z' && *(r-1)<'a') || *(r-1)>'z'))
			{
				ptr=r;
			}
			while((*r>='A' && *r<='Z') || (*r>='a' && *r<='z'))
				r++;
			if(*(r)<'A' || (*(r)>'Z' && *(r)<'a') || *(r)>'z')
				ktr=r; 
			pretp=1;
				while(ptp<kt)
				{
					if(*ptp!=*ptr && (*ptp-32)!=*ptr && (*ptp+32)!=*ptr )
						pretp=0;
					
					ptp++; ptr++;
				}
			ptp=pt;
			if(pretp)
				br++;
			r++;
		}
		if(br>max)
		{
			while(ptp!=kt)
			{
				*pp=*ptp;
				pp++; ptp++;
			}
			*pp='\0';
			max=br;
		}
		pp=pom;
		s++;
	}
	s=p; pp=pom;
	while(*s!='\0')
	{
		while((*(s)<'A' || (*(s)>'Z' && *(s)<'a') || *(s)>'z')) s++;
		if(((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && ((s==p) || *(s-1)<'A' || (*(s-1)>'Z' && *(s-1)<'a') || *(s-1)>'z'))
		{
			pt=s; ptp=s;
		}
		while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
			s++;
		if(*(s)<'A' || (*(s)>'Z' && *(s)<'a') || *(s)>'z')	
		{
			kt=s; ktp=s;
		}
		pretp=1;
		while(pt!=kt)
		{
			if(*pt!=*pp && (*pt-32)!=*pp && (*pt+32)!=*pp )
				pretp=0;
			pt++; pp++;
		}
		pt=ptp; kt=ktp; pp=pom;
		if(pretp)
		{
			while(*kt!='\0')
			{
				*pt=*kt;
				pt++; kt++;
			}
			*pt='\0';
			s-=kt-pt;
		}
	s++;
	}
	return p;
}

int main()
{
	char tekst[100]={"1PsT1 psT2 3Pst pstpst pst"};
	printf("%s ", izbaci_najcescu(tekst));
	return 0;
}






/*











char* izbaci_najcescu (char* s) {
	char* p=s,*r;
	char *pt=s,*pt1=s,*kt=s,*kt1=s,*prvi=s,*drugi=s,*pm=s,*km=s;
	int br=0,pret=1,max=0;
	while(*p!='\0') {
		if (((*p>='A' && *p<='Z')||(*p>='a' && *p<='z')) && ((p==s)||((*(p-1)>=1 && *(p-1)<'A'))||(*(p-1)>'Z' && *(p-1)<'a')||(*(p-1)>'z'&& (*p-1)<=127) ))
			pt=p;
		while ((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))
			p++;
			if((*p>=0 && *p<'A') || (*p>'Z' && *p<'a') || (*p>'z' && *p<=127)) {
				kt=p;
				br=0;
				
				r=p;
				while (*r!='\0') {
					if (((*r>='A' && *r<='Z')||(*r>='a' && *r<='z')) && ((r==s)||(*(r-1)>1 && *(r-1)<='A')||(*(r-1)>'Z' && *(r-1)<'a')||(*(r-1)>'z' && *(r-1)<=127) ))
						pt1=r;
						while ((*r>='A' && *r<='Z') || (*r>='a' && *r<='z'))
							r++;
							if ((*r>=0 && *r<'A') || (*r>'Z' && *r<'a') || (*r>'z' && *r<=127)) {
								kt1=r;
								
								pret=1;
								prvi=pt;
								drugi=pt1;
								while (drugi!=kt1)
									if (*prvi!=*drugi && (*(prvi)-32)!=*drugi && (*prvi)+32!=*drugi) {
										prvi++;
										drugi++;
										pret=0;
									}
								if (pret==1)
									br++;
							}
				if(br>max) {
					max=br;
					pm=pt;
					km=kt;
				}
				while(*kt1!='\0') {
					*pt1++=*kt1++;
					p-=kt1-pt1;
				}
		r++;}
	}
	p++;}
	return s;
}

int main() {
	char tekst[40]={"Primjer je ovo primjer primjer."};
	printf("%s",izbaci_najcescu(tekst));
	return 0;
}
*/