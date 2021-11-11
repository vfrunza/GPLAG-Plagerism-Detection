#include <stdio.h>

int sumacifara(int a)
{
	int suma=0;
	while (a!=0)
	{
		suma+=a%10;
		a/=10;
	}
	return suma;
}

int DaLiJeFibonacijev(int broj)
{
	int prvi=0,drugi=1, sljedeci,i;
	if(broj==1 || broj ==2 || broj==3||broj==5) return 1;
	for ( i = 0 ; i < broj ; i++ )
   {
      if ( i <= 1 )
         sljedeci = i;
      else
      {
         sljedeci = prvi + drugi;
         prvi = drugi;
         drugi = sljedeci;
      }
      if(broj==sljedeci) return 1;
   }
   return 0;
}

void ubaci (int niz[],int duzina)
{
	int i;
	for(i=duzina;i>=0;i--)
	{
		niz[2*i]=niz[i];
		if(niz[i]>0)
		{
		niz[2*i+1]=sumacifara(niz[i]);
		}
		else 
		{
		niz[2*i+1]=sumacifara(-niz[i]);
		}
	}
	
}
int izbaci(int niz[],int duzina)
{
	int i,j;
	for(i=0;i<duzina;i++)
	{
		if(DaLiJeFibonacijev(niz[i]))
		{
			for (j=i;j<duzina-1;j++) 
			{
				 niz[j]=niz[j+1];
			}
			duzina--;
			i--;
		}
	}
	return duzina;
}
int main() {
	int niz[20],i,vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d", &niz[i]);
	}
	ubaci(&niz,10);
	vel = izbaci(&niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0; i<vel; i++) 
	{
		if(i!=vel-1)
		printf("%d, ",niz[i]);
		else printf("%d.",niz[i]);
	}
	return 0;
}
