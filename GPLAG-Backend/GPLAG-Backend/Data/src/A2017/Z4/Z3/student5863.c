#include <stdio.h>

int JeLiSlovo(char s)
{
	return (s>='a' && s<='z') || (s>='A' && s<='Z');
}
char VratiManje(char s)
{
	return (s>='A' && s<='Z') ? s+=32:s;
}

int VratiPodniz(char *p,char *q)
{
	char *i,*j;
	int br=0;
	int isti=0;
	for(i=p;i!=q;i++)
	{   
	    br++;	
		for(j=i+1;j!=q;j++)
		{   
				
				if(VratiManje(*i)==VratiManje(*j))
				{
					isti=1;
					//br--;
					break;
					
				}
		
		}
	
	  
	
		if(isti==1)
			return br;
		
	}
	
	return br;
}

void najduzi_bp(char* s1, char* s2)
{
	char *p,*q,*r,*t,*u;
	char s;
	int br=0;
	int max=0;
	p=s1;

	while(*p!='\0')
	{   
		
		while(!JeLiSlovo(*p)) p++;
		if(JeLiSlovo(*p))
		{
			q=p;
			r=p;
		}
		
		while(JeLiSlovo(*q)) q++;
		
		
		
		
		
		//printf("%d ",VratiPodniz(r,q));
		if(VratiPodniz(r,q)>max)
		{
			max=VratiPodniz(r,q);
			t=r;
			u=q;
		}
		
		
		p++;
	}
	
	while(t!=u)
	{
		*s2=*t;
		s2++;
		t++;
	}
//	s2++;
	*s2='\0';
	
}

int main() {
		
	    char niz[10];
        najduzi_bp ("Ovo je neki primjer teksta", niz);
        printf ("Niz: '%s'", niz);
	return 0;
}
