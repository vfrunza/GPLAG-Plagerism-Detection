#include <stdio.h>

char* izbaci_najcescu(char* s)
{
	int broj[1000]={0},i=0,j,k,l,t,broj_rijeci,max,maxi;
	char rijeci[1000][1000]={{0}};
	char *pom=s;
	char* poc;
	char* kraj;
	//vadi sve rijeci u matricu znakova
	while(*s!='\0')
	{
		while((*s<'A'||(*s>'Z'&&*s<'a')||*s>'z')&&*s!='\0')
		{
			s++;
		}
		j=0;
		while((*s>='A'&&*s<='Z')||(*s>='a'&&*s<='z'))
		{
			rijeci[i][j]=*s;
			j++;
			s++;
		}
		rijeci[i][j]='\0';
		i++;
		if(*s!='\0')s++;
	}
	broj_rijeci=i;
	s=pom;
	//broji ponavljanja svake rijeci i brise visestruka ponavljanja
	for(i=0;i<broj_rijeci-1;i++)
	{
		for(k=i+1;k<broj_rijeci;k++)
		{
			t=1;
			for(j=0;rijeci[k][j]!='\0'&&rijeci[i][j]!='\0';j++)
			{
				if(rijeci[k][j]!=rijeci[i][j]&&rijeci[k][j]!=rijeci[i][j]+32&&rijeci[k][j]!=rijeci[i][j]-32)
				{
					t=0;
					break;
				}
			}
			if(rijeci[i][j]!='\0'||rijeci[k][j]!='\0') t=0;
			if(t)
			{
				broj[i]++;
				for(l=k;l<broj_rijeci;l++)
				{
					for(j=0;rijeci[l+1][j]!='\0';j++)
					{
						rijeci[l][j]=rijeci[l+1][j];
					}
					rijeci[l][j]='\0';
				}
				broj_rijeci--;
				k--;
			}
		}
	}
	maxi=0;
	max=broj[0];
	//trazi rijec koja se najvise puta ponavlja
	for(i=1;i<broj_rijeci;i++)
	{
		if(broj[i]>max)
		{
			max=broj[i];
			maxi=i;
		}
	}
	s=pom;
	//izbacuje najcescu rijec
	while(*s!='\0')
	{
		while((*s<'A'||(*s>'Z'&&*s<'a')||*s>'z')&&*s!='\0')
		{
			s++;
		}
		j=0;
		t=1;
		poc=s;
		kraj=s;
		for(j=0;rijeci[maxi][j]!='\0'&&((*kraj>='A'&&*kraj<='Z')||(*kraj>='a'&&*kraj<='z'));j++,kraj++)
		{
			if(rijeci[maxi][j]!=*kraj&&rijeci[maxi][j]!=(*kraj)+32&&rijeci[maxi][j]!=(*kraj)-32)
			{
				t=0;
			}
		}
		if(rijeci[maxi][j]!='\0') t=0;
		if((*kraj>='A'&&*kraj<='Z')||(*kraj>='a'&&*kraj<='z')) t=0;
		if(t)
		{
			while(*kraj!='\0')
			{
				*(poc++)=*(kraj++);
			}
			*poc='\0';
		}
		//ako nije dosao do kraja rijeci dolazi
		while((*s>='A'&&*s<='Z')||(*s>='a'&&*s<='z')) s++;
	}
	return pom;
}

int main()
{
	char t[] = "ss ss ss ss s s s s s s s s ";
printf("'%s'", izbaci_najcescu(t));
	return 0;
}