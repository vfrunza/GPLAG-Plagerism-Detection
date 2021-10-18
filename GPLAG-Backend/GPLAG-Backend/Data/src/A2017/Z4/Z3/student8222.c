#include <stdio.h>
int slovo(char c)
{
	if((c>='A' && c<='Z') || (c>='a' && c<='z')) return 1;
	return 0;
}
void najduzi_bp(char* s1,char* s2)
{
	int max,brojac,i,prva_rijec=1;
	char* poc;
	char* kraj;
	char* pok=s2;
	while (*s1!='\0') {
	    brojac=0;
	    if (slovo(*s1)==1) 
	    {
	    	for (i=0;slovo(*(s1+i)) == 1; i++, brojac++);
	    	if (prva_rijec==1)
	    	{
	    		max=brojac;
	    		poc=s1;
	    		kraj=s1+brojac;
	    	}
	    	else if (brojac>max) 
	    	{
	    		max=brojac;
	    		poc=s1;
	    		kraj=s1+brojac;
	    	}
	    	prva_rijec=0;
	    	s1+=brojac;
	    }
	    s1++;
	}
	while (poc<kraj) *pok++=*poc++;
	*pok='\0';
}
int main() {
	
	return 0;
}
