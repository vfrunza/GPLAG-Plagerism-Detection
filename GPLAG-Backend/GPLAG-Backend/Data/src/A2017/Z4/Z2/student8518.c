#include <stdio.h>

void unesi(char niz[], int n)
{
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<n-1 && znak!='\n')
	{
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine(char *s, int niz[], int p)
{
	int x, i=0;
	
	while(*s!='\0')
	{
	    if((*s>64 && *s<91) || (*s>96 && *s<123))
	    {
	        x=0;
	        while((*s>64 && *s<91) || (*s>96 && *s<123))
	        {
	        	x++;
	        	s++;
	        }
	        
	    	if(niz[i]!=x) return 0;
	    	i++;
	    }
	    
	    if(i>=p) return 0;
	    
	    s++;
	}
	
	return 1;
}

int main() 
{
	char s[100];
	int i, y, z=0;
	int niz[100];
	
	unesi(s, 100);
	
	for(i=0; i<100; i++)
	{
		scanf("%d", &y);
		if(y==0) break;
		niz[i]=y;
		z++;
	}
	
	printf("%d", provjeri_duzine(s, niz, z));
	
	return 0;
}