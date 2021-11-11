#include <stdio.h>

void unesi (char niz[], int velicina)
{
	char znak=getchar();
	if (znak=='\n') znak=getchar();
	int i=0;
	while (i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}



char* izbaci_najcescu(char* s)
{
	int rijec, slovo1, slovo2, counter, isto, brojac;
	char*t;
	char*l;
	char*b;
	char*r;
	r=s;
	t=s;
	slovo1=0;
	slovo2=0;
	rijec=0;
	counter=0;
	isto=0;
	brojac=0;
	
	while (*s!='\0')
	{
		if (((*(s+1)>=65 && *(s+1)<=90) || (*(s+1)>=97 && *(s+1)<=122)) && ((*s>=0 && *s<=64) || (*s>=91 && *s<=96) || (*s>=123 && *s<=127)))
		{
			rijec++;
			if (rijec==1)
			{l=s;}
			if (rijec>1)
			{t=s;}
			b=s;
			s++;
		}
		
		if (rijec==1)
		{
			while ((*b>=65 && *b<=90) || (*b>=97 && *b<=122))
			{
				b++;
				slovo1++;
			}
		}
		
		if (rijec>1)
		{
			while ((*b>=65 && *b<=90) || (*b>=97 && *b<=122))
			{
				b++;
				slovo2++;
			}
		}
		
		if (slovo1==slovo2)
		{
			counter++;
			while ((*l>=65 && *l<=90) || (*l>=97 && *l<=122))
			{
				if (*l==*t || *l==*(t+32) || *l==*(t-32))
				{
					isto++;
				}
				
				if (isto==slovo1)
				{
					while (brojac!=isto)
					{
					   char *z;
					   z=t;
				       while(*z!='\0')
				       {
				       	    *z=*(z+1);
				       	    z++;
				       }
				       brojac++;
					}
				}
				
				l++;
				t++;
			}
		}
		
		else if ((*s>=0 && *s<=64) || (*s>=91 && *s<=96) || (*s>=123 && *s<=127))
		{
			s++;
		}
		
	}
  return r;
}

int main() 
{
	char niz[100];
	printf("Napisi recenicu: ");
	unesi (niz,100);
	printf ("Promijenjena recenica glasi: %s", izbaci_najcescu(niz));
	return 0;
}
