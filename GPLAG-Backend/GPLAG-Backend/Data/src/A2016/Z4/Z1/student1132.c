#include <stdio.h>
int isAlpha(char x)
{
	if((x>='a'&&x<='z')||(x>='A'&&x<='Z')) return 1;
	else return 0;
}
char toLower(char x)
{
	if(x>='A'&&x<='Z') x+=32;
	return x;
}

char* izbaci_najcescu(char *s)
{
	char  *pok,*kroz,*pocetak,*kraj,*iter1,*iter2,*pocetakLongest=s,*krajLongest=s;
	int rep_max = 0,i,j,k,N,cnt,eq;
	pok = s;
	for(pok = s;*pok!='\0';pok++)
	{
		if(pok==s||!isAlpha(*(pok-1)))
		{
			cnt = 1;
			pocetak = pok;
			kraj = pok;
			while(isAlpha(*kraj)) kraj++;
			if(kraj==pok) continue;
			for(kroz = kraj;*kroz!='\0';kroz++)
			{
				if(!isAlpha(*(kroz-1)))
				{
					eq = 1;
					iter1 = pocetak;
					iter2 = kroz;
					while(iter1!=kraj)
					{
						if(toLower(*iter1)!=toLower(*iter2) || *iter1=='\0')
						{
							eq = 0;
							break;
						}
						iter1++;
						iter2++;
					}
					if(isAlpha(*iter2)) eq = 0;
					cnt+=eq;
				}
			}
			if(cnt>rep_max)
			{
			rep_max = cnt;
			pocetakLongest = pocetak;
			krajLongest = kraj;
			//	printf("%s\n",longest);
			}
		}
	}
	pocetak = pocetakLongest;
	kraj = krajLongest;
	while(*kraj!='\0') kraj++;
	for(kroz = s;*kroz!='\0';kroz++)
			{
				if(kroz==s || !isAlpha(*(kroz-1)))
				{
					eq = 1;
					iter1 = pocetakLongest;
					iter2 = kroz;
					while(iter1!=krajLongest)
					{
						if(toLower(*iter1)!=toLower(*iter2))
						{
							eq = 0;
							break;
						}
						iter1++;
						iter2++;
					}
					if(isAlpha(*iter2)) eq = 0;
			//	if(eq==1)	printf("%d ",kroz-s);
				    if(eq==1 && kroz!=pocetakLongest)
					{
						N = krajLongest - pocetakLongest;
						while(N--)
						{
							for(iter1 = kroz;*iter1!='\0';iter1++)
							{
								*iter1 = *(iter1+1);
							}
						}
					}
				}
			}
				N = krajLongest - pocetakLongest;
						while(N--)
						{
							for(iter1 = pocetakLongest;*iter1!='\0';iter1++)
							{
								*iter1 = *(iter1+1);
							}
						}
	return s;
}

int main()
{
char t[]=" Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";
printf("'%s'", izbaci_najcescu(t));

	return 0;
}
