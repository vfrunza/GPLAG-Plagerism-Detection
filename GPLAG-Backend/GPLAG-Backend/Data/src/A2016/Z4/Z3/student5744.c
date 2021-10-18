#include <stdio.h>

char* zamjena_rijeci(char* s, char** rijeci, char** zamjene, int broj_rijeci)
{
    char* pom=s;
    char* poc;
    char* kraj;
    int i,j,t,d,duzina;
    for(d=0;d<broj_rijeci;d++)
    {
    	s=pom;
	while(*s!='\0')
	{
	    //dolazi do rijeci
	    while(*s==' ')
	    {
	        s++;
	    }
	    for(i=0;i<broj_rijeci;i++)
	    {
	        kraj=s;
	        poc=s;
	        t=1;
	        if(rijeci[i][0]=='\0') t=0;
	        //provjerava da li rijec treba izbaciti
	        for(j=0;rijeci[i][j]!='\0'&&*kraj!='\0'&&*kraj!=' ';j++,kraj++)
	        {
	            if(rijeci[i][j]!=*kraj) t=0;
	        }
	        if(s!=pom)
	        {
	            if(*(s-1)!=' ') t=0;
	        }
	        if(rijeci[i][j]!='\0'||(*kraj!='\0'&&*kraj!=' ')) t=0;
	        //ako treba
	        if(t)
	        {
	            //prvo obrise tu rijec
	            while(*kraj!='\0')
	            {
	                *(poc++)=*(kraj++);
	            }
	            *poc='\0';
	            duzina=0;
	            //onda prosiri string za unos zamjene
	            for(j=0;zamjene[i][j]!='\0'&&zamjene[i][j]!=' ';j++)
	            {
	                duzina++;
	            }
                while(poc!=s)
                {
                    *(poc+duzina)=*poc;
                    poc--;
                }
                *(poc+duzina)=*poc;
                //unese zamjenu
                for(j=0;zamjene[i][j]!='\0'&&zamjene[i][j]!=' ';j++,s++)
                {
                    *s=zamjene[i][j];
                }
	        }
	    }
	    if(*s!='\0') s++;
	}
    }
	return pom;
}

int main()
{
    char* rijeci[2] = { "ss", "ss" };
char* zamjene[2] = { "bijeli", "snijeg" };
char tekst[100] = " s ss s ss s s  s s s";
printf("%s\n", zamjena_rijeci(tekst, rijeci, zamjene, 2));
/* Da li je promijenjen i polazni string? */
printf("%s", tekst);
	return 0;
}
