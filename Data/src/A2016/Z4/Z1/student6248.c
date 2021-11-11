#include <stdio.h>
#include <ctype.h>

int najcesci_string(char mat[1000][1000],int m,int n)
{
	int i,j,k,pom=0,max=0,nas_string,br=1;
	for(i=0; i<m-1; i++)
	{
		br=1;
		for(k=i+1; k<m; k++)
		{
			for(j=0; j<n; j++)
			{
				if(mat[i][j]!=mat[k][j])
				{
					pom=1; break;
				}
				else pom=0;
			}
			if(pom==0) br++;
		}
		if(br>max)
		{
			max=br;
			nas_string=i;
		}
	}
	return nas_string;
}

int broj_ponavljanja(char mat[1000][1000],int m,int n)
{
	int i,j,k,pom=0,max=0,br=1;
	for(i=0; i<m-1; i++)
	{
		br=1;
		for(k=i+1; k<m; k++)
		{
			for(j=0; j<n; j++)
			{
				if(mat[i][j]!=mat[k][j])
				{
					pom=1; break;
				}
				else pom=0;
			}
			if(pom==0) br++;
		}
		if(br>max)
		{
			max=br;
		}
	}
	return max;
}

int prebroji_rijeci(char* s)
{
	int br=0, razmak=1;
	while(*s!='\0')
	{
		if(!(*s>='a' && *s<='z') && !(*s>='A' && *s<='Z')) razmak=1;
		else if(razmak==1)
		{
			razmak=0;
			br++;
		}
		s++;
	}
	return br;
}

char* izbaci_najcescu(char* s)
{
	char mat[1000][1000]={{' '}},rijec[1000],*pt,*kt,*p=rijec,*novi=rijec,*st=s,*pok=s,*pocetak=s;
	int i=0,j,red=0,broj_rijeci,k=0;
	broj_rijeci=prebroji_rijeci(s);
	if(broj_rijeci==0) return s;
	if(broj_rijeci==1)
	{
		*s='\0';
		return s;
	}
	while(*st!='\0') 
	{
		if(((*st>='a' && *st<='z') || (*st>='A' && *st<='Z')))
		{
			j=0;
			while((*st>='a' && *st<='z') || (*st>='A' && *st<='Z'))
			{
				mat[i][j]=toupper(*st);
				j++;
				st++;
			}
			st--;
			i++;
		}
		st++;
	}
	st=s;
	red=najcesci_string(mat,broj_rijeci,1000);
	for(j=0; j<1000; j++)
	{
		*p=mat[red][j];
		if(!(*p>='a' && *p<='z') && !(*p>='A' && *p<='Z'))
		{
			*p='\0';
			break;
		}
		p++;
	}
	k=broj_ponavljanja(mat,broj_rijeci,1000);
	i=0;
	while(i<k)
	{
		pok=s;
		p=novi;
		pt=pok;
		kt=pok;
		while(*pok!='\0' && *p!='\0')
		{
			if((pok==pocetak && (toupper(*pok)>='A' && toupper(*pok)<='Z') && toupper(*pok)==*p && *p!='\0') || 
		    (pok!=pocetak  &&  !(toupper(*(pok-1))>='A' && toupper(*(pok-1))<='Z') && (toupper(*pok)>='A' && toupper(*pok)<='Z') && toupper(*pok)==*p && *p!='\0'))
		    {
		    	pt=pok;
		    	while((toupper(*pok)>='A' && toupper(*pok)<='Z') && toupper(*pok)==*p && *p!='\0' && *pok!='\0')
		    	{
		    		pok++;
		    		p++;
		    	}
		    	if(!(toupper(*pok)>='A' && toupper(*pok)<='Z') && *p=='\0')
		    	{
		    		kt=pok;
		    		while(*kt!='\0')
		    		{
		    			*pt++=*kt++;
		    		}
		    		*pt='\0';
		    		pok=pt-1;
		    	}
		    }
		    p=novi;
		    pok++;
		}
		i++;
	}
	return s;
}

int main() {
	char t[]="Pet plus pet plus pet daje petnaest";
	printf("%s",izbaci_najcescu(t));
    return 0;
}
