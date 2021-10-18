#include <stdio.h>

/*unos stringa*/
void unesi(char niz[], int velicina)
{
	int i;
	char znak=getchar();
	if (znak=='\n')
		znak=getchar();
	i=0;
	while(i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		znak=getchar();
		i++;
	}
	niz[i]='\0';
}

int Slovo(char c)
{
	if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
		return 1;
	return 0;	
}

void najduzi_bp(char *s1, char *s2)
{
	int duzina=1, max=0, isti=1;
	char *p, *q, *poc2,*upisuj, temp1, temp2;
	*s2='\0';
	while(*s1!='\0' && *s1==' ')
		s1++;
	while(*s1!='\0')
	{
		if (Slovo(*s1))
		{
			poc2=s2;
			duzina=1;
			if (Slovo(*(s1+1)))
			{
				p=s1;
				p++;
				duzina=1;
				while(Slovo(*p))
				{
					isti=0;
					temp1=*p;
					/*pretvaranje malog slova u veliko*/
					if (temp1>='a' && temp1<='z')
						temp1-='a'-'A';
					q=s1;
					/*provjeravanje da li se ponavljaju slova*/
					while(q<p)
					{
						temp2=*q;
						if (temp2>='a' && temp2<='z')
							temp2-='a'-'A';
						if(temp2==temp1)
						{
							if(duzina>max)
							{
								max=duzina;
								upisuj=s1;
								/*upisivanje u string*/
								while(upisuj<p)
								{
									*poc2=*upisuj;
									poc2++;
									upisuj++;
								}
								*poc2='\0';
							}
							isti=1;
							break;
						}
						q++;
					}
					if (isti==1)
						break;
					p++;
					duzina++;
				}
				if (duzina>max)
				{
					max=duzina;
					upisuj=s1;
					while(upisuj<p)
					{
						*poc2=*upisuj;
						poc2++;
						upisuj++;
					}
					*poc2='\0';
				}
			}
			/*slucaj kada je jedno slovo*/
			else 
			{
				duzina=1;
				if (duzina>max)
				{
					*poc2=*s1;
					poc2++;
					*poc2='\0';
				}
			}
		}
		s1++;
	}
}


int main() {
	char recenica[100], ubacuj[100];
	
	printf("Unesite recenicu: ");
	unesi(recenica,100);
	
	najduzi_bp(recenica, ubacuj);
	
	printf("%s",ubacuj);
	
	return 0;
}
