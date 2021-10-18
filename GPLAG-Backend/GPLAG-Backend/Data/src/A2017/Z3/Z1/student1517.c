#include <stdio.h>

int dva_od_tri (int n1[], int v1, int n2[], int v2, int n3[], int v3)
{
	int n, i, j, k, duzina, ima, brojac;
	int niz[1000];
	duzina=0;
	n=0;
	k=0;
	ima=0;
	
	for(i=0; i<v1; i++)
	{
		ima=0;
		if(i!=0)
		{
			for(j=0; j<duzina; j++)
			{
				if(niz[j]==n1[i]) ima=1;
			}
		}
		
		if(ima==0)
		{
			niz[k]=n1[i];
			k++;
			duzina++;
		}
	}
	
		for(i=0; i<v2; i++)
	{
		ima=0;
		
			for(j=0; j<duzina; j++)
			{
				if(niz[j]==n2[i]) ima=1;
			}
		
		
		if(ima==0)
		{
			niz[k]=n2[i];
			k++;
			duzina++;
		}
	}
	
		for(i=0; i<v3; i++)
	{
		ima=0;
		
			for(j=0; j<duzina; j++)
			{
				if(niz[j]==n3[i]) ima=1;
			}
		
		
		if(ima==0)
		{
			niz[k]=n3[i];
			k++;
			duzina++;
		}
	}
	
	for(i=0; i<duzina; i++)
	{
		brojac=0;
		for(j=0; j<v1; j++)
		{
			if(niz[i]==n1[j]) {brojac++; break;}
		}
		
		for(j=0; j<v2; j++)
		{
			if(niz[i]==n2[j]) {brojac++; break;}
		}
		
		for(j=0; j<v3; j++)
		{
			if(niz[i]==n3[j]) {brojac++; break;}
		}
		
		if(brojac==2) n++;
		
		
	}

	return n;
	

}
int main() {
	

	return 0;
}
