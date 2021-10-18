#include <stdio.h>

void sortiranje(int *sortiraj, int *index)
{
	int i=0, j, temp1, temp2;
	i=0;
	while(i<95)
	{
		j=0;
		while(j<95)
		{
			if(sortiraj[j]<sortiraj[i])
			{
				temp1=sortiraj[i];
				sortiraj[i]=sortiraj[j];
				sortiraj[j]=temp1;
				
				temp2=index[i];
				index[i]=index[j];
				index[j]=temp2;
			}
			
			if(sortiraj[i]==sortiraj[j] && index[i]<index[j])
			{
				temp2=index[i];
				index[i]=index[j];
				index[j]=temp2;
			}
			j++;
		}
		i++;
	}
}

void stvori(char *kljuc, int *sortiraj, int *index)
{
	int i;
	i=0;
	do
	{
		if(sortiraj[i]!=0) 
		{
			*kljuc=index[i]+32;
			kljuc++;
		}
		i++;
	} while(i<95);
	
	i=0;
	do{
		if(sortiraj[i]==0)
		{
			*kljuc=index[i]+32;
			kljuc++;
		}
		i++;
	} while(i<95);
	*kljuc='\0';
}

char *kodiraj (char *tekst, char *kljuc)
{
	char *p=tekst;
	char *q;
	int niz[95], sort[95], in[95];
	int i, br;
	
	i=0;
	while(i<95) 
	{
		niz[i]=0;
		i++;
	}
	do{
		q=p;
		br=0;
		while(*q!='\0')
		{
		if(*p==*q) br++;
		q++;
		}
		if(niz[*p-32]==0) {niz[*p-32]=br;}
		p++;
	}
	while(*p!='\0');
	
	i=0;
	while(i<95)
	{
		sort[i]=niz[i];
		in[i]=i;
		i++;
	}
	sortiranje(sort, in);
	stvori(kljuc, sort, in);
	p=tekst;
	q=kljuc;
	
	do{
		q=kljuc;
		br=0;
		while(*q!='\0')
		{
			if(*p==*q)
			{
				*p=126-br;
				break;
			}
			br++;
			q++;
		}
		p++;
	} while(*p!='\0');
	return tekst;
}

char *dekodiraj(char *tekst, char *kljuc)
{
	char *p=tekst;
	do
	{
	*p=kljuc[126-*p];
	p++;
	} while(*p!='\0');
	return tekst;
}

int main() {
	char primjer[]="LLMLNLNMONM";
	char sifra[100]="";
	printf("%s", kodiraj(primjer, sifra));
	return 0;
}
