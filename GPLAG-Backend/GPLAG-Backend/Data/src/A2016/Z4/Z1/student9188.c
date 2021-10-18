#include <stdio.h>
#include <ctype.h>

char* izbaci_najcescu(char* s)
{
	char *p=s;char help[100],*a;
	char *pt,*kt,*q,*pt1,*t,*r,*pm,*km;
	int br,isti,jeste,max=0;int i=0;
	int ima=0;

	if (*p=='\0') return 0;

	while(*p!='\0')
	{
		if(toupper(*p)>='A' && toupper(*p)<='Z') ima=1;
		p++;
	}
	
	if(ima==0) return s;
	
	p=s;
	while(*p!='\0')
	{ 	
		if(toupper(*p)>='A' && toupper(*p)<='Z')
		{  
			pt=p;
			while(toupper(*p)>='A' && toupper(*p)<='Z') p++;
			if(*p==' ' || *p=='\0')
			{   
				
				kt=p;
				q=p;
				br=1;
				while(*q!='\0')
				{
					if(toupper(*q)>='A' && toupper(*q)<='Z' )
					{
						pt1=q;
						while(toupper(*q)>='A' && toupper(*q)<='Z')q++;
						if(*q==' ' || *q=='\0')
						{
							isti=1;
							t=pt;
							r=pt1;
							while(t!=kt)
							{
								if(toupper(*t)!=toupper(*r)){isti=0;break;}
								t++;
								r++;
							}
							if(isti==1){br++;}
						}
						
						
					}else q++;
				}
				if(br>max)
				{  
					pm=pt;
					km=kt;
					max=br;
				}
			}
		}else p++;
		
	
	}

			

	p=s; 
	

		for(;;)
		{
			help[i]=*pm;
			i++;
			pm++;
			
			if(pm==km){help[i]='\0'; break; }
		}

	 a=help;

      
      
		while(*p!='\0')
		{
			if(toupper(*p)>='A' && toupper(*p)<='Z'	&& (*(p+1)!=' ' || *(p+1)=='\0'))
			{
				pt=p;q=p;
				while(toupper(*p)>='A' && toupper(*p)<='Z')p++;
				
				
					t=a;jeste=1;
				
				kt=p;
				
				
				while(pt!=kt)
				{   
					if(toupper(*t)!=toupper(*pt)) {jeste=0;break;}
					pt++;
					t++;
				}
			  
				
				if(jeste==1)
				{   
					while(*kt!='\0')
					{
				    	*q++=*kt++;
					}
					*q='\0';
					p=p-(kt-q);
				}
				
			}else p++;
			
		  
		}





	return s;
}

int main() {

char t[]="Ovo je neki bezvezni tekst tekst neki tekst";
printf("'%s'", izbaci_najcescu(t));
	
	return 0;
}
