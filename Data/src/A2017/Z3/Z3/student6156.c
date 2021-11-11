#include <stdio.h>

int provjeri_niz(int* niz, int duzina);
int izbaci_cifre(int* niz1, int duzina1, int* niz2, int duzina2);


int main()
{
	int niz1[]={12341,134121,14221,15551,16541};
	int niz2[]={1,6};
	
	
printf("%d ",izbaci_cifre(niz1,5,niz2,2));
printf("\n%d , %d , %d , %d , %d ",niz1[0],niz1[1],niz1[2],niz1[3],niz1[4] );
	return 0;
}

int provjeri_niz(int* niz, int duzina)
{
	int i,j;
	for(i=0; i<duzina; i++)
	{
		if(niz[i]>9||niz[i]<0)
			return 0;

		for(j=i+1; j<duzina; j++)
		{
			if(niz[i]==niz[j])
				return 0;
		}

		for(j=i-1; j>-1; j--)
		{
			if(niz[i]==niz[j])
				return 0;
		}

	}
	return 1;
}
/*
svaki broj posebno spremim u obrnutom redoslijedu pri 
cemu ne uvrstavam cifre koje se izbacuju i ponovo 
ga prevrnem 
*/
int izbaci_cifre(int* niz1, int duzina1, int* niz2, int duzina2)
{
	int i,j,t,broj,znak;
	if(provjeri_niz(niz2,duzina2))
	{

		for(i=0; i<duzina1; i++)
		{
			broj =0;
			if(niz1[i]<0){znak=-1;niz1[i]*=znak;}
			else znak = 1;
			while(niz1[i]!=0)
			{
				t=0;
				
				
				for(j=0; j<duzina2; j++)
				{
					if(niz1[i]%10==niz2[j])
					{
						t++;
					}
				}
				if(t==0)
				{
					broj*=10;
					broj+=niz1[i]%10;
				}
				niz1[i]/=10;
			}
			if(broj==0)niz1[i]=0;
			else
			while(broj!=0)
			{
				niz1[i]*=10;
				niz1[i]+=broj%10;
				broj/=10;
			}
			niz1[i]*=znak;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}