#include <stdio.h>

void izbaci(char* s, int duz)
{
    while(*(s+duz))
    {
        *s=*(s+duz);
        s++;
    }
    *s=*(s+duz);
}

char* izbaci_najcescu(char* s)
{
	char *maxkraj=s, *poc, *kraj, *p=s, *t, *spoc, *skraj, *tpoc, *q1, *q2;
	char ch1, ch2;
	int brmax=0, maxduz=0, br=0, ista, bslova, duz1, duz2, bilanerijec;
	if(*p=='\0') return s;
	while(*p!='\0')
	{
	    while((*p<'A' || (*p>'Z' && *p<'a') || *p>'z') && *(p+1)!='\0') p++;
		if(*p!='\0')
		{
			// Odredjujemo pocetak i kraj rijeci do koje smo dosli
			poc=p;
			kraj=p;
			duz1=1;
			while(((*(kraj+1)>='A' && *(kraj+1)<='Z') || (*(kraj+1)>='a' && *(kraj+1)<='z')) && *(kraj+1)!='\0')
			{
				duz1++;
				kraj++;
			}
			br=1;
			t=kraj+1;
			while(*t!='\0')
			{
				// Odredjujemo pocetak i kraj slijedece rijeci
				spoc=t;
				while((*spoc<'A' || (*spoc>'Z' && *spoc<'a') || *spoc>'z') && *(spoc+1)!='\0') spoc++;
				skraj=spoc;
				duz2=1;
				while(((*(skraj+1)>='A' && *(skraj+1)<='Z') || (*(skraj+1)>='a' && *(skraj+1)<='z')) && *(skraj+1)!='\0') 
				{
					duz2++;
					skraj++;
				}
				
				// Provjera dali je to ista rijec kao pocetna
				
				ista=1;
				bslova=0;
				
				// Posto ne mozemo koristiti pointer poc jer bi tada izgubili pointer na prvo slovo rijeci,
				// pravimo novi pointer
				tpoc=poc;
				
				if(duz1!=duz2) ista=0;
				else
				while(bslova<duz2)
				{
					// Posto se ne pravi razlika izmedju velikih i malih slova moramo svaki put ovo uraditi
					
					if(*tpoc>='A' && *tpoc<='Z') ch1=(*tpoc)+('a'-'A'); else ch1=*tpoc;
					if(*spoc>='A' && *spoc<='Z') ch2=(*spoc)+('a'-'A'); else ch2=*spoc;
					if(ch1!=ch2) ista=0;
					tpoc++;
					spoc++;
					bslova++;
				}
				
				if(ista) br++;
				t=skraj+1;
			}
			if (br>brmax)
			{
				brmax=br;
				maxkraj=kraj;
				maxduz=duz1;
			}
		}
		p=kraj+1;;
	}
	
	// Izbacivanje najcesce rijeci
	
	p=t-1;
	
	while(p>=s)
	{
		bilanerijec=0;
		if((*(p+1)<'A' || (*(p+1)>'Z' && *(p+1)<'a') || *(p+1)>'z') || *(p+1)=='\0') bilanerijec=1;
		if(*p>='A' && *p<='Z') ch1=(*p)+('a'-'A'); else ch1=*p;
		if(*maxkraj>='A' && *maxkraj<='Z') ch2=(*maxkraj)+('a'-'A'); else ch2=*maxkraj;
		if(ch1==ch2 && bilanerijec)
		{
			q2=p;
			q1=maxkraj;
			duz2=0;
			ista=1;
			while(q2>=s && ((*q2>='A' && *q2<='Z') || (*q2>='a' && *q2<='z')))
			{
				if(q1>=s)
				{
					if(*q1>='A' && *q1<='Z') ch1=(*q1)+('a'-'A'); else ch1=*q1;
					if(*q1>='A' && *q1<='Z') ch2=(*q1)+('a'-'A'); else ch2=*q1;
					if(ch1!=ch2) ista=0;
				}
				duz2++;
				q2--;
				q1--;
			}
			q2++;
			if(maxduz!=duz2) ista=0;
			if(ista)
			{
				izbaci(q2, duz2);
			}
		}
		p--;
	}
	return s;
}

int main() {
	char s[300]=" Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";
	printf("%s", izbaci_najcescu(s));
	return 0;
}
